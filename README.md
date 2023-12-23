# The Pike Programming Language
In which I once again try to make a programming language.

## List of Commands

| Command | Arguments | Description |
| --- | --- | --- |
| e | [SOURCE] [DESTINATION] | Encode hexadecimal numbers in text format to a binary. |
| d | [SOURCE] [DESTINATION] | Decode a binary into hexadecimal numbers in text format. |
| r | [BINARY] | Run a binary. |

## List of Opcodes

| Mnemonic | Code | Description |
| --- | --- | --- |
| PUT | 0x00 | Pop a number from the working stack and print it to the `stdout`. |
| PUSH x | 0x01 | Push x to the working stack. |