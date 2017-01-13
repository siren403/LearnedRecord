### Sprite 생성

Sprite::create()로 생성하면 cocos에서 메인루프를 돌때마다 레퍼런스를 체크해서 autorelease함수에서 자동으로 해제한다.

Sprite::create()호출 후 retain()을 호출하면 (refcount++)

후 에 수동으로 해제해 주어야 합니다.

이때 해제는 release(refcount--)로 해주면 된다.

?: create()한 후 retain없이 멤버변수로 참조하다가 멤버변수에 NULL을 지정해서 참조를 끊는다면 메인루프에서 해제해주나? -> 그 이전에 create한 인스턴스를 addchild등의 refcount를 증가시켜주는 메소드들을 통해 관리 해주지 않으면 ref가 1에서 변화 하지않기 때문에 autoReleasePool을 통해 메모리에서 해제 된다. 그래프에 추가 하지않고 멤버 변수로서만 참조하여 가지고 있고 싶다면 retain으로 카운트로 올린 후 멤버변수로 참조하여 가지고 있으면 된다. 단, 이 경우에는 반드시 해당 인스턴스가 해제 되는 시점에 release를 호출하여 정상해제 되도록 해야한다

```
멤버변수로 참조만 하고 있다면 런타임중에
해제되지는 않는가?
-> 해제되어 nullpointer가 된다

addChild로 상위 노드에 참조시킨다면?
상위 노드가 헤제 될때 레퍼런스가 감소?
-> addchild시 refcount가 1증가하고
부모 노드 해제시 refcount가 1감소하여
autoReleasePool에 의해 해제된다
```

---

create()해서 쓰시려면 생각하시는것처럼 retain()해주면 됩니다. 하지만 이렇게 수동으로 retain()하실경우 어딘가에 꼭 release해주는 부분이 있어야 합니다. 편하게 하시는 방법은 빈 노드( node, ref, object... ) 하나 만드시고 여기저기서 사용할 스프라이트를 거기다가 다 addchild해주시는겁니다. 그다음에 날려야 할때 해당 노드 날리면 싹 날아가겠죠.. removechild로 부분적으로 날릴수도 있고요. vector보다 이게 편한거 같더군요...

---

sprite만들때 로딩되어오는 텍스쳐는 texturecache 에서 한번에 관리합니다. 같은 이미지는 읽어들여 계속 메모리에 적재 시 낭비가 심하기 때문. sprite를 날리더라도 texture는 texturecache에 남아 있게 된다.

texturecache는 임의로 정리 가능하다. 개발 시 상황에 맞춰 적절하게 사용.

void Director::purgeCachedData(void)
------------------------------------

sprite에 참조중인 texture를 overwrite하여 원본 리소스를 변경시켜도 다시 불러울 시 메모리에 적재된 상태로 주기때문에 변경된 원본의 상태로 받을 수 없다. 메모리에 적재된 texture를 Unload후 다시 적재하면 변경된리소스로 불러올 수 있다.

관련 메소드

```
Director::getInstance()->getTextureCache()->removeUnusedTextures();

TextureCache::sharedTextureCache()->removeUnusedTextures();

TextureCache::sharedTextureCache()->removeAllTextures();

TextureCache::sharedTextureCache()->reloadTexture("파일명");
```

---

### Scene

Scene에 자식으로 포함된 Sprite는 디렉터로 Scene전환 시에 자동으로 해제된다.

### removeChild

removeChild 함수의 내부에서 지우는 자식의 autoRelease 함수가 호출 됩니다.

### CREATE_FUNC(type)

cocos2d::Node를 상속 받은 클래스는 헤더에 CREATA_FUNC매크로를 선언하면 create()메소드가 생성되는데, 호출 시 객체를 생성하고 autoReleasePool에 등록시킨 인스턴스를 반환해 준다.(pool에 등록 하면서 refCount = 1) cocos2d-x엔진에 구조에 맞게 new생성을 숨기고 엔진에 의해 관리된 객체가 생성되는것을 보장받을 수 있다.

```
class MyClass : public Node
{
    public:
        CREATE_FUNC(MyClass);
};

MyClass * tMyClass = MyClass::create();
```

### eventDispatcher

씬 전환 시에 등록했던 이벤트를 해제하기 위해

`_eventDispatcher->removeAllEventListeners();`

를 호출하게 되면 다음 씬 init()에서 등록하게 되는 이벤트도 같이 해제가 되버리는것 같다.

> 다음 씬 init()에 메뉴를 생성해서 addChild를 하는 코드가 있었는데 이전 씬 exit()에서 이벤트를 편하게 해제 하려고`_eventDispatcher->removeAllEventListeners();`를 호출했는데 다음 씬에서의 MenuItem이 동작을 하지 않았다

이 경우에는 리스너들을 멤버변수로 참조시켜 exit시에 각각 별도로 해제를 해주거나

```
_eventDispatcher->removeEventListenersForTarget(this);
```

로 현재 씬을 target으로 넘겨 현재 씬으로 등록된 리스너들만 별도로 해제시켜 준다
