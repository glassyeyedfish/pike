# The Pike Programming Language
In which I once again try to make a programming language.

## List of Commands

| Command | Arguments | Description |
| --- | --- | --- |
| e | [SOURCE] [DESTINATION] | Encode hexadecimal numbers in text format to a binary. |
| d | [SOURCE] [DESTINATION] | Decode a binary into hexadecimal numbers in text format. |
| r | [BINARY] | Run a binary. |

## Hardware

- 256 Pages of 8-Bit RAM
- Stack (256 Bytes)
- Program Counter
- Flag

## Bytecode Table

| 0xCR | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | A | B | C | D | E | F |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0 | KILL | ADD  | ADDI
| 1 | PUT  | SUB  | SUBI
| 2 | GET  | MUL  | MULI
| 3 | SAVE | DIV  | DIVI
| 4 | LOAD
| 5 | JUMP
| 6 | JEQ
| 7 | JNE
| 8 | JLT
| 9 | JGE
| A |
| B |
| C |
| D |
| E |
| F |