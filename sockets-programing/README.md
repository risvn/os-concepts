# ShowIP

A simple C program that resolves a hostname to its IP address using `getaddrinfo()`.

## Features
- Works with IPv4 (AF_INET).
- Uses `inet_ntop()` to convert binary IP to human-readable string.
- Demonstrates basic socket programming concepts.

## Build
Compile with `gcc`:

```bash
gcc showip.c -o showip

./showip example.com
'''
## output
'''bash
IP addresses for example.com:
  93.184.216.34
'''
