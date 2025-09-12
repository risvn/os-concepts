# 📘 Understanding Pointers in C

Pointers are one of the most important topics in C. They may seem confusing at first, but once you understand the basics, they become a powerful tool for programming.  

Think of a pointer as a **variable that stores the address of another variable**.

---

## 📑 Index

1. [What is a Pointer?](#1-what-is-a-pointer)  
2. [Declaring and Using Pointers](#2-declaring-and-using-pointers)  
3. [Working with Pointers](#3-working-with-pointers)  
4. [Types of Pointers](#4-types-of-pointers)  
5. [Pointer Arithmetic](#5-pointer-arithmetic)  
6. [Void Pointer](#6-void-pointer)  
7. [Pointers as Function Arguments](#7-pointers-as-function-arguments)  
8. [Summary](#8-summary)  

---

## 1. What is a Pointer?

Normally, when we declare a variable in C:

```c
int x = 10;
```

- `x` is a variable.  
- It has a **value** (`10`).  
- It is stored in a **memory location** (say, address `0x7ffc1234`).  

Now, if we want to keep track of the **address** of `x`, we use a **pointer**.

```c
int *p = &x;
```

Here:  
- `p` is a pointer to an `int`.  
- `&x` gives the address of `x`.  
- `p` now stores that address.

📌 Diagram:

```
x: 10       (at address 1000)
p: 1000     (at address 2000)
```

---

## 2. Declaring and Using Pointers

```c
#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x;

    printf("x = %d\n", x);             // value of x
    printf("&x = %p\n", (void *)&x);   // address of x
    printf("p = %p\n", (void *)p);     // pointer stores address of x
    printf("*p = %d\n", *p);           // value at address stored in p

    return 0;
}
```

Output (example):
```
x = 10
&x = 0x7ffd...
p = 0x7ffd...
*p = 10
```

👉 `*p` means “go to the address stored in `p` and fetch the value”.

---

## 3. Working with Pointers

We can modify a variable using its pointer:

```c
int a = 5;
int *p = &a;

*p = 20;   // changes a directly
printf("a = %d\n", a); // 20
```

📌 Diagram before:
```
a: 5        (at address 1000)
p: 1000
```

📌 Diagram after `*p = 20;`
```
a: 20       (at address 1000)
p: 1000
```

---

## 4. Types of Pointers

1. **Null Pointer**  
   ```c
   int *p = NULL;  // points to nothing
   ```

2. **Wild Pointer** (uninitialized → dangerous!)  
   ```c
   int *p;   // undefined value
   ```

3. **Dangling Pointer** (points to freed memory)  
   ```c
   int *p = malloc(sizeof(int));
   free(p);
   // p is now dangling
   ```

4. **Pointer to Pointer**  
   ```c
   int x = 5;
   int *p = &x;
   int **pp = &p;
   printf("%d\n", **pp); // 5
   ```

---

## 5. Pointer Arithmetic

Pointers can be moved forward/backward.  

```c
int arr[3] = {10, 20, 30};
int *p = arr;

printf("%d\n", *p);     // 10
printf("%d\n", *(p+1)); // 20
printf("%d\n", *(p+2)); // 30
```

📌 Diagram:
```
arr[0] (10) at 1000
arr[1] (20) at 1004
arr[2] (30) at 1008
```

Since `int` is 4 bytes,  
- `p` points to `1000`  
- `p+1` points to `1004`  
- `p+2` points to `1008`  

---

## 6. Void Pointer

A `void *` can hold the address of **any type**, but must be cast before use.  

```c
void *vp;
int x = 100;

vp = &x;
printf("%d\n", *(int *)vp);  // cast before dereferencing
```

---

## 7. Pointers as Function Arguments

Without pointers (pass by value):
```c
void addOne(int n) {
    n++;
}

int main() {
    int x = 5;
    addOne(x);
    printf("%d\n", x); // still 5
}
```

With pointers (pass by reference):
```c
void addOne(int *n) {
    (*n)++;
}

int main() {
    int x = 5;
    addOne(&x);
    printf("%d\n", x); // now 6
}
```

---

## 8. Summary

- A pointer stores the **address** of a variable.  
- `*` (dereference) → access the value at the address.  
- `%p` (with `(void *)`) → print addresses.  
- Pointer types: null, wild, dangling, pointer-to-pointer.  
- Pointer arithmetic depends on data type size.  
- Void pointers are generic pointers.  
- Functions can modify variables outside their scope using pointers.
