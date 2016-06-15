Enumerations
============

- Is a simple C++ enum...
- Use the pipable annotation to make this a pipable enum, this will ignore
any assignments to the values.
- Enums are automatically typed based on the size of elements, this will
always minimize memory.

```
enum
{
    VALUE1,     # 1
    VALUE2 = 5, # 5
    VALUE3,     # 6
    VALUE4,     # 7
}

@pipable enum
{
    VALUE1,
    VALUE2,
    VALUE3,
    VALUE4,
}
```
