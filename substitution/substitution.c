#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include  <math.h>

int i;
int j;
int length_arg;

int k;
string return_cipher;
char ciphervalue[100];
int position;
int position_p;

//string ciphertext(string key, string user_word);



int main(int argc, string argv[])
{
    if (argc!=2)
    {
      printf("you should enter one command-line beside ./substitution\n");
     return 1;

    }


  length_arg=strlen(argv[1]);
  string temp=argv[1];

  if (length_arg!=26){
   printf("All keys should be unique 26 letters \n");
    return 1;
   }


    // starting the check
  for (i=0;i<26;i++)
  {

    if (isalpha(temp[i]))
    {

     for(j=i+1; j <26 ; j++)
     {

    if(toupper(temp[i])==toupper(temp[j]))
     {
     printf("there's a repeated letter %c, the key should be unique! \n",temp[i]);
     return 1;
     }
     }

   }
   else {
     printf("All keys should be only letters");
    return 1;
   }

   }





string plain_text=get_string("Plaintext:");

for (k=0; k < strlen(plain_text);k++){


   position= toupper(plain_text[k])-'A';
   if(islower(plain_text[k]))

   {
   ciphervalue[k]=tolower(temp[position]);
   //printf("to lower %d %c %d\n",k, ciphervalue[k],plain_text[k]);
   }
   else if(isupper(plain_text[k])){
    ciphervalue[k]=toupper(temp[position]);
    //printf("from key %d %c\n",k, ciphervalue[k]);
   }

   else {

     ciphervalue[k]=plain_text[k];
     //printf("spaces  %d %c\n",k, ciphervalue[k]);
   }
  }
   printf("ciphertext: %s\n",ciphervalue);

return 0;



}









/*string ciphertext(string key, string user_word)
{


  for (k=0; k < strlen(user_word);k++){

  position_p= toupper(user_word[k])-'A'-1;
   return_cipher[k]=key[position];
  }

return  return_cipher;
}*/
