#include<header.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
int HexadecimalToDecimal(char *hex) {
    int p = 0; 
    int decimal = 0;
    int r, i;
    for(i = strlen(hex) - 1 ; i >= 0 ; --i){
        
        // converting c[i] to appropriate decimal form
        if(hex[i]>='0'&&hex[i]<='9'){
            r = hex[i] - '0';
        }
        else{
            r = hex[i] - 'A' + 10;
        }
        int power=1,j;
	for(j=1;j<=p;++j){
	power=power*16;
	}
        decimal = decimal + r * power;
        ++p;
    }
    
    return decimal;
}