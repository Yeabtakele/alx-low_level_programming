## 0x0B. C - malloc, free
# Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

## General
What is the difference between automatic and dynamic allocation
What is malloc and free and how to use them
Why and when use malloc
How to use valgrind to check for memory leak
## Resources
* Read or watch:

0x0a - malloc & free - quick overview.pdf
Dynamic memory allocation in C - malloc calloc realloc free 
man or help:

malloc
free



# Automatic and dynamic allocation, malloc and free
The malloc function is used to allocate a certain amount of memory during the execution of a program. It will request a block of memory from the heap. If the request is granted, the operating system will reserve the requested amount of memory and malloc will return a pointer to the reserved space.

When the amount of memory is not needed anymore, you must return it to the operating system by calling the function free.
## Automatic allocation
* When you declare variables or when you use strings within double quotes, 
* the program is taking care of all the memory allocation. 
* In the above example, the arguments and the local variables are stored automatically in memory when the function is called.
* By default, the memory used to store those variables can be read and written. When the program leaves the function, the memory used for all the above variables is released for future use.
 
## Dynamic allocation
Malloc
* The malloc function allocates a specific number of bytes in memory and returns a pointer to the allocated memory. 
* This memory will have read and write permissions.
# Why would I need dynamic allocation?

* So far we only have seen functions and programs that had fixed inputs. What happens when we do not know in advance
 how much memory you need and we will only know this at runtime, after compilation?
* For instance, imagine we have to create a program that will store all the words contained in a file in an array. 
* That file is passed as an argument to our program. There is no way we could know in advance how many words the file will contain. 
* We can not declare a big array like char *words[1024]; and assume that there will never be more than 1024 words in the file. 
* That’s when malloc and friends come to the rescue, and will permit us to allocate dynamically the amount of memory we need.
# The memory is not initialized

Just like with automatic allocation, the memory allocated by malloc is not initialized.
# Free
When you are using malloc, you have to handle the memory yourself. This means that:

You need to keep track of all the addresses of the allocated memory (in a variable of type pointer)
You have to deallocate every memory space you previously allocated yourself. If you do not do this, 
then your program can run out of memory. Your operating system could even kill your program while it is running
# Valgrind
When writing big and complex programs, it is not always easy to keep track of all allocated and deallocated memory. 
We can use the program Valgrind in order to ensure we are freeing all allocated memory. 
It is a programming tool for memory debugging, memory leak detection, and profiling.
