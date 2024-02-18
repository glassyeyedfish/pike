# The Pike Programming Language
In which I once again try to make a programming language.

## Usage
`pike [command] [args...]`

The commands are as follows:
- `e [src] [dst]` Encode hexadecimal text stored in the file `[src]`
to binary and write it to a file `[dst]`.
- `r [bin]` Run the binary file at `[bin]` containing valid byte code.

## Byte Code Instructions
| Name | Number | Description |
| --- | --- | --- |
| `NOP`         | 0x00 | Does nothing. |
| `PUSHI`       | 0x01 | Push int to working stack. |
| `POPI`        | 0x02 | Pop int from working stack. |
| `PUTI`        | 0x03 | Print int on working stack. |
| `ADDI`        | 0x04 | Adds two ints from stack. |
| `SUBI`        | 0x05 | Subtracts two ints from stack. |
| `MULI`        | 0x06 | Multiplies two ints from stack. |
| `END`         | 0xFF | Signal the interpreter to stop execution. |