Classes
=======

- A file is a class.
- Access levels:
    + `+` for public.
    + `-` for private.
    + `#` for protected.
- Classes can inherit just one class.

## Attributes
- Attributes are private by default.
- Getters and setters are called automatically, as an example: if you declare the attribute `myFloat`, and then say:
    ```
    set myFloat(float value)
    {
        myFloat = value + 2;
    }
    ```
    That method will be called automatically. And the getter would be:
    ```
    get myFloat()
    {
        return myFloat;
    }
    ```
    Note that the return type is not needed.

- Attributes that are marked with a `!` at the end of the type are readonly.

## Methods
- Methods are public by default.
- You can pass a primitive type by reference by receiving `<type>&` as parameter.
- The constructor is just another method, is public by default and is called
when the client calls new `<class-name>()`.

## Example
```
class MyClass;

static int myStaticAttribute;
int myPrivateDefaultInt;
+ int myPublicInt;
- int myPrivateInt;

MyClass()
{
    // public constructor.
}

- void somePrivateMethod()
{
    // do stuff.
}

+ void somePublicMethod()
{
    // do stuff.
}

void somePublicDefaultMethod()
{
    // do stuff.
}

set myPublicInt(int value)
{
    myPublicInt = value;
}

set myPublicInt(string value)
{
    myPublicInt = int.parseInt(value);
}

get myPublicInt
{
    return myPublicInt;
}

static void someStaticMethod()
{
    // do stuff.
}

void someAbstractMethod(int someValue);
```
