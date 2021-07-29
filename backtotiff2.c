#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[10];
int p;




struct TIFF_header{
char FOR[2];
short int ARB;
int IFD_OFFSET;
};
#define bytes_to_u16(MSB,LSB) (((unsigned int) ((unsigned char) MSB)) & 255)<<8 | (((unsigned char) LSB)&255) 

struct DIR_header{
short int TAG;
short int Type;
int count;
int value;
};

    
struct IFD_header{
    struct DIR_header *Taglist;
};


void maketiff(){
    FILE *txt,*ptr;
    char c;
    char one = 255;
    char zero = 0;
    
    txt=fopen("D:/FINAL YEAR PROJECT/maketiffer.tiff","wb");
    //FILE *fp = fopen("C:/Users/sreen/Downloads/SampleUncompressed.tiff","rb");
    //ptr=fopen("D:/FINAL YEAR PROJECT/work/mod_cmp_1.5d_3.txt","rb");
    ptr=fopen("D:/FINAL YEAR PROJECT/sample_bin_uc4.txt","rb");
    fseek(txt,0,SEEK_SET);
    if (txt == NULL) {
        printf("Error!");
        exit(1);
    }
    else{
        // 186 IS THE MAGIC NUMBER REQUIRED 
        struct TIFF_header header = {"II",42,8};
        fseek(txt,0,SEEK_SET);
        fwrite(&header, sizeof(header), 1, txt);

        fseek(txt,8,SEEK_SET);
        short int value2 = 15 | (0<<8);// number of ifd entries
        fputc(value2,txt);
        //tags
        struct DIR_header tags[15] ={ {256,3,1,1728},{257,3,1,2707},{258,3,1,8},
        {259,3,1,1},{262,3,1,1},{273,4,1,240},{274,3,1,1},{277,3,1,1},{278,3,1,2707},
        {279,4,1,4423680},{282,5,1,200},{283,5,1,220},{284,3,1,1},{296,3,1,2}
        ,{339,3,1,1}};
        long d[1] ={6912};
        long b[1] ={216};

        fseek(txt,10,SEEK_SET);
        fwrite(tags, sizeof(tags), 1, txt);
        fseek(txt,190,SEEK_SET);

        //next ifd offset
        int value3 = 0 | (0<<8) | (0<<16) | (0<<24); 
        fputc(value3,txt);

        unsigned long r[2]={200,1};
        unsigned long i[2]={193,1};
        fseek(txt,200,SEEK_SET);
        fwrite(r,sizeof(r),1,txt);
        fseek(txt,220,SEEK_SET);
        fwrite(i,sizeof(i),1,txt);
        fseek(txt,240,SEEK_SET);
        if (ptr == NULL)
        {
            printf("File is not available \n");
        }
        else{
            while ((c = fgetc(ptr)) != EOF)
            {   
                 if(c==49){
                    fputc(one,txt);
                   
                   // printf("OK1");
                }else{
                    fputc(zero,txt);
                    
                    
                   // printf("OK2");
                }
            }
        }
        printf("%d",p);
        fseek(txt,240+p,SEEK_SET);
        fputc(EOF,txt);
       //value2 = 13 | (0<<8);// number of ifd entries
       //fputc(value2,txt);
    }
       fclose(txt);
       fclose(ptr);




}
int binary(int n){
    int d,i;
    //printf("Enter the number");
    //scanf("%d", &n);
    //printf("the number is %d\n",n);
    
    for(i = 7;n>0;i--){
        a[i] = n%2;
        n = n/2;
        //printf("%d\t %d\n",a[i],i);
    }
    //sprintf("\n%d\n",i);
    
    for(d=0;d<=i;d++){
        a[d]=0;
    }
    for(int k=0;k<=57;k++){
        //printf("%d",a[k]);
    }
}



int main(){
    maketiff();
}