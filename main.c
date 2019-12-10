#include <stdio.h>
#include <stdlib.h>

FILE* n(FILE *p, char pole[1001])  {
  
  p=fopen("sifra.txt", "r");  
  if(p==NULL){
    printf("subor nie je k dispozicii");
    return;
  }
    
   fgets(pole, 1001, p);
      if(p==NULL){
        printf("Spravu sa nepodarilo nacitat");
        return; 
        }  
   rewind(p);
   return p;
}
void v(FILE *p, char pole[1001])  {
      if(p==NULL){
        printf("Sprava nie je nacitana\n");
        return; 
        }  
   printf("%s\n", pole);
}

int u(char pole[1001], char pole2[1001], FILE*p) {
     int q=0;
     char *e;
     e=pole2;
     if(p==NULL){
        printf("Sprava sa nenacitala\n");
        return 0; 
        }  
     for (q=0;q<1001;q++){
         *e=pole[q];
         if ((pole[q]>64&&pole[q]<91)||(pole[q]>96&&pole[q]<123)){
           if(pole[q]>96&&pole[q]<123){
           *e=pole[q]-32;                            
           }
           e++;                        
         }
         if (pole[q] == NULL || pole[q] == EOF) {
                      break;
         }
     }
     return 1;
     }

void s (char pole2[1001], int isu){
     switch(isu){
       case 0: printf("Nie je k dispozicii upravena sprava\n");
       break;
       case 1: printf("%s\n", pole2);
       break;
                 }
     } 
     
void d(FILE *p){
     int k, pocet=0, pele=0;
     char *l, pole3[1001];
     scanf("%d", &k);
     rewind(p);
     while((pocet=fscanf(p, "%s", pole3))>0){
     pele=0;
     l=pole3;
     while(*l!='\0'){
     pele++;
     l++;
     }
     if(pele==k){ printf("%s\n", pole3);
     }
      
     }
     rewind(p);
     }     

void c(char pole2[1001], int isu){
     int n,t;
     char *z, *r, pele2[1001];
     if(isu==0){
     printf("Nie je k dispozicii upravena sprava\n");
     return;
     }
     scanf("%d", &n);
     z=pole2;
     r=pele2;
     while(*z!='\0'){
     if(*z-n<=65){
     t=65-(*z-n);
     *r=90-t;
     }
     else{*r=*z-n;}
     z++;
     r++;
     }
     printf("%s\n", pele2);
     }

void h(char pole2[1001], int isu){
     float pocty[26] = {0};
     int celok=0;
     if(isu==0){
     printf("Nie je k dispozicii upravena sprava\n");
     return;
     }
     char *g;

     
     g=pole2;
     while(*g!='\0'){
     celok++;
      switch(*g){
        case 'A':
             pocty[0]++;
             break;
        case 'B':
             pocty[1]++;
             break;
        case 'C':
             pocty[2]++;
             break;
        case 'D':
             pocty[3]++;
             break;
        case 'E':
             pocty[4]++;
             break;
        case 'F':
             pocty[5]++;
             break;
        case 'G':
             pocty[6]++;
             break;
        case 'H':
             pocty[7]++;
             break;
        case 'I':
             pocty[8]++;
             break;
        case 'J':
             pocty[9]++;
             break;
        case 'K':
             pocty[10]++;
             break;
        case 'L':
             pocty[11]++;
             break;
        case 'M':
             pocty[12]++;
             break;
        case 'N':
             pocty[13]++;
             break;
        case 'O':
             pocty[14]++;
             break;
        case 'P':
             pocty[15]++;
             break;
        case 'Q':
             pocty[16]++;
             break;
        case 'R':
             pocty[17]++;
             break;
        case 'S':
             pocty[18]++;
             break;
        case 'T':
             pocty[19]++;
             break;
        case 'U':
             pocty[20]++;
             break;
        case 'V':
             pocty[21]++;
             break;
        case 'W':
             pocty[22]++;
             break;
        case 'X':
             pocty[23]++;
             break;
        case 'Y':
             pocty[24]++;
             break;
        case 'Z':
             pocty[25]++;
             break;
                 }               
     g++;
     }
     
     int i, j, max=0;
     for (i=0;i<26;i++){
         pocty[i]=(pocty[i]/celok)*100;

         if (pocty[i]<=10&&pocty[i]>0){pocty[i]=1;}
         if (pocty[i]<=20&&pocty[i]>10){pocty[i]=2;}
         if (pocty[i]<=30&&pocty[i]>20){pocty[i]=3;}
         if (pocty[i]<=40&&pocty[i]>30){pocty[i]=4;}
         if (pocty[i]<=50&&pocty[i]>40){pocty[i]=5;}
         if (pocty[i]<=60&&pocty[i]>50){pocty[i]=6;}
         if (pocty[i]<=70&&pocty[i]>60){pocty[i]=7;}
         if (pocty[i]<=80&&pocty[i]>70){pocty[i]=8;}
         if (pocty[i]<=90&&pocty[i]>80){pocty[i]=9;}
         if (pocty[i]<=100&&pocty[i]>90){pocty[i]=10;}
         
         if ( pocty[i] > max ) {
           max = pocty[i];
         }
     }
     
     for(i=max;i>0;i--){
       for (j=0;j<26;j++){
           if (pocty[j]>=i){
             printf("*");
           } else {
             printf(" ");
           }
           }
           printf("\n");
     }
     
     for (j=0;j<26;j++){
           printf("%c", j+65);
           }
     printf("\n");
     
     }

void k(FILE *p){
     if (fclose(p)==EOF) {
     printf("subor sa nepodarilo zatvorit");
      }} 
     
int main(int argc, char *argv[])
{
  FILE *p=NULL;
  
  char x, pole[1001], pole2[1001];
  int isu=0;
  
  while(x=getchar()){
  switch(x){
    case 'n':
         p = n(p, pole);
         break;
    case 'v':
         v(p, pole);
         break;
    case 'u':
         isu=u(pole, pole2,p);
         break;
    case 's':
         s(pole2, isu);
         break;
    case 'd':
         d(p);
         break;
    case 'h':
         h(pole2, isu);
         break;
    case 'c': 
         c(pole2, isu);
         break;
    case 'k':
         k(p);
         return 0;                  
  }                   
    /*if(x=='k'){
      if (fclose(p)==EOF) {
      printf("subor sa nepodarilo zatvorit");
      }
      break;       
    }*/
  }
  
  //kvôli Dev-C++
  //system("PAUSE");	
  return 0;
}
