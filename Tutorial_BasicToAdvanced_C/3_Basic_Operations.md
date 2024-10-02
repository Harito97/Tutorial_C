# Basic Operations

## Arithmetic Operations

(+, -, ##, /, %, //, ++ and --: prefix - return first, calculate after; postfix - calculate first, return after)

## Relational Operators

(!=, ==, >, <, >=, <=)

## Logical Operators

(&&: and, ||: or, !: not)

## Loop

```cpp
#include <iostream>

int main() {
    for (int i = 0; i < 5; i++) {
        std::cout << "Iteration: " << i << std::endl;
        // cout: character output
        // cin: character input
    }
    return 0;
}
```

or

```cpp
#include <iostream>

int main() {
    int i = 0;
    while (i < 5) {
        std::cout << "Iteration: " << i << std::endl;
        i++;
    }
    return 0;
}
```

or

```cpp
#include <iostream>

int main() {
    int i = 0;
    do {
        std::cout << "Iteration: " << i << std::endl;
        i++;
    } while (i < 5);
    return 0;
}
```

## Bitwise Operations

(directly manipulate the bits of a number).

Purpose:

* optimizing algorithms,
* performing certain calculations,
* manipulating memory in lower-level programming languages like C and C++

Detail:

* and

```cpp
int result = 5 & 3; // result will be 1 (0000 0101 & 0000 0011 = 0000 0001)
```

* or

```cpp
int result = 5 | 3; // result will be 7 (0000 0101 | 0000 0011 = 0000 0111)
```

* xor: 0 and 0 = 0, 1 and 1 = 0, 0 and 1 = 1, 1 and 0 = 1

```cpp
int result = 5 ^ 3; // result will be 6 (0000 0101 ^ 0000 0011 = 0000 0110)
```

* not

```cpp
int result = ~5; // result will be -6 (1111 1010)
```

* left shift & right shift

```cpp
// left shift: move bits to left
int result = 5 << 1; // result will be 10 (0000 0101 << 1 = 0000 1010)

// right shift: move bits to right
int result = 5 >> 1; // result will be 2 (0000 0101 >> 1 = 0000 0010)
```

## Assignment Operators

(=, +=, -=, *=, /=, %=)
