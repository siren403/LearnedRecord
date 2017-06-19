### Editor Window

ScriptableObject를 수정하는 에디터를 만들 때
수정전에 Undo.RecordObject를 거치면 유니티 종료 시에
데이터가 저장되지 않을 수 있는 경우를 방지 할 수 있다.
```
Undo.RecordObject()는 전달한 대상을 실행취소(Ctrl+Z)
스택에 저장하여 커맨드 실행 시 변경사항을 되돌릴 수 있다.
이전 상태와 비교하여 변경사항이 없을 시 스택에 저장되지
않는다.
```
