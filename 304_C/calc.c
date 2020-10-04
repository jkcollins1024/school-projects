//Jonathan Collins
//CS 304 Homework 3
//2-15-2018
//This program provides the user with the option to enter any Octal,
//Decimal, or Hexadecimal number and see its conversion into Octal, 
//Decimal, and Hexadecimal.
//Also allows mathematical and bitwise operations with the number stored in the accumulator.

#include <stdio.h>
#include <string.h>

unsigned short get_binary_op (char *bin);
void convert_to_binary (short acc, char *bin);
short get_operand(char mode);
void print_acc(short acc);
char print_menu();
void add(short *acc, char mode);
void subtract(short *acc, char mode);

int main() {

	short acc = 0;
	//char option_string[];
	char option;
	char mode = 'D';
	short operand = 0;
	unsigned short temp_acc = 0;

	do{
		print_acc(acc);
		option = print_menu();
		
		switch(option){
		case 'B':
			mode = 'B';
			printf("Mode is Binary\n");
			printf("\n");
			break;
		case 'O':
			mode = 'O';
			printf("Mode is Octal\n");
            		printf("\n");
			break;
		case 'H':
			mode = 'H';
			printf("Mode is Hexadecimal\n");
            		printf("\n");
			break;
		case 'D':
			mode = 'D';
			printf("Mode is Decimal\n");
            		printf("\n");
			break;
		case 'C':
			acc = 0;
			break;
		case 'S':
			acc = get_operand(mode);
			break;
		case '&':
			operand = get_operand(mode);
			acc &= operand;
			break;
		case '|':
			operand = get_operand(mode);
			acc |= operand;
			break;
		case '^':
			operand = get_operand(mode);
			acc ^= operand;
			break;
		case '~':
			acc = ~acc;
			break;
		case '+':
			add(&acc, mode);
			break;
		case '-':
			subtract(&acc, mode);
			break;
		case 'N':
			acc = -acc;
			break;
		case '<':
			operand = get_operand('<');
			acc = acc << operand;
			break;
		case '>':
			operand = get_operand('>');
			acc = acc >> operand;
			break;
		case 'Q':
			break;
		default:
			printf("Invalid option: %c\n", option);
            		printf("\n");
			break;
        	}
	}while (option != 'Q');
}

void print_acc(short acc){
	int x = 0;
	char bin_array[20];
	char *bin2 = bin_array;
	convert_to_binary(acc, bin2);
	

	for (x = 0; x < 40; x++){
		printf("*");
	}

	printf("\n");
    
	printf("* Accumulator:                         *\n");
	printf("*   Binary  :  %.19s     *\n", bin2);
	printf("*   Hex     :  %04hX %20c\n", acc, '*');
	printf("*   Octal   :  %06ho %18c\n", acc, '*');
	printf("*   Decimal :  %-23hd *\n", acc);
    
	for (x = 0; x < 40; x++){
		printf("*");
	}

	printf("\n");
	printf("\n");
}

char print_menu(){
	char option;
	char option_string[10];

	printf("Please select one of the following options: \n");
	printf("\n");
    
	printf("%-20s %-20s %-20s\n", "B Binary Mode", "& AND with Accumulator", "+ Add to Accumulator");
	printf("%-20s %-20s %-20s\n", "O Octal Mode", "| OR with Accumulator", "- Subtract from Accumulator");
	printf("%-20s %-20s %-20s\n", "H Hexadecimal Mode", "^ XOR with Accumulator", "N Negate Accumulator");
	printf("%-20s %-20s\n", "D Decimal Mode", "~ Complement Accumulator");
	printf("\n");
    
	printf("%-20s %-20s\n", "C Clear Accumulator", "< Shift Accumulator Left");
	printf("%-20s %-20s\n", "S Set Accumulator", "> Shift Accumulator Right");
	printf("\n");
    
	printf("Q Quit\n");
	printf("\n");
    
	printf("Option:");

	scanf("%s", &option_string);
    	printf("%s\n", option_string);
    	printf("\n");

	if (option_string[1] == '\0'){
		option = option_string[0];
	}
	else {
		option = 'X';
	}

	return toupper(option);
}

short get_operand(char mode){
	short acc;
	char bin_arr[20];
	char *bin = bin_arr;

	switch(mode){
		case 'B':
			printf("Enter Binary Value: ");
			scanf("%s", bin);
			printf("%s", bin);
			printf("\n");
			acc = (short) get_binary_op(bin);
			break;

		case 'O':
            		printf("Enter Octal Value: ");
			scanf("%ho", &acc);
            		printf("%ho\n", acc);
            		printf("\n");
			break;

		case 'D':
           		printf("Enter Decimal Value: ");
			scanf("%hd", &acc);
            		printf("%hd\n", acc);
            		printf("\n");
			break;

		case 'H':
            		printf("Enter Hexadecimal Value: ");
			scanf("%hX", &acc);
            		printf("%hX\n", acc);
            		printf("\n");
			break;

		case '<':
			printf("Enter number of positions to left shift accumulator: ");
			scanf("%hd", &acc);
			printf("%hd\n", acc);
			printf("\n");
			break;

		case '>':
			printf("Enter number of positions to right shift accumulator: ");
			scanf("%hd", &acc);
			printf("%hd\n", acc);
			printf("\n");
			break;

		default:
			printf("Invalid option: Resetting accumulator.\n");
            		printf("\n");
            		acc = 0;
		}
	return acc;
}

void add(short *acc, char mode){
	short operand = get_operand(mode);
	short temp = *acc;
	*acc = temp + operand;

	if (operand < 0 && temp < 0 && acc > 0){
		printf("Underflow Error\n");
	}

	if (operand > 0 && temp > 0 && acc < 0){
		printf("Overflow Error\n");
	}

}

void subtract(short *acc, char mode){
	short operand = get_operand(mode);
	short temp = *acc;
	*acc = temp - operand;

	if (temp < 0 && operand > 0 && *acc > 0){
		printf("Underflow Error\n");
	}

	if (temp > 0 && operand < 0 && *acc < 0){
		printf("Overflow Error\n");
	}

}

unsigned short get_binary_op(char *bin){
	short binary_place = 1;
	unsigned short acc = 0;
	int iterator = strlen(bin) - 1;
	short temp = 0;

	while (iterator >= 0){
		temp = ((short) bin[iterator]) - 48;
		acc += temp * binary_place;
		binary_place *= 2;
		iterator -= 1;
	}
	return acc;
}

void convert_to_binary(short acc, char *bin){
	unsigned short temp_acc = acc;
	int count = 0;
	int divisor = 32768;

	while (count < 19){
		if ((count + 1) % 5 == 0){
			bin[count] = ' ';
		}

		else{
			if (temp_acc / divisor == 1){
				temp_acc -= divisor;
				bin[count] = '1';
			}
			else{
				bin[count] = '0';
			}
			divisor = divisor / 2;
		}
		count += 1;
	}
}
