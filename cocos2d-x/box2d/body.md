### 바디의 운동상태

바디가 운동 중인지 체크할 때는

    b2Vec velo = body->getLinearVelocity();
    float length = velo.Length();

로 현재 속도의 길이를 구해 판단할 수 있다.
