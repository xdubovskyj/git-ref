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
     int index=0;
     char *e;
     e=pole2;
     if(p==NULL){
        printf("Sprava sa nenacitala\n");
        return 0; 
        }  
     for (index=0;index<VELKOSTPOLA;index++){
         *e=pole[index];
         if ((pole[index]>64&&pole[index]<91)||(pole[index]>96&&pole[index]<123)){
           if(pole[index]>96&&pole[index]<123){
           *e=pole[index]-32;                            
           }
           e++;                        
         }
         if (pole[index] == NULL || pole[index] == EOF) {
                      break;
         }
     }
     return 1;
     }

void vypisuprava (char pole2[VELKOSTPOLA], int boloupravene){
     switch(boloupravene){
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

void sifra(char pole2[VELKOSTPOLA], int boloupravene){
     int n,t;
     char *z, *r, pele2[VELKOSTPOLA];
     if(boloupravene==0){
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
  int boloupravene=0;
  
  while(x=getchar()){
  switch(x){
    case 'n':
         p = nacitanie(p, pole);
         break;
    case 'v':
         vypis(p, pole);
         break;
    case 'u':
         boloupravene=uprava(pole, pole2,p);
         break;
    case 's':
         vypisuprava(pole2, boloupravene);
         break;
    case 'd':
         vypisdlzka(p);
         break;
    case 'h':
         histogram(pole2, boloupravene);
         break;
    case 'c': 
         sifra(pole2, boloupravene);
         break;
    case 'k':
         zatvaranie(p);
         return 0;                  
  }                   
  }
  
  //kvôli Dev-C++
  //system("PAUSE");	
  return 0;
}
