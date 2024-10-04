# Debugger Messages

**notifications** or alerts provided by a debugger to help you **identify problems or errors** in your C++ code

## Types

- Error
- Warning
- Informational

## Eg use GDB to debug

```cpp
$ g++ -g -o test test.cpp  // Compile with -g flag to include debugging information
$ gdb ./test               // Run the GDB debugger
(gdb) run                  // Execute the program inside GDB
```