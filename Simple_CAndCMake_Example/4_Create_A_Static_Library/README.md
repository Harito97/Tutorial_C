# How to use CMake create a static library

## Static Library

* được **tạo tại thời điểm compile**
* để có thể **tổng hợp toàn bộ code liên quan đến thư viện**
* về bản chất thì nó sẽ **copy lại code của các dependency vào một thư viện khác**

* Điều này dẫn đến việc **lib được sinh ra** thường sẽ có **kích cỡ lớn hơn một shared library**
* tuy nhiên thì do tất cả các dependency đều được xác định tại thời điểm compile nên **chi phí cho việc loading tại thời điểm runtime sẽ ít hơn** và **lib sẽ ít trở nên ít phụ thuộc hơn vào platform mà nó đang chạy**

* Trong phần lớn các trường hợp thì chúng ta **chỉ nên dùng shared library, trừ khi bắt buộc mới dùng static library**. Lý do là bởi nó sẽ **hạn chế được việc trùng lặp code** và trong trường hợp **shared library có thể được cập nhật thì sẽ không phải recompile**

## Simple That `STATIC` keyword in `CMakeLists.txt`

```bash
# CMakeList.txt

add_library(testStudent STATIC ${SOURCES})
# note the keyword STATIC
```

## Some command that helpful about STATIC lib

### Xác định được các thành phần cấu tạo nên static library

```bash
# in build path
ar -t libtestStudent.a
# Student.cpp.o
```

### Liệt kê tất cả các ký tự trong file object và binary

(liệt kê các ký tự trong thư viện student và kiểu của nó)
(T là code, U là không xác định, R là dữ liệu read-only)

```bash
# in build path
nm -C libtestStudent.a

Student.cpp.o:
0000000000000000 r .LC0
                 U memcpy
                 U __stack_chk_fail
0000000000000000 T Student::display()
0000000000000000 t Student::display() [clone .cold]
00000000000000a0 T Student::Student(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)
00000000000000a0 T Student::Student(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)
                 U std::ctype<char>::_M_widen_init() const
0000000000000000 W std::ctype<char>::do_widen(char) const
                 U std::ostream::put(char)
                 U std::ostream::flush()
                 U std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_create(unsigned long&, unsigned long)
                 U std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long)
                 U std::__throw_bad_cast()
                 U std::ios_base_library_init()
                 U std::cout
0000000000000000 V typeinfo for Student
0000000000000000 V typeinfo name for Student
0000000000000000 V vtable for Student
                 U vtable for __cxxabiv1::__class_type_info
```
