# Get Next Line Project

## Description
The **Get Next Line (GNL)** project aims to implement a function that reads a file descriptor (typically standard input or a file) line by line, returning one line at a time. The goal is to create a function that reads a line of text, stores it, and allows the program to continue reading subsequent lines without having to reload the entire file into memory. This is a fundamental project for working with input/output (I/O) operations and memory management in C.

The challenge in this project is to manage reading and storing text incrementally, while dealing with memory allocation, buffer management, and handling edge cases like reaching the end of the file or dealing with errors.

---

## Project Requirements
- **Reading Line by Line:**  
  The program should read input one line at a time, returning a pointer to each line. Each line should be terminated by a newline character (`\n`).

- **Buffer Management:**  
  Since reading line by line requires buffering the data, the program needs to handle a dynamic buffer that grows as necessary. The buffer should read data incrementally from the file or input until it finds a newline character.

- **Memory Management:**  
  The program must allocate memory for each line dynamically and ensure that memory is freed appropriately to avoid leaks.

- **Handling Multiple File Descriptors:**  
  The function should handle multiple file descriptors by storing the state of each one, so it can return the next line when called repeatedly for each descriptor.

- **Return Value:**  
  The function should return a line of text each time it's called, and return `NULL` when the end of the file (EOF) is reached or if an error occurs.

---

## Key Restrictions & Challenges

- **Incremental Reading:**  
  Reading a file line by line means that data must be buffered in chunks. The function should handle reading from the file until a newline or EOF is encountered, which can be tricky when dealing with various input sizes.

- **Memory Allocation:**  
  The program needs to allocate memory for each line dynamically as it’s read, which requires managing memory properly to avoid leaks. You need to ensure that you append the newly read characters to the previous data without overwriting it.

- **Handling Buffer Overflow and State:**  
  Since the function needs to handle multiple file descriptors, it must maintain the state of each file descriptor independently. For example, if you call the function multiple times on the same file descriptor, the function should return the subsequent lines correctly.

- **Edge Cases:**  
  - Handle files that are empty, have one line, or are very large.  
  - Handle lines that are longer than the buffer size.  
  - Deal with the special case of EOF and error conditions without crashing.

- **Efficiency:**  
  Efficient memory handling and reading from the file descriptor in small increments are essential to avoid unnecessary memory usage and performance issues.

---

## Using it
Try i out with this command the compiles, links, and executes program
```bash
gcc -Wall -Wextra -Werror -c get_next_line.c -o get_next_line.o && \
gcc -Wall -Wextra -Werror -c get_next_line_utils.c -o get_next_line_utils.o && \
ar rcs libget_next_line.a get_next_line.o get_next_line_utils.o && \
gcc -Wall -Wextra -Werror main.c -L. -lget_next_line -o get_next_line_program && \
./get_next_line_program

