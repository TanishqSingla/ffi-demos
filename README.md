# demos
This repo contains demo for the FFI talk

## Prerequisites for the repo
- [Bun](https://bun.sh) - Javascript runtime
- C/C++ compiler - GCC is preferred

## How this repo is structured
```
.
├── data-passing.cpp
├── get_metadata.1.cpp
├── hello-world.cpp
├── package.json
├── tests
│   ├── data-passing.js
│   ├── hello-world.js
│   ├── index.test.js
│   ├── libdata-passing.so
│   ├── libget_metadata.so
│   ├── libhello-world.so
│   └── TEST.md

```

The repo contains source files as well as test to check the behavior of the program. 

`tests/`
This folder contains test files as well as compiled libraries, so you don't have to
**Note** - The libraries are compiled on a linux platform, if you're using any other OS make sure to replace the compiled files with your OS specific compiled libraries

### Compiling libraries
The compile target needs to have following properties
- PIC - positionally independent code
- shared - Make sure the source file is compiled to shared object file

E.g - This can be done in gcc using
```sh
gcc -shared -fpic -o libmylib.so mylib.cpp
```
## Run the test
To run the test, make sure you're in the `tests/` folder. 

After ensuring you're in the correct folder, simply run:
```sh
bun test
```

## Contact
Feel free to create and issue or contact me on my handles for any query
