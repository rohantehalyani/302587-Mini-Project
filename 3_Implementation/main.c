#include<header.h>
#include<stdio.h>    
#include<stdlib.h>  
#include<string.h>
#include <math.h>
int main(){  
    int  select=0;
    printf("What you want to convert\n");
    printf("1. Decimal to binary\n");
    printf("2. binary to Decimal\n");
    printf("3. Decimal to Hexadecial\n");
    printf("4. Hexadecial to Decimal\n");
    printf("5. Decimal to Octal\n");
    printf("6. Octal to Decimal\n");
    printf("Enter the code to convert:");
    scanf("%d",&select);


    if(select==1){ //decimal to binary
    int a[10],n,i;    
    system ("cls");  
    printf("Enter the number to convert: ");    
    scanf("%d",&n);    
    for(i=0;n>0;i++)    
        {    
            a[i]=n%2;    
            n=n/2;    
        }       
    printf("\nBinary of Given Number is=");    
    for(i=i-1;i>=0;i--)    
    {    
    printf("%d",a[i]);    
    }    }


    if(select==2){
	long long n;
    printf("Enter a binary number: ");
    scanf("%lld", &n);
    printf("%lld in binary = %d in decimal", n, convert(n));
    return 0;
	}


    if(select==3){
	long int decimalNumber,remainder,quotient;
	int i=1,j,temp;
	char hexadecimalNumber[100];
	printf("Enter any decimal number: ");
	scanf("%ld",&decimalNumber);
	quotient = decimalNumber;
	while(quotient!=0) {
		temp = quotient % 16;
		//To convert integer into character
		if( temp < 10)
		           temp =temp + 48; else
		         temp = temp + 55;
		hexadecimalNumber[i++]= temp;
		quotient = quotient / 16;
	}
	printf("Equivalent hexadecimal value of decimal number %d: ",decimalNumber);
	for (j = i -1 ;j> 0;j--)
	      printf("%c",hexadecimalNumber[j]);

	}


    if(select==4){
	char hex[100];
    	printf("Enter Hexadecimal: ");
    	scanf("%s", hex);
	printf("\nDecimal: %d", HexadecimalToDecimal(hex));
	}
	

	if(select==5){
	long decimalnum, remainder, quotient;
    int octalNumber[100], i = 1, j;
 
    printf("Enter the decimal number: ");
    scanf("%ld", &decimalnum);
    quotient = decimalnum;
    while (quotient != 0)
    {
        octalNumber[i++] = quotient % 8;
        quotient = quotient / 8;
    }
    printf("Equivalent octal value of decimal no %d: ", decimalnum);
    for (j = i - 1; j > 0; j--)
        printf("%d", octalNumber[j]);

	}
	
	
	if(select==6){
	long int octal, decimal = 0;
    int i = 0;
 
    printf("Enter any octal number: ");
    scanf("%ld", &octal);
    while (octal != 0)
    {
        decimal =  decimal +(octal % 10)* pow(8, i++);
        octal = octal / 10;
    }
    printf("Equivalent decimal value: %ld",decimal);
    }	
return 0;

}
