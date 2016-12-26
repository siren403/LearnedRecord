라즈베리파이 IP
192.168.0.147

pi/351236

TightVNC
5901/qkr351236

[절전모드 해제](http://zelkun.tistory.com/65)

무선랜 절전모드

  $ iw wlan0 get power_save

  위 커맨드로 기존 wlan0 상태 값을 확인 하신 뒤에

  $ sudo iw wlan0 set power_save off or on

  위 커맨드로 옵션 조절이 가능합니다.

  # Jessie 4.4.13+ 이후 커널 기준입니다.
