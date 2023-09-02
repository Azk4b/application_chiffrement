#include <stdio.h>
#include <stdlib.h>
#include "cesar_code.h"
#include "code_vigenere.h"

char endOfProg(void);

int main() {
    unsigned short cipherChoice = 0;
    unsigned short codeChoice = 0;
    unsigned char key = 'y';

    while(key != 'n')
    {
        printf("Do you want to cipher or uncipher ? (1/2)\n");
        fflush(stdin);
        scanf("%hu", &cipherChoice);

        switch (cipherChoice) {

            case 1:
                printf("Which program do you want to use ?\nCesar (1)\nVigenere (2)\nPlease enter the number associate with the program.\n");
                fflush(stdin);
                scanf("%hu", &codeChoice);

                switch (codeChoice) {

                    case 1:
                        chiffrementCodeCesar();
                        printf("Done!\n");
                        key = endOfProg();
                        break;

                    case 2:
                        chiffrementCodeVigenere();
                        printf("Done!\n");
                        key = endOfProg();
                        break;


                    default:
                        printf("Error this code does not exist!\n");
                        key = endOfProg();
                        break;

                }
                break;

            case 2:
                printf("Which program do you want to use ?\nCesar (1)\nVigenere (2)\nPlease enter the number associate with the program.\n");
                fflush(stdin);
                scanf("%hu", &codeChoice);

                switch (codeChoice) {

                    case 1:
                        dechiffrementCodeCesar();
                        printf("Done!\n");
                        key = endOfProg();
                        break;

                    case 2:
                        dechiffrementCodeVigenere();
                        printf("Done!\n");
                        key = endOfProg();
                        break;

                    default:
                        printf("Error this code does not exist!\n");
                        key = endOfProg();
                        break;

                }
                break;

            default:
                printf("Error this code does not exist!\n");
                key = endOfProg();
                break;

        }
    }

    return 0;
}

char endOfProg(void){

    char Key;

    printf("Do you want to continue ? (y/n) :\n");
    fflush(stdin);
    scanf("%c", &Key);

    return Key;

}