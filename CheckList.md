### CheckList

메트리코

*[서버없이 메일 보내기](https://github.com/dwyl/html-form-send-email-via-google-script-without-server)

[Node.js 아키텍쳐 설명 문서(번역)](http://blog.canapio.com/52)

***[프로시쥬얼 버튼효과 제작기](http://cafe.naver.com/unityhub/43778)

[How to make a climbing system like in Assassins Creed in Unity part1](https://www.youtube.com/watch?v=y4dLaZ5eK44)
[How to make a climbing system like in Assassins Creed in Unity part2](https://www.youtube.com/watch?v=y3dZ1y3sbYM)
[How to make a climbing system like in Assassins Creed in Unity part3](https://www.youtube.com/watch?v=UMdd4rRH120)
[How to make a climbing system like in Assassins Creed in Unity part4](https://www.youtube.com/watch?v=MuIA6nja0Kw)

[Blade Runner 9732 In Unity](https://80.lv/articles/blade-runner-9732-in-unity/)

**[유니티 게임 데이터를 해킹하고 프로텍트 하는 데에 대한 튜토리얼](http://www.alanzucconi.com/2015/09/02/a-practical-tutorial-to-hack-and-protect-unity-games/)

*[Unity Dinamic Swap Shader - 01](http://blog.naver.com/roki0321/220788472677)

***[오버워치 FPS추적,AStar](http://m.blog.naver.com/for_goodgame/220777803189)

[유니티 c++ 소켓통신]

    < 코딩과 유관합니다 >
    c++에서 unity3d 로의 데이터 전송 방법을 찾고 있습니다.
    예를들어 아두이노와 pc간 시리얼 통신 처럼
    서버를 사용하지 않고 c++ 프로그램에서 몇개의 아스키값을 지속적으로 유니티로 전송해 줄 수 있는 에셋이나 라이브러리같은게 있을까요?
     c++ 코드에서 Serial.write 을 해주면 유니티에서 Serial.read 를 통해서 읽을 수 있다


[개발자가 이직에 대해 생각할 때 #2](http://www.mobiinside.com/kr/2016/08/25/developer-recruit-2/)

**[3D Games and Trigonometry(Youtube 재생목록)](https://www.youtube.com/playlist?list=PLRf-PfhVvwFAwoXlUYyYQpKPqP9iUIdn_)


[유니티 모바일 용량 최적화 팁]

    0. 직진용사는 Unity 5.3.4f1 + Unity UI Extention 5.3 + Unity IAP + Unity Analytics + UnityEngine.SocialPlatforms(iOS) & GooglePlayGamesPlugin-0.9.32(Google)을 사용하였습니다. 광고를 위해 UnityAds + GoogleMobileAds_v3.0.4를 사용했습니다.
    1. 직진용사는 그래픽이 복잡한 3D 게임이 아니고, 스프라이트 기반 2D 게임이어서 QualitySetting은 Simple로 해 두었습니다. 그리고 V Sync를 Don't sync로 해 두었는데요, Android 단말에서 Application.targetFrameRate를 지정하시려면 Don’t sync가 필수 옵션입니다(iOS 단말에서는 60으로 고정되는 것으로 알고 있습니다). 렌더링, 섀도우 옵션 등을 더 만질 수 있을 것 같네요.
    2. iOS Settings 에서는 Target minimum iOS Version은 7.0으로, 게임에서 Accelerometer는 사용하지 않기 때문에 Disabled로 했구요, GooglePlayGameService Plugin은 Unity.SocialPlatform interface를 사용하고 있기 때문에, GPGS를 Android에서만 사용하고, iOS에서는 GameCenter를 쓰려면 Scripting Define Symbols에 NO_GPGS를 해 주셔야 합니다(GPGS 가이드에 나와있습니다. ^^).
    3. 이어서 Android Settings 입니다. 특별할 건 없고, Device Filter 쪽만 ARMv7 only로 세팅했습니다. Default는 ARMv7 + x86 인데요, x86은 중국 일부 폰 및 태블릿에서만 사용되는 것으로 알고 있어서 제외시켰습니다. Minimum API Level은 15 (4.0.3) 정도면 대다수의 단말 및 SDK들을 커버 가능하고, 저사양 단말에서 게임이 구동되지 않아 낮은 별점을 받는 것을 방지할 수 있습니다.
    4. 직진용사 그래픽 특성 상, Sprite들은 모두 Generate Mip Maps 옵션을 껐습니다. 도트 그래픽 특성을 살려야 하기 때문에 Filter Mode는 Point(no filter)로 해 두었고요, 각 스프라이트 별로 원본 사이즈를 확인하고, 그에 맞는 Max Size를 세팅하였습니다. Format은 전부 TrueColor로 했고, 각 Scene 및 Instantiate하는 Pop up 마다 사용되는 이미지들을 분류하여 Packing tag를 달아주고, Sprite packing을 하였습니다. Texture Atlas는 가급적 1024*1024 이하로, 빈 공간이 많지 않게 꽉꽉 채워서 만들어지게 했습니다. 참고로 전체 Sprite 폴더 용량은 3.9MB 정도 됩니다.
    5. 마지막 Audio clip들인데요, 역시 직진용사 특성 상, 8비트 라이크한 사운드를 효과음으로 사용하였기 때문에 Force To Mono 옵션을 체크하였습니다. 원본 용량 대비 많이 줄어듭니다(BGM은 Stereo 그대로 사용하였습니다). 참고로 전체 Audio Clip 폴더 용량은 7.7MB 정도 됩니다.
    6. 추가로, Unity > Edit > Project Settings > Time 에서 Fixed Timestep을 지정할 수 있는데요, 기본값은 0.02 이며(void FixedUpdate ()가 0.02초 마다 불리게 되죠) 물리가 필요 없거나, 애니메이션이 매우 부드럽게 이루어져야하는 씬이 아닌 경우 저는 0.2로 세팅을 했습니다. 이 값은 씬 마다 Script로 Dynamic 하게 지정이 가능한데요, 이 값으로 게임 중에 시간이 느려지는 듯한 연출도 가능하며, 기본 값으로라면 1초에 50번 FixedUpdate ()가 호출되는만큼, 잘 조정하시면 여러모로 쓸모가 있습니다. ^^ 그리고 1번에서 말씀드린 Application.targetFrameRate 값도 씬 및 특정 상황마다 잘 조정하시면 Android 단말에서의 발열을 잡는데도 도움이 될 수 있을 것입니다(Unity Editor에서도요. 저는 맥북에서 작업하는데요, 이 값 조정 안하고 이것 저것 테스트 하다보면 팬이 미친 듯이 돕니다...ㅜㅜ)


[Math Application](http://m.wolframalpha.com/)

[이미지와 비디오 리사이즈 서비스](http://cloudinary.com/)

[인터넷 스크랩 보관 개인 어플리케이션 제작 필요]

[React.js 한글강좌](https://www.inflearn.com/course/react-%EA%B0%95%EC%A2%8C-velopert/?subscribe)

[ES7에 제안된 바인드 연산자(Bind Operator)](https://github.com/tc39/proposal-bind-operator)
    
    새로 ES7에 제안된 바인드 연산자(Bind Operator)입니다. bind/call/apply를 할 필요없이 ::한번에 연결할 수 있게 해주네요. ES6의 class가 constructor의 문법 설탕이듯이 bind/call/apply의 문법설탕이라고 하네요.

    ex)
    // <= ES6
    var obj = { value: 5 };
    function method1() { return this.value; }

    method1.call(obj); // 5

    // ES7 Bind Operator
    obj::method1(); // 5


[알고리즘문제 - 드래곤 커브](https://algospot.com/judge/problem/read/DRAGON)

    https://www.facebook.com/groups/codingeverybody/permalink/1290545624319304/

[APK크기 줄이는법 4가지, 메모리 누수 사례 정리](https://realm.io/kr/news/aw208-android-leaner-apk-memory-leak/)

[비디자이너의 얕은 지식 쌓기: 디자인 용어 20](http://slowalk.tistory.com/m/2427)

[안드로이드 앱성능 최적화-05 : 벤치마크와 프로파일링](http://www.openeg.co.kr/248)

[컴활 준비, 엑셀 함수 이것만은 꼭 알아둬!](https://www.facebook.com/MicrosoftKorea/posts/1080790145291916)

[링크드인, 안드로이드용 테스트·버그 보고 기술 공개](http://www.bloter.net/archives/261131)

**[안드로이드/JAVA : 한글 받침에따라서 '을/를' 구분하기](http://gun0912.tistory.com/65)

[React 컴포넌트의 계층 구조를 시각적으로 보여주는 오픈](https://github.com/team-gryff/react-monocle)

[인디 게임 다큐 : Branching Paths](http://www.ibatstudio.com/%EC%9D%BC%EB%B3%B8%EC%9D%98-%EC%9D%B8%EB%94%94-%EA%B2%8C%EC%9E%84-%EA%B0%9C%EB%B0%9C%EC%9E%90-%EB%8B%A4%ED%81%90%EB%A9%98%ED%84%B0%EB%A6%AC%EA%B0%80-%EC%B6%9C%EC%8B%9C%EB%90%98%EC%97%88%EB%84%A4/)

[개발환경별 쓰이는 git ignore 데이터베이스](https://www.gitignore.io/)
    
    Visual studio에 git를 이용하여 협업을 할 때 
    각자 컴퓨터에서 헤더파일 경로나 라이브러리 경로 등등
    각각 다르게 지정될 필요가 있는 경우가 많을 것 같습니다.
    그런 경우에 모든 변경된 파일을 커밋한다면 혼란이 올텐데
    어떻게 해결하는 것이 일반적인 방법인가요?
    제가 생각하기로는.. .gitignore파일을 이용해서 커밋하지 않을 파일을 지정하면 될것 같은데.. 어떤 파일을 지정해줘야 하는지.. 잘 모르겠고..
    또는 다른 방법이 있다면 정보를 주시면 감사하겠습니다.
    -------------------------------------
    이미 빌드된 라이브러리를 패키지 매니저로 땡겨서 쓰든, 코드만 가져다 솔루션 내에서 빌드해서 쓰든, 빌드 depdendency를 절대 경로로 적어 넣지 말아야 하고, 최악의 경우라도 환경 변수를 참조하는 식이어야 합니다. CI에서 자동 빌드를 유지하고 있으면 누군가 빌드 시스템을 깨먹을만한 커밋을 올렸을 때 빨리 발견-조치할 수 있어서 유용하죠.


[유니티 구글 애드몹 이슈 : unity-plugin-library.jar파일 누락](https://www.facebook.com/groups/unitykorea/permalink/1061289017286257/)

**[2016 동국대 컴퓨터그래픽스 입문 강의 모음](http://blog.naver.com/atelierjpro/220775601324)

[여러분이 생각하는 디테일은 무엇인가요?](https://www.facebook.com/groups/indiera/permalink/635710233246340/)

[Python Luige 예제](http://blog.naver.com/hancury/220775449482)

[인디는 스팀에서 어떻게 생존해야 하나요?](https://www.facebook.com/thisisgamecom/posts/1242376775774521)

[포토샵 도트 기초 1](https://www.facebook.com/groups/indiera/permalink/630897410394289/)
[포토샵 도트 기초 2-2](https://www.facebook.com/groups/unitykorea/permalink/1058572764224549/)

[파라독스 인터렉트의 개발자가 2016GDC에서 "역사 와 게임 디자인"이란 주제로 40여분의 강연](https://www.youtube.com/watch?v=hYzxcf_ZL_g&utm_content=buffera1389&utm_medium=social&utm_source=twitter.com&utm_campaign=buffer)

[개발자들을 위한 인공지능 기술시대](http://www.zdnet.co.kr/column/column_view.asp?artice_id=20160720105047)

**[Delegates and Events in Unity](http://www.unitygeek.com/delegates-events-unity/)

[김포프님 Youtube - 해쉬와 암호화]

    http://Owasp - Top10

    #### Hash
    데이터 -> 해쉬 O
    해쉬 -> 데이터 X

    Hash 변환 시 Hash Collision 발생 가능성 있음

    -Hash를 이용한 패스워드 관리
    패스워드->Hash->Hash+Salt(_???)->hash->결과물 저장
    패스워드 검사 시
    입력받은 패스워드->Hash+Salt->hash->결과물 비교
    패스워드는 직접 공개 불가해야함
    암호화는 부적절

    -암호화 패턴을 유추하기 어렵게 변환하기
    string a = "empty";
    const string salt = "salt";
    encrypt(key, a+"_"+salt+"_"+{RandomNumber});


[유니티(Unity)에서 애셋이 어디에서 참조되고 있는지 알아 내는 방법](https://sunhyeon.wordpress.com/2013/04/21/746/)

[Dynamic-Sprite-Color-Swap-Shader](https://github.com/tutsplus/Dynamic-Sprite-Color-Swap-Shader)

[How to Use a Shader to Dynamically Swap a Sprite's Colors](http://gamedevelopment.tutsplus.com/tutorials/how-to-use-a-shader-to-dynamically-swap-a-sprites-colors--cms-25129)

[두나미스 테크니컬 아티스트](http://tartist.tistory.com/)

[Basic 2D Platformer Physics ](http://gamedevelopment.tutsplus.com/series/basic-2d-platformer-physics--cms-998)

***[바야바님 공유 자료 링크](https://drive.google.com/drive/folders/0B6Vj-m5tcMbKMDZ6a3VDeFVjMnM)
[온라인 장기 서버를 응용해서 만든 아바타 채팅 풀소스입니다.](https://www.facebook.com/groups/indiera/permalink/654872607996769/)
[유니티로 만든 장기 온라인 게임 서버/클라 풀소스](https://www.facebook.com/groups/unitykorea/permalink/1090554317693060/)
[2D 유도탄 미사일 예제](https://www.facebook.com/groups/indiera/permalink/652954291521934/)
[LineRenderer를 활용한 전기 이펙트 예제](https://www.facebook.com/groups/unitykorea/permalink/1086428154772343/)


*[키스토어 관리 프로그램](http://www.keystore-explorer.org/downloads.html)

***[유니티 c# 6.0](http://potatonaru.tistory.com/4)

[한개의 텍스쳐 개별 맵핑(ex:사각사진퍼즐)](https://www.facebook.com/groups/unitykorea/permalink/1089914797757012/)

**[수학을 포기한 직업 프로그래머가 머신러닝 학습을 시작하기위한 학습법 소개](http://www.moreagile.net/2015/05/how-to-start-machine-learning-study.html)

[다이나믹한 컷씬 연출 방법?(ex:나루티밋스톰4)](https://www.facebook.com/groups/unitykorea/permalink/1087466391335186/)

[ATOM 필수 플러그인](https://joshuajangblog.wordpress.com/2016/09/01/atom-plugins-cant-live-without-it/)



----7월 19일