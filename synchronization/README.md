# Synchronization Concepts in Operating Systems

Synchronization is the coordination of multiple processes/threads to ensure correct execution when accessing shared resources. It prevents **race conditions**, ensures **mutual exclusion**, and avoids issues like **deadlocks** and **starvation**.

---

##  Core Synchronization Concepts

1. [Critical Section Problem](#1-critical-section-problem)  
2. [Race Conditions](#2-race-conditions)  
3. [Mutual Exclusion](#3-mutual-exclusion)  
4. [Synchronization Tools](#4-synchronization-tools)  
   - [Mutex (Mutual Exclusion Lock)](#-mutex-mutual-exclusion-lock)  
   - [Semaphores](#-semaphores)  
   - [Condition Variables](#-condition-variables)  
   - [Monitors](#-monitors)  
5. [Deadlock](#5-deadlock)  
   - [Deadlock Handling](#deadlock-handling)  
6. [Starvation & Fairness](#6-starvation--fairness)

### 1. Critical Section Problem
- **Critical section**: A part of the code where shared resources are accessed.
- **Problem**: Multiple processes executing it simultaneously can cause **race conditions**.
- **Goal**: Allow only one process at a time in the critical section.

---

### 2. Race Conditions
- Occur when output depends on the **unpredictable order of execution** of processes.
- Example: Two processes incrementing the same counter simultaneously.

---

### 3. Mutual Exclusion
- Ensures only **one process** executes in the critical section at a time.
- Achieved with:
  - **Locks / Mutexes**
  - **Semaphores**
  - **Monitors**

---

### 4. Synchronization Tools

####  Mutex (Mutual Exclusion Lock)
- A binary lock: **locked/unlocked**.
- Used to protect critical sections.

####  Semaphores
- **Binary Semaphore** → Works like a mutex.
- **Counting Semaphore** → Manages access to multiple instances of a resource.

####  Condition Variables
- Used with mutexes to block/wake threads based on conditions.

####  Monitors
- High-level construct that encapsulates **mutex + condition variables**.
- Examples: Java `synchronized`, Python `threading.Lock`.

---

### 5. Deadlock
- A situation where processes wait forever due to **circular waiting**.
- Four necessary conditions (Coffman):
  1. **Mutual Exclusion**
  2. **Hold and Wait**
  3. **No Preemption**
  4. **Circular Wait**

#### Deadlock Handling
- **Prevention**: Break one of the 4 conditions.
- **Avoidance**: Banker’s Algorithm.
- **Detection & Recovery**: Detect cycle, kill/restart processes.

---

### 6. Starvation & Fairness
- **Starvation**: A process waits indefinitely.
- **Fairness**: Ensure all processes eventually proceed.
- Achieved using **fair locks** and scheduling.


