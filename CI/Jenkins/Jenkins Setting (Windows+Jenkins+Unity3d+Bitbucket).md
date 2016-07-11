1.시작 환경
공유기 사용 중
노트북(윈도우8,Unity5.3.4f1)
Git/Bitbucket


2. 클라이언트 다운로드
https://jenkins.io/
왼쪽 위 다운로드에서 버전 및 플랫폼을 선택

3. 인스톨러 실행 후 안내에 따라 설치 진행
- 파일 설치
- 계정 생성
- 플러그인 설치 설정 선택

4. 플러그인 확인 후 추가 설치
대시보드/Jenkins 관리/PluginManager
- Git Plugin
- Bitbucket Plugin
- Unity3d Plugin

5. 각종 세팅
- Configure Global Security
* Enable security : true
* Access Contorl/Security Realm/Jenkins' own user database 선택,
  사용자 가입 허용 : true
- Global Tool Configuration
* JDK installations 설정
Name : 구별용 이름 ex) Default
JAVA_HOME : jdk디렉토리 
* Unity3d
Name : ex) Unity 5.3.4f1
ins...Diretory : 유니티 설치 경로
6. 빌드 생성
- 새로운 Item
- 빌드 프로젝트 이름 설정
- Freestyle project 선택

7. 유니티 세팅
- 유니티 프로젝트 생성
- 안드로이드 프로젝트 환경 세팅(플랫폼,패키지 등)
- 젠킨스에서 빌드요청 시 필요한 스크립트 작성
* Assets/Editor/Jenkinsbuilder.cs 생성 
using System;
using UnityEditor;
using System.Collections.Generic;
using System.IO;
using UnityEngine;

//batchmode 빌드 시 클래스 이름 사용
//사용자에 맞게 이름 변경 사용
class JenkinsBuilder
{
    static string[] SCENES = FindEnabledEditorScenes();
    //Apk 파일 이름
    static string APP_NAME = "JenkinsBuildTest";

    #region 필수 메소드
    private static string[] FindEnabledEditorScenes()
    {
        List<string> EditorScenes = new List<string>();
        foreach (EditorBuildSettingsScene scene in EditorBuildSettings.scenes)
        {
            if (!scene.enabled) continue;
            EditorScenes.Add(scene.path);
        }
        return EditorScenes.ToArray();
    }

    static void GenericBuild(string[] scenes, string target_dir, BuildTarget build_target, BuildOptions build_options)
    {
        EditorUserBuildSettings.SwitchActiveBuildTarget(build_target);
        string res = BuildPipeline.BuildPlayer(scenes, target_dir, build_target, build_options);
        if (res.Length > 0)
        {
            throw new Exception("BuildPlayer failure: " + res);
        }
    }
    #endregion


    //에디터 상에서 빌드 테스트 및 젠킨스,batchmode에서 호출할 빌드 메소드
    [MenuItem("Custom/CI/Build Android")]
    static void PerformAndroidBuild()
    {
        //빌드 옵션 설정
        BuildOptions opt = BuildOptions.None;
        
        //현재 프로젝트/Android/BundleVersion 디렉토리 생성
        string Path = Directory.GetCurrentDirectory() + "\\Android\\" + PlayerSettings.bundleVersion;
        if (!Directory.Exists(Path))
            Directory.CreateDirectory(Path);

        //위 디렉토리에 apk파일 이름 Append
        string BUILD_TARGET_PATH = Path + string.Format("\\{0}_{1}.apk", APP_NAME, PlayerSettings.bundleVersion);

        //최종 경로 확인
        Debug.Log(BUILD_TARGET_PATH);
       
        GenericBuild(SCENES, BUILD_TARGET_PATH, BuildTarget.Android, opt);
    }

}
- 유니티 메뉴 바에서 Custom/CI/PerformAndroidBuild 실행 후 
  출력된 로그의 디렉토리에 빌드가 성공하였는지 확인
8. 빌드 프로젝트 설정
- 프로젝트/구성
- Build/Invoke Unity3d Editor/Editor command line arguments에 batch커맨드 입력

-quit -batchmode -executeMethod JenkinsBuilder.PerformAndroidBuild -projectPath "빌드할 프로젝트 경로"

[JenkinsBuilder.PerformAndroidBuild] : 유니티 프로젝트 내에 작성한 빌드 스크립트의 클래스이름.메소드

- 배치 커맨드 테스트
* cmd에서 Unity.exe가 위치한 폴더 이동 후
Unity.exe batch커맨드
  실행
- 젠킨스 프로젝트 메뉴에서 BuildNow를 실행하면 빌드가 진행됨
9. Bitbucket Repository 연동
- 소스코드관리에서 Git선택
- Repository URL 입력
- Credentials 옆 Add/Jenkins
Domain : Global
Kind : Username with password
Username : 저장소 계정 Username
Password : 저장소 계정 비밀번호
- 빌드 유발에서 Bitbucket Webhooks URL추출
Authentication Token : 인증 토큰 이름 입력
InputBox밑의 툴팁을 참조해서 URL작성
ex) Use the following URL to trigger build remotely:JENKINS_URL/job/UnityBuildTest/build?token=TOKEN_NAME or /buildWithParameters?token=TOKEN_NAME
Optionally append &cause=Cause+Text to provide text that will be included in the recorded build cause.

URL : JENKINS_URL/job/UnityBuildTest/build?token=TOKEN_NAME
JENKINS_URL : 도메인또는ip:젠킨스포트(기본 8080), 해당포트가 열려있어야 Bitbucket에서 요청이 가능함
TOKEN_NAME : Authentication Token에 입력한 토큰이름
      http://127.0.0.1:8080/job/UnityBuildTest/build?token=jenkinsToken   

- Build when a change is pushed to Bitbucket : true
- 7.에서 작성한 batch커맨드에서 -projectPath제거
- Bitbucket 저장소/Settings/Webhooks이동
- AddWebhook
Title 
URL : 좀 전에 작성해 놓은 URL입력
Triggers : Repository push 선택

- 저장소에 Push를 하게되면 젠킨스에서 설정할 Branch를 가져와 빌드 실행
 젠킨스설치경로/workspace에 clone 생성