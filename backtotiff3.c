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
    char *one = "11111111";
    char *zero = "00000000";
    //txt=fopen("maketiff_final.tiff","wb");
    //ptr=fopen("mod_cmp_1.5d_2.txt","rb");

    txt=fopen("D:/FINAL YEAR PROJECT/maketiffer.tiff","wb");
    //FILE *fp = fopen("C:/Users/sreen/Downloads/SampleUncompressed.tiff","rb");
    //ptr=fopen("D:/FINAL YEAR PROJECT/work/mod_cmp_1.5d_3.txt","rb");
    ptr=fopen("D:/FINAL YEAR PROJECT/sample_bin_uc3.txt","rb");

    fseek(txt,0,SEEK_SET);
    if (txt == NULL) {
        printf("Error!!!!");
        exit(1);
    }
    else{
        // 186 IS THE MAGIC NUMBER REQUIRED 
        struct TIFF_header header = {"II",42,8};
        fseek(txt,0,SEEK_SET);
        fwrite(&header, sizeof(header), 1, txt);

        fseek(txt,8,SEEK_SET);
        short int value2 = 13 | (0<<8);// number of ifd entries
        fputc(value2,txt);
        //tags
        struct DIR_header tags[13] ={ {256,3,1,1728},{257,3,1,2707},{258,3,1,1}
        ,{259,3,1,1},{262,3,1,1},{273,4,1,216},{277,3,1,1},{278,3,1,2707},{279,4,1,4426241},
        {282,5,1,170},{283,5,1,190},{284,3,1,1},{296,3,1,2}
        };

        fseek(txt,10,SEEK_SET);
        fwrite(tags, sizeof(tags), 1, txt);
        fseek(txt,166,SEEK_SET);

        //next ifd offset
        int value3 = 0 | (0<<8) | (0<<16) | (0<<24); 
        fputc(value3,txt);

        unsigned long r[2]={200,1};
        unsigned long i[2]={193,1};
        fseek(txt,170,SEEK_SET);
        fwrite(r,sizeof(r),1,txt);
        fseek(txt,190,SEEK_SET);
        fwrite(i,sizeof(i),1,txt);

        fseek(txt,216,SEEK_SET);
        if (ptr == NULL)
        {
            printf("File is not available \n");
        }
        else
        {    
            while ((c = fgetc(ptr)) != EOF)
            {   
                if(c==49){
                    //fputc('00110001',txt);
                   fwrite(zero,sizeof(char),8,txt);
                   // printf("OK1");
                }else{
                    //fputc('00110000,txt);
                    
                     fwrite(one,sizeof(char),8,txt);
                   // printf("OK2");
                }
            }
        }
        printf("%d",p);
        fseek(txt,216+p,SEEK_SET);
        fputc(EOF,txt);
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