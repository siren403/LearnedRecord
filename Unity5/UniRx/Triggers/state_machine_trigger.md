### Animator의 스테이트 변화 통지

스트림으로 스테이트 변화를 톨지받아 스테이트 변화에 따른 로직을 
MonoBehaviour에서 작성 가능

1. ObservableStateMachineTrigger를 상속받은 클래스를 작성 

2. Animator에서 작성한 StateMachineClass를 Add한다.

3. Animator.GetBehaviour<StateMachineClass>() 로 작성한 클래스를 가져와 Subscribe해서 사용한다

    Animator Anim;
    StateMachineClass AnimTrigger;

    void Awake()
    {
        Anim = GetComponent<Animator>();
        AnimTrigger = Anim.GetBehaviour<StateMachineClass>();

        AnimTrigger.OnStateEnterAsObservable()
            .Subscribe(onStateInfo=>
            {
                //todo...
            });
        ...
    }

