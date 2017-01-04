### 윈도우에서 pygame 환경 세팅

1.  http://www.pygame.org/download.shtml 에서

        pygame-1.9.1.win32-py3.1.msi 3MB

    다운로드


pygame과 python은 bit와 버전이 일치해야하는데
pygame은 32bit만이 공식 지원이기 때문에
python도 pygame 버전과 함께 맞춰서
python3.1.0 32bit를 다운로드하여 설치하여야 한다.

2. https://www.python.org/download/releases/3.1/ 에서

        Windows x86 MSI Installer (3.1) (sig)

    다운로드

3. python을 먼저 설치한 후 pygame패키지 파일을 python설치 경로에
옮긴 후 패키지를 설치한다.

4. python console을 실행 후 아래코드를 입력해서 pygame의
정상설치를 확인한다

        >>> import pygame
        >>> pygame.init()
        (6, 0)

위와 같은 결과가 나온다면 문제없음
