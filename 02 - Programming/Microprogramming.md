# Introduction to Microprogramming

If you've ever seen processor assembly code that looks something like the following:
```asm
_start:
    MOV ECX, 10

loop:
    DEC ECX
    LEA EAX, [EDX + 10]
    CMP ECX, 0
    JNE loop
```

Or maybe you're more familiar with ARM processors:

```asm
_start:
    MOV R1, #10

loop:   
    SUBI R1, R1, #1
    ADDI R3, R2, #10
    CBZ R1, loop
```

What you're seeing here are processor instructions. Each line corresponds to a simple set of instructions, such as `SUB`, `ADD`, `MOV`. In principle, processor assembly is nothing more than very low-level programming. It's probably as low as makes sense to interface with, frankly. 

When you want to execute this instruction:
```asm
MOV R1, #10
```
You're effectively _instructing_ the CPU to load the value `10` into the register `R1`. Hence the name, instruction. Different architechtures will have different implementations of this principle and execute instructions differently, most notable are the architechtures `x86` and `ARM`. Because they operate differently and implement different concepts differently, their Assembly language is different. So, x86 Assembly is a distinct programming language, and so is ARM Assembly.

There are no built-in complex data structures or functions, nothing is on a high layer of abstraction.  

However, we can go even lower level.

#### Types of instructions

//TODO

## Microinstructions

An instruction can (and has to) be broken down into different steps and final micro-instructions, often written as μinstructions.

These can have steps, such as:

- `IF` or `Instruction Fetch`
- `ID` or `Instruction Decode`
- `EX` or `Execute`
- `MEM` or `Memory Access`
- `WB` or `Write Back`

Let's break down a simple `ADD R3, R2, R1` instruction into the different stages.

- `IF`: Fetch `ADD R3, R2, R1` from the memory address specified in `PC`.
- `ID`: Decode the instruction `ADD` and identify the destination `R3` as well as operands `R2` and `R1`.
- `EX`: Calculate `R2 + R1`
- `MEM`: Not needed for `R-Type` instructions. `NOP` or `No Operation`.
- `WB`: Store result of `EX` step in destination register `R3`.

Key notes: 
- "Decoding" in `ID` means only here do we know what type of operation we're even performing. 
- `PC` or `Program Counter` is the memory address we're currently at in the program. Typically incremented with every instruction (indicating that we've advanced a whole instruction); Manipulating this value not only indicates where we are in the program, but also helps with branches, loops, etc etc.

### Micro-operations

![_There's always a lower fish._](lowerfish.jpg)

μinstructions can be broken down into `μops`, which are the fundamental steps taken by each part of a CPU. Several μops make up a μinstruction, several of which make up an instruction, several of which make up a program.
An example of a `μop` would be adding our instruction length to the program counter, which happens inside the `EX` μinstruction and is carried out by the ALU[^1].

You can think of a μop as whatever a single part of a processor (like an ALU) is doing inside a μinstruction process. 

## Pipelining

//TODO


[^1]: considering a simple processor that needs to wait for the ALU to calculate the PC and has no dedicated PC adder.