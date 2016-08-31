### ReactNative 윈도우 환경 세팅

[ReactNative github.io](https://facebook.github.io/react-native/docs/getting-started.html)


#### 필수 패키지 설치

1. node.js 설치
    
    - cmd에 npm입력으로 설치 확인

2. python2 설치
3. npm install -g react-native-cli 커맨드로 ReactNative설치 

#### 프로젝트 생성

    // AwesomeProject(프로젝트 이름) 초기화
    react-native init AwesomeProject
    cd AwesomeProject
    react-native run-android



#### 이슈
// -디바이스를 pc에 연결 중인데 패키지 설치가 되지 않을경우

- js리로드 불가 시 
    1. 안드로이드 디바이스의 연결포트가 다를경우
        adb reverse tcp:8081 tcp:8081 
    2. adb devices로 확인하였을때 다수의 디바이스가 잡힐경우
        adb kill-server 후 재확인

    

