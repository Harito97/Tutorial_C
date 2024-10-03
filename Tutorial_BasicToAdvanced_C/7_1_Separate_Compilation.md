# Separate Compilation

* each source file can be compiled independently into an object file
* object files can then be linked together to form the final executable

$\to$ **faster build** times when **making changes to a single source file** since **only that file needs to be recompiled**, and the **other object files can be reused**

Eg:

```cpp
# Compile each source file into an object file 
# .o with o means `object`
g++ -c main.cpp -o main.o
g++ -c example.cpp -o example.o

# Link object files together to create the executable
g++ main.o example.o -o my_program
```
