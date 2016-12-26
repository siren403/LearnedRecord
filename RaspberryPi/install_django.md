1. instal docker

docker-hypriot

2. pull raspbian iamge

3. run container

  docker run -it [image] /bin/bash

4. install wget

  sudo apt-get update
  sudo apt-get install wget

5. install python3

[참고](https://wikidocs.net/8)
[다운로드 페이지](https://www.python.org/downloads/release/python-351/)
[zlib 다운로드](http://www.zlib.net/)

  wget http://zlib.net/zlib-1.2.8.tar.gz
  tar -xvzf zlib-1.2.8.tar.gz
  cd zlib-1.2.8
  ./configure
  make
  make install

  sudo apt-get install gcc g++ make

  apt-get install libssl-dev
  [pip3](http://blog.colab.kr/11)
  만일 파이썬3를 사용하고있다면

    sudo apt-get install python3-setuptools
    sudo easy_install3 pip

  또는 별도의 명령으로 pip를 설치할 수도 있다

    sudo apt-get install python3-pip


  sudo apt-get install sqlite3 libsqlite3-dev

  wget https://www.python.org/ftp/python/3.5.1/Python-3.5.1.tar.xz
  tar -xvf Python-3.5.1.tar.xz

  cd Python3.5.1
  ./configure
  make
  su -
  make install


[django 진행](http://astronaut94.tistory.com/entry/Django-%EC%82%AC%EC%9D%B4%ED%8A%B8-%EA%B5%AC%EC%B6%95-1-%EA%B0%84%EB%8B%A8%ED%95%9C-Nginx-uWSGI-Django-%EC%82%AC%EC%9D%B4%ED%8A%B8-%EB%A7%8C%EB%93%A4%EA%B8%B0#recentTrackback)

5. virtualenv 가상환경 생성

  sudo apt-get install python-virtualenv
  cd ~
  mkdir myproject
  cd myproject
  virtualenv --python=python3 venv
  source venv/bin/activate

가상환경에서 빠져나오기 위해서는 아래 명령어면 충분하다.

  deactive

6. install django

  (venv)pip install django

7. 프로젝트 생성

  (venv)django-admin startproject

  myproject
  ├── myproject
  │   ├── db.sqlite3
  │   ├── myproject
  │   │   ├── __init__.py
  │   │   ├── settings.py
  │   │   ├── urls.py
  │   │   └── wsgi.py
  │   └── manage.py
  └── venv
      ├── bin
      │   └── ...
      ├── lib
      │   └── ...
      └── share
          └── ...

  cd myproject
  (venv)python manage.py runserver 0.0.0.0:8000
  curl http://127.0.0.1:8080/

3. Nginx,uWSGI 설치

  sudo apt-get install nginx-full uwsgi
