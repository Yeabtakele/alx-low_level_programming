## 0x0E. C - Structures, typedef
* Resources
* Read
[Documentation](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/misc/2021/1/6eb80c79c99f6125450a0dc11b300d46238d1a5a.pdf?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20231009%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20231009T181016Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=f2c19bb16327ba92ee8fe392359588a19f03d275f6b7b6572fa507016f9dcd2e /README.md)
# Learning Objectives
* At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

## General
* What are structures, when, why and how to use them
* How to use typedef
* Copyright - Plagiarism
* You are tasked to come up with solutions for the tasks below yourself to meet with the above learning objectives.
* You will not be able to meet the objectives of this or any following project by copying and pasting someone else’s work.
* You are not allowed to publish any content of this project.
* Any form of plagiarism is strictly forbidden and will result in removal from the program.

# 1. A dog is the one  thing on earth that loves you more than you love yourself
mandatory
Write a function that initialize a variable of type struct dog

Prototype: void init_dog(struct dog *d, char *name, float age, char *owner);
Write a function that prints a struct dog

Prototype: void print_dog(struct dog *d);
Format: see example bellow
You are allowed to use the standard library
If an element of d is NULL, print (nil) instead of this element. (if name is NULL, print Name: (nil))
If d is NULL print nothing.

