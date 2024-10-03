# Debuggers

help in detecting, diagnosing, and fixing bugs in the code

## Main types

Both `gdb` and `lldb` can be use in Linux.

With `Microsoft Visual Studio Debugger` - well we don't care about it. It's Microsoft :((

Other like: Intel, ...

* **GDB (GNU Debugger)**: This is the most widely used C++ debugger in the **Linux environment**. It **can debug many languages**. Eg:

```bash
g++ -g main.cpp -o main    # compile the code with debug info (-g)
gdb ./main                 # start gdb session (gdb)
b main                     # set a breakpoint at the start of the main function
run                        # run the program
next                       # step to the next line
```

* **LLDB**: This is the **debugger developed by LLVM** (note: **LLVM được sử dụng** để **xây dựng** nên nhiều bộ chuyển đổi (**compiler**) của nhiều ngôn ngữ lập trình cấp cao phổ biến hiện nay, ví dụ như C, C++, Python, Java, Ruby ...). It **supports multiple languages** and is popular among **macOS and iOS** developers. Eg:

```bash
clang++ -g main.cpp -o main # compile the code with debug info (-g)
lldb ./main                 # start lldb session (lldb)
breakpoint set --name main  # set a breakpoint at the start of the main function
run                         # run the program
next                        # step to the next line
```

* **Microsoft Visual Studio Debugger**: This debugger is built into **Visual Studio** and is typically used in a **graphical interface** on **Windows** systems.

* **Intel Debugger (IDB)**: This debugger is part of **Intel’s parallel** development suite and is **popular for high-performance applications**. And it can only use in **Intel chip** (maybe).

* **TotalView Debugger**: Developed by **Rogue Wave Software**, TotalView Debugger is **a commercial debugger** designed for **parallel**, **high-performance**, and **enterprise applications**.
