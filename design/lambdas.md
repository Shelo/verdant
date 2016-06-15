# Lambda

- Lambdas are on-the-fly functions.
- Lambdas can be assigned to variables or passed as arguments.
- The `func` type is able to hold lambda functions, it requires a type and the types of args.

## Syntax
```
func<type>(arg_type_1, arg_type_2, ...) myField;
```

## Example
```
func<int>(int) mySquareLambda = x: x * x;

someFunction(mySquareLambda);
someFunction(x: x * x)
```
