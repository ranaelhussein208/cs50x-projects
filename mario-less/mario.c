#include <stdio.h>
#include <cs50.h>
int Layer_no;
int i;
int j;
int k;
int main()
 {


 do{
   Layer_no=get_int("Height:");
 } while (Layer_no <= 0);


    for(j=1;j <= Layer_no;j++)
    {
    for(k=Layer_no;k>j;k--)
    {
      printf(" ");
    }
    for (i=0;i<j;i++)
    {
     printf("#");
    }
    printf("\n");
    }



    return 0;
}


