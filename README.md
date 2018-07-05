# wethinkcode_

## get_next_line

<img src="resources/get_next_line-finalmark.png" width="350" />

GNL Project

This projects is about creating a function that, allows to read a line ending with a newline character ('\n') 
from a file descriptor, without knowing its size beforehand. This was a great opportunity to understand how memory
leaks occur and how to use utilities such as valgrind (with debugging flags) to identify and stop leaks.

Concepts tested:
- Memory allocation
- Static variables
- Life cycle of a buffer

## Usage

How to install valgrind on Linux
    `sudo apt-get install valgrind`


