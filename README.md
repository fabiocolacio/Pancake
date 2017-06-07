# The Pancake Interpreter

🥞🥞 The is the interpreter for the Pancake programming language 🥞🥞

Pancake is a multi-stack-based esoteric programming language inspired by postscript and brainfuck.
Like other stack-based languages, operations work with data stored at the top of the stack (TOS).
Like brainfuck, the stack can only store single characters.
Pancake adds a twist to the stack-based paradigm by adding the ability to control multiple stacks at once.
This is similar to the "tape" in brainfuck, except that each cell can contain an entire stack,
rather than a single character. Also, the "tape" (which I refer to as a "belt" in Pancake), is
dynamically sized. At the start of every program, you have a belt which contains a single empty stack.
Through the usage of Pancake commands, you are able to create extra stacks in the belt, and switch between
them. At all times, there can only be one active stack.

## Terminology

### Belt

The dynamically sized list of all the stacks in your program.
This can be thought of as a Circularly Linked List. There is always
one "active" stack, with stacks to its left and right. moving to far
past the left stack will wrap around to the right-most stack, and vise-versa.
The belt is initialized with a single empty stack.

### Active Stack

Functions push and pop data off of the currently active stack by default.

### TOS

The top of the currently active stack.

### TOLS

The top of the stack directly to the left of the active stack.

### TORS

The top of the stack directly to the right of the active stack.

## Currently Working Commands

Pancake commands must be separated by one or more whitespace character
(spaces, tabs, or newlines).

Command          | Action
----------------:|---
``$NUM``         | Any number that is typed will be pushed to TOS
``'$CHAR'``      | The ASCII code of a character surrounded with ``'`` will be pushed to TOS
``"$STRING"``    | Push each character of the string to TOS starting from the end (spaces wont work yet)
``+``            | Pop the top two values from TOS, and push their sum to TOS
``-``            | Pop the top two values from TOS, and push their difference to TOS
``*``            | Pop the top two values from TOS, and push their product to TOS
``/``            | Pop the top two values from TOS, and push their quotient to TOS (truncates remainder)
``%``            | Pop the top two values from TOS, and push their modulus to TOS
``peek``         | Output the value at TOS (as an ASCII charcter)
``peek_int``     | Output the decimal ASCII value at TOS
``pop``          | Pop the value from TOS and output its value as an ASCII character
``pop_int``      | Pop the value from TOS and output its ASCII decimal value
``multipop``     | ``pop`` x amount of times, where x is the value at TOS
``multipop_int`` | ``pop_int`` x amount of times, where x is the value at TOS
``pop_all``      | ``pop`` everything off of the stack.
``pap_all_int``  | ``pop_int`` everything off of the stack.
``size``         | Push the length of the active stack to TOS. **WARNING:** The stack can be bigger than the size of a cell, so this becomes unpredictable for very large stacks.
``drop``         | Remove the value from TOS (no output)
``drop_all``     | Remove everything from the active stack.
``#``            | Comment. Interpreter ignores everything to the right of this on this line.
``{$FUNC_NAME``  | Begin a function definition
``}``            | End your function definition
``[``            | Begin a loop. (loop continues as long as TOS is non-zero)
``]``            | End a loop.
``bye``          | Exits the program

### Hello World

It won't always suck this much, I swear :)

```
'\n' "Hello world!"
pop_all
```

### Math

Math works using the commands listed above, and expressions
can be writen in reverse polish notation.

```
#! /usr/bin/pancake

5 6 + pop       # prints 11
3 2 * 1 + pop   # prints 7
```

### User-Defined Functions

```
#! /usr/bin/pancake

{add + }      # this function just calls the existing '+' function
5 5 add       # call our add function here
pop_int       # prints '10'

'\n' pop      # print a newline

{print_hello
	'\n' "Hello World!"
	pop_all
}

print_hello   # calls our print_hello function

```

### Loops

The following example prints "Hello World!" to the console 10 times.

```
#! /usr/bin/pancake

{print_hello
	'\n' "Hello World!"
	13 multipop
}

10 [
	print_hello
	1 -
]
```

### In The Pipeline

- Belt commands

## Build

You will need CMake, and C++ 11 or newer to successfully build Pancake.

```
$ git clone https://github.com/fabiocolacio/Pancake
$ cd Pancake
$ mkdir build
$ cd build
$ cmake -DCMAKE_INSTALL_PREFIX=/usr ..
$ make
```

## Install

After building:

```
$ sudo make install
```
