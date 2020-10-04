/*Jonathan Collins
Homework 7, CS304 Organization
This program uses recursion to get correct powers of numbers with only the add, subtract, AND, and XOR functions at our disposal. */

#include<stdio.h>

int rmult(int i, int j){
	
	//if multiplying by 1, no need to go further; otherwise, we keep recurring
	if (j == 1){
		return i;
	}
	else{
		return(i + rmult(i, j-1));
	}
}

int rpow(int base, int power){

	//if our power is 1, we know the answer already, and can just return
	if (power == 1){
		return base;
	}
	else{
		return(rmult(base, rpow(base, power-1)));
	}
}

int main(){
	
	//declare initial variables, including a result in which the power can be stored
	int base, power, result;

	printf("***********************\n");

	for (base = 2; base <= 5; base++){
		for (power = 1; power <=8; power++){
			result = rpow(base,power);
			printf("%d^%d = %6d 0x%08x\n", base, power, result, result);
		}

		printf("***********************\n");
	}
}