/*

Title: ENG1003 Programming Assignment 1 - C Cipher
Student Name: Nicholas O'Brien 
Student Number: 3329907

HOW TO USE THIS PROGRAM:

Begin by compiling and running the program, next follow the steps and give all inputs within
their data type. Doing this will allow you to sucessfully follow the program throughout its operation.
 
*/

//----------------- C Library Headers -----------------
#include <stdio.h> //Functions to perform input & output.
#include <string.h> //Functions for maniulating arrays of characters.
#include <ctype.h> // Library useful for testing and mapping characters.
#include <stdlib.h> //Functions for performing general functions.

//Define the Rotation cipher function for encrytion.
void rotationEncrypt(char* message, int key);
//Define the Rotation cipher function for decryption.
void rotationDecrypt(char* message, int key);
//Define the Brute force Decryption cipher function.
void bruteRotation(char* message, int key);
//Define substitution index function.
int f_index(char subkey[], char to_find);
//Define substitution encryption function.
char* substitutionEncrypt(char* message, char subkey[]);
//Define substitution decryption function.
char* substitutionDecrypt(char* message, char subkey[]);


//----------------- User Friendly menu & Task selection -----------------
int main() {
    
    int operation, key; //declared integers for operation
    char message[255]; //This is the array which holds the user's message to be used in the Cipher.
    //Alphabet -------- A    B    C    D    E    F    G    H    I    J    K    L    M    N    O    P    Q    R    S    T    U    V    W    X    Y    Z
    //Declaration of substitution key array which holds the indexed key.
    char subkey[26] = {'Z', 'A', 'Q', 'W', 'S', 'X', 'C', 'D', 'E', 'R', 'F', 'V', 'B', 'G', 'T', 'Y', 'H', 'N', 'M', 'J', 'U', 'I', 'K', 'L', 'O', 'P'};
    
    
    printf("Please enter a message:\t"); //Ask the user for the message they wish to use.
    fgets(message, sizeof(message), stdin); //Gets the user's text input and stores it in the message variable through stdin.
//User friendly task selection menu which relate to the switch case statements.
    printf("\nPlease choose from the following options:\n");
    printf("1 = Encrypt with the Rotation Cipher.\n");
    printf("2 = Decrypt with the Rotation Cipher.\n");
    printf("3 = Encrypt with the Substitution Cipher.\n");
    printf("4 = Decrypt with the Substitution Cipher.\n");
    printf("\n5 = Use brute force Rotation Decryption.\n");
    printf("\nEnter a number to make your selection:\t");
    scanf("%d", &operation); //assigning the user enterered integer "%d" to the variable "operation" to be used in the switch case.
    fflush(stdin); //clear stream/buffer before next input.
    
    
    //-----------------Switch case statesments to order the selction of operations / performable tasks-----------------
    switch(operation) {
        case 1: // Encryption with Rotation cipher
            fflush(stdin);
            printf("\nEncryption with Rotation Cipher selected.\n"); //confirmation message printed once operation has been selected.
            printf("Enter the Rotation Cipher Key (between 0-25):\t"); //Promting user to enter key between 0-25 for rotation.
            scanf("%d", &key); //Read integer from stdin using and assign it to variable "Key".
            //Print the encyrpted text
            printf("\nEncrypted message: "); //descriptive text for the encrypted message.
            rotationEncrypt(message, key); //Refers case statement to the encryption function & associated variables.
            break; //Separates case statements.
            
        case 2: // Decryption with Rotation cipher
            fflush(stdin);
            printf("\nDecryption with Rotation Cipher selected.\n"); //confirmation message printed once operation has been selected.
            printf("Enter the Rotation Cipher Key (between 0-25):\t"); //Promting user to enter key between 0-25 for rotation.
            scanf("%d", &key); //Read integer from stdin using and assign it to variable "Key".
            //print the decrypted text
            printf("\nDecrypted message: "); //Descriptive text for the decrypted message.
            rotationDecrypt(message, key); //Refers case statement to the decryption function & associated variables.
            break;
            
        case 3: //Encryption with Substitution cipher
             printf("\nEncryption with Substitution Cipher selected.\n"); //confirmation message printed once operation has been selected.
            char *esub = substitutionEncrypt(message, subkey); //Refers case statement to the encryption function & associated variables.
            printf("\nEncrypted message: %s\n", esub); //Prints encrypted message as a string form the variable "esub".
            break;
            
        case 4: //Decryption with Substitution cipher
            printf("\nDecryption with Substitution Cipher selected.\n"); //confirmation message printed once operation has been selected.
            char *dsub = substitutionDecrypt(message, subkey); //Refers case statement to the decryption function & associated variables.
            printf("\nDecrypted Message: %s\n", dsub); //Prints decrypted message as a string from the variable "dsub".
            break;
            
        case 5:  // Brute force rotation decryption
            printf("\nBrute force Decryption selected.\n"); //confirmation message printed once operation has been selected.
                bruteRotation(message, key); //Refers case statement to the brute force function & associated variables.
            break;
            
        default: //Default case if none are selected.
            printf("\nError incorrectly entered inputs, try again.\n"); //Error message for incorrectly entered inputs.
    }

}
//----------------- Rotation Encryption Function -----------------
void rotationEncrypt(char* message, int key) { //void allows the function to be coded outside of main. Declared variables of message and key.
    
    int i; //integer variable "i" to reference each character's index.
    
    for(i = 0; message[i] != '\0'; ++i) { //For loop with conditions for varibale "i" beginning at 0 while the message is not blank and incrementing i.
        
        if(message[i] >= 'a' && message[i] <= 'z') { //Resticting cipherable message to lowercase alphabetical characters of the ASCII numerals between 'a' and 'z'.
                message[i] = toupper(message[i]) + key; //Encrypt input message using the "key" variable & convert any lower case characters to uppercase with "toupper" - ctype.h
            
            if(message[i] > 'Z') {                       //Subtracts the ASCII vales of the character in the message[i] and shifts it. Prevents the characters from rotating 
                message[i] = message[i] - 'Z' + 'A' - 1; // into ASCII values of special characters. E.g. A character 'z' would equal [124-122+97-1 = 98] 98 = b hence 
    				                                      //remaining in alphabetical format.
            }
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') { // Else resticting cipherable message to uppercase alphabetical characters of the ASCII numerals betwee 'A' and 'Z'.
                message[i] = message[i] + key; //Encrypt input message using the "key" variable.
        
            if(message[i] > 'Z') {                       //Subtracts the ASCII vales of the character in the message[i] and shifts it. Prevents the characters from rotating
                message[i] = message[i] - 'Z' + 'A' - 1; // into ASCII values of special characters. E.g. A character 'z' would equal [124-122+97-1 = 98] 98 = b hence 
    				                                       //remaining in alphabetical format.
            }
        }
        printf("%c", message[i]); //Print array value of ciphered message. 
    }
    printf("\n"); //insert new line after printed message.
}
//-----------------Rotation Decryption Function-----------------
void rotationDecrypt(char* message, int key) { //void allows the function to be coded outside of main. Declared variables of message and key.
    
    int i; //integer variable "i" to reference each character's index.
    
    for(i = 0; message[i] != '\0'; ++i) { //For loop with conditions for varibale "i" beginning at 0 while the message is not blank and incrementing i.
    		
    	if(message[i] >= 'a' && message[i] <= 'z') { //Resticting cipherable message to lowercase alphabetical characters of the ASCII numerals between 'a' and 'z'.
    		message[i] = toupper(message[i]) - key; //Decrypt input message using the "key" variable & convert any lower case characters to uppercase with "toupper" - ctype.h
    			
    		if(message[i] < 'A') {                       //Subtracts the ASCII vales of the character in the message[i] and shifts it. Prevents the characters from rotating
    			message[i] = message[i] + 'Z' - 'A' + 1;  // into ASCII values of special characters. E.g. A character 'z' would equal [124-122+97-1 = 98] 98 = b hence 
    				                                        //remaining in alphabetical format.
    		}
    	}	
    	else if(message[i] >= 'A' && message[i] <= 'Z') { // Else resticting cipherable message to uppercase alphabetical characters of the ASCII numerals betwee 'A' and 'Z'.
    		message[i] = message[i] - key; //Decrypt input message using the "key" variable and related ASCII values.
    			
    		if(message[i] < 'A') {                       //Subtracts the ASCII vales of the character in the message[i] and shifts it. Prevents the characters from rotating
    			message[i] = message[i] + 'Z' - 'A' + 1; // into ASCII values of special characters. E.g. A character 'z' would equal [124-122+97-1 = 98] 98 = b hence 
    				                                        //remaining in alphabetical format.
    		}
    	}
    	printf("%c", message[i]); //Print array value of ciphered message.
    }
    printf("\n"); //insert new line after printed message.
}
//-----------------Brute Force Rotation Function -----------------
void bruteRotation(char* message, int key) { //void allows the function to be coded outside of main. Declared variables of message and key.
    
    int i; //integer variable "i" to reference each character's index.
    
    for(key = 1; key <= 26; key++) { //Looping decryption algorithm for every useable key 1-26 - printing all results in a brute force manner.
        for(i = 0; message[i] != '0' && i < strlen(message); ++i) { //For loop with conditions for varibale "i" beginning at 0 while the message is not blank
                                                                    //and "i" is less than the length of "message". incrementing "i" after.
    		
    		if(message[i] >= 'a' && message[i] <= 'z') { //Resticting cipherable message to lowercase alphabetical characters of the ASCII numerals between 'a' and 'z'.
    			message[i] = toupper(message[i]) - key; //Decrypt input message & convert any lower case characters to uppercase
    			
    			if(message[i] < 'A') {                       //Subtracts the ASCII vales of the character in the message[i] and shifts it. Prevents the characters from rotating
    				message[i] = message[i] + 'Z' - 'A' + 1; // into ASCII values of special characters. E.g. A character 'z' would equal [124-122+97-1 = 98] 98 = b hence 
    				                                           //remaining in alphabetical format.
    			}
    		}
    		else if(message[i] >= 'A' && message[i] <= 'Z') { // Else resticting cipherable message to uppercase alphabetical characters of the ASCII numerals betwee 'A' and 'Z'.
    			message[i] = message[i] - key; //Decrypt input message using the "key" variable adn realted ASCII values.
    			
    			if(message[i] < 'A') {                       //Subtracts the ASCII vales of the character in the message[i] and shifts it. Prevents the characters from rotating
    				message[i] = message[i] + 'Z' - 'A' + 1; // into ASCII values of special characters. E.g. A character 'z' would equal [124-122+97-1 = 98] 98 = b hence 
    				                                           //remaining in alphabetical format.
    			}
    		}
    	}
    	printf("Key: %d Decrypted Message: %s", key, message); //Print decryption key and string value of decrypted message.
    }
    printf("\n"); //insert new line after printed message.
}
//-----------------Index function for Subsitution Key-----------------
int f_index(char subkey[], char to_find) { //Integer fucntion to map the index of substitution cipher alphabet "subkey".
    
    int i; //Integer "i" referencing each index character in "subkey"
    
    for(i = 0; i < 26; i++) { //for loop to increment I for each character of the index less than 26.
        if(subkey[i] == to_find) { //assign each indexed character to it respective subkey character.
            return i; //return the index location.
        }
    }
    return -1;
}
//-----------------Encryption Function for Substiution Cipher-----------------
char* substitutionEncrypt(char* message, char subkey[]) {
    
    int i; //Integer "i" referencing each index character in the string "message".
    int length = strlen(message); //Gather length of string "message" and assign it to length.
    int e_index; //Integer index of encryption message[i];
    char *esub = (char *) malloc(sizeof(char)*length); //Allocate space to the cipher result string "esub" equalling the length of the original "message".
    
    for(i = 0; i < length; i++) { //for loop to increment I for each character less than the length of the string.
        e_index = toupper(message[i]) - 'A'; //uppercase all characters against encryption index 
        
        if (e_index >= 0 && e_index < 26) { //index character must be between 0 & 26
            esub[i] = subkey[e_index]; // message character of same index as the subkey is matched with the subkey characters' index to perform the substitution.
        }
        else {
            esub[i] = message[i]; //If the character is not alphabetic or a white space, it will remain the same as the original.
        }
    }
    return esub; //return encrypted message value to be printed
}
//-----------------Decryption Function for Subsitution Cipher-----------------
char* substitutionDecrypt(char* message, char subkey[]) {
    
    int i; //Integer "i" referencing each index character in the string "message".
    int length = strlen(message);
    int d_index; //Integer index of decryption message[i];
    int subkey_index;
    char *dsub = (char *) malloc(sizeof(char)*length); //Allocate space to the cipher result string "dsub" equalling the length of the original "message".
    
    for(i = 0; i < length; i++) { //for loop to increment I for each character less than the length of the string.
        d_index = toupper(message[i]) - 'A'; //uppercase all characters against encryption index.
        
        if(d_index >= 0 && d_index < 26) { //index character must be between 0 & 26
            subkey_index = f_index(subkey, toupper(message[i])); // encrypted character of same index as the subkey is matched with the subkey characters' index to perform the substitution.
            dsub[i] = 'A' + subkey_index; //align indexed character of each array.
        }
        else {
            dsub[i] = message[i]; //If the character is not alphabetic or a white space, it will remain the same as the original.
        }
    }
    return dsub; //return decrypted message value to be printed.
}