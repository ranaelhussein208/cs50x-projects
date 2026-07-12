#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include  <math.h>

int length;
int i;
int sum_L;
int sum_w;
int sum_s;
float L;
float S;
float index;
int r_index;

typedef struct
{
   float letters;
   float words;
   float sentences;
}
Counts;

Counts LWS;
Counts count_LWS(string text);

int main(){

    string text = get_string("Text: ");

   LWS=count_LWS(text);

    //printf("Letters: %f\n", LWS.letters);
   //printf("Words: %f\n", LWS.words);
    //printf("Sentences: %f\n", LWS.sentences);

    L = (LWS.letters/ LWS.words) * 100;
    S = (LWS.sentences/ LWS.words) * 100;

    index = (0.0588 * L) - (0.296 * S) - 15.8;
     //printf("index: %f\n", index);
  r_index=round(index);


 if (r_index < 1){

    printf("Before Grade 1\n");

 }
else if (r_index >= 1 && r_index< 16 ){

    printf("Grade %d\n",r_index);
}
else if(r_index > 16){

printf("Grade 16+\n");

}
    return 0;
}

Counts count_LWS(string text ){

    length=strlen(text);

    for (i=0; i < length ; i++)
    {

   if(isalpha(text[i]))
   {
    LWS.letters=LWS.letters+1;

   }
   else if(text[i]==' ')
   {

    LWS.words=LWS.words+1;
   }
   else if (text[i]=='.' ||text[i]=='!' || text[i]=='?')
   {

    LWS.sentences=LWS.sentences+1;

   }

    }
LWS.words=LWS.words+1;
return LWS;

}
