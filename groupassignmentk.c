#include "groupassignment.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encryptdecrypt();
int passphrase();

/*int main(void) {

    /*********************FUNCRIONS TO GO IN MAIN ************************/
    /*************************TO ENCRYPT THE FILES************************
    encryptdecrypt();
    printf("File encrypted successfully.\n Press any key to exit.");
    getch();
    exit(0);
    *********************************************************************/
    /***********************TO DECRYPT THE FILES**************************
    encryptdecrypt();
    printf("File decrypted successfully.\n Press any key to exit.");
    getch();
    exit(0);
    *********************************************************************/

int passphrase()
{
    char passphrase[MAX];
    printf("Enter passphrase>");
    scanf("%s", passphrase);
}

void encryptdecrypt()
{
        char filename[MAX], temp[] = "temp.txt";
        FILE *fp1,*fp2;
        /* get the file name from the user */
        printf("Enter your file name:");
        scanf("%s", filename);
        /* open the given file in read mode */
        fp1 = fopen(filename, "rb");
        /* error handling */
        if (fp1== NULL)
        {
            printf("Unable to open the source file!\n");
            exit(0);
        }
        /* open the temporary file in write mode */
        fp2 = fopen(temp, "wb");
        /* error handling */
        if (fp2== NULL)
        {
            printf("Unable to open the temporary file!\n");
            exit (0);
        }
        /* converting plain text to cipher text */
		char key = passphrase();
        int ch;
        while(1)
        {

           ch=fgetc(fp1);/*gets character from source file*/
           if(ch == EOF)
           {
            break;
           }
           else
           {
            ch=ch ^ key; /*XOR's the character using the key*/
            fputc(ch, fp2);/*saves the encrypted character to temporary file*/
           }
        }
        /* closing all opened files */
        /*saving encrytped files from temp file to original file*/
        fclose(fp1);
        fclose(fp2);
        fp1=fopen(filename, "wb");
        if(fp1==NULL)
        {
        printf("Error in opening source file.");
        exit (0);
        }
        fp2=fopen("temp.txt", "rb");
        if(fp2==NULL)
        {
        printf("Error in opening temp.txt file.");
        fclose(fp1);
        exit(0);
        }
        while(1)
        {
        ch=fgetc(fp2);/*gets character from temp file*/
        if(ch==EOF)
        {
            break;
        }
        else
        {
            fputc(ch, fp1);/*saves character to source file*/
        }
    }
    fclose(fp1);
   	fclose(fp2);
}
