#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

long number;
long copy;
int sum = 0;
int position = 0;
int length = 0;
int digit;
int doubled=0;
long start;

int main()
{

  do{
  number = get_long("Number: ");
  }while(number <= 0);

copy=number;
start=number;

while(copy>0){

digit=copy%10;
copy=copy/10;
position++;
length++;

if (position%2 == 0)
{
doubled=digit*2;
sum+=doubled/10+doubled%10;

}
else{
sum+=digit;

}

}

while(start >= 100)
{
start=start/10;up

}

printf("star:%ld, length:%d",start,length);

if (sum%10 != 0)
{

  printf("INVALID\n");

}

else if( length==15 && (start==34 || start==37))
{
printf("AMEX\n");
}
else if(length==16 && (51 <= start && start<= 55))
{
printf("MASTERCARD\n");

}

else if( (length==13 || length==16) && (start/10) ==4){
printf("VISA\n");


}
else{

  printf("INVALID\n");
}


return 0;
}
