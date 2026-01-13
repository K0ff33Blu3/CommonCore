# C++ Module 00 — README

This repository contains **C++ Module 00** exercises, focused on the very first building blocks of C++ and Object-Oriented Programming (OOP): **namespaces, classes, member functions, stdio streams (iostream), initialization lists, static**, and other fundamentals.

> Target standard: **C++98** (compile with `-std=c++98`) and strict warnings.

---

## Contents

- `ex00/` — Megaphone
- `ex01/` — My Awesome PhoneBook
- `ex02/` — The Job Of Your Dreams

(See the module PDF for full subject details and requirements.)

---

## General rules (from the subject)

### Compilation
Compile using:
- `c++ -Wall -Wextra -Werror -std=c++98`

### Forbidden / constraints
- **No** `printf`, `malloc`, `free` (and related) — write C++-style code.
- `using namespace <...>` is **forbidden** unless explicitly allowed. 
- Until later modules: **no STL containers** (`vector`, `list`, `map`, …) and **no `<algorithm>`**. 
- Put implementations in `.cpp` files (non-template functions in headers are not allowed). 
- Use include guards and make headers independently includable. 

---

## Core concepts explained (and why they matter here)

### 1) Namespaces
Namespaces prevent name collisions by grouping identifiers.
- Standard library symbols live in `std::` (e.g. `std::cout`, `std::string`).
- In this module, you should **avoid** `using namespace std;` and instead qualify names explicitly:
  - ✅ `std::cout << "Hello\n";`
  - ❌ `using namespace std; cout << ...;` (forbidden by subject rules) 

**Where you’ll use it:**
- Everywhere you use iostream/string/iomanip: `std::cout`, `std::cin`, `std::setw`, etc.

---

### 2) Classes
A class bundles **data (members)** and **behavior (methods)**, and enforces encapsulation with `private`/`public`.

Typical layout:
- **Private**: data that must not be modified freely from outside
- **Public**: methods to interact with the object safely

**Where you’ll use it:**
- `ex01` requires two classes: `PhoneBook` and `Contact`.
- `ex02` revolves around recreating an `Account` class implementation matching an existing header/log.

---

### 3) Member functions (methods)
Member functions operate on an object’s state.
- Use them to implement actions like `addContact()`, `search()`, `printSummaryRow()`, etc.
- Decide carefully what should be:
  - **public** API (called from `main`)
  - **private** helpers (only used inside the class)

**Important idea:** keep invariants inside the class. Example: a `Contact` should never be “half-empty” if the subject says fields can’t be empty.

---

### 4) stdio streams (iostream)
C++ uses stream-based I/O instead of `printf/scanf`:
- Output: `std::cout`, `std::cerr`
- Input: `std::cin`, `std::getline`

Formatting tools:
- `<iomanip>` utilities like `std::setw` help build aligned columns (used in `ex01`).

**Why it matters:**
- `ex01` requires printing a table with 10-char columns, right-aligned, truncation with `.`.

---

### 5) Initialization lists
Constructors can initialize members in two ways:
- assignment inside the constructor body
- **member initialization list** (preferred/required for `const` members, references, and for efficiency)

### 5) Static
Ex02 is specifically designed to teach how `static` works in C++ **in a real, meaningful context**: modeling a bank system with both *individual* and *global* state.

 ## static variables

The `Account` class manages **two different kinds of information**:

1. **Per-account data** (belongs to one object)
2. **Global data** (shared by all accounts)

This distinction is implemented using `static`.
`static` variables do not live inside an object. There is exactly one copy for the whole program, shared by every `Account`

 ## static methods

The `Account` class also has static methods that return **global data** (shared by all accounts), and you call them by

Example:
 Account::displayAccountsInfos();

*Important rule:*
A static member function has no `this` pointer, so it cannot access non-static members like _amount or _accountIndex directly.
It can access static variables like _totalAmount.
---