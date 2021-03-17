# cpp_interpreter

This project is divided into three main parts:
1. Lexer - this part takes the script file and:
    * Convert it to one long string.
    * From the long string creates an array of tokens that are the strings in the long string which are separated from each other by white spaces and ignore those white spaces.
    * retrun an array of the tokens.
2. Parser - this part takes the array of tokens returned from the Lexer and:
    * creates command of every token which represent one:
      * open server.
      * connection.
      * while loop.
      * placement (placement of value into variable with =).
      * define variable (name of new variable so his value will be saved in a symbol table).
      * print.
      * sleep (delay for x second).
      * exit (the program).
   * executs those commands, one after another.
3. Communication with a flight simulator (flight gear) by sending commands to it and receiving data from it:
   * Every command the parser creates is executed and influence the simulator.
   * Sends commands to the simulator with TCP connection and receiving data from it to update the symbol table in the program (using Multithreading).
