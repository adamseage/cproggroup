#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 256


void encryptdecrypt(FILE* fp1, FILE* fp2, char *key);
char filename[MAX], temp[] = "temp.txt";

int main(void) {
    int choice;

    char *key = malloc(MAX);
    printf("Enter key: ");
    fgets(key,MAX,stdin);
    while(1)
    {
        printf("Select One of the Following:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        if(choice ==1 )
        {

        FILE *fp1,*fp2;
        encryptdecrypt(fp1,fp2,key);
        printf("File  encrypted successfully.");
        printf("\nPress any key to exit.");
        getch();
        }
        if(choice ==2)
        {
        FILE *fp1,*fp2;
        encryptdecrypt(fp1,fp2,key);
        printf("File %s decrypted successfully.");
        printf("\nPress any key to exit.");
        getch();
        }


}
}
void encryptdecrypt(FILE* fp1, FILE* fp2, char* key)
{
        /* get the file name from the user */
        printf("Enter your file name:");
        scanf("%s", filename);
        /* open the given file in read mode */
        fp1 = fopen(filename, "r");
        /* error handling */
        if (fp1== NULL) {
                printf("Unable to open the input file!\n");
                exit(5);
        }
        /* open the temporary file in write mode */
        fp2 = fopen(temp, "w");
        /* error handling */
        if (fp2== NULL) {
                printf("Unable to open the temporary file!\n");
                exit (6);
        }
        /* converting plain text to cipher text */
        int key_count = 0; //Used to restart key if strlen(key) < strlen(encrypt)
        int ch;
        while(1)
        {
           ch=fgetc(fp1);
           if(ch == EOF)
           {
            break;
           }
           else
           {
            ch=ch ^ key[key_count];
            fputc(ch, fp2);
            key_count++;
            if(key_count == strlen(key))
            	key_count=0;

           }
        }
        /* closing all opened files */
        /*saving encrytped files from temp file to original file*/
        fclose(fp1);
        fclose(fp2);
        fp1=fopen(filename, "w");
        if(fp1==NULL)
        {
        printf("Error in opening source file.");
        exit (3);
        }
        fp2=fopen("temp.txt", "r");
        if(fp2==NULL)
        {
        printf("Error in opening temp.txt file.");
        fclose(fp1);
        exit(4);
        }
        while(1)
        {
        ch=fgetc(fp2);
        if(ch==EOF)
        {
            break;
        }
        else
        {
            fputc(ch, fp1);
        }
    }
    fclose(fp1);
   	fclose(fp2);
}
