/*Jonathan Collins
CS304 Computer Organization Homework 6
This project prints out squares of numbers 1-20 using only add, subtract, AND, and XOR functions*/

#include<stdio.h>

int squareadd(int i){
	int x, sum = 0;
	
	for(x = 0; x < i; x++){
		
		sum += i;
	}

	return sum;
}

int squarebit(int i){
	
	int sum = 0;
	int mult = i;
	int bit = 1;

	while (bit <= i){
		
		//unless the AND is equal to the original bit value, it should not be added
		if ((bit & i) == bit){
	
			sum = sum + mult;
		}
		
		//doubles bit value and multiple value for next iteration
		bit = bit + bit;
		mult = mult + mult;
	}
	return sum;
}


int main(){
	int i;

	for(i = 1; i <= 20; i++){
	
		printf("%-2d %-3d %-3d\n", i, squareadd(i), squarebit(i));
	}
}