/*

Title: ENG1003 Project 1 - Rotation & Substitution Cipher
Student: Nicholas O'Brien 
Student Number: 3329907

HOW TO USE THIS PROGRAM:


*/

#include <stdio.h> // fget(), stdin
#include <string.h> //stringlen() function
#include <stdlib.h>

//Define the Rotation cipher function for encrytion of type char.
void rotationEncrypt(char* message, int key);


int main(void) {
    
    int key = 1;
    int x;
    char message[];
    
    printf("\nPlease enter a string:\t"); //Ask the user for the message they wish to use.
    fgets(message, sizeof(message), stdin); //Gets the user's text input and stores it in the message variable.
}

void rotationEncrypt(char* message, int key) {
    
    int i;
    char cipher; //this is the encryted message
    /*
    while(message[i] != '\0' && strlen(message)-1 > i){
		cypherValue = ((int)message[i] -97 + key) % 26 + 97;
		cypher = (char)(cypherValue);
	*/
    for(i = 0; (message[i] != '\0' && strlen(message)-1 > i); i++) {
        cypher = ((int)message[i])
    }
}