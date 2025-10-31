### TCP Socket Programming (Client & Server)


#### simple echo server that just forwords the recvd msg back to the server


Run the server
```
> ./server
Server is listening on 0.0.0.0:3490
```

send the msg from client
``` 
./client localhost "hello world!"

```

out put of the program
```
client: attempting connection to 127.0.0.1
client: connected to 127.0.0.1
bytes sent: 12
bytes recvd: 12
msg:hello world!

```
