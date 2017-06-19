[commands](https://gist.github.com/nacyot/8366310)
[commands2](http://pyrasis.com/Docker/Docker-HOWTO)

### issues

우분투 컨테이너에서 iptables접근 시 permission denied로 접근안될시
http://ikarishinjieva.github.io/tachikoma-blog/post/2014-07-10-docker-some-error/
컨테이너 실행 명령어에 --privileged=true 추가



docker에서 컨테이너를 종료하지 않고 나오는 방법(bash쉘)
ctrl + p + q


ex)
docker run -it --name django -p out:in -p 8000:80 --privileged=true a11ac7a3a26f /bin/bash
