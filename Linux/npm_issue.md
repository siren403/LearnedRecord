### npm local install package

패키지를 글로벌이 아닌 로컬로 설치 했을 경우에 패키지 커맨드를 실행 할 수 없는 경우가 있다.

```
>> npm install webpack
>> touch webpack.config.js
>> vi webpack.config.js
>> webpack --config webpack.config.js
>> command not found
```

설치한 package.json의 scripts부분에 실행할 커맨드를 등록하여 npm run <scriptname>으로 실행한다.

```
{
"name": "dreact",
"version": "1.0.0",
"main": "index.js",
"scripts": {
    "webpack": "webpack --config webpack.config.js"
},

>> npm run webpack
```

### rasbian(데비안계열 리눅스?)

라즈비안에서 로컬로 설치한 npm 패키지 스크립트를 실행 시키는데 에러가 난다.

```
0 info it worked if it ends with ok
1 verbose cli [ '/usr/bin/nodejs', '/usr/bin/npm', 'run', 'webpack-build' ]
2 info using npm@1.4.21
3 info using node@v0.10.29
4 verbose run-script [ 'prewebpack-build', 'webpack-build', 'postwebpack-build' ]
5 info prewebpack-build dreact@0.0.0
6 info webpack-build dreact@0.0.0
7 verbose unsafe-perm in lifecycle true
8 info dreact@0.0.0 Failed to exec webpack-build script
9 error dreact@0.0.0 webpack-build: `webpack --config webpack.config.js`
9 error Exit status 127
10 error Failed at the dreact@0.0.0 webpack-build script.
10 error This is most likely a problem with the dreact package,
10 error not with npm itself.
10 error Tell the author that this fails on your system:
10 error     webpack --config webpack.config.js
10 error You can get their info via:
10 error     npm owner ls dreact
10 error There is likely additional logging output above.
11 error System Linux 4.4.13-v7+
12 error command "/usr/bin/nodejs" "/usr/bin/npm" "run" "webpack-build"
13 error cwd /home/seong/workspace/dreact
14 error node -v v0.10.29
15 error npm -v 1.4.21
16 error code ELIFECYCLE
17 verbose exit [ 1, true ]

```

찾아보니 이렇게 하면된다

`sudo ln -fs /usr/bin/nodejs /usr/local/bin/node`

/usrlocal/bin/ 으로 nodejs파일의 심볼릭링크를 걸어두면 된다
