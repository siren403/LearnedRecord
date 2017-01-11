### npm local install package

패키지를 글로벌이 아닌 로컬로 설치
 했을 경우에 패키지 커맨드를 실행 할 수
 없는 경우가 있다.

    >> npm install webpack
    >> touch webpack.config.js
    >> vi webpack.config.js
    >> webpack --config webpack.config.js
    >> command not found

설치한 package.json의 scripts부분에 실행할 커맨드를
등록하여 npm run <scriptname>으로 실행한다.

    {
    "name": "dreact",
    "version": "1.0.0",
    "main": "index.js",
    "scripts": {
        "webpack": "webpack --config webpack.config.js"
    },

    >> npm run webpack
