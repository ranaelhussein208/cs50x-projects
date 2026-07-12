#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

char alphebet[26]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
char alphebet_ch[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

string Player_1;
string Player_2;
int i;
int j;
int k;
int kj;
int sum_1;
int sum_2;
int length_1;
int length_2;

int main()
{



Player_1=get_string("Player 1: ");
Player_2=get_string("Player 2: ");

length_1=strlen(Player_1);
length_2=strlen(Player_2);




for(k=0; k < length_1;k++){

for (i=0; i < 26 ; i++){

    if(alphebet_ch[i]==toupper(Player_1[k])){
        sum_1=sum_1+alphebet[i];

    }

}

}

for(kj=0;kj < length_2; kj++){

for (j=0; j < 26 ; j++){

    if(alphebet_ch[j]==toupper(Player_2[kj])){
        sum_2= sum_2+alphebet[j];


    }

  }

}

  if (sum_2==sum_1){
    printf("Tie \n");


  }
   if(sum_2 > sum_1){

        printf("Player 2 wins!");
  }
    if(sum_1 > sum_2){

        printf("Player 1 wins!");
  }









return 0;
}
