version : cocos2d-x 3.14

---
[issue 링크](http://discuss.cocos2d-x.org/t/label-crashes-app-in-android-when-switching-scenes/31578)

createWithTTF로 Label 생성 후 Scene 전환 시

윈도우에서는 정상 작동 하지만

안드로이드에서 실행 할 경우 Crash가 나는 경우가 있다.

```
Fatal signal 11 (SIGSEGV), ...
```

이경우 create로 생성하여 autoreleasepool에 등록하지 않고

new로 별도로 생성하여 사용하면 해결 할 수 있다.

```
Label labelTTF = new Label();
//labelTTF->retain();
labelTTF->initWithTTF(TTFConfig("fonts/NotoSansKR-Regular-Hestia.otf", 28),"textsample");
this->addChile(labelTTF);

using....

//CC_SAFE_RELREASE_NULL(labelTTF);

```
