pyenv-virtualenv-autenv

[1](http://gyus.me/?p=475)

-	[windows for ubuntu, pycharm](#windows-for-ubuntu-pycharm)

[2](http://yujuwon.tistory.com/entry/pyenv-%EC%84%A4%EC%B9%98%ED%95%98%EA%B8%B0)

1번 링크로 진행 중 pyenv명령어 입력시 '찾을 수 없는 명령어..'머 이런식으로 나온다면 2번링크 중 경로 설정 부분 참고하여 진행

[nginx-uwsgi-django](http://brownbears.tistory.com/16#recentComments)

uwsgi

(env)pip install uwsgi

[uwsgi setting](http://arcanelux.tistory.com/entry/Ubuntu1404-Nginx-uWSGI-MySQL-Nodejs-npm-Bower-Django-%EC%84%A4%EC%A0%95)
test

uwsgi --http :8080 --home ~/.pyenv/versions/py343 --chdir ~/workspace/pygram -w pygram.wsgi
# 설명
uwsgi --http :8080 --home (PythonPath) --chdir (Django proejct folder) -w (Project name).wsgi


[pyenv commands](https://leop0ld.github.io/python-development-setting/)

[autoenv](https://leop0ld.github.io/python-development-setting/)

### windows for ubuntu, pycharm

[wsl ssh설정](http://jnuxy.tistory.com/2) pycharm->remote

wfu->openssh
