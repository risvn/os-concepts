# 📦 Block I/O in C

## Overview
**Block I/O** refers to reading or writing **multiple bytes or elements in one operation** instead of processing them one at a time.  
In C, this is done using the `fread()` and `fwrite()` functions from the **Standard I/O Library (`stdio.h`)**.

---

## Function Signatures

```c
size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
