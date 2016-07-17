### 한글 세팅

- AWS에서 우분투 돌려서 공부용으로 사용하고 있는데 한글 입력이 안된다. 문제의 원인은 시스템 locale이 미국 영어로 되어있기 때문인데, 이것을 변경해주면 한글을 사용할 수 있다.

- 일단 locale을 확인해본다. 아마 미국 영어로 되어 있을 것이다.

    $ locale

- 우선 첫번째 할 일은 한글 입력 패키지를 다운받아 설치해야한다. apt-get으로 간단히 설치할 수 있는데, 문제는 어떤 패키지가 있는지 알기 힘들다는것... 구글링 결과 여러가지 썰이 있었는데 아래의 것을 설치하면 된다.

    $ sudo apt-get install language-pack-ko

- 다음으로 시스템 전체의 locale을 변경한 후 설정한다.

    $ sudo locale-gen ko_KR.UTF-8

    $ sudo dpkg-reconfigure locales

- 그리고 다음번 부팅할 때도 기본적으로 한글을 사용하기 위해 /etc/default/locale 파일을 아래와 같이 변경해준다.

    LANG="ko_KR.UTF-8"
    LANGUAGE="ko_KR:ko:en_US:en"

- 이제 다시 접속할 때마다 자동으로 한글을 사용할 수 있다.

- 단! 이렇게 했음에도 한글이 제대로 표시/입력되지 않을 수 있는데 그건 사용하는 터미널 프로그램의 설정이 잘못되어있기 때문이다. 아마존 클라우드는 SSH를 사용하고, 아무래도 많이 사용하는 프로그램이 putty 일테니 putty 기준으로 설명하면(사실 본인이 putty를 쓰기 때문), putty 설정창의 Window->Translation 항목을 보면 Remote character set이 있다. 이게 기본값이 Use font encoding으로 되어 있는데 이걸 UTF-8으로 바꾸면 정상적으로 한글을 사용할 수 있다