# Reflection을 이용한 CustomAttribute 수집

## Partial Class in Class

```c#
public abstract class Base { }
public class CustomAttribute : System.Attribute { } 

public partial class Samples
{
    [Custom]
    public class BaseA : Base { }

    [Custom]
    public class BaseB : Base { }
}

public void OnCollection()
{
    MemberInfo[] sampleMembers = typeof(Samples).GetMembers();
    for (int i = 0; i < sampleMembers.Length; i++)
    {
        object[] attrs = sampleMembers[i].GetCustomAttributes(typeof(CustomAttribute), true);
        if (attrs == null || attrs.Length == 0) continue;
        foreach (var attr in attrs)
        {
            CustomAttribute custom = attr as CustomAttribute;
            if (custom != null)
            {
                //todo...
                //sampleMembers[i].FullName;
                break;
            }
        }
    }
}
```
* Create Class
```csharp
using System;

public Base CreateClass(string fullName)
{
    return (Base)Activator.CreateInstance(fullName);
}
```
## Namespace In Class
```csharp
public abstract class Base { }
public class CustomAttribute : System.Attribute { } 

namespace Samples
{
    [Custom]
    public class BaseA : Base { }

    [Custom]
    public class BaseB : Base { }
}

public void OnCollection()
{
    string nameSpace = "Samples";
    var nameSpaceInClass = Assembly.GetExecutingAssembly().GetTypes()
    .Where(t =>
    {
        return t.IsClass && t.Namespace == nameSpace;
    });
    foreach (var item in nameSpaceInClass)
    {
        object[] attrs = item.GetCustomAttributes(typeof(CustomAttribute), true);
        if (attrs == null || attrs.Length == 0) continue;
        foreach (var attr in attrs)
        {
            CustomAttribute custom = attr as CustomAttribute;
            if (custom != null)
            {
                //todo...
                string className = item.FullName;
                break;
            }
        }
    }
}
```
* Create Class
```csharp
using System;

public Base CreateClass(string fullName)
{
    return (Base)Activator.CreateInstance(fullName);
}
```


