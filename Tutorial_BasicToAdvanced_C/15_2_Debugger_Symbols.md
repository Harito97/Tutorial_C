# Debugger Symbols

**additional information embedded** within the compiled program’s binary code, that help debuggers in understanding the structure, source code, and variable representations at a particular point in the execution process

## Types

- **Internal Debugging Symbols**: the size of the binary increases, which **may not be desirable for production environments**. Eg use the `-g` flag to create a internal debugger binary file:

```bash
g++ -g -o my_program my_program.cpp
```

- **External Debugging Symbols**: kept **in separate files apart from the binary code**, usually with file extensions. Eg use the `-gsplit-dwarf` flag:

```bash
g++ -g -gsplit-dwarf -o my_program my_program.cpp
```

$\to$ compiles `my_program.cpp` into an executable named `my_program` and generates a separate file named `my_program.dwo` containing the debugging symbols.

When sharing to end-user, use:

```bash
strip --strip-debug my_program
```

This will removes internal debug symbols:

- resulting in a smaller binary size
- keeping the `.dwo file` for debugging purposes
