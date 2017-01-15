### 클래스 멤버 함수 콜백(STL function)

```
#include <functional>

typedef std::function<int(int)> pFunc
//typedef int(*pFunc)(int); 와 같음

private:
    pFunc mMyfunc = nullptr;


void SetMyFunc(pFunc p_Func)
{
    mMyfunc = std::move(p_Func);
}

//call
if(mMyfunc != nullptr)
{
    mMyfunc();
}
```
---
```
//인자가 1개
SetMyFunc(std::bind(&ThisClass::Function,this,std::placeholders::_1));
//인자가 3개
SetMyFunc(std::bind(&ThisClass::Function,this,
    std::placeholders::_1,
    std::placeholders::_2,
    std::placeholders::_3
    ));
//없다면 적지않는다
```
