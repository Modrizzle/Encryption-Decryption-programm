#include <stdio.h> // most of functions used in this algorithm are from this library
#include <stdlib.h>
char Encrypt_or_Decrypt()// this function  will be called in by the main function
{
 char MorK; // Declaring MorK as a character, M will represent Encryptoin and K will represent Decryption.
 printf("\nEncrypt or Decrypt this file?\n"); // This scentence will be printed on the sreen
 printf("enter letter 'M' = Encryption or 'K' = Decryption:\n"); // This scentence will be printed on the sreen
 scanf("%c", &MorK); // When the chosen letter is entered, a character is scanned for not an integer using %c
 fflush(stdin); //gets rid of any inputs from beforehand and begins again 
 MorK = toupper(MorK); // if m or k is entered they will automatically into M or K so this isnt case sensitive. 
 return MorK; //MorK value returned into the function 
}
int main() // this function contains all the functions togather for the program to work
{
 char MorK; // Declaring MorK as a character, M will represent Encryptoin and K will represent Decryption.
 char input_file_name[50]; // input_file_name[50] declared as a character along with an array of 50 characters which means character number is limited to 50 
 char key_file_name[50]; // key_file_name[50] declared as a character along with an array of 50 characters which means character number is limited to 50  
 char Output_file_name[50]; // output_file_name[50] declared as a character along with an array of 50 characters which means character number is limited to 50 
 FILE *Input_Text_File; // input_file declared as a pointer towards a file
 FILE *Key_Text_File; // key_file declared as a pointer towards a file
 FILE *Output_Text_File; // output_file declared as a pointer towards a file
 int length_of_input = 0; //The integer length_of_input initialised with a value of 0
 int length_of_key = 0; // The integer length_of_key initialised with a value of 0
 char ongoing_char; // ongoing_char declared as a character
 char Input[length_of_input]; // Input is declared as a char with an array named length_of_input initialised with a value of 0
 int ongoing_int = 0; // ongoing_int declared as an integer and initialised with a value of 0
 int key[length_of_key]; // key declared as an integer with an array named lenght_of_key initialised with a value of 0
 int repeater = 0; // repeater declred as an integer and intialised with a value of 0
 int Input_2_Ascii; // Input_2_ascii is declared as an integer 
 int ongoing_key_digit = 0; // ongoing_key_digit is declared as an intiger and initialised with a value of 0
 printf(" (+)(-)(+)(-)(+)(-)(+)(-)(+)(-)(+)\n"); // this title will be printed on the screen 
 printf(" {    Encrypter/Decrypter 7000   }\n"); // this title will be printed on the screen 
 printf(" (+)(-)(+)(-)(+)(-)(+)(-)(+)(-)(+)\n"); // this title will be printed on the screen 
 MorK = Encrypt_or_Decrypt(); // this refers to the function before the assignment of the return char MorK
 while(MorK != 'M' && MorK != 'K') // this while statement is used to loop the function again if the user inputs anythinh other than 'M' or 'K'
 {
 printf("\nWrong letter bruh! Gonna have to try again\n"); // this messege apears or prints on the screen when the user enters any letter other than 'M' or 'K'
 MorK = Encrypt_or_Decrypt(); //this refers or calls upon the function before the assignment of the return char MorK
 }
 printf("\nInsert the name of the Input file with .txt:\n"); // this is printed on the screen 
 scanf("%s", input_file_name); // a string which is the name of the input_file with .txt is entered here by the user for example a specified name of the file
 printf("\nInsert the name of the Key file with .txt:\n"); // this is printed on the screen 
 scanf("%s", key_file_name); //a string which is the name of the key_file with .txt is entered here by the user for example a specified name of the file
 printf("\nInsert the name of the Output file with .txt:\n"); //printing the sentence in the program
 scanf("%s", Output_file_name); //a string which is the name of the output_file with .txt is entered here by the user for example a random name 
 Input_Text_File = fopen(input_file_name, "r+"); // the file at the input is acccessed and read by the algorithm 
 Key_Text_File = fopen(key_file_name, "r+"); // the file at the input is acccessed and read by the algorithm 
 while (Input_Text_File == NULL || Key_Text_File == NULL) // if any of keyfile or namefile cannot be accessed then the program moves down to the conditions below
 {
 printf("\nBad news mate! This file is not accessible!\n"); // this is printed on the screen 
 printf("Enter again please!\n"); // this is printed on the screen 
 printf("\nInsert the name of the Input file with .txt:\n"); // this is printed on the screen 
 scanf("%s", input_file_name); // a string which is the name of the input_file with .txt is entered here by the user for example a specified name of the file
 printf("\nInsert the name of the Key file with .txt:\n"); // this is printed on the screen 
 scanf("%s", key_file_name); // a string which is the name of the key_file with .txt is entered here by the user for example a specified name of the file
 printf("\nInsert the name of the Output file with .txt:\n"); // this is printed on the screen 
 scanf("%s", Output_file_name); // a string which is the name of the output_file with .txt is entered here by the user for example a random name
 Input_Text_File = fopen(input_file_name, "r+"); // the file at the input is acccessed and read by the algorithm 
 Key_Text_File = fopen(Output_file_name, "r+"); // the file at the input is acccessed and read by the algorithm 
 }
 while((ongoing_char = fgetc(Input_Text_File)) != EOF) // a character is retured from the input_file up until the reaches the character file for example reads the input file
 {
 length_of_input ++; // Length_of_input initialised from 0 which then increases upuntill end of the file is reached 
 }
 while(fscanf(Key_Text_File, "%1d", &ongoing_int) > 0) // this will return a character of the key_file upuntill this gets to the end of the file character, for example accesses key_file
 {
 length_of_key ++; // Length_of_key initialised from 0 which then increases upuntill end of the file is reached 
 }
 rewind(Input_Text_File); //thie will rewind to the start of input, for example rewinds prior to the occurance of character count 
 rewind(Key_Text_File) ; //this will rewind to the start of key, for example rewinds prior to the occurance of character count 
 while((ongoing_char = fgetc(Input_Text_File)) != EOF) // a character is retured from the input_file up until the reaches the character file for example this would computes the input file 
 {
 Input[repeater] = ongoing_char; // an array of input is the repeater, this will increase to the end of the file which is then equal to the amount of characters at the input file
 repeater ++;
 }
 repeater = 0; //this reinitialises iterator to 0, initailises the repeater again with a value of 0
 while(fscanf(Key_Text_File, "%1d", &ongoing_int) > 0) // this will return a character of the key_file upuntill this gets to the end of the file character, for example accesses key_file
 {
 key[repeater] = ongoing_int; //// an array of key is the repeater, this will increase to the end of the file which is then equal to the amount of characters at the input file
 repeater ++; // within the function key shall repeat upuntill the equivalent number of characters has been achieved at the input_file
 }
 fclose(Input_Text_File); // shuts input text file
 fclose(Key_Text_File); // shuts key text file
 for (repeater = 0; repeater < length_of_input; repeater ++) //
 {
 Input_2_Ascii = Input[repeater]; // the input characters are changed to ASCII
 if (MorK == 'M') // encryption is an option which is equal to 1 then the follwoing function plays its part
 {
 Input_2_Ascii += key[ongoing_key_digit]; //this starts to encrypt the ASCII code 
 }
 else// this will take place if the users choice is anything other than 1
 {
 Input_2_Ascii -= key[ongoing_key_digit]; //This begins to decrypt the ASCII code
 }
 Input[repeater] = Input_2_Ascii; // this will convert the encrypted ASCII back to the encrypted character 
 if (ongoing_key_digit == length_of_key - 1) // this comes to be there is need to start from 1
 {
 ongoing_key_digit = 0;
 }
 else
 {
 ongoing_key_digit ++; //++ this will increase in increments 
 }
 }
 Output_Text_File = fopen(Output_file_name, "w"); // a new file is accessd in order to write a text file which the user can name what the user wnats which also stated from above
 fprintf(Output_Text_File, "%*.*s",length_of_input,length_of_input, Input); // some pointers and a member is utulized to write the encrypted/decrypted piece of text into the output_file 
 fclose(Output_Text_File); // shuts input text file
 if (MorK == 'M') // this is the case during encryption 
 {
 printf("\nThe proccess of encryption is finished!"); // this is printed on the screen
 }
 else//when its decryption
 {
 printf("\nThe Decryption process is completed!"); // this is printed on the screen
 }
 printf("\nPlease do go over to the folder which contains the encryption/decryption program for your file '%s'.\n", Output_file_name); //this is printed on the screen
}
