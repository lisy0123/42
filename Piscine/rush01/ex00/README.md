# Rush01

> **[*rush01.en.pdf*](https://github.com/lisy0123/42/blob/master/Piscine/PDF/rush01.en.pdf)**

| **Language** | C                                       |
| :----------: | --------------------------------------- |
|  **Topics**  | `Sudoku`, `Recursive`, `Backtracking`   |
|   **Goal**   | Create a program that resolves a Sudoku |
|  **Result**  | **96/100**                              |

### Example

```bash
❯ gcc -Wall -Wextra -Werror *.c -o rush-1

❯ ./rush-1 "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47...." | cat -e
Error$

❯ ./rush-1 "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......99" | cat -e
Error$

❯ ./rush-1 "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......." | cat -e
9 1 4 3 7 5 2 6 8$
2 8 7 4 9 6 1 5 3$
3 6 5 8 1 2 4 7 9$
8 4 6 5 2 1 3 9 7$
5 2 9 6 3 7 8 1 4$
7 3 1 9 8 4 5 2 6$
1 5 3 7 4 9 6 8 2$
6 9 8 2 5 3 7 4 1$
4 7 2 1 6 8 9 3 5$
```



[↩️ Go Back](https://github.com/lisy0123/42/tree/master/Piscine)

