# Algorithms and Data Structures in C

A hands-on, capstone-driven journey through C foundations, core data structures,
and classic algorithms — built from scratch, one project at a time.

This repository is **Part 1 of 3** of a larger systems-programming track:

| Repository | Scope | Capstones |
|---|---|---|
| **Algorithms and Data Structures in C** (this repo) | C foundations & I/O, core data structures, algorithms | 01–15 |
| `systems-programming` | Low-level C, POSIX system calls, processes, threads, sockets | 16–24 |
| `systems-projects` | Unix shell, storage engine, virtual memory, file systems, OS internals | 25–32 |

The goal here is **depth over breadth**: every capstone is a small, self-contained
project with its own `README.md`, build instructions, and notes on what was learned.
No frameworks, no external dependencies beyond a C compiler, `make`, and standard
POSIX tools.

---

## Why this repository exists

Most "learn C" material stops at syntax. This repo is organized around **capstones** —
small projects that force you to integrate multiple concepts at once:

- Compile and link a multi-file project by hand.
- Parse real (messy) text and binary files.
- Reason about the stack, the heap, and the data segment.
- Build generic containers with `void *` and function pointers.
- Analyze complexity and benchmark it honestly.

Each capstone is designed to be **completed in a few sittings**, then revisited
later for refactoring, tests, and write-ups. The repository is a living portfolio,
not a course to be "finished".

---

## Roadmap

The table below maps each capstone to its topic and the artifact you build.

### Part I — C Foundations & I/O

| # | Topic | Capstone |
|---|---|---|
| 01 | Compilation, Makefile, Headers, Modular Code | Multi-file project with Makefile |
| 02 | File I/O (text and binary) | Input and Output |
| 03 | Pointers and Memory Layout (stack, heap, data) | Memory map visualizer |
| 04 | Dynamic Memory and Debugging (Valgrind, GDB, sanitizers) | Leak-free vector library |
| 05 | Strings and Structs/Unions/Enums | Tokenizer / text processor |

### Part II — Core Data Structures

| # | Topic | Capstone |
|---|---|---|
| 06 | Dynamic Arrays and Linked Lists (single, double, circular) | Generic list with `void *` |
| 07 | Stacks, Queues, Deque | Expression evaluator |
| 08 | Hash Tables | In-memory key-value store |
| 09 | Trees (BST, AVL, Red-Black, Trie) | Autocomplete engine |
| 10 | Heaps and Priority Queues | Task scheduler by priority |
| 11 | Graphs | Route finder |

### Part III — Algorithms

| # | Topic | Capstone |
|---|---|---|
| 12 | Recursion, Sorting, Searching | Sorting benchmark |
| 13 | Divide and Conquer, Greedy, Backtracking | Sudoku / N-Queens solver |
| 14 | Dynamic Programming | Diff tool (LCS) |
| 15 | Complexity Analysis and Benchmarking | Performance report with graphs |

---

## Employability tiers

Not all capstones carry the same weight for a first internship or junior role.
Use this as a guide for where to invest extra effort.

| Tier | Capstones | What it signals |
|---|---|---|
| **Foundational** | 01–05 | You can build, debug, and reason about real C programs. |
| **Core** | 06–11 | You understand memory, containers, and trade-offs. Non-negotiable for C/system interviews. |
| **Differentiator** | 12–15 | You can measure, analyze, and communicate performance. |

**Recommended "showcase" capstones** (do these with tests, a write-up, and a
refactored second pass): **06, 11, 14**. The rest can be "functional and lean".

---

## Suggested execution order

The numeric order is a fine default. For a backend/infra focus, pull 08 (hash
tables) and 11 (graphs) earlier:

1. 01 → 02 → 03 → 04 → 05
2. 06 → 07 → 08 → 10 → 09 → 11
3. 12 → 13 → 14 → 15

Capstone 15 depends on the others and should be done last.

---
