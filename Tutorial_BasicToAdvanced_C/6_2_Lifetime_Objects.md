# Lifetime of Objects

## What

Lifetime of object from the moment it is created until it is destroyed.

## Categories

4 categories:

* Static Storage Duration: exist for the entire run of the program. Eg like **Global variables, static data members, and static local variables**

```cpp
// static global var
int global_var;            // Static storage duration
class MyClass {
  // static data member 
  static int static_var;   // Static storage duration
};
void myFunction() {
  // static local var
  static int local_var;    // Static storage duration
}
```

* Thread Storage Duration: exist for the lifetime of the thread they belong to. Eg like **use keyword `thread_local`**

* Automatic Storage Duration: created at the point of definition and destroyed when the scope in which they are declared is exited. Eg like **Function parameters and local non-static variables**

* Dynamic Storage Duration: created at runtime, using memory allocation functions such as **use keyword `new` or `malloc`**. Eg like `new object`. Note that lifetime of object have to be managed manually by `delete` or `free` command

