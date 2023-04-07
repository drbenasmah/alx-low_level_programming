0x1A. C - Hash Tables
This project is about hash tables implementation in C programming language.

What is a Hash Table?
A hash table is a data structure that implements an associative array abstract data type, a structure that can map keys to values. A hash table uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.

Files
hash_tables.h: Header file containing all function prototypes and structures.
0-hash_table_create.c: C function that creates a hash table.
1-djb2.c: C function that implements the djb2 algorithm.
2-key_index.c: C function that returns the index of a key.
3-hash_table_set.c: C function that adds an element to a hash table.
4-hash_table_get.c: C function that retrieves a value associated with a key.
5-hash_table_print.c: C function that prints the content of a hash table.
6-hash_table_delete.c: C function that deletes a hash table.
Compilation and Testing
All files will be compiled with gcc -Wall -Werror -Wextra -pedantic flags.

To compile, run:

Copy code
gcc -Wall -Werror -Wextra -pedantic \*.c -o executable
To test, run:

bash
Copy code
./executable
Credits
This project was completed by Ben Asmah as part of the curriculum of the Holberton School.
