
## WHY CoreFetch

CoreFetch is a minimal system information fetch tool written in C++.
Instead of contributing to an existing tool like Fastfetch, this project was built from scratch for the following reasons:

---

### 1. Practical Learning and Simplicity

CoreFetch started as a self-contained C++ project to explore how system information can be fetched and displayed without relying on high-level scripting languages or large external libraries.

It prioritizes:

* Simplicity over feature bloat
* Code clarity over performance optimization
* Direct control over every function and output

---

### 2. Clear Differences from Fastfetch

| Aspect        | Fastfetch                          | CoreFetch                         |
| ------------- | ---------------------------------- | --------------------------------- |
| Language      | C                                  | C++                               |
| Focus         | Speed + modularity + extensibility | Simplicity + self-containment     |
| Output        | Templated, full-featured           | Static ASCII + plain formatting   |
| Config        | Structured config system           | Hardcoded or basic `.config/` use |
| System Access | Native syscalls + libraries        | Shell commands + partial C++      |
| Target Users  | General users                      | Terminal users, devs, hobbyists   |

---

### 3. No External Dependencies

CoreFetch avoids dependency chains. It uses:

* Only standard Linux tools (`ps`, `lspci`, etc.)
* A single C++ source file (monolithic)
* No external libraries or scripting layers

This makes it easy to read, audit, and modify for small use-cases or custom fetch needs.

---

### 4. Not Trying to Compete

This project isn't a replacement for Fastfetch or Neofetch.
It intentionally limits scope and avoids complexity.
It does a few things, and does them simply.

---

### Summary

CoreFetch is:

* Linux-only
* C++-based
* Minimal by design

It's for those who prefer smaller, simpler tools, and want full ownership of the output and internals.

---
The only thing that i realized after making it, people just find flaws when a new developer makes something but not to appreciate it i had to make this file becuase of this.
