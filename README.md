reads a line from a filedesciptor and return that line. Any excess ascii values (after the newline character) is being stores in a static buffer.
The amount of bytes to read at a time (using the read call) can be modified.