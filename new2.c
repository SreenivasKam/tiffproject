#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
char a[200];

int main(){

    FILE *txt,*ptr;
    char c;
    int p=0;
    ptr=fopen("C:/Users/sreen/Downloads/SampleUncompressed.tiff","rb");
        fseek(ptr,4423688,SEEK_SET);
        fread(&a,sizeof(char),186,ptr);
        /*if (ptr == NULL)
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
        */
       for(int k=0;k<186;k++)
       {
           printf("%d",a[k]);
       }
    fclose(ptr);
}