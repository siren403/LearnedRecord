### Sprite 생성

Sprite::create()로 생성하면 cocos에서
메인루프를 돌때마다 레퍼런스를 체크해서
autorelease함수에서 자동으로 해제한다.

Sprite::create()호출 후 retain()을 호출하면
(refcount++)

후 에 수동으로 해제해 주어야 합니다.

이때 해제는 release(refcount--)나 autorelease둘 중 하나로
해주면 된다.

?: create()한 후 retain없이 멤버변수로 참조하다가
멤버변수에 NULL을 지정해서 참조를 끊는다면
메인루프에서 해제해주나?

멤버변수로 참조만 하고 있다면 런타임중에
해제되지는 않는가?

addChild로 상위 노드에 참조시킨다면?
상위 노드가 헤제 될때 레퍼런스가 감소?
---
create()해서 쓰시려면 생각하시는것처럼 retain()해주면 됩니다. 하지만 이렇게 수동으로 retain()하실경우 어딘가에 꼭 release해주는 부분이 있어야 합니다.
편하게 하시는 방법은 빈 노드( node, ref, object... ) 하나 만드시고 여기저기서 사용할 스프라이트를 거기다가 다 addchild해주시는겁니다. 그다음에 날려야 할때 해당 노드 날리면 싹 날아가겠죠.. removechild로 부분적으로 날릴수도 있고요. vector보다 이게 편한거 같더군요...

---

sprite만들때 로딩되어오는 텍스쳐는 texturecache
에서 한번에 관리합니다. 같은 이미지는 읽어들여
계속 메모리에 적재 시 낭비가 심하기 때문.
sprite를 날리더라도 texture는 texturecache에
남아 있게 된다.

texturecache는 임의로 정리 가능하다.
개발 시 상황에 맞춰 적절하게 사용.
void Director::purgeCachedData(void)
---
sprite에 참조중인 texture를 overwrite하여 원본
리소스를 변경시켜도 다시 불러울 시 메모리에
적재된 상태로 주기때문에 변경된 원본의 상태로
받을 수 없다.
메모리에 적재된 texture를 Unload후 다시 적재하면
변경된리소스로 불러올 수 있다.

관련 메소드

    Director::getInstance()->getTextureCache()->removeUnusedTextures();

    TextureCache::sharedTextureCache()->removeUnusedTextures();

    TextureCache::sharedTextureCache()->removeAllTextures();

    TextureCache::sharedTextureCache()->reloadTexture("파일명");

---
[spritesheet를 사용해야 하는 이유 동영상]:(https://www.codeandweb.com/what-is-a-sprite-sheet)
---
### Scene
Scene에 자식으로 포함된 Sprite는
디렉터로 Scene전환 시에 자동으로 해제된다.


### removeChild

removeChild 함수의 내부에서 지우는 자식의 autoRelease 함수가 호출 됩니다.
