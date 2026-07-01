






I have not made this readme cause im too lazy but you can read below,
i have recently added control flow you can make labels with lowercase letters without the need for any colons or similar shit like that
theres only JMP (label name) or JZ (label name) JZ is jump-if-zero aka it will jump if the top of the stack is zero since there is no heap
i also added OUTPUT and EMIT, EMIT outputs the ascii value of the top of the stack and OUTPUT prints it as a normal number like 32 etc
try compiling and running the helloworld.as file once you clone the repo!

# StackAsm esolang Interpreter

A lightweight, stack-based assembly-like interpreter written in C++. It processes tokenized instructions from a source file to manipulate a central data stack.

---

## 🚀 Features

* **Strict Stack Operations:** Core stack manipulation including `PUSH`, `POP`, `DUP`, and `SWAP`.
* **Arithmetic Support:** Basic math operators (`ADD`, `SUB`) that evaluate the top stack elements.
* **Flexible I/O:** Output data as raw integers or convert them directly to ASCII text characters on the fly.

---

## 🛠️ Instruction Set (Opcodes)

| Opcode | Arguments | Description |
| :--- | :--- | :--- |
| `PUSH` | `<integer>` | Pushes the following integer onto the top of the stack. |
| `POP` | *None* | Removes the top element from the stack. |
| `DUP` | *None* | Duplicates the top element of the stack. |
| `SWAP` | *None* | Swaps the positions of the top two elements on the stack. |
| `ADD` | *None* | Pops the top two elements, adds them together, and pushes the result. |
| `SUB` | *None* | Pops the top two elements, subtracts the top from the second-to-top, and pushes the result. |
| `EMIT` | *None* | Prints the top element of the stack interpreted as an **ASCII character**. |
| `OUTPUT` | *None* | Prints the top element of the stack as a **raw number**. |

---

## 💻 Getting Started

### Prerequisites
You will need a C++ compiler supporting at least **C++11** (like `g++` or `clang`).

### Compilation
Compile the source code using your terminal compiler:

```bash
g++ -std=c++11 main.cpp -o stackasm
