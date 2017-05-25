# The Pancake Interpreter

This is the interpreter for the Pancake programming language.

Pancake is a multi-stack-based programming language inspired by postscript and brainfuck.
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

