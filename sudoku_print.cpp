
#ifndef SUDOKU_PRINT
	#define SUDOKU_PRINT
	#include "define.h"
#endif

void print_bits(unsigned int num, int num_of_bits, int size){

	if(num_of_bits >= size * 8) return;

	unsigned int mask = 1 << (num_of_bits - 1);

	for(int i = 0; i < num_of_bits; i++){

		if( ( (num_of_bits - i) % 4 ) == 0)
			printf(" ");
		//printf("%d\n", mask);
		unsigned int bit = (num & mask) >> (num_of_bits - 1 - i);
		mask = mask >> 1;
		/*int bit = num & 1;
		num = num >> 1;*/

		printf("%ud", bit);

	}

	return;

}

void sudoku::print_grid(){

	printf("	┌───────┬───────┬───────┐\n");

	for(int row = 1; row < 10; row++){

		printf("	│ ");

		for(int column = 1; column < 10; column++){

			printf("%d ", sudoku_pole[row][column]);

			if( column == 3 || column == 6 )
				printf("│ ");

		}

		printf("│\n");

		if( row == 3 || row == 6)
			printf("	├───────┼───────┼───────┤\n");


	}


	printf("	└───────┴───────┴───────┘\n");


}


void sudoku::print_possibilities(){
	//print_bits(sudoku_possibilities[9][1], 12, 2);
	//printf("%d\n", sudoku_possibilities[9][1]);
	printf("\n");
	printf("	╔═════════════════╦═════════════════╦═════════════════╗\n");


	int row_real = 1;
	int row_box = 0;

	for(int row_print = 1; row_print < 28; row_print++){

		printf("	║ ");

		for(int column = 1; column < 10; column++){

			const int row3 = row_box * 3;

			int number1 = 1 + row3;
			int number2 = 2 + row3;
			int number3 = 3 + row3;

			unsigned int number_mask1 = sudoku_possibilities[number1][row_real] & (1 << column);
			unsigned int number_mask2 = sudoku_possibilities[number2][row_real] & (1 << column);
			unsigned int number_mask3 = sudoku_possibilities[number3][row_real] & (1 << column);

			number_mask1 = (unsigned int) __builtin_popcount(number_mask1);
		    number_mask2 = (unsigned int) __builtin_popcount(number_mask2);
			number_mask3 = (unsigned int) __builtin_popcount(number_mask3);

			number1 = number1 * (int)number_mask1;
			number2 = number2 * (int)number_mask2;
			number3 = number3 * (int)number_mask3;

			if(number1 == 0) number1 = 120;
			else number1 = number1 + 48;

			if(number2 == 0) number2 = 120;
			else number2 = number2 + 48;

			if(number3 == 0) number3 = 120;
			else number3 = number3 + 48;

			printf("%c%c%c ", number1, number2, number3);

			if( column == 3 || column == 6 || column == 9 ) printf("║ ");
			else printf("│ ");

		}

		printf("%d\n",row_real);


		if( row_print == 9 || row_print == 18){

			printf("	╠═════════════════╬═════════════════╬═════════════════╣%d\n",row_real);

		}
		else if( ( ( row_print % 9) != 0) & ( ( row_print % 3) == 0) ){

			printf("	║ ────┼─────┼──── ║ ────┼─────┼──── ║ ────┼─────┼──── ║%d\n",row_real);

		}

		if(row_box == 2){

			row_box = 0;
			row_real++;

		}
		else row_box++;


	}


	printf("	╚═════════════════╩═════════════════╩═════════════════╝\n");


}


void sudoku::print_debug(){

	printf("	┌───────┬───────┬───────┐\n");

	for(int row = 1; row < 10; row++){

		printf("	│ ");

		for(int column = 1; column < 10; column++){

			printf("%d ", sudoku_pole[row][column]);

			if( column == 3 || column == 6 )
				printf("│ ");

		}

		printf("│\n");

		if( row == 3 || row == 6)
			printf("	├───────┼───────┼───────┤\n");


	}


	printf("	└───────┴───────┴───────┘\n");
	printf("\n");

	printf("\n            98 7654 3210");

	for(int i = 1; i < 10; i++){

		printf("\n    Row %d : ", i);
		print_bits(rows_mask[i], 10, sizeof(rows_mask[i]));

	}

	printf("\n");
	printf("\n               98 7654 3210");

	for(int i = 1; i < 10; i++){

		printf("\n    Column %d : ", i);
		print_bits(columns_mask[i], 10, sizeof(columns_mask[i]));

	}

	printf("\n\n");

	for(int i = 1; i < 10; i++){

		printf("    Number of %d is: %d\n", i, 9 - count[i]);

	}

}


void sudoku::print_debug2(){

	constexpr int countBegining = 2;
	constexpr int rowMaskBegining = 15;
	constexpr int columnMaskBegining = 26;


	printf("\n");

	int row_real_possibilities = 1;
	int row_box = 0;

	int row_real_grid = 1;

	for(int row_print = 1; row_print < 38; row_print++){


		if(row_print == 1)
			printf("	╔═════════════════╦═════════════════╦═════════════════╗ ");


		else if( row_print == 13 || row_print == 25)
			printf("	╠═════════════════╬═════════════════╬═════════════════╣ ");


		else if( (row_print == 9) | (row_print == 5) | (row_print == 17) | (row_print == 21) | (row_print == 29) | (row_print == 33) )
			printf("	║ ────┼─────┼──── ║ ────┼─────┼──── ║ ────┼─────┼──── ║ ");


		else if(row_print == 37)
			printf("	╚═════════════════╩═════════════════╩═════════════════╝ ");


		else{

			printf("	║ ");

			for(int column = 1; column < 10; column++){

				const int row3 = row_box * 3;

				int number1 = 1 + row3;
				int number2 = 2 + row3;
				int number3 = 3 + row3;

				unsigned int number_mask1 = sudoku_possibilities[number1][row_real_possibilities] & (1 << column);
				unsigned int number_mask2 = sudoku_possibilities[number2][row_real_possibilities] & (1 << column);
				unsigned int number_mask3 = sudoku_possibilities[number3][row_real_possibilities] & (1 << column);

				number_mask1 = (unsigned int) __builtin_popcount(number_mask1);
				number_mask2 = (unsigned int) __builtin_popcount(number_mask2);
				number_mask3 = (unsigned int) __builtin_popcount(number_mask3);

				number1 = number1 * (int) number_mask1;
				number2 = number2 * (int) number_mask2;
				number3 = number3 * (int) number_mask3;

				if(number1 == 0) number1 = 120;
				else number1 = number1 + 48;

				if(number2 == 0) number2 = 120;
				else number2 = number2 + 48;

				if(number3 == 0) number3 = 120;
				else number3 = number3 + 48;

				printf("%c%c%c ", number1, number2, number3);

				if( column == 3 || column == 6 || column == 9 ) printf("║ ");
				else printf("│ ");

			}


			if(row_box == 2){

					row_box = 0;
					row_real_possibilities++;

				}
			else row_box++;


		}


		if(row_print == 1)
			printf("	┌───────┬───────┬───────┐");


		else if( row_print == 5 || row_print == 9)
			printf("	├───────┼───────┼───────┤");


		else if(row_print == 13)
			printf("	└───────┴───────┴───────┘");


		else if(row_print < 14){

			printf("	│ ");

			for(int column = 1; column < 10; column++){

				printf("%d ", sudoku_pole[row_real_grid][column]);

				if( column == 3 || column == 6 )
					printf("│ ");

			}

			printf("│");

			row_real_grid++;

		}

		//print count of numbers
		if( (row_print > countBegining) & ( row_print < (countBegining + 10) ) )
			printf("    Number of %d is: %d", row_print - countBegining, 9 - count[row_print - countBegining]);

		//print row masks
		if(row_print == rowMaskBegining)
			printf("	        98 7654 3210");

		if( (row_print > rowMaskBegining) & (row_print < (rowMaskBegining + 10) ) ){

			int index = row_print - rowMaskBegining;

			printf("	Row %d : ", index);
			print_bits(rows_mask[index], 10, sizeof(rows_mask[index]));

		}

		//print columns masks
		if(row_print == columnMaskBegining)
			printf("	           98 7654 3210");

		if( (row_print > columnMaskBegining) & (row_print < (columnMaskBegining + 10) ) ){

			int index = row_print - columnMaskBegining;

			printf("	Column %d : ", index);
			print_bits(columns_mask[index], 10, sizeof(columns_mask[index]));

		}


		printf("\n");


	}

}
