# krul-interpreter

School project. Interpreter for a very simple, made-up programming language called "krul". Written in C++. 

[Assignment instructions (dutch).pdf](https://github.com/jessevdp/krul-interpreter/files/6446168/eindopdracht.pdf)

Example "krul" program that repeats the string `"hello world\n"` 3 times:

```sh
3 # add 3 to the stack
=cnt # move this number to cnt
\Hello, world # add "hello world" to the stack
enl # add a newline to that string
=hello # move the string to hello
\ # add an empty string to the stack
=result # move the string to result
:loop # define location 'loop'
$result # put result on the stack
$hello # put hello on the stack
cat # concatinate these two strings
=result # move that string to result
$cnt # put cnt to the stack
dec # decrement the value by 1
=cnt # move this value back to cnt
0 # put 0 on the stack
>loop # put reference to location 'loop' on the stack
ggt # if cnt > 0, go to 'loop'
$result # put result on the stack, this is the output value of the program
```
