# Rush02

> **[*rush02.en.pdf*](https://github.com/lisy0123/42/blob/master/Piscine/PDF/rush02.en.pdf)**

| **Language** | C                             |
| :----------: | ----------------------------- |
|  **Topics**  | `Makefile`, `Shape detection` |
|  **Result**  | **100/100**                   |

### Example

```bash
❯ make fclean
rm -f *.o
rm -f colle-2

❯ make
gcc -Wall -Werror -Wextra *.c -o colle-2

❯ echo "adsfdsf" | ./colle-2
aucune

❯ ./colle-00 4 4
o--o
|  |
|  |
o--o

❯ ./colle-00 4 4 | ./colle-2
[colle-00] [4] [4]

❯ ./colle-00 3 4 | ./colle-2
[colle-00] [3] [4]

❯ ./colle-02 1 1
A

❯ ./colle-03 1 1
A

❯ ./colle-04 1 1
A

❯ ./colle-02 1 1 | ./colle-2
[colle-02] [1] [1] || [colle-03] [1] [1] || [colle-04] [1] [1]
```



[↩️ Go Back](https://github.com/lisy0123/42/tree/master/Piscine)

