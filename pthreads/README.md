# Understanding Threads in Programming

## 1. What is a Thread?
A **thread** is the smallest unit of execution within a process.  
Every program you run starts with **at least one thread** — called the *main thread*.  
You can create additional threads to perform tasks concurrently.

Think of:
- **Process** → A factory (with its own memory and resources)
- **Thread** → A worker inside the factory (sharing the same resources)

---

## 2. Threads vs Processes
| Feature         | Process                           | Thread                               |
|-----------------|-----------------------------------|---------------------------------------|
| Memory          | Has its own separate memory space | Shares memory with other threads     |
| Creation Cost   | High (needs new memory allocation)| Low (shares process memory)          |
| Communication   | Inter-process communication (IPC)| Directly via shared variables/memory |
| Failure Impact  | One process crash doesn't affect others | Thread crash can bring down the process |

---

## 3. Why Use Threads?
- **Parallelism** → Run multiple tasks at the same time (useful on multi-core CPUs).
- **Responsiveness** → Keep a program responsive while doing background work.
- **Resource Sharing** → Threads in the same process can easily share data.

---

#include <pthread.h>

int pthread_create(
    pthread_t *thread,            // Thread identifier (output)
    const pthread_attr_t *attr,   // Thread attributes (NULL for defaults)
    void *(*start_routine)(void *), // Function for the thread to execute
    void *arg                     // Argument to pass to that function
);

