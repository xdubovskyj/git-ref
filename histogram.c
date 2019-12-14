#include <stdio.h>
#include <stdlib.h>

#define VELKOSTPOLA 1001
#define STREND '\0'
#define NOMSGEDITED "Nie je k dispozicii upravena sprava\n"

void histogramprint(float pocty[26], int max) {
     int i, j;
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
     }
     
void histogramlegenda() {
     int j;
     for (j=0;j<26;j++){
           printf("%c", j+65);
           }
     printf("\n");
     }
     
int histogrammax(float pocty[26], int celok) {
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
     
     return max;
     }

void histogram(char pole2[VELKOSTPOLA], int isu){
     float pocty[26] = {0};
     int celok=0;
     if(isu==0){
     printf(NOMSGEDITED);
     return;
     }
     char *g;
     g=pole2;
     while(*g!=STREND){
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
     
     int max = histogrammax(pocty, celok);
     histogramprint(pocty, max);
     histogramlegenda();
     }
     
