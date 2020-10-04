//Jonathan Collins
//CS 304 Homework 2
//2-15-2018
//This program provides the user with the option to enter any Octal,
//Decimal, or Hexadecimal number and see its conversion into Octal, 
//Decimal, and Hexadecimal.

#include <stdio.h>

unsigned short get_binary_op (char *bin);
void convert_to_binary (short acc, char *bin);
short get_operand(char mode);
void print_acc(short acc);
char print_menu();

int main() {

	short acc = 0;
	//char option_string[];
	char option;
	char mode = 'D';

	do{
		print_acc(acc);
		option = print_menu();
		
		switch(option){
		//case "B":
			//mode = "B";
			//break;
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
			acc ~= acc;
			break;
		case '+':
			operand = get_operand(mode);
			acc += operand;
			break;
		case '-':
			operand = get_operand(mode);
			acc -= operand;
			break;
		case 'N':
			acc = -acc;
			break;
		case '<':
			operand = get_operand('D');
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
	for (x = 0; x < 40; x++){
		printf("*");
	}
	printf("\n");
    
	printf("* Accumulator:                         *\n");
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
    
	printf("B Binary Mode\n");
	printf("O Octal Mode\n");
	printf("H Hexadecimal Mode\n");
	printf("D Decimal Mode\n");
	printf("\n");
    
	printf("C Clear Accumulator\n");
	printf("S Set Accumulator\n");
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
	switch(mode){
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
		default:
			printf("Invalid option: Resetting accumulator.\n");
            printf("\n");
            acc = 0;
	}
	return acc;
}

