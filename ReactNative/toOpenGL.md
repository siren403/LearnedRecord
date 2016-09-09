### 리액트 네이티브에서 OpenGL 사용하기

[gl-react-native](https://github.com/ProjectSeptemberInc/gl-react-native)

-gl-react-native 설치
      
    npm i --save gl-react-native

-gl-react 설치
        
    npm i --save gl-react

-on Android

1. 프로젝트\android\settings.gradle에 코드 추가

    include ':RNGL'
    project(':RNGL').projectDir = file('../node_modules/gl-react-native/android')

2. 프로젝트\android\app\build.gradle
dependencies {
    ...
    compile project(':RNGL')
}
3. 프로젝트\android\app\src\main\java\com\프로젝트명\MainApplication.java
    
    import com.projectseptember.RNGL.RNGLPackage;
    
    @Override
    protected List<ReactPackage> getPackages() {
      return Arrays.<ReactPackage>asList(
        new MainReactPackage(),
        ...,
        new RNGLPackage()// Add
      );
    }

### 이슈

-requiring unknown module "gl-react".

    npm i --save gl-react


