#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>
int a[7];
int p;
struct TIFF_header{
char FOR[2];
short int ARB;
int IFD_OFFSET;
};

struct DIR_header{
short int TAG;
short int Type;
int count;
int value;
};  
struct IFD_header{
    struct DIR_header *Taglist;
};
struct codewords{
    int number;
    char codew[25];
};

struct codewords terminalb[65];
struct codewords terminalw[65];
struct codewords makeupb[41];
struct codewords makeupw[41];

/*-------------------------------------------------------------------------
Function Name: readbterminal()

Description : Function to read the black terminal huffman codes into an structured array

Input Arguments: 

Return Value: A  global structured array 
---------------------------------------------------------------------------*/
void readbterminal(){
    
    FILE *txt;
    int r; char c[25];
    txt = fopen("C:/Users/sreen/Downloads/terminal_cw_b.txt","rb");
    if(txt == NULL){
        printf("Error in opening the file");
    }
    else{
        for(int i =0;i<64;i++){
            fscanf(txt,"%d",&r);
            fscanf(txt,"%s",&c);
            terminalb[i].number=r;
            strcpy(terminalb[i].codew,c);
        }
        /*
        for(int i=0;i<64;i++){
            printf("%d\t%s\n",terminalb[i].number,terminalb[i].codew);
        }
        */
    }
    fclose(txt);
}
/*-------------------------------------------------------------------------
Function Name: readwterminal()

Description : Function to read the white terminal huffman codes into an structured array

Input Arguments: 

Return Value: A  global structured array 
---------------------------------------------------------------------------*/
void readwterminal(){
    FILE *txt;
    int r; char c[25];
    txt = fopen("C:/Users/sreen/Downloads/terminal_cw_w.txt","rb");
    if(txt == NULL){
        printf("Error in opening the file");
    }
    else{
        for(int i =0;i<64;i++){
            fscanf(txt,"%d",&r);
            fscanf(txt,"%s",&c);
            terminalw[i].number=r;
            strcpy(terminalw[i].codew,c);
        }
        /*
        for(int i=0;i<64;i++){
            printf("%d\t%s\n",terminalw[i].number,terminalw[i].codew);
        }
        */
    }
    fclose(txt);
}
/*-------------------------------------------------------------------------
Function Name: readbmakeup()

Description : Function to read the black makeup huffman codes into an structured array

Input Arguments: 

Return Value: A  global structured array 
---------------------------------------------------------------------------*/
void readbmakeup(){
    FILE *txt;
    int r; char c[25];
    txt = fopen("C:/Users/sreen/Downloads/makeup_cw_b.txt","rb");
    if(txt == NULL){
        printf("Error in opening the file");
    }
    else{
        for(int i =0;i<40;i++){
            fscanf(txt,"%d",&r);
            fscanf(txt,"%s",&c);
            makeupb[i].number=r;
            strcpy(makeupb[i].codew,c);
        }
        /*
        for(int i=0;i<40;i++){
            printf("%d\t%s\n",makeupb[i].number,makeupb[i].codew);
        }*/
    }
    fclose(txt);
}
/*-------------------------------------------------------------------------
Function Name: readwmakeup()

Description : Function to read the black makeup huffman codes into an structured array

Input Arguments: 

Return Value: A  global structured array 
---------------------------------------------------------------------------*/
void readwmakeup(){
    FILE *txt;
    int r; char c[25];
    txt = fopen("C:/Users/sreen/Downloads/makeup_cw_w.txt","rb");
    if(txt == NULL){
        printf("Error in opening the file");
    }
    else{
        for(int i =0;i<40;i++){
            fscanf(txt,"%d",&r);
            fscanf(txt,"%s",&c);
            makeupw[i].number=r;
            strcpy(makeupw[i].codew,c);
        }
        /*
        for(int i=0;i<40;i++){
            printf("%d\t%s\n",makeupw[i].number,makeupw[i].codew);
        }
        */
    }
    fclose(txt);
}
char putsss[25];
/*-------------------------------------------------------------------------
Function Name:printandwrite() 

Description : This function is used to write the huffman codes into a desired file using the csum,
temp(character), and txt(writing File pointer)

Input Arguments: csum(sum of the rle count),temp(character), and txt(writing File pointer)

Return Value: None
---------------------------------------------------------------------------*/
void printandwrite(int csum,int temp,FILE* txt){
    //printf("%d->%d\t",temp,csum);
    if(temp == 0){
        if(csum <=63){
            fputs(terminalw[csum].codew,txt);

        }
        else{
            if(csum%64==0){
                fputs(makeupw[(csum/64)-1].codew,txt);
                fputs(terminalw[0].codew,txt);
            }
            else{
                fputs(makeupw[(csum/64)-1].codew,txt);
                fputs(terminalw[(csum%64)].codew,txt);
            }

        }


    }
    else{
        if(csum <=63){
            fputs(terminalb[csum].codew,txt);

        }
        else{
            if(csum%64==0){
                fputs(makeupb[(csum/64)-1].codew,txt);
                fputs(terminalb[0].codew,txt);
            }
            else{
                fputs(makeupb[(csum/64)-1].codew,txt);
                fputs(terminalb[(csum%64)].codew,txt);
            }

        }

    }
}
/*-------------------------------------------------------------------------
Function Name:makerle3() edit this and above

Description : This function is used to write the huffman codes into a desired file using the csum,
temp(character), and txt(writing File pointer)

Input Arguments: csum(sum of the rle count),temp(character), and txt(writing File pointer)

Return Value: None
---------------------------------------------------------------------------*/
void makerle3(){
    FILE *txt,*ftr;
    char c,q[]="0000000000000001",e[]="000000000001";
    int  sum =0,y=1,csum=0,count =1800,width;
    int temp =-1,ones=1;
    ftr = fopen("D:/FINAL YEAR PROJECT/sample_bin_uc11.txt","rb");
    txt = fopen("D:/FINAL YEAR PROJECT/work/rled3.txt","wb");
    if(ftr == NULL){
        printf("Error in opening the file");
    }
    else{
        fputs(q,txt);
        //fputc('\n',txt);
        while((c=fgetc(ftr)) !=EOF){
            c = c-'0';
            if(c<0){
                continue;
            }
            if(ones==1){
                ones = 0;
                if(c!=0){
                    printf("0->0\t");
                    fputs(terminalw[0].codew,txt);

                }
                //csum = csum+1;
                temp = c;
            }
            else
            {
                if(c == temp && csum+sum<=1726){
                    csum = csum+1;
                }
                else
                {
                    
                    csum = csum+1;
                    printandwrite(csum,temp,txt);
                    temp = c;
                    if(!(csum+sum<=1727)){
                        sum = 0;
                        csum =0;
                        fputc('\n',txt);
                    }
                    sum = sum + csum;
                    csum =0;
                }
            }
            

        }
        csum = csum+1;
        printandwrite(csum,temp,txt);
          
        
    }
    fclose(txt);
    fclose(ftr);

}
char d[50];
void makeeols(int sum,FILE* txt){
    char c,q[]="0000000000000001",e[]="000000000001",z[]="000000000001";
    int n=0;
    sum = sum-1;
    if(sum%8==0){
        fputs(q,txt);
    }
    else
    {
        n = sum%8;
        //printf("%d\n",n);
        if(n==4){
            fputs(e,txt);
            
        }
        else
        {
            switch(n) {
                case 1 :
                    fputc('0',txt);
                    fputc('0',txt);
                    fputc('0',txt);
                    fputs(e,txt);
                    break;
                case 2 :
                    fputc('0',txt);
                    fputc('0',txt);
                    fputs(e,txt);
                    break;
                case 3 :
                    fputc('0',txt);
                    fputs(e,txt);
                    break;
                case 5 :
                    fputc('0',txt);
                    fputc('0',txt);
                    fputc('0',txt);
                    fputs(q,txt);
                    break;
                case 6 :
                    fputc('0',txt);
                    fputc('0',txt);
                    fputs(q,txt);
                    break;
                case 7 :
                    fputc('0',txt);
                    fputs(q,txt);
                    break;
            }
        }
    }

}
void byteboundaryfixing()
{
    FILE *txt,*ftr;
    char c,q[]="0000000000000001",e[]="000000000001",z[]="000000000001",r=0,t=1;
    int sum=0,p=0,n=0;
    ftr = fopen("D:/FINAL YEAR PROJECT/work/rled3.txt","rb");
    txt = fopen("D:/FINAL YEAR PROJECT/work/edittedcode1.txt","wb");
    if(ftr == NULL){
        printf("Error in opening the file");
    }
    else
    {
        while((c=fgetc(ftr)) !=EOF){
            c= c-'0';
            sum = sum+1;
            //printf("%d",c);
            if(c==-38){
                makeeols(sum,txt);
                sum =0;
            }
            if(c==0){
                fputc('0',txt);
            }
            else
            {
                if(c==1)
                {
                    fputc('1',txt);
                }
            }
        }
        printf("%d",sum);
        makeeols(sum+1,txt);
    }
    for(int i=0;i<5;i++){
        fputs(e,txt);
    }
    fclose(txt);
    fclose(ftr);
}
int power(int exponent)
{
    int result=1;
    for (exponent; exponent>0; exponent--)
        {
        result = result * 2;
        }
    return result;
}
void maketiff(){
    FILE *txt,*ptr;
    char c;
    char one = 255;
    char zero = 0;
    int sum = 0,num=1,m=0;
    
    //txt=fopen("D:/FINAL YEAR PROJECT/maketiffer2.tiff","wb");
    txt=fopen("D:/FINAL YEAR PROJECT/packingtiff.tiff","wb");
    //FILE *fp = fopen("C:/Users/sreen/Downloads/SampleUncompressed.tiff","rb");
    //ptr=fopen("D:/FINAL YEAR PROJECT/work/mod_cmp_1.5d_3.txt","rb");
    //ptr=fopen("D:/FINAL YEAR PROJECT/work/mod_cmp_1.5d_1.txt","rb");
    ptr=fopen("D:/FINAL YEAR PROJECT/work/edittedcode1.txt","rb");
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
        struct DIR_header tags[15] ={ {254,4,1,2},{255,3,1,3},{256,3,1,1728},{257,3,1,2707},
        {258,3,1,1},{259,3,1,3},{262,3,1,0},{273,4,1,240},{278,3,1,2707},{279,4,1,690748},
        {274,3,1,1},{277,3,1,1},{292,4,1,4},{284,3,1,1},{296,3,1,2}};
        long d[1] ={6912};
        long b[1] ={216};

        fseek(txt,10,SEEK_SET);
        fwrite(tags, sizeof(tags), 1, txt);
        fseek(txt,190,SEEK_SET);

        //next ifd offset
        int value3 = 0 | (0<<8) | (0<<16) | (0<<24); 
        fputc(value3,txt);

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
        else{
            while ((c = fgetc(ptr)) != EOF)
            {   
                ///p++;
                fseek(ptr,8*m,SEEK_SET);
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
                //printf("\n%d\n",sum);
                fputc(sum,txt);
                sum=0;
            }
        }
        p+=8;
        printf("%d",p);
        fseek(txt,240+p,SEEK_SET);
        fputc(EOF,txt);
       //value2 = 13 | (0<<8);// number of ifd entries
       //fputc(value2,txt);
    }
       fclose(txt);
       fclose(ptr);




}
void opentifffile(){
    short int NumberofDirEntries;
    int i=0,StripsInImage,pixels;
    long *array,*barray;
    int Nextoffset;
    int minimunifd=1,k=0;
    long data1,data2;
    int Imagelength,Rowsperstrip,Stripoffset,Stripoffsetcount,StripBytecounts,StripoffsetType;
    int StripBytecountType,StripBytecountscount,ImageWidth;
    char c;
    FILE *txt;
    txt=fopen("D:/FINAL YEAR PROJECT/sample_bin_uc12.txt","wb");
    struct TIFF_header Tiffheader;
    struct IFD_header Ifdheader;


    //FILE *fp = fopen("D:/FINAL YEAR PROJECT/work/faximage_aTw5.tif","rb");
    //D:/FINAL YEAR PROJECT/maketiff4.tiff
    //D:/FINAL YEAR PROJECT/maketiff45678.tiff
    FILE *fp = fopen("C:/Users/sreen/Downloads/SampleUncompressed.tiff","rb");
    //FILE *fp = fopen("D:/FINAL YEAR PROJECT/maketiffer3.tiff","rb");
    //FILE *fp = fopen("D:/FINAL YEAR PROJECT/maketiff45678.tiff","rb");
    printf("\n----------------------TIFF FILE HEADER--------------------------\n\n");
    fread(&Tiffheader,sizeof(struct TIFF_header),1,fp);
    printf("Format: %c%c \n",Tiffheader.FOR[0],Tiffheader.FOR[1]);
    printf("Arbitary Value: %d\n",Tiffheader.ARB);
    printf("IFD OFFSET: %d \n",Tiffheader.IFD_OFFSET);

    while(minimunifd){


    printf("\n-------------------------IFD HEADER-----------------------------\n\n");
    fseek(fp,Tiffheader.IFD_OFFSET, SEEK_SET);
    fread(&NumberofDirEntries,sizeof(short int),1,fp);
    printf("The Number of Directories in the File is: %d\n",NumberofDirEntries);


    Ifdheader.Taglist = (struct DIR_header*)malloc(NumberofDirEntries*sizeof(struct DIR_header));
    for(i=0;i<NumberofDirEntries;i++){
    fread(&Ifdheader.Taglist[i],sizeof(struct DIR_header),1,fp);
    }
    
    printf("\n-------------------------DIRECTORIES-----------------------------\n\n");
    for (i=0;i<NumberofDirEntries;i++ ){
    //fread(&Ifdheader,NumberofDirEntries*sizeof(struct DIR_header),1,fp);
    
    printf("%d. Tag:  %d\n",i+1,Ifdheader.Taglist[i].TAG);
    printf("%d. Value:%d\n\n\n",i+1,Ifdheader.Taglist[i].value);
    if(Ifdheader.Taglist[i].TAG==257){
        Imagelength = Ifdheader.Taglist[i].value;
    }
    if(Ifdheader.Taglist[i].TAG==278){
        Rowsperstrip = Ifdheader.Taglist[i].value;
    }
     if(Ifdheader.Taglist[i].TAG==256){
        ImageWidth= Ifdheader.Taglist[i].value;
    }
    if(Ifdheader.Taglist[i].TAG==273){
        Stripoffset = Ifdheader.Taglist[i].value;
        StripoffsetType = Ifdheader.Taglist[i].Type;
        Stripoffsetcount = Ifdheader.Taglist[i].count;
    }
    if(Ifdheader.Taglist[i].TAG==279){
        StripBytecounts = Ifdheader.Taglist[i].value;
        StripBytecountType = Ifdheader.Taglist[i].Type;
        StripBytecountscount = Ifdheader.Taglist[i].count;
    }
    

    }
    fread(&Nextoffset,sizeof(int),1,fp);
    printf("Next Offset: %d\n\n",Nextoffset);

    minimunifd = Nextoffset;
    Tiffheader.IFD_OFFSET = Nextoffset;


    StripsInImage = floor((Imagelength +(Rowsperstrip  - 1)) / Rowsperstrip);
    printf("StripsInImage: %d\n",StripsInImage);



    if(StripoffsetType*Stripoffsetcount >=5){
        fseek(fp,Stripoffset,SEEK_SET);
        fread(&data1,sizeof(long),1,fp);
        printf("\n-------------------------OFFSET VALUES-----------------------------\n\n");
        printf("\nThe value of is:\n");
        array =(long*)malloc(Stripoffsetcount*sizeof(long));
        array[0]=data1;

        for(i=1;i<Stripoffsetcount;i++){
            fread(&data1,sizeof(long),1,fp);
            array[i] =  data1;
        }
         for(i=0;i<Stripoffsetcount;i++){
             printf("%d\t",array[i]);
        }

    }

    if(StripBytecountscount*StripBytecountType>=5){
        // configure next line 
        fseek(fp,StripBytecounts,SEEK_SET);
        fread(&data2,sizeof(long),1,fp);
        printf("\n\n\n-------------------------OFFSET BYTE COUNT VALUES-----------------------------\n");
        printf("\n\nThe value of is bytes:\n");
        barray =(long*)malloc(Stripoffsetcount*sizeof(long));
        barray[0] = data2;
        for(i=1;i<Stripoffsetcount;i++){
            fread(&data2,sizeof(long),1,fp);
            barray[i] =  data2;
        }
        for(i=0;i<Stripoffsetcount;i++){
            printf("%d\t",barray[i]);
            }
    }


    if(Stripoffsetcount>2){
        int width = 1;
        for(int i=0;i<Stripoffsetcount;i++){
            if(i){
                fputc('\n',txt);
            }
            pixels=0;
            width =1;
            fseek(fp,array[i],SEEK_SET);
            while(pixels!=barray[i]){
                pixels++;
                if((width)%1729==0){
                    fputc('\n',txt);
                    width = 1;
                }
            width++;
            fread(&c,sizeof(char),1,fp);
            if(c&&1 == 1)
                {
                    fputc('0',txt);
                    //fputc('1',txt);//before the changes
                }
            else
                {
                    fputc('1',txt);
                    //fputc('0',txt);//before the changes
                }
            }
        }
        k=1;
    }
    else
    {
        int width = 1;
        pixels =0;
        fseek(fp,Stripoffset,SEEK_SET);
        while(pixels!=StripBytecounts){
            pixels++;
            if(width%(ImageWidth+1)==0){
                //fputc('\n',txt); // add this line if u wat it to be in lines
                
                width = 1;

            }
            width++;
            fread(&c,sizeof(char),1,fp);
            if(c&&1 == 1)
            {
                fputc('1',txt);
            }
            else
            {
                fputc('0',txt);
            }
        }
        k=1;
    }



    }

    if(k){
        printf("\n\n\n\n\n\t\t\t\t~~~~~~~ Successfully Written to sample_bin_uc6.txt ~~~~~~~~\n\n\n");
    }
    else{
        printf("\n\n\n\n\n\t\t\t\t~~~~~~~~ Error Couldn't Write the Extracted data ~~~~~~~\n\n\n");
    }
    fclose(fp);
    fclose(txt);




    

} 



int main(){
    opentifffile();
    readbterminal();
    //printf("%d\t%s\n",terminalb[0].number,terminalb[0].codew);
    readwterminal();
    //printf("%d\t%s\n",terminalw[0].number,terminalw[0].codew);
    readbmakeup();
    //printf("%d\t%s\n",makeupb[26].number,makeupb[26].codew);
    readwmakeup();
    //printf("%d\t%s\n",makeupw[1].number,makeupw[1].codew);
    makerle3();
    byteboundaryfixing();
    maketiff();
    printf("TIFF FILE HAS BEEN SUCCESSFULLY CREATED");
}
