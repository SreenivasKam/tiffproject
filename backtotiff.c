#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[10];
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
    int p=0;
    txt=fopen("D:/FINAL YEAR PROJECT/maketiff2.tiff","wb");
    ptr=fopen("D:/FINAL YEAR PROJECT/work/trail.txt","rb");
    fseek(txt,0,SEEK_SET);
    if (txt == NULL) {
        printf("Error!");
        exit(1);
    }
    else{
        // 186 IS THE MAGIC NUMBER REQUIRED   
        fputc(73,txt);
        fputc(73,txt);
        fseek(txt,2,SEEK_SET);
        short int value2 = 42 | (0<<8); //to make a 16 bit data
        fputc(value2,txt);
        fseek(txt,4,SEEK_SET);
        unsigned int value = 8 | (0<<8) | (0<<16) | (0<<24); // to make a 32 bt data
        fputc(value,txt);
        fseek(txt,8,SEEK_SET);
        /*if (ptr == NULL)
        {
            printf("File is not available \n");
        }
        else{
            while ((c = fgetc(ptr)) != EOF)
            {   
                fputc(c-'0',txt);
            },
        }
        fseek(txt,8+p,SEEK_SET);
        */
       value2 = 13 | (0<<8);// number of ifd entries
       fputc(value2,txt);
    
//tag1
       fseek(txt,10,SEEK_SET);
       unsigned int intval = 0b00000001;       // assuming compiler likes it
       unsigned char charval = intval;
       fwrite (&charval, 1, 1, txt);//"0000000100000000"
       fseek(txt,11,SEEK_SET);
       intval = 0b00000000;       // assuming compiler likes it
       charval = intval;
       fwrite (&charval, 1, 1, txt);
       //fputc(value2,txt);

       fseek(txt,12,SEEK_SET);
       value2 = 3 | (0<<8);
       fputc(value2,txt);

       fseek(txt,14,SEEK_SET);
       value = 1 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt);

       fseek(txt,18,SEEK_SET);
       value = 192 | (6<<8) | (0<<16) | (0<<24); 
       fputc(value,txt);


//tag2
       fseek(txt,22,SEEK_SET);
       value2 = 1 | (1<<8);
       fputc(value2,txt);

       fseek(txt,24,SEEK_SET);
       value2 = 3 | (0<<8);
       fputc(value2,txt);

       fseek(txt,26,SEEK_SET);
       value = 1 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt);

       fseek(txt,30,SEEK_SET);
       value = 2707 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt);

//tag3
       fseek(txt,34,SEEK_SET);
       value2 = 258 | (0<<8);
       fputc(value2,txt);

       fseek(txt,36,SEEK_SET);
       value2 = 3 | (0<<8);
       fputc(value2,txt);

       fseek(txt,38,SEEK_SET);
       value = 1 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt);

       fseek(txt,42,SEEK_SET);
       value = 8 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt);

//tag4
       fseek(txt,46,SEEK_SET);
       value2 = 259 | (0<<8);
       fputc(value2,txt);

       fseek(txt,48,SEEK_SET);
       value2 = 3 | (0<<8);
       fputc(value2,txt);

       fseek(txt,50,SEEK_SET);
       value = 1 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt);

       fseek(txt,54,SEEK_SET);
       value = 1 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt);

//tag5
       fseek(txt,58,SEEK_SET);
       value2 = 262 | (0<<8);
       fputc(value2,txt);

       fseek(txt,60,SEEK_SET);
       value2 = 3 | (0<<8);
       fputc(value2,txt);

       fseek(txt,62,SEEK_SET);
       value = 1 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt);

       fseek(txt,66,SEEK_SET);
       value = 1 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt);
       
//tag6
       fseek(txt,70,SEEK_SET);
       value2 = 273 | (0<<8);
       fputc(value2,txt);

       fseek(txt,72,SEEK_SET);
       value2 = 4 | (0<<8);
       fputc(value2,txt);

       fseek(txt,74,SEEK_SET);
       value = 1 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt);

       fseek(txt,78,SEEK_SET);
       value = 170 | (0<<8) | (0<<16) | (0<<24); //8 + 2 + (13 * 12) + 4
       fputc(value,txt);

//tag7
       fseek(txt,82,SEEK_SET);
       value2 = 277 | (0<<8);
       fputc(value2,txt);

       fseek(txt,84,SEEK_SET);
       value2 = 3 | (0<<8);
       fputc(value2,txt);

       fseek(txt,86,SEEK_SET);
       value = 1 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt);

       fseek(txt,90,SEEK_SET);
       value = 1 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt);

//tag8
       fseek(txt,94,SEEK_SET);
       value2 = 278 | (0<<8);
       fputc(value2,txt);

       fseek(txt,96,SEEK_SET);
       value2 = 3 | (0<<8);
       fputc(value2,txt);

       fseek(txt,98,SEEK_SET);
       value = 1 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt);

       fseek(txt,102,SEEK_SET);
       value = 128 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt);
        
//tag9
       fseek(txt,106,SEEK_SET);
       value2 = 279 | (0<<8);
       fputc(value2,txt);

       fseek(txt,108,SEEK_SET);
       value2 = 4 | (0<<8);
       fputc(value2,txt);

       fseek(txt,110,SEEK_SET);
       value = 1 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt);

       fseek(txt,114,SEEK_SET);
       value = 0 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt); 

//tag10
       fseek(txt,118,SEEK_SET);
       value2 = 282 | (0<<8);
       fputc(value2,txt);

       fseek(txt,120,SEEK_SET);
       value2 = 5 | (0<<8);
       fputc(value2,txt);

       fseek(txt,122,SEEK_SET);
       value2 = 1 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value2,txt);

       fseek(txt,126,SEEK_SET);
       value = 200 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt); 

//tag11
       fseek(txt,130,SEEK_SET);
       value2 = 283 | (0<<8);
       fputc(value2,txt);

       fseek(txt,132,SEEK_SET);
       value2 = 5 | (0<<8);
       fputc(value2,txt);

       fseek(txt,134,SEEK_SET);
       value = 1 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt);

       fseek(txt,138,SEEK_SET);
       value = 193 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt); 

//tag12
       fseek(txt,142,SEEK_SET);
       value2 = 284 | (0<<8);
       fputc(value2,txt);

       fseek(txt,144,SEEK_SET);
       value2 = 3 | (0<<8);
       fputc(value2,txt);

       fseek(txt,146,SEEK_SET);
       value = 1 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt);

       fseek(txt,150,SEEK_SET);
       value = 1 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt); 

//tag13
       fseek(txt,154,SEEK_SET);
       value2 = 296 | (0<<8);
       fputc(value2,txt);

       fseek(txt,156,SEEK_SET);
       value2 = 3 | (0<<8);
       fputc(value2,txt);

       fseek(txt,158,SEEK_SET);
       value = 1 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt);

       fseek(txt,162,SEEK_SET);
       value = 2 | (0<<8) | (0<<16) | (0<<24); 
       fputc(value,txt); 

    }
    fseek(txt,166,SEEK_SET);
    unsigned int value3 = 0 | (0<<8) | (0<<16) | (0<<24); 
    fputc(value3,txt); 

    fseek(txt,170,SEEK_SET);
    fputc(EOF,txt);
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