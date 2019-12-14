#include <stdio.h>
#include <stdlib.h>
#include "histogram.h"
#include "histogram.c"

#define VELKOSTPOLA 1001
#define STREND '\0'
#define NOMSGEDITED "Nie je k dispozicii upravena sprava\n"

FILE* nacitanie(FILE *p, char pole[VELKOSTPOLA])  {
  
  p=fopen("sifra.txt", "r");  
  if(p==NULL){
    printf("subor nie je k dispozicii");
    return;
  }
    
   fgets(pole, VELKOSTPOLA, p);
      if(p==NULL){
        printf("Spravu sa nepodarilo nacitat");
        return; 
        }  
   rewind(p);
   return p;
}
void vypis(FILE *p, char pole[VELKOSTPOLA])  {
      if(p==NULL){
        printf("Sprava nie je nacitana\n");
        return; 
        }  
   printf("%s\n", pole);
}

int uprava(char pole[VELKOSTPOLA], char pole2[VELKOSTPOLA], FILE*p) {
     int q=0;
     char *e;
     e=pole2;
     if(p==NULL){
        printf("Sprava sa nenacitala\n");
        return 0; 
        }  
     for (q=0;q<VELKOSTPOLA;q++){
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

void vypisuprava (char pole2[VELKOSTPOLA], int isu){
     switch(isu){
       case 0: printf(NOMSGEDITED);
       break;
       case 1: printf("%s\n", pole2);
       break;
                 }
     } 
     
void vypisdlzka(FILE *p){
     int k, pocet=0, pele=0;
     char *l, pole3[VELKOSTPOLA];
     scanf("%d", &k);
     rewind(p);
     while((pocet=fscanf(p, "%s", pole3))>0){
     pele=0;
     l=pole3;
     while(*l!=STREND){
     pele++;
     l++;
     }
     if(pele==k){ printf("%s\n", pole3);
     }
      
     }
     rewind(p);
     }     

void sifra(char pole2[VELKOSTPOLA], int isu){
     int n,t;
     char *z, *r, pele2[VELKOSTPOLA];
     if(isu==0){
     printf(NOMSGEDITED);
     return;
     }
     scanf("%d", &n);
     z=pole2;
     r=pele2;
     while(*z!=STREND){
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
     
void zatvaranie(FILE *p){
     if (fclose(p)==EOF) {
     printf("subor sa nepodarilo zatvorit");
      }
      } 
      
int main(int argc, char *argv[])
{
  FILE *p=NULL;
  
  char x, pole[VELKOSTPOLA], pole2[VELKOSTPOLA];
  int isu=0;
  
  while(x=getchar()){
  switch(x){
    case 'n':
         p = nacitanie(p, pole);
         break;
    case 'v':
         vypis(p, pole);
         break;
    case 'u':
         isu=uprava(pole, pole2,p);
         break;
    case 's':
         vypisuprava(pole2, isu);
         break;
    case 'd':
         vypisdlzka(p);
         break;
    case 'h':
         histogram(pole2, isu);
         break;
    case 'c': 
         sifra(pole2, isu);
         break;
    case 'k':
         zatvaranie(p);
         return 0;                  
  }                   
  }
  
  //kv�li Dev-C++
  //system("PAUSE");	
  return 0;
}
