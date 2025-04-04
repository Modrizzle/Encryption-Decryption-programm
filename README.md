 Encryption & Decryption Program in C
 
  Introduction

This is an encryption and decryption algorithm developed in C, designed for a computer security software company. Its primary function is to securely encrypt confidential information using an external numerical key and decrypt it again using the same key.

The program operates on text files, using ASCII conversions to secure data, ensuring confidentiality and security for client communications.



  Problem Specification
  
The primary goal is to develop a robust and secure encryption/decryption system that:

Reads a plaintext message or encrypted data from an input text file.

Utilizes a numerical key stored in a separate key file.

Encrypts or decrypts the message based on client choice.

Outputs the result to a separate text file (encrypted or decrypted).



   How the Program Works
   
Encryption Process
Converts plaintext from the input file to ASCII values.

Adds numerical key values to these ASCII values.

If the message length exceeds the key length, the key repeats until matched.

The encrypted message (in ASCII) is converted back to characters and written into the output file.

Decryption Process
Converts encrypted data from the input file to ASCII values.

Subtracts numerical key values from these ASCII values.

If the message length exceeds the key length, the key repeats until matched.

The decrypted message (ASCII) is converted back to characters and written into the output file.



   Program Input
When executed, the program prompts the user clearly:

Operation Choice:

Enter M to Encrypt

Enter K to Decrypt

Input is case-insensitive (m or k accepted).

File Inputs:

Input file: Name of the plaintext or encrypted message file.

Key file: Name of the numerical key file.

Output file: Desired name for the result file (encrypted/decrypted).



  Program Output
  
The program outputs clearly structured results and informative messages:

Successful Operation:

Creates the encrypted or decrypted file in the program's directory.

Prints a confirmation message:

lua
Copy
Edit
Encryption successful! Check the output file in your folder.
or

lua
Copy
Edit
Decryption successful! Check the output file in your folder.
Input Validation & Error Handling:

Invalid encryption/decryption choice:

pgsql
Copy
Edit
Invalid choice entered! Please enter 'M' to Encrypt or 'K' to Decrypt.
File not found or inaccessible:

pgsql
Copy
Edit
Error: File does not exist. Please enter a valid file name.


  Additional Requirements Met
  
ASCII-Based Encryption:

Information is encrypted and decrypted based on ASCII character codes, ensuring compatibility and simplicity.

Key Handling:

If the message length > key length, the key repeats until it matches the message length.

If the message length < key length, the key truncates at the length of the message.

File Management:

Input files and key files must exist in the same directory as the program.

The algorithm ensures file existence before proceeding.



  Project Structure
  
The program follows a clear structure for maintainability and readability:

main() Function

Handles user interaction, file I/O, and main logic flow.

Encrypt_or_Decrypt() Function

Processes encryption or decryption based on user selection.

Manages file reading, ASCII conversions, encryption/decryption operations, and writing outputs.



  Implementation Details
  
Functions Used:

fopen() and fclose() for file handling.

fgetc() and fscanf() to read characters/numbers from files.

fprintf() to write to output files.

rewind() to reset file pointers after counting characters.

toupper() to handle case insensitivity.

Control structures (while, if, else) for logical flow.

ASCII Conversion:

During encryption: ASCII(plaintext) + key

During decryption: ASCII(encrypted_text) - key

Loops & Conditions:

Repetitive input validation loops ensure correct user input.

Key repetition loops handle length discrepancies between message and key.



  How to Run the Program
  
Use any standard C compiler (e.g., GCC) to compile and run the program:

bash
Copy
Edit
gcc encryption_program.c -o encrypt_decrypt
./encrypt_decrypt
Ensure your input and key files are correctly placed in the same directory as the compiled executable.



  Example Folder Structure
  
pgsql
Copy
Edit
Encryption_Project/
├── encrypt_decrypt.c
├── input.txt           (plaintext or encrypted message)
├── key.txt             (numerical encryption/decryption key)
└── output.txt          (created after running the program)


  Future Improvements
  
GUI implementation for easier interaction.

Support for advanced encryption algorithms (AES, RSA).

Enhanced key management features (key generation, secure storage).

  Author
Mohammed Kekli

Assignment: Introduction to Programming C, Encryption and Decryption (University Of Liverpool Project)
