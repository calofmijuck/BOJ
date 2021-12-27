## ⚠️ Disclaimer

**The sources are very old!** (4+ years) The old sources may not have consistent style.

---

# BOJ

Repository of submissions to [Baekjoon Online Judge (BOJ)](https://www.acmicpc.net/) problems.

## 📚 Reference

Submitted sources are grouped into directories in `Codes/`, according to the problem number.

- The directory name will be `(problem number) / 100 * 100`.

> Source code for problem #3584 can be found in `Codes/3500`.

### Creating files with `make.sh`

Use `./make.sh problem_number [file_extension]` to create a source file in the correct directory.

- `[file_extension]` is optional. Defaults values is `cpp`.

> `./make.sh 3584 cpp` will create `Codes/3500/3584.cpp`.

## 🖥️ Compile & Run

The default compile options are:
- `-Wall`: Show all warnings.
- `-std=c++17`: Use C++17.

### Compile and run `submit.cpp`

`submit.cpp` is the file I usually use for writing code. I solve problem on this file first, then move the source after the source is accepted.

To run the file, type `./cmp.sh` on the terminal. It will automatically run the following:

```bash
g++ submit.cpp -Wall -std=c++17 -o submit && ./submit
```

> Note. This does not support additional compile options for `g++`.

### Compile and run specific source

To execute the source for some particular problem, type the following:

```bash
./cmp.sh [PROBLEM_NUMBER] [OPTIONS]
```
- `PROBLEM_NUMBER`: Problem number.
- `OPTIONS`: (Optional) Additional compile options for `g++`.

> Example. To run the code for #1000 with `-Werror` option, type `./cmp.sh 1000 -Werror`.

> Note. When compiling a specific source using problem number, `-I .` has been added so that `g++` will look for files in the current directory. Without this option, custom headers don't work and compilation fails.

## 🛠️ Utils

Contains some utils for convenience / reference.

### Algorithms

Contains useful algorithms.

### Data Structures

Contains useful data structures.
