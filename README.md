# BenFuck
![Ho! Ho! Hooo!](./READMEimages/BenFuck.png)

BenFuck is a programming language that consists of nothing but Talking Ben catchphrases, such as "Ben", "Yes" and "Hohoho!".
## How does it work?
BenFuck functions identical to the programming language BrainFuck. This repository contains a program that takes .ben (BenFuck) files, creates a .bf (BrainFuck) file from it, and uses a C interpretter [(courtesy of Krzysztof Gabis)](http://github.com/kgabis/brainfuck-c) to run the created BrainFuck file. In addition to being able to convert .ben files into .bf files, included is a seperate program that can convert .bf files into .ben files.
## What does it look like?
Each character from BrainFuck has a BenFuck equivelant word:
```benfuck
ben    = > = increases memory pointer
hohoho = < = decreases memory pointer
yes    = + = increases value stored at memory pointer
no     = - = decreases value stored at memory pointer
*ring  = [ = begin while memory pointer != 0 loop.
*burp  = ] = end while memory pointer != 0 loop.
grrr   = , = input 1 character.
ugh    = . = print 1 character to the console
```
Here is an example of a program that prints "Hello World" to the console:
```benfuck
yes yes yes yes yes yes yes yes *ring ben yes yes yes yes *ring ben
yes yes ben yes yes yes ben yes yes yes ben yes hohoho hohoho hohoho 
hohoho no *burp ben yes ben yes ben no ben ben yes *ring hohoho *burp 
hohoho no *burp ben ben ugh ben no no no ugh yes yes yes yes yes 
yes yes ugh ugh yes yes yes ugh ben ben ugh hohoho no ugh hohoho 
ugh yes yes yes ugh no no no no no no ugh no no no no no no no no 
ugh ben ben yes ugh ben yes yes ugh
```
This, along with a few more examples I've created from the BrainFuck wiki sit in the "ExampleBens" folder at the root.
## How do I start?
These programs are all written in C, so you'll need a few things to be able to run them
### What you'll need
**Programs**
- gcc
- make

**Libraries**
- <stdlib.h>
- <stdio.h>
- <string.h>

*On a Linux machine, you should be able to run <code>sudo sh -c 'apt update ; apt install -y build-essential'</code> to get the dependancies you need to run C programs*
### How to run
In the Ben2Brain&Program directory, open a terminal and run
```console
make
```
This will use gcc to compile the imterpretter program. Next, add a .ben file to the directory. To run the .ben file, run
```console
./interpretter nameOfBenFile.ben
```
This will create your .bf file and of course, run the ben program in the terminal.
### How to convert BrainFuck to BenFuck
In the Brian2Ben directory, open a terminal and run
```console
make
```
The converter program will be compiled. Next, create a .bf file in the directory and run
```console
./converter nameOfBrainFile.bf
```
This will convert the .bf file to one named "benfuck.ben"!
## Misc notes
- The BrianFuck interpretter used is simple, so certain BrainFuck actions (like using memory pointers to the left of the main one) unfortunately won't work.
