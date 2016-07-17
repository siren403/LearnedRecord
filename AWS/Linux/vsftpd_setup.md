### EC2 Ubuntu에 vsftpd세팅
*root계정으로 진행*

    apt-get update
    apt-get install vsftpd

    nano /etc/vsftpd.conf

*주석 해제*
anonymous_enable=NO
local_enable=YES
write_enable=YES
local_umask=022

chroot_local_user=NO
chroot_list_enable=YES
chroot_list_file=/etc/vsftpd.chroot_list

*vsftpd.chroot_list에 적은 유저는 상위폴더 접근 불가*
*적지않으면 상위폴더 접근가능*

    chroot_local_user=NO 
    chroot_list_enable=YES
    chroot_list_file=/etc/vsftpd.chroot_list

*접속 계정의 홈디렉토리만 접근 가능*

    chroot_local_user=YES 
    #chroot_list_enable=YES
    #chroot_list_file=/etc/vsftpd.chroot_list

*vsftpd.chroot_list에 적은 유저만 접속, 상위폴더 접근 가능*

    chroot_local_user=YES 
    chroot_list_enable=YES
    chroot_list_file=/etc/vsftpd.chroot_list


*맨밑에 작성*
allow_writeable_chroot=YES

pasv_enable=YES 
pasv_min_post=1024
pasv_max_port=1048
pasv_address=[ec2 public IP]

- allow_writeable_chroot=YES을 적으면 500 ... chroot() 에러 해결

*ec2 콘솔에서 Inbound설정*
- Security Group -> Inbound Edit
Custom TCP Rule
TCP
20 - 21
Anywhare 0.0.0.0/0
Custom TCP Rule
TCP
1024 - 1048
Anywhare 0.0.0.0/0

*ftp user생성*

    useradd [user name] -m
    passwd [user name]
    패스워드 설정

*chroot_list 작성*

    nano /etc/vsftpd.chroot_list

    [ftp user name 추가]

*etc/passwd 확인*

    nano /etc/passwd

ftp계정 옆에 /bin/bash가 없으면 추가
없을경우 접속할 시 530에러 발생 

*vsftpd 재시작*

    service vsftpd restart
