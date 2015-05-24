# base

Convert a number to it another presentation with base from 2 to 36

## Build and Install

This program should work on Linux or Unix.

Install `build-essential`, `cmake`, and `libglib2.0-dev` to build this program.

On Debian/Ubuntu:

```
$ sudo apt-get install build-essential cmake libglib2.0-dev
```

Then, build the program with cmake and make:

```
$ cmake CMakeLists.txt
$ make
```

## Usage

`base number from_base to_base`.  `from_base` is optional, default to 10.
For digits larger than 10, please use lowercase letters.  This program only works 
when number is equal to or larger than zero. 

Convert decimal 36 to its binary

```
$ base 36 2
100100
```

Convert decimal 128 to its octal

```
$ base 128 8
200
```

Convert binary 100100 to its octal

```
$ base 100100 2 8
44
```

Convert hex ff to its octal 

```
$ base ff 16 8
377
```

## Author

Michael Chen

## License

MIT