#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define no_of_tags 15

int p;
// Structure for the Image Header
struct TIFF_header
{
    char FOR[2];
    short int ARB;
    int IFD_OFFSET;
};


// Structure for the Directory Header

struct DIR_header
{
    short int TAG;
    short int Type;
    int count;
    int value;
};

/*-------------------------------------------------------------------------
Function Name: power

Description : This function helps in calculating the decimal equivalent 
value of an 8-bit binary sequence.(This function is used in maketiff function)

Input Arguments: exponent - It is used to decide what is the value a number
should be multiplied with based on its position in the 8-bit field.

Return Value: Returns an Integer which is 2^e , where e can take a value 
from 0 to 7.
---------------------------------------------------------------------------*/
int power(int exponent)
{
    int result=1;
    for (exponent; exponent>0; exponent--)
        {
        result = result * 2;
        }
    return result;
}

/*-------------------------------------------------------------------------
Function Name: maketiff

Description : This function is used to set all the tags for the compressed
tiff file according to the users choice. It then generates the compressed
viewable tiff file.

Input Arguments: None

Return Value: None - (Void)
---------------------------------------------------------------------------*/
void maketiff()
{
    FILE *txt,*ptr;
    char c;
    char one = 255;
    char zero = 0;
    int sum = 0,num=1,m=0;
    
    txt=fopen("sample_compressed.tiff","wb");//New TIFF file which created or generated
    
    ptr=fopen("encoded_img_bin.txt","rb");//compressed encoded data file
    fseek(txt,0,SEEK_SET);
    if (txt == NULL) 
    {
        printf("Error!");
        exit(1);
    }
    else
    {
        //Tiff File header
        struct TIFF_header header = {"II",42,8};
        fseek(txt,0,SEEK_SET);
        fwrite(&header, sizeof(header), 1, txt);

        fseek(txt,8,SEEK_SET);
        short int value2 = 15 | (0<<8);// number of ifd entries
        fputc(value2,txt);

        //tags
        struct DIR_header tags[no_of_tags] ={ {254,4,1,2},{255,3,1,3},{256,3,1,1728},{257,3,1,2707},
        {258,3,1,1},{259,3,1,3},{262,3,1,0},{273,4,1,240},{278,3,1,2707},{279,4,1,694016},
        {274,3,1,1},{277,3,1,1},{292,4,1,4},{284,3,1,1},{296,3,1,2}};
        long d[1] ={6912};
        long b[1] ={216};

        fseek(txt,10,SEEK_SET);
        fwrite(tags, sizeof(tags), 1, txt);
        fseek(txt,190,SEEK_SET);

        //next ifd offset
        int value3 = 0 | (0<<8) | (0<<16) | (0<<24); 
        fputc(value3,txt);

        //Few Tags whose values has to be written in offset format
        unsigned long r[2]={200,1};
        unsigned long i[2]={70,1};
        fseek(txt,200,SEEK_SET);
        fwrite(r,sizeof(r),1,txt);
        fseek(txt,220,SEEK_SET);
        fwrite(i,sizeof(i),1,txt);
        fseek(txt,240,SEEK_SET);
        if (ptr == NULL)
        {
            printf("File is not available \n");
        }
        else
        {
            while ((c = fgetc(ptr)) != EOF)
            {   
                ///p++;
                fseek(ptr,8*m,SEEK_SET);//move the pointer to each every byte of the file
                m++;
                for(int k=7;k>=0;k--){
                    fread(&c,sizeof(char),1,ptr);
                    //printf("%d",c-48);
                    //printf("%d\t",power(k));
                    num = (c-48)*power(k);
                    sum +=num;
                    p++;
                    //printf("%d\t",c-48);
                    
                }
                //printf("\n");
                fseek(ptr,8*(m+1),SEEK_SET);
                fputc(sum,txt);
                
                sum=0;
            }
        }
        p+=8; // Padding extra bytes for end of file
        printf("%d",p);
        fseek(txt,240+p,SEEK_SET);
        fputc(EOF,txt);
    }
    fclose(txt);
    fclose(ptr);

}

int main()
{
    maketiff();
    printf(" \n\n --------------------------------------COMPRESSION DONE------------------------------------------------");
    //printf("\n                                       You're WELCOME :)                                               ");
}