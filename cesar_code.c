//
// Created by theob on 07/04/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "cesar_code.h"

void chiffrementCodeCesar(void)
{
    unsigned short Key = 3;


    char toCipherFilePath[] = "C:\\Users\\theob\\OneDrive\\Documents\\programmation\\C\\projet_application_chiffrement_dechiffrement\\test.txt";
    char CipheredFilePath[] = "C:\\Users\\theob\\OneDrive\\Documents\\programmation\\C\\projet_application_chiffrement_dechiffrement\\test_ciphered.txt";
    /*
    printf("Please enter the absolute path of the file you want to cipher.\n");
    fflush(stdin);
    scanf("%s", &toCipherFilePath);
     */

    FILE *input, *output;
    int c;

    input = fopen(toCipherFilePath, "r");
    if(input == NULL)
    {

        printf("Error : impossible to open the file to cipher !\n");
        exit(1);

    }

    output = fopen(CipheredFilePath, "w");
    if(output == NULL)
    {

        printf("Error : impossible to open the ciphered file !\n");
        exit(1);

    }

    while((c = fgetc(input)) != EOF)
    {

        if(c >= 'a' && c <= 'z')
        {

            c = (c - 'a' + Key) %26 + 'a';

        }
        else if(c >= 'A' && c <= 'Z')
        {

            c = (c - 'A' + Key) % 26 + 'A';

        }

        fputc(c, output);

    }

    fclose(input);
    fclose(output);

    return;
}

void dechiffrementCodeCesar(void)
{

    unsigned short Key = 3;

    char uncipheredFilePath[] = "C:\\Users\\theob\\OneDrive\\Documents\\programmation\\C\\projet_application_chiffrement_dechiffrement\\test_unciphered.txt";
    char toUncipheredFilePath[] = "C:\\Users\\theob\\OneDrive\\Documents\\programmation\\C\\projet_application_chiffrement_dechiffrement\\test_ciphered.txt";
    /*
    printf("Please enter the absolute path of the file you want to cipher.\n");
    fflush(stdin);
    scanf("%s", &toCipherFilePath);
     */

    FILE *input, *output;
    int c;

    input = fopen(toUncipheredFilePath, "r");
    if(input == NULL)
    {

        printf("Error : impossible to open the file to uncipher !\n");
        exit(1);

    }

    output = fopen(uncipheredFilePath, "w");
    if(output == NULL)
    {

        printf("Error : impossible to open the unciphered file !\n");
        exit(1);

    }

    while((c = fgetc(input)) != EOF)
    {

        if(c >= 'a' && c <= 'z')
        {

            c = (c - 'a' - Key) %26 + 'a';

        }
        else if(c >= 'A' && c <= 'Z')
        {

            c = (c - 'A' - Key) % 26 + 'A';

        }

        fputc(c, output);

    }

    fclose(input);
    fclose(output);

    return;
}