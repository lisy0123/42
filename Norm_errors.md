# Norm errors

### :bulb: global scope bad aligned

Find a line in your function that declares a function of the form int main. Delete the space after `int` and inset two TABs after it.

---

### :bulb: 42 header not at top of the file

Insert 42 school header(`:Stdheader` or `fn + F1`).

---

### :bulb: must not begin by spaces/tabulations

Remove the spaces or tab from the beginning. 

---

### :bulb: bad indentation

Check the indentation before the commands in the function. Only TABs, 4 spaces long! 

---

### :bulb: space before FUNCTION_NAME

Replace the space before the function name with TAB.

---

### :bulb: bad spacing after FUNCTION_NAME

After the end of the function (after the last '}') the number of empty lines is not set correctly. 

---

### :bulb: FUNCTION_NAME has XX lines

Function contains too many lines. 25 lines maximum!

---

### :bulb: declarations must be followed by one empty line in XXXXXXXXX

Check how you declare variables. You can declare one variable at a time, and after the declaration of variables there should be an empty line. 

---

### :bulb: missing space around </+/-/=

ex) `a<b` :x:	`a < b` :o:

---

### :bulb: global scope bad aligned

Check in front of function names. The names of the functions must be one above the other, strictly, throughout the program. Use TAB to align!

---

### :bulb: declarations in XXXXXXXXX are bad aligned

Problem in declaring variables in a function. Using the TABs, align them so that they are located one above the other column. If there are data types with a long name, put several TABs before short ones.

---

### :warning: / Users / XXXXXXXX may not compile or is invalid for some reasons.

Check the basic syntax of C. Add `int main () {...}` to the end of the program.

---

### :bulb: missing void in function main

If your function does not accept any arguments, this must be specified explicitly. 

```c
int main (void)
{
  ...
}
```

---

### :bulb: multiple empty lines

Delete the extra empty lines.

---

### :bulb: wrong number of spaces in preprocessor indentation

There must be a space before define

```c
# define
```



[↩️ Go Back](https://github.com/lisy0123/42)