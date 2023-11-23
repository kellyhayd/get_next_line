<h1 align="center"> 📑 get_next_line </h1>

<p align="center">
<img alt="Static Badge" src="https://img.shields.io/badge/42-S%C3%A3o_Paulo-orange"> <img alt="Static Badge" src="https://img.shields.io/badge/language-c-green">  <img alt="Static Badge" src="https://img.shields.io/badge/submitted_in-nov%2F23-orange">
</p>

>This project is about programming a function that returns a line read from a file descriptor.


<h2> ✏ About </h2>

```
  Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file
pointed to by the file descriptor, one line at a time.
```

<h2> ⚙ Requirements </h2>

- Your project must be written in C

- Your functions should not quit unexpectedly (segmentation fault, bus error, double
free, etc) apart from undefined behaviors

- All heap allocated memory space must be properly freed when necessary
  
- Your project must be able to compile with and without the -D
BUFFER_SIZE flag in addition to the usual flags.


<h2>  📝 Instructions </h2>

- Your function should return the line that was read.
  If there is nothing else to read or if an error occurred, it should return NULL.

- Make sure that your function works as expected both when reading a file and when
  reading from the standard input.

- Please note that the returned line should include the terminating \n character,
  except if the end of file was reached and does not end with a \n character.

- Your header file get_next_line.h must at least contain the prototype of the
  get_next_line() function.

- Add all the helper functions you need in the get_next_line_utils.c file.

<h2> 🪛 Approach </h2>

Function get_next_line reads `BUFFER_SIZE` characters at time, while not finding a `\n`, storing `buffer` in a linked list.
When `\n` is found, the characters are copied to a `char` that will be returned.
The remnant character from the reading that are after the `\n` are storage in the static list.

<h2> 🌟 Bonus Part </h2>

<h4> ⭐ Requirements </h4>

* Develop get_next_line() using only one static variable.
  
* Your get_next_line() can manage multiple file descriptors at the same time.
  * For example, if you can read from the file descriptors 3, 4 and 5, you should be
able to read from a different fd per call without losing the reading thread of each
file descriptor or returning a line from another fd.
  * It means that you should be able to call get_next_line() to read from fd 3, then
fd 4, then 5, then once again 3, once again 4, and so forth.

<h4> ⭐ Approach </h4>

As for storing the remainder of the last read of different files, the static variable is a linked list array, using it's position as fd identification.
