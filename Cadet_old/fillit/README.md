# Fillit

> **[*fillit.en.pdf*](https://github.com/lisy0123/42/blob/master/Cadet_old/PDF/fillit.en.pdf)**

### Example

```bash
❯ make re
a - ft_atoi.o
...
...
a - ft_toupper.o

❯ make clean

❯ cat sample1 | cat -e
....$
##..$
.#..$
.#..$
$
....$
####$
....$
....$
$
#...$
###.$
....$
....$
$
....$
##..$
.##.$
....$

❯ ./fillit sample1 | cat -e
DDAA$
CDDA$
CCCA$
BBBB$

❯ cat sample2 | cat -e
....$
....$
####$
....$
$
....$
...$
..##$
..##$

❯ ./fillit sample2 | cat -e
error$

❯ cat sample3 | cat -e
...#$
...#$
...#$
...#$
$
....$
....$
....$
####$
$
.###$
...#$
....$
....$
$
....$
..##$
.##.$
....$
$
....$
.##.$
.##.$
....$
$
....$
....$
##..$
.##.$
$
##..$
.#..$
.#..$
....$
$
....$
###.$
.#..$
....$

❯ ./fillit sample3 | cat -e
ABBBB.$
ACCCEE$
AFFCEE$
A.FFGG$
HHHDDG$
.HDD.G$
```

---

| **Language** | C                                               |
| :----------: | ----------------------------------------------- |
|  **Topics**  | `Tetriminos`, `Backtracking`, `Time complexity` |
|  **Result**  | **100/100**                                     |

[↩️ Go Back](https://github.com/lisy0123/42/tree/master/Cadet_old)