#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int length;
int i;
int sum_L;
int sum_w;
int sum_s;

int main(){

    string text = get_string("Text: ");




    return 0;
}

int count_letters(string text ){

    length=strlen(text);

    for (i=0; i < length ; i++)
    {

   if(isalpha(text[i]){
    sum_L=sum_L+1;

   }
   else if(text[i]==' '){

    sum_w=sum_w+1;
   }
   else{

    sum_s=sum_s+1;
   }

    }

}
