#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct codewords{
    int number;
    char codew[25];
};
struct codewords terminalb[65];
struct codewords terminalw[65];
struct codewords makeupb[41];
struct codewords makeupw[41];
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

int main(){
    readbterminal();
    printf("%d\t%s\n",terminalb[63].number,terminalb[63].codew);
    readwterminal();
    printf("%d\t%s\n",terminalw[63].number,terminalw[63].codew);
    readbmakeup();
    printf("%d\t%s\n",makeupb[1].number,makeupb[1].codew);
    readwmakeup();
    printf("%d\t%s\n",makeupw[1].number,makeupw[1].codew);
    //makerle();
    /*
    for(int i=0;i<5;i++){
        printf("%d \t\t\t %d",terminalb[i].number,terminalb[i].codeword);
    }*/
}