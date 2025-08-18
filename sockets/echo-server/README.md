# TCP Socket Programming (Client & Server)

This document explains the steps involved in building a simple **TCP client** and **TCP server** in C using the Berkeley sockets API.  

---

## 📌 Server Side Steps

The server waits for incoming connections and communicates with clients.  

### Steps:
1. **Create `addrinfo` hints**
   - Zero out the `struct addrinfo hints` using `memset()`.
   - Set:
     - `hints.ai_family = AF_INET` (IPv4)
     - `hints.ai_socktype = SOCK_STREAM` (TCP)
     - `hints.ai_flags = AI_PASSIVE` (for server, use local machine’s IP).

2. **Call `getaddrinfo()`**
   - Use `NULL` as hostname to bind to local machine.
   - Example:  
     ```c
     getaddrinfo(NULL, "3490", &hints, &res);
     ```

3. **Create a socket**
   - Use the parameters from `res`:  
     ```c
     sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
     ```

4. **Bind the socket**
   - Assign the socket to an IP/Port:  
     ```c
     bind(sockfd, res->ai_addr, res->ai_addrlen);
     ```

5. **Listen for connections**
   - Put the socket into passive mode:  
     ```c
     listen(sockfd, BACKLOG);
     ```

6. **Accept a connection**
   - Accept an incoming client request:  
     ```c
     new_fd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len);
     ```

7. **Receive data**
   - Read data from client:  
     ```c
     recv(new_fd, buffer, sizeof(buffer), 0);
     ```

8. **Close sockets**
   - After communication, close `new_fd` and `sockfd`.

---

## 📌 Client Side Steps

The client connects to the server and sends messages.

### Steps:
1. **Create `addrinfo` hints**
   - Similar to server, but **no `AI_PASSIVE` flag**.
   - Example:  
     ```c
     hints.ai_family = AF_INET;
     hints.ai_socktype = SOCK_STREAM;
     ```

2. **Call `getaddrinfo()`**
   - Pass server’s IP and port number:  
     ```c
     getaddrinfo("127.0.0.1", "3490", &hints, &res);
     ```

3. **Create a socket**
   - Same as server:  
     ```c
     sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
     ```

4. **Connect to server**
   - Use `connect()` to establish connection:  
     ```c
     connect(sockfd, res->ai_addr, res->ai_addrlen);
     ```

5. **Send data**
   - Send message to server:  
     ```c
     send(sockfd, msg, strlen(msg), 0);
     ```

6. **Close socket**
   - Release resources:  
     ```c
     close(sockfd);
     ```

---

## 📌 Example Communication Flow

- **Server**:
  - Runs first, listens on port `3490`.
  - Prints: `Server is listening on 127.0.0.1:3490`.

- **Client**:
  - Connects to `127.0.0.1:3490`.
  - Sends: `"hello from the client\n"`.

- **Server**:
  - Receives and prints:  
    ```
    Client says: hello from the client
    ```

---

## 📌 Libraries Used
- `<stdio.h>` – standard I/O
- `<stdlib.h>` – memory, exit()
- `<string.h>` – memset(), strlen()
- `<sys/types.h>` – system data types
- `<sys/socket.h>` – socket APIs
- `<netdb.h>` – `getaddrinfo()`
- `<unistd.h>` – close()
- `<arpa/inet.h>` – `inet_ntop()`, `inet_pton()`
- `<netinet/in.h>` – sockaddr_in structures

---

