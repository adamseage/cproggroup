void encryptdecrypt(FILE*fp1,FILE*fp2 , char * key);
char filename[MAX], temp[] = "temp.txt";

int main(void) {
    int choice;
    char *key = malloc(MAX);
    printf("Enter key: ");
    fgets(key,MAX,stdin);
        if(choice ==1 )
        {
    FILE *fp1 = fopen(filename, "rb");
    FILE *fp2 = fopen(temp, "wb");
        encryptdecrypt(fp1,fp2,key);
        printf("File encrypted successfully.\n");
        exit(5);
        }
        if(choice ==2)
        {
    FILE *fp1 = fopen(filename, "rb");
    FILE *fp2 = fopen(temp, "wb");
        encryptdecrypt(fp1,fp2,key);
        printf("File decrypted successfully.\n");
        exit(6);
        }


}




void encryptdecrypt(FILE*fp1,FILE*fp2 , char * key)
{
        /* get the file name from the user */
        printf("Enter your file name:");
        scanf("%s", filename);
        /* open the given file in read mode */
        fp1 = fopen(filename, "rb");
        /* error handling */
        if (fp1== NULL) {
                printf("Unable to open the input file!\n");
                exit(5);
        }
        /* open the temporary file in write mode */
        fp2 = fopen(temp, "wb");
        /* error handling */
        if (fp2== NULL) {
                printf("Unable to open the temporary file!\n");
                exit (6);
        }
        /* converting plain text to cipher text */

        int key_count = 0;/*Used to restart key if strlen(key) < strlen(encrypt)*/
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
            ch=ch ^ key[key_count]; /*XOR's the character using the key*/
            fputc(ch, fp2);/*saves the encrypted character to temporary file*/
            key_count++;
            if(key_count == strlen(key))
            	key_count=0;/*restarts the key when end is reache*/

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
        exit (3);
        }
        fp2=fopen("temp.txt", "rb");
        if(fp2==NULL)
        {
        printf("Error in opening temp.txt file.");
        fclose(fp1);
        exit(4);
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
