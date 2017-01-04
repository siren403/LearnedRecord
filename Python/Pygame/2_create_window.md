## 윈도우 창 띄우기

* 예제 코드


    import pygame

    pygame.init()

    ourScreen = pygame.display.set_mode((400,300))

    pygame.display.set_caption('파이게임')

    finish = False

    while not finish:
    for event in pygame.event.get():#발생한 이벤트 리스트
        if event.type == pygame.QUIT:
            finish = True

        # pygame.display.update()
        pygame.display.flip()

### 부분 설명

    pygame.display.set_mode((400,300))

set_mode의 첫번째 인자로 튜플로 구성된
Resolution(해상도)을 전달하여 화면의
사이즈를 지정

***
    pygame.display.set_caption('파이게임')

생성된 윈도우의 제목을 지정

***

    finish = False

    while not finish:
    for event in pygame.event.get():#1.
        if event.type == pygame.QUIT:#2.
            finish = True#3.

        #4.
        # pygame.display.update()
        pygame.display.flip()

1. 발생한 이벤트의 리스트를 가져와서
2. 해당이벤트의 타입이 QUIT(종료)라면
3. finish를 True로 값을 변경하여 루프의 종료를 작성
4. 디스플레이를 업데이트 시킬때 update()나 flip()을 사용

flip은 그림을 한장씩 넘기며 애니메이션을
표현하는 flipbook처럼 이해
