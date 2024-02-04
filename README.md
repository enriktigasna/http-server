# Basic HTTP Server in C

Current project features:
- Can return hard-coded message on any port for http server
- Returns correct, but hard-coded headers for http
- Prints out raw request packet
- Gets index.html
- Gets other files
- Has 404.html aswell

MAIN Project requirements:
Be able to return index.html on /

Secondary project requirements
Be able to 404
Be able to return any file in public directory on /filename.xxx
Be able to customize headers in different ways (like different response numbers)


Compilation instructions (linux):
```bash
gcc main.c socketsend.c socketsend.h createsocket.h createsocket.c readfile.c readfile.h socketread.h socketread.c parseheaders.c parseheaders.h
```

```
./a.out
```