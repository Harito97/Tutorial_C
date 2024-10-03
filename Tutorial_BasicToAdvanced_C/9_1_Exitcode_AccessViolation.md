# Exit codes & Memory violation when access

## Exit code

**0** is the standard exit code for a **successful execution**, while **non-zero exit codes** typically indicate errors or **other exceptional situations**

Commands:

* `return code_value` eg: 0, 1, 2
* `std:exit(code_value)` eg: 0, -1, 1

## Access Violations

* a specific type of error that **occurs when a program attempts to access an illegal memory location**
* Dereferencing null or invalid pointer

```cpp
int *p = nullptr;
int x = *p;  // Access violation: trying to access null pointer's content
```

* Accessing an array out of bounds

```cpp
int arr[5] = {1, 2, 3, 4, 5};
int y = arr[5];  // Access violation: index out of bounds (valid indices are 0-4)
```

* Reading or writing to freed memory

```cpp
int* p2 = new int[10];
delete[] p2;
p2[3] = 42;  // Access violation: writing to memory that has been freed
```
