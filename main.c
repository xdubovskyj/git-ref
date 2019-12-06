#include <stdio.h>
#include <stdlib.h>

FILE* n(FILE *p, char pole[1000])  {
  
  p=fopen("sifra.txt", "r");  
  if(p==NULL){
    printf("subor nie je k dispozicii");
    return;
  }
  
   //fscanf(p,"%s", pole);  
   fgets(pole, 1000, p);
      if(p==NULL){
        printf("Spravu sa nepodarilo nacitat");
        return; 
        }  
   //printf("%s", pole);
   rewind(p);
   return p;
}
void v(FILE *p, char pole[1000])  {
      if(p==NULL){
        printf("Sprava nie je nacitana\n");
        return; 
        }  
   printf("%s\n", pole);
}

int u(char pole[1000], char pole2[1000], FILE*p) {
     int q=0;
     char *e;
     e=pole2;
     /*while(1){
       *e=pole[q];
       if ((*e>64&&*e<91)||(*e>96&&*e<123)){
           printf("%c",*e); 
           e++;                     
         }
         q++;
     }*/
     if(p==NULL){
        printf("Sprava nie je nacitana\n");
        return 0; 
        }  
     for (q=0;q<1000;q++){
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
     //printf("%s", pole2);
     return 1;
     }

void s (char pole2[1000], int isu){
     if(isu==0){
     printf("Nie je k dispozicii upravena sprava\n");
     }
     if(isu==1){
     printf("%s\n", pole2);
     }
     } 
     
void d(FILE *p){
     int k;
     int pocet=0;
     int pele=0;
     char *l;
     char pole3[1000];
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

void c(char pole2[1000], int isu){
     int n;
     int t;
     char *z;
     char *r;
     char pele2[1000];
     if(isu==0){
     printf("Nie je k dispozicii upravena sprava\n");
     return;
     }
     scanf("%d", &n);
     z=pole2;
     r=pele2;
     while(*z!='\0'){
     if(*z-n<=65){
     t=64-(*z-n);
     *r=90-t;
     }
     else{*r=*z-n;}
     z++;
     r++;
     }
     printf("%s\n", pele2);
     }

void h(char pole2[1000], int isu){
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
     //printf("%c", *g);
       if(*g=='A'){pocty[0]++;}   
       if(*g=='B'){pocty[1]++;} 
       if(*g=='C'){pocty[2]++;} 
       if(*g=='D'){pocty[3]++;} 
       if(*g=='E'){pocty[4]++;} 
       if(*g=='F'){pocty[5]++;} 
       if(*g=='G'){pocty[6]++;} 
       if(*g=='H'){pocty[7]++;} 
       if(*g=='I'){pocty[8]++;} 
       if(*g=='J'){pocty[9]++;} 
       if(*g=='K'){pocty[10]++;} 
       if(*g=='L'){pocty[11]++;} 
       if(*g=='M'){pocty[12]++;} 
       if(*g=='N'){pocty[13]++;} 
       if(*g=='O'){pocty[14]++;} 
       if(*g=='P'){pocty[15]++;} 
       if(*g=='Q'){pocty[16]++;} 
       if(*g=='R'){pocty[17]++;} 
       if(*g=='S'){pocty[18]++;} 
       if(*g=='T'){pocty[19]++;} 
       if(*g=='U'){pocty[20]++;} 
       if(*g=='V'){pocty[21]++;} 
       if(*g=='W'){pocty[22]++;} 
       if(*g=='X'){pocty[23]++;} 
       if(*g=='Y'){pocty[24]++;} 
       if(*g=='Z'){pocty[25]++;}           
                     
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
    //printf("%.0f %d", pocty[0], celok);
     
     }
     
int main(int argc, char *argv[])
{
  FILE *p=NULL;
  
  char x;
  char pole[1000];
  char pole2[1000];
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
  }                   
    if(x=='k'){
      if (fclose(p)==EOF) {
      printf("subor sa nepodarilo zatvorit");
      }
      break;         
    }
  }
  
  //kvôli Dev-C++
  //system("PAUSE");	
  return 0;
}
