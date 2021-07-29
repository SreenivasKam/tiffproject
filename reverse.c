#include<stdio.h>
int a[10],b[10];

int power(int exponent)
{
    int result=1;
    for (exponent; exponent>0; exponent--)
        {
        result = result * 2;
        }
    return result;
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
    
    for(int k=0;k<=7;k++){
        printf("%d",a[k]);
        b[7-k] = a[k];
    }
    printf("\n");
     for(int k=0;k<=7;k++){
        printf("%d",b[k]);
        
    }
}
int main()
{
    FILE *txt;
    char c;
    int sum = 0,num=1,m=0;
    txt=fopen("D:/FINAL YEAR PROJECT/sample_bin_uc5.txt","rb");
    while ((c = fgetc(txt))!= EOF)
     {
        fseek(txt,8*m,SEEK_SET);
        m++;
        for(int k=7;k>=0;k--){
            fread(&c,sizeof(char),1,txt);
            //printf("%d",c-48);
            //printf("%d\t",power(k));
            num = (c-48)*power(k);
            sum +=num;
            printf("%d\t",c-48);
            
        }
        //printf("\n");
        fseek(txt,8*(m+1),SEEK_SET);
        printf("\n%d\n",sum);
        sum=0;
    }

    
    
    for(int k=0;k<=7;k++){
        printf("%d",b[k]);
        
    }
    

}
