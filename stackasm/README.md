






I have not made this readme cause im too lazy but you can read below, and do basic stuff
but there is no control flow, 




# StackAsm Interpreter

A lightweight, stack-based assembly interpreter written in C++. It processes tokenized instructions from a source file to manipulate a central data stack.

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
