# Functions

## What is function

A function is a **group of statements** that **perform a specific task**, organized as a **separate unit** in a program. Functions help in breaking the code into **smaller, manageable, reusable blocks**.

## Types of function

There are mainly two types of functions in C++:

* **Standard library functions**: Pre-defined functions available in the C++ standard library, such as sort(), strlen(), sqrt(), and many more. These functions are part of the standard library, so you **need to include the appropriate header file to use them**.

* **User-defined functions**: Functions created by the programmer to perform a specific task. To create a user-defined function, you need to define the function and call it in your code.

## Function prototype

In some cases, you might **want to use a function before actually defining it**. To do this, you need to declare a **function prototype** at the beginning of your code.

```cpp
// Function prototype
int multiplyNumbers(int x, int y);

// Use multiplyNumbers func

// Define multiplyNumber func
```

## Lambda functions

A lambda function, or simply “lambda”, is an **anonymous (unnamed) function** that is defined in place, within your source code, and with a concise syntax. Lambda functions were introduced in C++11 and have since become a widely used feature, especially in combination with the Standard Library algorithms.

* Syntax:
  * capture-list: A **list of variables** from the surrounding scope that the lambda function can access.
  * parameters: The **list of input parameters**, just like in a regular function. Optional.
  * return_type: The type of the value that the lambda function will return. This part is optional, and the compiler can deduce it in many cases.
  * function body: The code that defines the operation of the lambda function.

```cpp
[capture-list](parameters) -> return_type {
    // function body
};

// no capture, parameters, or return type
auto printHello = []() {
    std::cout << "Hello, World!" << std::endl;
};
printHello(); // Output: Hello, World!

// with parameters
auto add = [](int a, int b) {
    return a + b;
};
int result = add(3, 4); // result = 7

// with capture-by-value
int multiplier = 3;
auto times = [multiplier](int a) {
    return a * multiplier;
};
int result = times(5); // result = 15

// with capture-by-reference
int expiresInDays = 45;
auto updateDays = [&expiresInDays](int newDays) {
    expiresInDays = newDays;
};
updateDays(30); // expiresInDays = 30
```
