# 📚 C Programming Exercises

This part of this repository contains three practical exercises developed in the C programming language, covering fundamental concepts such as cryptography, modularization using header files, and basic mathematical operations.

## 📋 Table of Contents

1. [Caesar Cipher](#1-caesar-cipher)
2. [Basic Calculator](#2-basic-calculator)
3. [Caesar Cipher with Header](#3-caesar-cipher-with-header)

## 1. Caesar Cipher

### 📖 Description

This exercise implements a simple program that reads a string provided by the user and encrypts it using the **Caesar Cipher**, through the `encrypt_cesar()` function.

Input is read using `scanf`, and the encrypted result is printed to standard output (`stdout`).

### 🎯 Objectives

- Understand how the Caesar Cipher works.
- Practice reading strings using `scanf`.
- Use externally defined encryption functions.

### 🛠️ Structure

- **Input:** A string entered by the user.
- **Processing:** Application of the Caesar Cipher through `encrypt_cesar()`.
- **Output:** The encrypted string.

### 📦 Dependencies

- Inclusion of the `cryptography.h` header file, which declares the `encrypt_cesar()` function.

## 2. Basic Calculator

### 📖 Description

This exercise implements a **basic calculator** in C, supporting the four fundamental mathematical operations:

- ➕ Addition
- ➖ Subtraction
- ✖️ Multiplication
- ➗ Division

### 🎯 Objectives

- Practice **code modularization** in C.
- Create and use custom header files.
- Separate function declarations from the main implementation.

### 🛠️ Structure

- **Custom header:** `operations.h` — responsible for declaring the mathematical functions.
- **Main file:** Contains the user interaction logic and function calls.

### 📦 Dependencies

- Inclusion of the `operations.h` header file.

## 3. Caesar Cipher with Header

### 📖 Description

This exercise is a variation of the first one, reinforcing the importance of **code organization** through the use of header files.

The program reads a string using `scanf`, applies encryption through the `encrypt_cesar()` function, and prints the result to standard output.

### 🎯 Objectives

- Consolidate the use of header files (`cryptography.h`).
- Reinforce the separation between function declarations and implementations.
- Practice reusing encryption functions.

### 🛠️ Structure

- **Input:** A string provided by the user via `scanf`.
- **Processing:** A call to the `encrypt_cesar()` function declared in `cryptography.h`.
- **Output:** The encrypted string displayed in `stdout`.

### 📦 Dependencies

- Inclusion of the `cryptography.h` header file.

## 🚀 How to Compile

To compile any of the exercises, use `gcc`:

```bash
gcc main.c -o program
./program
```
