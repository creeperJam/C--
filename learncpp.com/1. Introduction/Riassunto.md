# Capitolo 1

## Statements

Statements are instructions that cause the program to perform some action. This is the most common type of instruction and most of the time it ends with a semicolon.

>**There are different kinds of statements:**
>
> 1. Declaration statements
> 2. Jump statements
> 3. Expression statements
> 4. Compound statements
> 5. Selection statements (conditionals)
> 6. Iteration statements (loops)
> 7. Try blocks

## Functions and the main function

Whenever there is a collection of statements that get executed sequentially (top to bottom) we have a function. In general if you execute certain statements multiple times (like calculating the power of a number) you can create a function and call the function each time.
> **NOTE**
> In c++ and other languages as well (like Java) we have a main function, a function that has to be present in the file that gets executed. This function gets called when the file gets executed and when we reach the end of this the program ends.

The simplest program that gets made for the first time by anyone is "Hello, world!". In C++ it looks like this and we'll understand each line of code:

``` c++
    #include <iostream>

    int main()
    {
       std::cout << "Hello, world!";
       return 0;
    }
```

The only purspose of the "Hello, world!" program is to print to the console the text "Hello, world!" but there's still some interesting things that need explanation:

1. `#include <iostream>` --- This line is called a preprocessor directive and it indicate that we want to use the contents of the `iostream` library. Note that not including this line results in a compile error because the compiler doesn't recognize `std::cout`.
2. The blank line gets ignored by the compiler.
3. `int main()` --- this tells the compiler that we want to define a function called main.
4. The brackets at the start and the end of the function are delimiters, they are there just to tell the compiler where the function starts and when it ends. Anything in between the brackets is part of the function.
5. `std::cout << "Hello, world!";` --- This is the first statement in the function and it allows to print whatever is after the `<<` to the console. (cout stands for 'character output').
6. `return 0;` --- This indicates when an executable program finishes and based on the value that it returns the result of the program changes, in this case '0' stands for 'Everything worked correctly'. This is used in functions that need to return its result, for example if we call a function that multiplies two numbers at the end of it we use `return a*b`.

## Syntax and errors



---
