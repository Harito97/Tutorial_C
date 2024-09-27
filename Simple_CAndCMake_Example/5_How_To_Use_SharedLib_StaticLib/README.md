# How to use a shared or static library

**Step 1**. Simple setup code like this:

* src code
* CMakeLists.txt

In `CMakeLists.txt` contains the path to shared or static library.

Note that when create a link in this file, we **can use relative path**.
However, the **regular expression for directory/file will not working**.

**Step 2**. CMake build

```bash
cd build && cmake .. && make
```

**Step 3**. Now we can use the program (that use the lib - in this case: Student)

```bash
# program will be build in build folder with name program
./program

# Eg: ./libtest
A student with name Joe
```
