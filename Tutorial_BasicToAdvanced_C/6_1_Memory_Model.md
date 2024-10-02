# Memory model

(Stack, Heap, Data Segment, Code Segment)

## Stack

Stack memory is used for **automatic storage duration variables**, such as **local variables and function call data**. Stack memory is managed by the compiler, and it’s **allocation and deallocation are done automatically**. The stack memory is also a LIFO (Last In First Out) data structure, meaning that the most recent data allocated is the first to be deallocated.

```cpp
void functionExample() {
    int x = 10; // x is stored in the stack memory
}
```

## Heap

Heap memory is used for **dynamic storage duration variables**, such as **objects** created using the `new` keyword. The programmer has control over the allocation and deallocation of heap memory using `new` and `delete` operators (note: must delete object manually). Heap memory is a larger pool of memory than the stack, but has a slower access time.

```cpp
void functionExample() {
    int* p = new int; // dynamically allocated int in heap memory
    *p = 10;
    // more code
    delete p; // deallocate memory
}
```

## Data Segment

The Data segment is composed of two parts: the **initialized data segment** and the **uninitialized data segment**. The initialized data segment stores **global, static, and constant variables** with initial values, whereas the uninitialized segment stores uninitialized global and static variables.

```cpp
// Initialized data segment
int globalVar = 10; // global variables
static int staticVar = 10; // static local variables
const int constVar = 10; // constant variables with value

// Uninitialized data segment
int globalVar; // uninitialized global variables
```

**Tổng kết**:

* Các **biến toàn cục, tĩnh và hằng** đều được **lưu trữ** trong **phân đoạn dữ liệu**.
* Biến toàn cục có phạm vi toàn bộ chương trình.
* Biến tĩnh cục bộ có phạm vi trong khối lệnh nơi nó được khai báo, nhưng giá trị của nó được giữ nguyên giữa các lần gọi hàm.
* Biến hằng không thể thay đổi giá trị sau khi được khởi tạo.
* Biến toàn cục chưa được khởi tạo có giá trị ban đầu không xác định.

**Lưu ý**:

* Việc **khởi tạo các biến toàn cục và tĩnh bằng các giá trị cụ thể** có thể giúp tránh các lỗi không mong muốn trong chương trình.
* Sử dụng **biến hằng** là một cách tốt để **đảm bảo rằng giá trị của một biến không bị thay đổi vô tình**.
* Nếu bạn cần một biến có giá trị thay đổi được nhưng chỉ trong phạm vi một hàm, bạn có thể sử dụng biến cục bộ thông thường.

## Code Segment

The **Code segment** (also known as the **Text segment**) **stores the executable code** (machine code) of the program. It’s usually **located in a read-only area of memory** to prevent accidental modification.

```cpp
void functionExample() {
    // The machine code for this function is stored in the code segment.
}
```
