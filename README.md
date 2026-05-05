# Coding Challenges

Solutions to competitive programming problems across multiple platforms, written in C++ and Python.

## Platforms

| Folder             | Platform                                                           |
| ------------------ | ------------------------------------------------------------------ |
| `atcoder/`         | [AtCoder](https://atcoder.jp)                                      |
| `leetcode/`        | [LeetCode](https://leetcode.com)                                   |
| `paiza/`           | [Paiza](https://paiza.jp) (gitignored)                             |
| `tips-and-tricks/` | Input/algorithm patterns                                           |
| `aizu/`            | [AIZU Online Judge](https://onlinejudge.u-aizu.ac.jp) (gitignored) |

## Structure

Each platform folder is organized by language:

```bash
atcoder/
  cpp/
  python/
leetcode/
  cpp/
  python/
paiza/
  cpp/
  python/
tips-and-tricks/
  cpp/
  python/
```

## Running solutions

**C++:**

```bash
./run.sh atcoder/cpp/ABC455-C.cpp < input.txt
```

**Python:**

```bash
python3 paiza/python/A093.py < input.txt
```

`run.sh` requires GCC (`g++`). Install via Homebrew if needed: `brew install gcc`.
