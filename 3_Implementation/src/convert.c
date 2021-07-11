#include <header.h>
#include <math.h>
#include <stdio.h>

int convert(long long n) {
    int dec = 0, i = 0, rem;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
	int power=1,j;
	for(j=1;j<=i;++j){
	power=power*2;
	}
        dec += rem * power;
        ++i;
    }
    return dec;
}