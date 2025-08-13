# Understanding `fork()` in C

## 📌 What is `fork()`?
`fork()` is a system call in UNIX/Linux that **creates a new process** by duplicating the calling process.  
The newly created process is called the **child process**, and the original process is called the **parent process**.

---

## 🛠 How it works
- When `fork()` is called:
  - **Parent process** continues executing after `fork()`.
  - **Child process** starts executing as a copy of the parent, from the point right after the `fork()` call.
- Both processes run **independently**.

---

## 🔄 Return values of `fork()`
`fork()` returns **different values** in the parent and child:

| Return Value | Process       | Meaning                                           |
|--------------|--------------|---------------------------------------------------|
| `0`          | Child        | You are in the **child process**                  |
| `> 0`        | Parent       | You are in the **parent process**, value = child PID |
| `-1`         | Error        | Fork failed (no new process created)               |

---
## Example
```C
pid_t rc = fork();

if (rc == 0) {
    printf("Child process\n");
} else if (rc > 0) {
    printf("Parent process\n");
}
```
---
Parent process:

fork() returns the child's PID (> 0).

So in the parent, rc > 0 → executes else if branch.

Child process:

fork() returns 0 to the child.

So in the child, rc == 0 → executes if branch.

