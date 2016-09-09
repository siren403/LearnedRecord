[apktool 참조](http://blog.naver.com/programmist/220646356985)
[motizen-sign 참조](http://egloos.zum.com/jhpsb/v/231908)

### Apk추출

    1. 추출할 apk의 설치 패키지 명 검색

    adb shell pm list packages -f | findstr [검색 문자열]
    ex) adb shell pm list packages -f | findstr test

        package:/data/app/com.test.test-1/test.apk=com.test.test

        | 뒤에 검색 문자열을 같이 주지 않으면 패키지 검색량이 많아
        콘솔창에 내용이 전부 출력되지않음

    2. Apk추출

    adb pull [apk 경로] [추출할 경로:적지않으면 현재 경로]

    ex)adb pull /data/app/com.test.test-1/test.apk


### Apk 디컴파일,리패키징

    1. 필요 프로그램

        - ApkTool
        - motizen-sign
        - java

    2. 디컴파일

        java -jar apktool d [apk이름]

        ex) java -jar apktool.jar d test.apk

    3. 리패키징

        java -jar apktool b [리패키징 폴더] [리패키징파일이름.apk]

        ex) java -jar apktool b test test_repack.apk 

    4. 재서명

        java -jar signapk.jar testkey.x509.pem testkey.pk8 <새로 만들어질 파일 명>.apk

### 추가 : 유니티로 개발한 apk의 경우 *.asset 파일 확인하기

[AssetsBundleExtractor 다운로드]()

    위의 툴로 .asset 의 확장명을 가진 파일을 학인 할 수 있다.
    .asset 파일중에 *.asset.split0,...,*.asset.split10 같이
    여러개로 분리가 되어있는 경우도 있는데, 이 경우에는 cmd명령어로
    통합파일로 변환 가능하다 

    ex)
        copy /b *.asset.split0+...+*.asset.split10 *.asset

    현재 .asset내에서 export해서 원본을 확인해본것은 TextAsset Type뿐이다.
    경우에 따라 Base64같은 것으로 인코딩 되어있을 때도 있으니 경우에 맞게 
    변환하면 내용이 확인 가능하다.
    게임내의 대사내용 같은것을 발견할 경우에는 번역하여 재삽입하고 리패키징하는 것으로
    한글화로 활용이 가능하다

    