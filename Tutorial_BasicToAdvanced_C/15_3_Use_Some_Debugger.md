# Use some debugger

## GDB

(GNU Debugger)

See more in here: `https://roadmap.sh/cpp` in `Debuggers` for `GDB`.

**Some example**:

```bash
g++ -g myfile.cpp -o myfile
gdb myfile
```

**Basic commands**:

- run: Start your program.
- break [function/line number]: Set a breakpoint at the specified function or line.
- continue: Continue the program execution after stopping on a breakpoint.
- next: Execute the next line of code, stepping over function calls.
- step: Execute the next line of code, entering function calls.
- print [expression]: Evaluate an expression in the current context and display its value.
- backtrace: Show the current call stack.
- frame [frame-number]: Switch to a different stack frame.
- quit: Exit GDB.
