#include<stdio.h>

int main(){

    FILE *txt,*ptr;
    char c;
    int p=0;
    ptr=fopen("D:/FINAL YEAR PROJECT/maketiffs.tiff","rb");
    
        if (ptr == NULL)
        {
            printf("File is not available \n");
        }
        else{
            while ((c = fgetc(ptr)) != EOF)
            {   
                printf("%d",c-'0');
                p++;
            }
        }
        printf("\n\n\n%d",p);
    fclose(ptr);
}