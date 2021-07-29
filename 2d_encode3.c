#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>


////-------------------------------------Huffman Encoding---------------------------------------------------------------////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////Only search operations for 2d using hash tables////////////////////////////////////
typedef struct codewords
{
    int runlen;
    char cw[25];

}cw;

int capacity = 64;
int capacity_mu = 40;

cw *table_wt[64],*table_bt[64];
cw *table_wmu[40],*table_bmu[40];

char en_data_b[50];
char en_data_w[50];


void insert_hashtable(int key,char *data,int table,int ind) 
{
    cw *temp = (cw*) malloc(sizeof(cw));
    strcpy(temp->cw,data);  
    temp->runlen = key; 
   
    switch(table)
    {
        case 1: table_wt[ind] = temp; break;
        case 2: table_bt[ind] = temp; break;
        case 3: table_wmu[ind] = temp; break;
        case 4: table_bmu[ind] = temp; break;
    } 
}

void insert_values(char *filename,int table)
{
    int r; char c[25];
    char str[100];
    int temp_capacity;
    if (table == 1 || table == 2)
        temp_capacity = capacity;
    else
        temp_capacity = capacity_mu;
    
    FILE *ptr=fopen(filename,"r");

    if(ptr==NULL)
        printf("File does not exist!");
    else
    {
        for(int i=0;i<temp_capacity;i++)
        {
            fscanf(ptr,"%d",&r);
            fscanf(ptr,"%s",&c);
            insert_hashtable(r,c,table,i);
            fgets(str,100,ptr);
        }
    }
    fclose(ptr);
}

void terminal_cw_gen()
{
    char filename_w[]="terminating_cw_w.txt";
    char filename_b[]="terminating_cw_b.txt";
    
    
    insert_values(filename_w,1);
    insert_values(filename_b,2);
    //display();
}

void makeup_cw_gen()
{
    char filename_w[]="makeup_cw_w.txt";
    char filename_b[]="makeup_cw_b.txt";

    insert_values(filename_w,3);
    insert_values(filename_b,4);
    //display();
}

char* search_w(int key)
{
    //char en_data[50];
    int m,t;
    int i = 0;
   
    if (key > 63)
    {
        m = key/64;
        t = key%64;

        //printf("\n -   -   -   - %d -  -   -   -",m*64);
        //printf("\n -   -   -   - %d -  -   -   -",t);
        
        while(table_wmu[i]->runlen != m*64)
        {
            i = i+1;
        }
        //printf("\n -   -   -   - %s -  -   -   -",table_wmu[i]->cw);
        strcpy(en_data_w,table_wmu[i]->cw);
        i = 0;
        while(table_wt[i]->runlen != t)
        {
            i = i+1;
        }
        //printf("\n -   -   -   - %s -  -   -   -",table_wt[i]->cw);
        strcat(en_data_w,table_wt[i]->cw);
        //printf("\n Search output :  %s ",en_data_w);

    }
    else
    {
        while(table_wt[i]->runlen != key)
        {
            i = i+1;
        }
        //printf("\n -   -   -   - %s -  -   -   -",table_wt[i]->cw);
        strcpy(en_data_w,table_wt[i]->cw);
        //printf("\n Search output :  %s ",en_data_w);
    }
    return en_data_w;

}

char* search_b(int key)
{
    //char en_data_b[50];
    int m,t;
    int i = 0;
   
    if (key > 63)
    {
        m = key/64;
        t = key%64;

        //printf("\n -   -   -   - %d -  -   -   -",m*64);
        //printf("\n -   -   -   - %d -  -   -   -",t);
        
        while(table_bmu[i]->runlen != m*64)
        {
            i = i+1;
        }
        //printf("\n -   -   -   - %s -  -   -   -",table_wmu[i]->cw);
        strcpy(en_data_b,table_bmu[i]->cw);
        i = 0;
        while(table_bt[i]->runlen != t)
        {
            i = i+1;
        }
        //printf("\n -   -   -   - %s -  -   -   -",table_wt[i]->cw);
        strcat(en_data_b,table_bt[i]->cw);
        //printf("\n Search output :  %s ",en_data_b);
        
    }
    else
    {
        while(table_bt[i]->runlen != key)
        {
            i = i+1;
        }
        //printf("\n -   -   -   - %s -  -   -   -",table_wt[i]->cw);
        strcpy(en_data_b,table_bt[i]->cw);
        //printf("\n Search output :  %s ",en_data_b);
        
    }
    return en_data_b;
}

////--------------------------------------Global Initializations--------------------------------------------------------/////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char eol1[]="0000000000011";
char eol2[]="0000000000010";

const int line =1728;
const int c=1728;
const int r=2;

char original[]="original.txt";
char onefile[]="new.txt";
char outputfile[]="twoD_c_3.txt";

typedef struct assign{
    int a0,a1,a2,b1,b2;
    char val;

}assign;
void create_newfile()
{
    
    FILE* ptr=fopen(original,"r");
    FILE* fptr=fopen(onefile,"w");
  
    char c;
    
    char *str=(char*)malloc(sizeof(char)*1728);

    while(!feof(ptr))
    {
       
         c=fgetc(ptr);
         if(c!='\n')
              fputc(c,fptr);
    }

    fclose(fptr);
    fclose(ptr);
    
}

int maxi(int a0,int a1,int a2,int b1,int b2)
{
  int m=b2;
    if(b2<a2)
     m=a2;


  return m;

}

////------------------------------------Stores Elementd---------------------------------------------------------------////

//for making 2D array of coding and refrence lines
typedef struct data{

    char rect[2][1728];
   // int rectcount;

}data;

const int num=(2560/2);
data list[1280],clist[1280];
// inserts into the 2D array ie storing
void insert(char array[2][1728],int count)
{
    int i,j;
    //int r=2,c=line;

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
           list[count].rect[i][j]= array[i][j];/////*(array +i*c  +j);     //

    
    /*for(i=0;i<r;i++)
    { 
        printf("\n");
        for(j=0;j<c;j++)
           printf("%c ",list[count].rect[i][j]);
    }*/

}

//to get the lines from file
void getdata_file()   
{
    FILE *fptr=fopen(onefile,"r");
   // int c=line; //1728
   // int r=2;
    int i,j,k;
    char ch;
   // char *array=(char*)malloc(r*c*sizeof(char));       //2D array that stores the refrence line and coding line
    char array[2][1728];
    int count=0;
  for(k=0;k<num;k++)
 {        
         
               for(i=0;i<r;i++)
                 for(j=0;j<c;j++)
                  {
                     if(feof(fptr))
                          break;
                      ch=fgetc(fptr);
                     // *(array +i*c  +j)=ch;
                        array[i][j]=ch;
                  }

         /*   printf("\n-------------------------");

             for(i=0;i<r;i++)
                    {   
                         printf("\n");
                         for(j=0;j<c;j++)
                          {
                          // printf(" Refrence pair %d\n ",j);
                           printf("%c", *(array + i*c + j));
                        }
                          
                     }
            // fseek(fptr,-10,SEEK_CUR); */
             
             insert(array,count);
             count++;

    }
  fclose(fptr);

}

void copy()
{
  int k=0;
    while(k<num)
{
  
  for(int i=0;i<r;i++)
      {
         // printf("\n");
          for(int j=0;j<c;j++)
             list[k].rect[i][j]=clist[k].rect[i][j];
      }
    k++;
}

}

////------------------------------Coding Modes Fuctions------------------------/////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////--------------------------------------------------------------------------////////////////////////////////////////////////
FILE* passmode(FILE *ptr)
{
  const char p[]="0001 ,";
   
   fputs(p,ptr);
   
   return ptr;
   
}

FILE* verticalmode(FILE *ptr,int num)
{
   switch (num) 
   {

     case 0 :  fputs("1 ,",ptr);break;
     case 1 :  fputs("011 ,",ptr);break;
     case 2 :  fputs("000011 ,",ptr);break;
     case 3 :  fputs("0000011,",ptr);break;
     case -1:  fputs("010 ,",ptr);break;
     case -2:  fputs("000010,",ptr);break;
     case -3:  fputs("0000010 ,",ptr);break;

   }

   return ptr;

}

FILE* horizontalmode(FILE *ptr,int num1,int num2,char val)
{

  fputs("001,",ptr);

    
  if(val=='0')
  
  {
      
          fputs( search_b(num1),ptr);
          fputs(search_w(num2),ptr);
  }

  else
  
  {
          fputs( search_w(num1),ptr);
          fputs(search_b(num2),ptr);
  }


  
   return ptr;

}
//////////////////////-------------------------------------2 D ENCODING Subfunctions----------------/////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

assign assignment(int a,int n)
{
    int j,i,k,l;
    j=a;k=a;
    assign values;
    values.a0=a;
    char val_a=list[n].rect[1][a]; // 1 or 0
    char val_a1;
    while(j+1<line)
    {
        if(list[n].rect[1][j]!=val_a)
        {
            
             values.a1=j;
             val_a1=list[n].rect[1][j]; 
             for(i=j+1;i<line;i++)
                  if(list[n].rect[1][i]!=val_a1)
                      {  values.a2=i;
                         values.val=list[n].rect[1][i];  }
        }

       j++;

    }

   while(k<line)
   {
        if(val_a!=list[n].rect[0][k])
          {

              values.b1=k;
              for(l=k+1;l<line;l++)
                    if(list[n].rect[0][l]==val_a)
                            values.b2=l;
          }

   }
   



  return values;
}   

int check(int a0, int a1,int a2,int b1,int b2)
{
     if(b2<a1) 
         return 0;
     else if ((b1-a1)<=3)
         return 1;
     else
       return 2;

}

FILE* twoD(int k,FILE *ptr)
{
     // [0].rect is the coding line and refrence line 2D array
     // element is the 2D array
   // copy();
     //char array[2][1728];
  

   
     int mode,newa;
     int num,num1,num2;
     char val;
     int a0=0,a1,a2,b1,b2;
     assign values;
     printf("\n\nin function 2d\n\n");
{
   if(a0==0)
       values=assignment(a0,k);
          
    else
       values=assignment(newa,k);

          
          
          a0=values.a0;
          a1=values.a1;
          a2=values.a2;
          b1=values.b1;
          b2=values.b2;

          val=values.val;
          
          printf("\n-----------------------\n");

          printf("\n%d:  %d: %d:  %d  %d",a0,a1,a2,b1,b2);
          
          
          
           mode=check(a0,a1,a2,b1,b2);
           printf("\nmode :\t%d ",mode);

           printf("\n---------------------------\n");
       
     switch(mode) 

     {

     
      case 0 :{
                 ptr=passmode(ptr);
                 newa=b2;
                  break;
                }
      case 1:
               {
                  num=b1-a1;
                  ptr=verticalmode(ptr,num);
                  newa=a1;
              
                  break;
               }
      case 2:     
                {

                  num1=a1-a0;
                  num2=a2-a1;
                  ptr=horizontalmode(ptr,num1,num2,val);
                  newa=a2;
                  break;

                }
        default: fputs("Invalid mode",ptr);

     }

   
        a0=newa;
        
}
    

 return ptr;
}

//////////////////////////////////////////////// 2D ENCODING///////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void encode()
{
    FILE *fptr=fopen(outputfile,"w"); 
    int k=2;  
  //  while(k<num)
     {

      //fputs(eol1,fptr);
      //fptr = huffman(&list[k].rect[0][i],fptr); //
        fputs(eol2,fptr);
        fptr= twoD(k,fptr);
         //  k++;
        
        fputs("after 2d",fptr);
        printf("\n-----------------------\n");
        printf("\n%ld ",ftell(fptr));
     }

}


//// ------------------------------Main Finctions------------------------------////


int main()
{
     create_newfile();
     getdata_file();
    // copy();
  
     terminal_cw_gen();
     makeup_cw_gen();

   printf("here after base functions\n");
     int k=0,i;
   printf("In file");
    
//printing the 2D arrays   

while(k<num)
{
  printf("\n//////////////2D array %d//////////////\n",k+1);
  for(int i=0;i<r;i++)
      {
          printf("\n");
          for(int j=0;j<c;j++)
             printf("%c",list[k].rect[i][j]);
      }
    k++;
}
   
//printing the second array
 printf("\n//////////////////////done printing all elements/////////////////////////\n");

 for(i=0;i<r;i++)
      {
          printf("\n");
          for(int j=0;j<c;j++)
            { printf("%c",list[1].rect[i][j]);
              //printf("\n%d",j); 
              }
      }

printf("\n//////////////////////done printing 2/////////////////////////\n");


encode();
  return 0;

}


