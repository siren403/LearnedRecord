### Animator

#### StateMachine의 상태 변화 콜백 받기

1. StateBehaviour를 상속받아 대상 Animator에 Add한다.

2. 가상함수를 구현하여 각 스테이트 변화에 따라 로직 구현

    public class State : StateBehaviour 
    {
        override ...
    }

[UniRx를 활용한 State변화 통지] : (Unity5\UniRx\Triggers\StateMachineTrigger)
