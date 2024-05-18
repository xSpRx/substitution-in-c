#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define ALPHABET_LENGTH 26

int main()
{
	SetConsoleTitle("Substitution");
	system("color 04");
	
	FILE *fptr;
	char txt, filename[100];
	
	int option;
	char encrypt_key[26];
	char plain_text[100], cipher_text[100];
	int i, j;
	
	printf(" ===============================");
    printf("\n ||                           ||");
    printf("\n ||     ENCRYPTION MACHINE    ||");
    printf("\n ||         ver. 0.1          ||");
    printf("\n ||                           ||");
    printf("\n ===============================");
    printf("\n\n");
	
	do
	{
	    printf(" ********** MAIN MENU **********");
        printf("\n\n [1] Enter key");
        printf("\n [2] Encrypt message");
        printf("\n [3] Decrypt message");
        printf("\n [4] Export the data");
        printf("\n [5] Exit");
		
		printf("\n\n Enter your choice: ");
        scanf("%d", &option);
        
        switch(option)
		{
			case 1:
				start:
		    	printf("\n Please enter the key: ");
				scanf("%s", encrypt_key);
				
				if (strlen(encrypt_key) == 26)
				{
					for (i = 0; i < strlen(encrypt_key); i++)
					{
						if (!isalpha(encrypt_key[i]))
						{
							printf(" ERROR: Key must contain only alphabetic characters.\n");
							goto start;
						}
						
						for (j = i + 1; j < strlen(encrypt_key); j++)
						{
							if (toupper(encrypt_key[j]) == toupper(encrypt_key[i]))
							{
								printf(" ERROR: Key must not contain repeated characters.\n");
								goto start;
							}
						}
					}
				}
				else
				{
					printf(" ERROR: Key must contain 26 characters.\n");
					goto start;
				}
				
				printf("\n");
				break;
			
			case 2:
				if (strlen(encrypt_key) == 26)
				{
					printf("\n Enter a plain text (max 100 characters): ");
					scanf(" %[^\n]", plain_text);
					
					for (i = 0; plain_text[i] != '\0'; i++) {
				        if (isalpha(plain_text[i])) {
				            char base = isupper(plain_text[i]) ? 'A' : 'a';
				            int index = plain_text[i] - base;
				            plain_text[i] = isupper(plain_text[i]) ? toupper(encrypt_key[index]) : tolower(encrypt_key[index]);
				        }
				    }
					
					printf(" The cipher text is: %s\n\n", plain_text);
				}
				else
				{
					printf("\n ERROR: Please enter the key first.\n\n");
				}
				break;
			
			case 3:
				if (strlen(encrypt_key) == 26)
				{
					printf("\n Enter a cipher text (max 100 characters): ");
					scanf(" %[^\n]", cipher_text);
					
					for (i = 0; cipher_text[i] != '\0'; i++) {
				        if (isalpha(cipher_text[i])) {
				            char base = isupper(cipher_text[i]) ? 'A' : 'a';
				            for (j = 0; j < ALPHABET_LENGTH; j++) {
				                if (tolower(cipher_text[i]) == tolower(encrypt_key[j])) {
				                    cipher_text[i] = isupper(cipher_text[i]) ? toupper('A' + j) : tolower('a' + j);
				                    break;
				                }
				            }
				        }
				    }
					
					printf(" The plain text is: %s\n\n", cipher_text);
				}
				else
				{
					printf("\n ERROR: Please enter the key first.\n\n");
				}
				break;
				
			case 4:
				if (strlen(encrypt_key) == 26)
				{
					printf("\n--|NOTE| It will create the file in the folder where the program runs and set its name to (you will determine).\n\n-Do you want this data to be output as a file? -|Y|: YES |N|: NO(menu)-: ");
					scanf(" %c", &txt);
					
					if(txt == 'Y' || txt == 'y')
					{
						printf("\nEnter the filename to open (add .txt after name): ");
	    				scanf("%s", filename);
						
						fptr = fopen(filename, "w");
						
						if (fptr == NULL)
					    {
					        printf("Could not open file");// add controller
					    }
					    else
						{
							fprintf(fptr, " ****** Encryption Machine ******");
							
			                fprintf(fptr, "\n\n Encryption Key: %s", encrypt_key);
			                fprintf(fptr, "\n\n Original text is: %s", cipher_text);
			                fprintf(fptr, "\n\n Encryption text is: %s", plain_text);
			                
			                fclose(fptr);
							
					        printf("\nThe file is created Successfully.\n\n");
					    }
					}
					else if(txt == 'N' || txt == 'n')
					{
						break;
					}
				}
				else
				{
					printf("\n ERROR: Please enter the key first.\n\n");
				}
                
            case 5:
                break;
                
			default:
                printf(" ERROR: Invalid choice!\n\n");
		}
        
	} while(option != 5);
	
	return 0;
}
