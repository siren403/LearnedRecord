#### 용도
    에디터 플레이모드 Play와 Stop상태로 전환 시 콜백

#### 구현
    using UnityEditor;

    [InitializeOnLoad]
    static class EditorPlayState
    {
        static EditorPlayState()
        {
            EditorApplication.playmodeStateChanged += ModeChanged;
        }

        static void ModeChanged()
        {
            if(!EditorApplication.isPlayingOrWillChangePlaymode &&
                EditorApplication.isPlaying)//스톱
            {
                Debug.Log("Exiting Playmode");
            }
            else if(EditorApplication.isPlaying)//플레이
            {
                Debug.Log("Start Playmode");
            }
        }
    }