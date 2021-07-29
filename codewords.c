#include<stdio.h>


struct header{
    int number;
    long codeword;
};
struct header terminalb[65];

void readbterminal(){
    FILE *txt;
    int n;
    char c;
    long d,f;
    int p=0,m=0;
    int flag =63;
    txt = fopen("C:/Users/sreen/Downloads/terminal_cw_b.txt","rb");
    while((c=fgetc(txt))!=EOF && flag!=0){
        m=0;
        while (c!=' '){
            terminalb[p].number[m++] = c-'0';
           // printf("%d",c-'0');
            c = fgetc(txt);
            m++;
        }
       // printf("\t");
        c = fgetc(txt);
        while (c!=32)
        {
            //terminalb[p].codeword = c;
           // printf("%d",c-'0');
            c = fgetc(txt);
        }
        c = fgetc(txt);
        c = fgetc(txt);
        //printf("\n");
        flag--;
        p++;
    }

    
    for(int i=0;i<p;i++){
        printf("%d\t\n",terminalb[i].number[0]);
    }
}

int main(){
    readbterminal();
    /*
    for(int i=0;i<5;i++){
        printf("%d \t\t\t %d",terminalb[i].number,terminalb[i].codeword);
    }*/
}