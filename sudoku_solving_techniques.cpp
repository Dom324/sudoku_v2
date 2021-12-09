
#ifndef SUDOKU_SOLVING_TECHNIQUES
	#define SUDOKU_SOLVING_TECHNIQUES
	#include "define.h"
#endif

#define FAST_X_WING
//#define EVEN_FASTER_X_WING
#define FAST_PAIR
//#define EVEN_FASTER_PAIR

NO_INLINE void sudoku::naked_single() noexcept{

	for(int row = 1; row < 10; row++){

		for(int column = 1; column < 10; column++){

			const unsigned int square_possibilities = getSquarePossibilities(row, column);

			if(__builtin_popcount(square_possibilities) != 1) continue;

			const int num = __builtin_ctz(square_possibilities);

			setVal(row, column, num);

			#ifdef PRINT_DEBUG
				printf("boooooooom naked single			row: %d column: %d number: %d\n", row, column, num);
			#endif

		}

	}

	return;

}


/*NO_INLINE void sudoku::naked_single() noexcept{

	int col1 = 1;
	int col2 = 2;
	int col3 = 3;

	int rows[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for(int i = 1; i < 10; i++){

		const int cols[10] = 	{0, col1, col1 + 3, col1 + 6,
								 col2, col2 + 3, col2 + 6,
								 col3, col3 + 3, col3 + 6};

		const unsigned int squares[10] = {
			0,
			getSquarePossibilities(rows[1], cols[1]),		//box1
			getSquarePossibilities(rows[2], cols[2]),		//box2
			getSquarePossibilities(rows[3], cols[3]),		//box3
			getSquarePossibilities(rows[4], cols[4]),		//box4
			getSquarePossibilities(rows[5], cols[5]),		//box5
			getSquarePossibilities(rows[6], cols[6]),		//box6
			getSquarePossibilities(rows[7], cols[7]),		//box7
			getSquarePossibilities(rows[8], cols[8]),		//box8
			getSquarePossibilities(rows[9], cols[9])		//box9
		};*/

		/*printf("square1 %d %d\n", rows[1], cols[1]);
		printf("square2 %d %d\n", rows[2], cols[2]);
		printf("square3 %d %d\n", rows[3], cols[3]);
		printf("square4 %d %d\n", rows[4], cols[4]);
		printf("square5 %d %d\n", rows[5], cols[5]);
		printf("square6 %d %d\n", rows[6], cols[6]);
		printf("square7 %d %d\n", rows[7], cols[7]);
		printf("square8 %d %d\n", rows[8], cols[8]);
		printf("square9 %d %d\n", rows[9], cols[9]);

		printf("\n\n\n");*/

		/*if(__builtin_popcount(squares[1]) == 1){
			const int num = __builtin_ctz(squares[1]);
			setVal(rows[1], cols[1], num);
			#ifdef PRINT_DEBUG
				printf("boooooooom naked single			row: %d column: %d number: %d\n", row, column, num);
			#endif
		}
		if(__builtin_popcount(squares[2]) == 1){
			const int num = __builtin_ctz(squares[2]);
			setVal(rows[2], cols[2], num);
			#ifdef PRINT_DEBUG
				printf("boooooooom naked single			row: %d column: %d number: %d\n", row, column, num);
			#endif
		}
		if(__builtin_popcount(squares[3]) == 1){
			const int num = __builtin_ctz(squares[3]);
			setVal(rows[3], cols[3], num);
			#ifdef PRINT_DEBUG
				printf("boooooooom naked single			row: %d column: %d number: %d\n", row, column, num);
			#endif
		}
		if(__builtin_popcount(squares[4]) == 1){
			const int num = __builtin_ctz(squares[4]);
			setVal(rows[4], cols[4], num);
			#ifdef PRINT_DEBUG
				printf("boooooooom naked single			row: %d column: %d number: %d\n", row, column, num);
			#endif
		}
		if(__builtin_popcount(squares[5]) == 1){
			const int num = __builtin_ctz(squares[5]);
			setVal(rows[5], cols[5], num);
			#ifdef PRINT_DEBUG
				printf("boooooooom naked single			row: %d column: %d number: %d\n", row, column, num);
			#endif
		}
		if(__builtin_popcount(squares[6]) == 1){
			const int num = __builtin_ctz(squares[6]);
			setVal(rows[6], cols[6], num);
			#ifdef PRINT_DEBUG
				printf("boooooooom naked single			row: %d column: %d number: %d\n", row, column, num);
			#endif
		}
		if(__builtin_popcount(squares[7]) == 1){
			const int num = __builtin_ctz(squares[7]);
			setVal(rows[7], cols[7], num);
			#ifdef PRINT_DEBUG
				printf("boooooooom naked single			row: %d column: %d number: %d\n", row, column, num);
			#endif
		}
		if(__builtin_popcount(squares[8]) == 1){
			const int num = __builtin_ctz(squares[8]);
			setVal(rows[8], cols[8], num);
			#ifdef PRINT_DEBUG
				printf("boooooooom naked single			row: %d column: %d number: %d\n", row, column, num);
			#endif
		}
		if(__builtin_popcount(squares[9]) == 1){
			const int num = __builtin_ctz(squares[9]);
			setVal(rows[9], cols[9], num);
			#ifdef PRINT_DEBUG
				printf("boooooooom naked single			row: %d column: %d number: %d\n", row, column, num);
			#endif
		}


		if(col1 == 3){

			col1 = 1;
			if(rows[1] == 3) rows[1] = 1;
			else rows[1]++;
			if(rows[2] == 3) rows[2] = 1;
			else rows[2]++;
			if(rows[3] == 3) rows[3] = 1;
			else rows[3]++;


		} else col1++;

		if(col2 == 3){

			col2 = 1;
			if(rows[4] == 6) rows[4] = 4;
			else rows[4]++;
			if(rows[5] == 6) rows[5] = 4;
			else rows[5]++;
			if(rows[6] == 6) rows[6] = 4;
			else rows[6]++;


		} else col2++;

		if(col3 == 3){

			col3 = 1;
			if(rows[7] == 9) rows[7] = 7;
			else rows[7]++;
			if(rows[8] == 9) rows[8] = 7;
			else rows[8]++;
			if(rows[9] == 9) rows[9] = 7;
			else rows[9]++;


		} else col3++;


	}

	return;

}*/

NO_INLINE void sudoku::only_option() noexcept{

	for(int num = 1; num < 10; num++){

		if(getCount(num) == 0) continue;

		//only option in row
		for(int row = 1; row < 10; row++){

			const unsigned int row_possibilities = getRowPossibilities(num, row);

			if(__builtin_popcount(row_possibilities) != 1) continue;

			const int column_index = __builtin_ctz(row_possibilities);

			setVal(row, column_index, num);

			#ifdef PRINT_DEBUG
				printf("boooooooom only option row		row: %d column: %d\n", row, column_index);
			#endif

		}

		/*unsigned int column_possibilities_arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

		getColumns(num, column_possibilities_arr);*/

		//only option in column
		for(int column = 1; column < 10; column++){

			const unsigned int column_possibilities = getColumnPossibilities(num, column);
			//const unsigned int column_possibilities = column_possibilities_arr[column];

			if(__builtin_popcount(column_possibilities) != 1) continue;

			const int row_index = __builtin_ctz(column_possibilities);

			setVal(row_index, column, num);

			#ifdef PRINT_DEBUG
			printf("boooooooom only option column		row: %d column: %d\n", row_index, column);
			#endif


		}

		//only option in box
		for(int box = 1; box < 10; box++){

			//if(getBoxPossibility(num, box) == 0) continue;

			const unsigned int box_possibilities = getBoxPossibilities(num, box);

			if(__builtin_popcount(box_possibilities) != 1) continue;

			const int box_index = __builtin_ctz(box_possibilities);

			const int row_index = boxToRow(box, box_index);
			const int column_index = boxToColumn(box, box_index);

			setVal(row_index, column_index, num);

			#ifdef PRINT_DEBUG
			printf("boooooooom only option box		row: %d column: %d\n", row_index, column_index);
			#endif

		}

	}

	return;

}

NO_INLINE void sudoku::pair() noexcept{

	//posledni iterace je zbytecna
	//protoze neni zadne vyssi cislo nez num
	//s kterym by mohl byt par
	for(int num = 1; num < (10 - 1); num++){

		if(getCount(num) == 0) continue;

		const unsigned int num_mask = (1 << num);

		//pair in row
		for(int row = 1; row < 10; row++){

			unsigned int num_possibilities = getRowPossibilities(num, row);

			if(__builtin_popcount(num_possibilities) != 2) continue;

			for(int num2 = num + 1; num2 < 10; num2++){

				if(num_possibilities != getRowPossibilities(num2, row)) continue;

				//IILE

				#ifdef EVEN_FASTER_PAIR

				const int column_index1 = __builtin_ctz(num_possibilities);
				const int column_index2 = 31 - __builtin_clz(num_possibilities);		//bsr

				#else
				#ifdef FAST_PAIR
				const int column_index1 = __builtin_ctz(num_possibilities);

				num_possibilities = num_possibilities & (unsigned)~(1 << column_index1);

				const int column_index2 = __builtin_ctz(num_possibilities);

				#else

				int column_index1, column_index2;
				int counter = 1;

				do{

					num_possibilities = num_possibilities >> 1;
					column_index1 = counter * (int)(num_possibilities & 1);
					counter++;

				}while(column_index1 == 0);

				do{

					num_possibilities = num_possibilities >> 1;
					column_index2 = counter * (int)(num_possibilities & 1);
					counter++;


				}while(column_index2 == 0);

				#endif
				#endif

				const unsigned int mask = num_mask | (1 << num2);

				setPossibilities(row, column_index1, mask);
				setPossibilities(row, column_index2, mask);

				#ifdef PRINT_DEBUG
					printf("boooooooom pair in row		num1 %d num2 %d row %d column1 %d column2 %d\n", num, num2, row, column_index1, column_index2);
				#endif


			}

		}


		//pair in column
		for(int column = 1; column < 10; column++){

			unsigned int num_possibilities = getColumnPossibilities(num, column);

			if(__builtin_popcount(num_possibilities) != 2) continue;

			for(int num2 = num + 1; num2 < 10; num2++){

				if(num_possibilities != getColumnPossibilities(num2, column)) continue;

				#ifdef EVEN_FASTER_PAIR

				const int row_index1 = __builtin_ctz(num_possibilities);
				const int row_index2 = 31 - __builtin_clz(num_possibilities);		//bsr

				#else
				#ifdef FAST_PAIR

				const int row_index1 = __builtin_ctz(num_possibilities);

				num_possibilities = num_possibilities & (unsigned)~(1 << row_index1);

				const int row_index2 = __builtin_ctz(num_possibilities);

				#else


				//IILE
				int row_index1, row_index2;
				int counter = 1;

				do{

					num_possibilities = num_possibilities >> 1;
					row_index1 = counter * (int)(num_possibilities & 1);
					counter++;

				}while(row_index1 == 0);

				do{

					num_possibilities = num_possibilities >> 1;
					row_index2 = counter * (int)(num_possibilities & 1);
					counter++;


				}while(row_index2 == 0);

				#endif
				#endif

				const unsigned int mask = num_mask | (1 << num2);

				setPossibilities(row_index1, column, mask);
				setPossibilities(row_index2, column, mask);

				#ifdef PRINT_DEBUG
					printf("boooooooom pair in column	num1 %d num2 %d column %d row1 %d row2 %d\n", num, num2, column, row_index1, row_index2);
				#endif

			}

		}


		//pair in box
		for(int box = 1; box < 10; box++){

			unsigned int num_possibilities = getBoxPossibilities(num, box);

			if(__builtin_popcount(num_possibilities) != 2) continue;

			for(int num2 = num + 1; num2 < 10; num2++){

				if(num_possibilities != getBoxPossibilities(num2, box)) continue;

				#ifdef EVEN_FASTER_PAIR

				const int box_index1 = __builtin_ctz(num_possibilities);
				const int box_index2 = 31 - __builtin_clz(num_possibilities);		//bsr

				#else
				#ifdef FAST_PAIR

				const int box_index1 = __builtin_ctz(num_possibilities);

				num_possibilities = num_possibilities & (unsigned)~(1 << box_index1);

				const int box_index2 = __builtin_ctz(num_possibilities);

				#else

				//IILE
				int box_index1, box_index2;
				int counter = 1;

				do{

					num_possibilities = num_possibilities >> 1;
					box_index1 = counter * (int)(num_possibilities & 1);
					counter++;

				}while(box_index1 == 0);

				do{

					num_possibilities = num_possibilities >> 1;
					box_index2 = counter * (int)(num_possibilities & 1);
					counter++;


				}while(box_index2 == 0);

				#endif
				#endif

				const unsigned int mask = num_mask | (1 << num2);

				const int row1 = boxToRow(box, box_index1);
				const int column1 = boxToColumn(box, box_index1);

				const int row2 = boxToRow(box, box_index2);
				const int column2 = boxToColumn(box, box_index2);

				setPossibilities(row1, column1, mask);
				setPossibilities(row2, column2, mask);

				#ifdef PRINT_DEBUG
					printf("boooooooom pair in box		num1 %d num2 %d box %d box_index1 %d box_index2 %d\n", num, num2, box, box_index1, box_index2);
				#endif


			}

		}

	}

	return;

}

void sudoku::hidden_triple() noexcept{

	//posledni iterace je zbytecna
	//protoze neni zadne vyssi cislo nez num
	//s kterym by mohl byt par
	for(int num1 = 1; num1 < (10 - 1); num1++){

		if(getCount(num1) == 0) continue;

		//pair in row
		for(int row = 1; row < 10; row++){

			const unsigned int num1_possibilities = getRowPossibilities(num1, row);
			if( (__builtin_popcount(num1_possibilities) > 3) | (__builtin_popcount(num1_possibilities) < 2) ) continue;

			for(int num2 = num1 + 1; num2 < 10; num2++){

				const unsigned int num2_possibilities = getRowPossibilities(num2, row);
				if( (__builtin_popcount(num2_possibilities) > 3) | (__builtin_popcount(num2_possibilities) < 2) ) continue;

				for(int num3 = num2 + 1; num3 < 10; num3++){

					const unsigned int num3_possibilities = getRowPossibilities(num3, row);
					if( (__builtin_popcount(num3_possibilities) > 3) | (__builtin_popcount(num3_possibilities) < 2) ) continue;

					const unsigned int cells = num1_possibilities | num2_possibilities | num3_possibilities;

					if(__builtin_popcount(cells) != 3) continue;

					const unsigned int num_mask = (1u << num1) | (1u << num2) | (1u << num3);

					const int column1_index = __builtin_ctz(cells);
					const int column2_index = __builtin_ctz( cells & ~(1u << column1_index));
					const int column3_index = 31 - __builtin_clz(cells);

					setPossibilities(row, column1_index, num_mask);
					setPossibilities(row, column2_index, num_mask);
					setPossibilities(row, column3_index, num_mask);

				}

			}

		}

	}

	return;

}

void sudoku::hidden_quadrouple() noexcept{

	//posledni iterace je zbytecna
	//protoze neni zadne vyssi cislo nez num
	//s kterym by mohl byt par
	for(int num1 = 1; num1 < (10 - 1); num1++){

		if(getCount(num1) == 0) continue;

		//pair in row
		for(int row = 1; row < 10; row++){

			const unsigned int num1_possibilities = getRowPossibilities(num1, row);
			if( (__builtin_popcount(num1_possibilities) > 4) | (__builtin_popcount(num1_possibilities) < 2) ) continue;

			for(int num2 = num1 + 1; num2 < 10; num2++){

				const unsigned int num2_possibilities = getRowPossibilities(num2, row);
				if( (__builtin_popcount(num2_possibilities) > 4) | (__builtin_popcount(num2_possibilities) < 2) ) continue;

				for(int num3 = num2 + 1; num3 < 10; num3++){

					const unsigned int num3_possibilities = getRowPossibilities(num3, row);
					if( (__builtin_popcount(num3_possibilities) > 4) | (__builtin_popcount(num3_possibilities) < 2) ) continue;

					for(int num4 = num3 + 1; num4 < 10; num4++){

						const unsigned int num4_possibilities = getRowPossibilities(num4, row);
						if( (__builtin_popcount(num4_possibilities) > 4) | (__builtin_popcount(num4_possibilities) < 2) ) continue;

						const unsigned int cells = num1_possibilities | num2_possibilities | num3_possibilities | num4_possibilities;

						if(__builtin_popcount(cells) != 4) continue;

						const unsigned int num_mask = (1u << num1) | (1u << num2) | (1u << num3) | (1u << num4);

						const int column1_index = __builtin_ctz(cells);
						const int column2_index = __builtin_ctz( cells & ~(1u << column1_index));
						const int column3_index = 31 - __builtin_clz(cells);
						const int column4_index = 31 - __builtin_clz( cells & ~(1u << column3_index));

						setPossibilities(row, column1_index, num_mask);
						setPossibilities(row, column2_index, num_mask);
						setPossibilities(row, column3_index, num_mask);
						setPossibilities(row, column4_index, num_mask);

					}

				}

			}

		}

	}

	return;

}

NO_INLINE void sudoku::x_wing() noexcept{

	//posledni iterace je zbytecna
	//protoze neni zadne vyssi cislo nez num
	//s kterym by mohl byt par
	for(int num = 1; num < 10; num++){

		if(getCount(num) == 0) continue;

		//x wing in row
		for(int row1_i = 1; row1_i < 10; row1_i++){

			if(getRowPossibility(num, row1_i) == 0) continue;

			unsigned int row1_possibilities = getRowPossibilities(num, row1_i);

			if(__builtin_popcount(row1_possibilities) != 2) continue;

			for(int row2_i = row1_i + 1; row2_i < 10; row2_i++){

				if(row1_possibilities != getRowPossibilities(num, row2_i)) continue;

				//IILE
				int column1_i, column2_i;

				#ifdef FAST_X_WING
				column1_i = __builtin_ctz(row1_possibilities);

				row1_possibilities = row1_possibilities & (unsigned)~(1 << column1_i);

				column2_i = __builtin_ctz(row1_possibilities);

				#else

				int counter = 1;

				do{

					row1_possibilities = row1_possibilities >> 1;
					column1_i = counter * (row1_possibilities & 1);
					counter++;

				}while(column1_i == 0);

				do{

					row1_possibilities = row1_possibilities >> 1;
					column2_i = counter * (row1_possibilities & 1);
					counter++;


				}while(column2_i == 0);

				#endif

				const unsigned int mask = (unsigned int) ( (1 << row1_i) | (1 << row2_i) );

				setPossibilitiesColumn(column1_i, mask, num);
				setPossibilitiesColumn(column2_i, mask, num);

				#ifdef PRINT_DEBUG
					printf("boooooooom x wing in row	num %d row1 %d row2 %d column1 %d column2 %d\n", num, row1_i, row2_i, column1_i, column2_i);
				#endif

			}


		}


		//x wing in column
		for(int column1_i = 1; column1_i < 10; column1_i++){

			if(getColumnPossibility(num, column1_i) == 0) continue;

			unsigned int column1_possibilities = getColumnPossibilities(num, column1_i);

			if(__builtin_popcount(column1_possibilities) != 2) continue;

			for(int column2_i = column1_i + 1; column2_i < 10; column2_i++){

				if(column1_possibilities != getColumnPossibilities(num, column2_i)) continue;

				//IILE
				int row1_i, row2_i;

				#ifdef FAST_X_WING

				row1_i = __builtin_ctz(column1_possibilities);

				column1_possibilities = column1_possibilities & (unsigned int)~(1 << row1_i);

				row2_i = __builtin_ctz(column1_possibilities);

				#else

				int counter = 1;

				do{

					column1_possibilities = column1_possibilities >> 1;
					row1_i = counter * (column1_possibilities & 1);
					counter++;

				}while(row1_i == 0);

				do{

					column1_possibilities = column1_possibilities >> 1;
					row2_i = counter * (column1_possibilities & 1);
					counter++;


				}while(row2_i == 0);

				#endif

				const unsigned int mask = (unsigned int) ( (1 << column1_i) | (1 << column2_i) );

				setPossibilitiesRow(row1_i, mask, num);
				setPossibilitiesRow(row2_i, mask, num);

				#ifdef PRINT_DEBUG
					printf("possibilities %ud\n", mask);
					printf("boooooooom x wing in column	num %d column1 %d column2 %d row1 %d row2 %d\n", num, column1_i, column2_i, row1_i, row2_i);
				#endif


			}

		}


	}

	return;

}

NO_INLINE void sudoku::sameRowColumnBox() noexcept{

	for(int num = 1; num < 10; num++){

		if(getCount(num) == 0) continue;


		//Row
		for(int row = 1; row < 10; row++){

			if(getRowPossibility(num, row) == 0) continue;

			const unsigned int row_possibilities = getRowPossibilities(num, row);
			//printf("%d\n", row_possibilities);

			constexpr unsigned int masks[3] = {
				0b111'111'000'0,	//first box
				0b111'000'111'0,	//second box
				0b000'111'111'0		//third box
			};

			int num_box;

			if( (row_possibilities & masks[0]) == 0)
				num_box = 0;	//first box

			else if( (row_possibilities & masks[1]) == 0)
				num_box = 1;	//second box

			else if( (row_possibilities & masks[2]) == 0)
				num_box = 2;	//third box

			else continue;


			constexpr char row_combinations[10][2] = {
					// 0	   1	   2	   3	   4
					{0, 0}, {2, 3}, {1, 3}, {1, 2}, {5, 6},
					{4, 6}, {4, 5}, {8, 9}, {7, 9}, {7, 8}
					// 5	   6	   7	   8	   9
			};

			const int row1 = row_combinations[row][0];
			const int row2 = row_combinations[row][1];

			#ifdef PRINT_DEBUG
				if(		( sudoku_possibilities[num][row1] != (sudoku_possibilities[num][row1] & masks[num_box]) )
					||	( sudoku_possibilities[num][row2] != (sudoku_possibilities[num][row2] & masks[num_box]) ) ){

					printf("boooooooom same row	num: %d row: %d num_box: %d\n", num, row, num_box + 1);

				}
			#endif

			sudoku_possibilities[num][row1] = sudoku_possibilities[num][row1] & masks[num_box];
			sudoku_possibilities[num][row2] = sudoku_possibilities[num][row2] & masks[num_box];

		}


		//Column

		for(int column = 1; column < 10; column++){

			if(getColumnPossibility(num, column) == 0) continue;

			const unsigned int column_possibilities = getColumnPossibilities(num, column);

			//printf("%d\n", row_possibilities);

			constexpr unsigned int masks[3] = {
				0b111'111'000'0,	//first box
				0b111'000'111'0,	//second box
				0b000'111'111'0		//third box
			};

			int num_box;

			if( (column_possibilities & masks[0]) == 0)
				num_box = 0;	//first box

			else if( (column_possibilities & masks[1]) == 0)
				num_box = 1;	//second box

			else if( (column_possibilities & masks[2]) == 0)
				num_box = 2;	//third box

			else continue;


			constexpr char column_combinations[10][2] = {
					// 0	   1	   2	   3	   4
					{0, 0}, {2, 3}, {1, 3}, {1, 2}, {5, 6},
					{4, 6}, {4, 5}, {8, 9}, {7, 9}, {7, 8}
					// 5	   6	   7	   8	   9
			};

			const int column1 = column_combinations[column][0];
			const int column2 = column_combinations[column][1];

			#ifdef PRINT_DEBUG
				if(		( getColumnPossibilities(num, column1) != (getColumnPossibilities(num, column1) & masks[num_box]) )
					||	( getColumnPossibilities(num, column2) != (getColumnPossibilities(num, column2) & masks[num_box]) ) ){

					printf("boooooooom same column	num: %d column: %d num_box: %d\n", num, column, num_box + 1);

				}
			#endif

			setPossibilitiesColumn(column1, getColumnPossibilities(num, column1) & masks[num_box], num);
			setPossibilitiesColumn(column2, getColumnPossibilities(num, column2) & masks[num_box], num);

		}

		//Column

		/*unsigned int column_possibilities_arr[10] = {
			0,
			getColumnPossibilities(num, 1),
			getColumnPossibilities(num, 2),
			getColumnPossibilities(num, 3),
			getColumnPossibilities(num, 4),
			getColumnPossibilities(num, 5),
			getColumnPossibilities(num, 6),
			getColumnPossibilities(num, 7),
			getColumnPossibilities(num, 8),
			getColumnPossibilities(num, 9)
		};*/

		/*unsigned int column_possibilities_arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

		getColumns(num, column_possibilities_arr);

		for(int column = 1; column < 10; column++){

			if(getColumnPossibility(num, column) == 0) continue;

			const unsigned int column_possibilities = column_possibilities_arr[column];
			//const unsigned int column_possibilities = getColumnPossibilities(num, column);

			//printf("%d\n", row_possibilities);

			constexpr unsigned int masks[3] = {
				0b111'111'000'0,	//first box
				0b111'000'111'0,	//second box
				0b000'111'111'0		//third box
			};

			int num_box;

			if( (column_possibilities & masks[0]) == 0)
				num_box = 0;	//first box

			else if( (column_possibilities & masks[1]) == 0)
				num_box = 1;	//second box

			else if( (column_possibilities & masks[2]) == 0)
				num_box = 2;	//third box

			else continue;


			constexpr char column_combinations[10][2] = {
					// 0	   1	   2	   3	   4
					{0, 0}, {2, 3}, {1, 3}, {1, 2}, {5, 6},
					{4, 6}, {4, 5}, {8, 9}, {7, 9}, {7, 8}
					// 5	   6	   7	   8	   9
			};

			const int column1 = column_combinations[column][0];
			const int column2 = column_combinations[column][1];

			#ifdef PRINT_DEBUG
				if(		column_possibilities_arr[column1] != (column_possibilities_arr[column1] & masks[num_box]) )
					||	( column_possibilities_arr[column2] != column_possibilities_arr[column2] & masks[num_box]) ) ){

					printf("boooooooom same column	num: %d column: %d num_box: %d\n", num, column, num_box + 1);

				}
			#endif

			const int new_possibilities_col1 = column_possibilities_arr[column1] & masks[num_box];
			const int new_possibilities_col2 = column_possibilities_arr[column2] & masks[num_box];

			column_possibilities_arr[column1] = new_possibilities_col1;
			column_possibilities_arr[column2] = new_possibilities_col2;

			setPossibilitiesColumn(column1, new_possibilities_col1, num);
			setPossibilitiesColumn(column2, new_possibilities_col2, num);

		}*/

		/*int box1 = 1;
		int box2 = 4;
		int box3 = 7;

		for(int column = 1; column < 3; column++){

			//const unsigned int column_possibilities = column_possibilities_arr[column];
			const unsigned int box1_possibilities = getColumnPossibilities(num, box1);
			const unsigned int box2_possibilities = getColumnPossibilities(num, box2);
			const unsigned int box3_possibilities = getColumnPossibilities(num, box3);

			int box1_predicate = !(getColumnPossibility(num, box1) == 0);
			int box2_predicate = !(getColumnPossibility(num, box2) == 0);
			int box3_predicate = !(getColumnPossibility(num, box3) == 0);

			//printf("%d %d %d\n", box1_predicate, box2_predicate, box3_predicate);

			constexpr unsigned int masks[3] = {
				0b111'111'000'0,	//first box
				0b111'000'111'0,	//second box
				0b000'111'111'0		//third box
			};

			box1_predicate = box1_predicate * ( ((box1_possibilities & masks[0]) == 0) | (((box1_possibilities & masks[1]) == 0) * 2) | (((box1_possibilities & masks[2]) == 0) * 3) );
			box2_predicate = box2_predicate * ( ((box2_possibilities & masks[0]) == 0) | (((box2_possibilities & masks[1]) == 0) * 2) | (((box2_possibilities & masks[2]) == 0) * 3) );
			box3_predicate = box3_predicate * ( ((box3_possibilities & masks[0]) == 0) | (((box3_possibilities & masks[1]) == 0) * 2) | (((box3_possibilities & masks[2]) == 0) * 3) );

			//printf("%d %d %d\n\n", box1_predicate, box2_predicate, box3_predicate);

			constexpr char column_combinations[10][2] = {
					// 0	   1	   2	   3	   4
					{0, 0}, {2, 3}, {1, 3}, {1, 2}, {5, 6},
					{4, 6}, {4, 5}, {8, 9}, {7, 9}, {7, 8}
					// 5	   6	   7	   8	   9
			};

			if(box1_predicate != 0){

				const int column1 = column_combinations[box1][0];
				const int column2 = column_combinations[box1][1];

				setPossibilitiesColumn(column1, getColumnPossibilities(num, column1) & masks[box1_predicate - 1], num);
				setPossibilitiesColumn(column2, getColumnPossibilities(num, column2) & masks[box1_predicate - 1], num);

			}

			if(box2_predicate != 0){

				const int column1 = column_combinations[box2][0];
				const int column2 = column_combinations[box2][1];

				setPossibilitiesColumn(column1, getColumnPossibilities(num, column1) & masks[box1_predicate - 1], num);
				setPossibilitiesColumn(column2, getColumnPossibilities(num, column2) & masks[box1_predicate - 1], num);

			}

			if(box3_predicate != 0){

				const int column1 = column_combinations[box3][0];
				const int column2 = column_combinations[box3][1];

				setPossibilitiesColumn(column1, getColumnPossibilities(num, column1) & masks[box1_predicate - 1], num);
				setPossibilitiesColumn(column2, getColumnPossibilities(num, column2) & masks[box1_predicate - 1], num);

			}

			box1++;
			box2++;
			box3++;

			#ifdef PRINT_DEBUG
				if(		( getColumnPossibilities(num, column1) != (getColumnPossibilities(num, column1) & masks[num_box]) )
					||	( getColumnPossibilities(num, column2) != (getColumnPossibilities(num, column2) & masks[num_box]) ) ){

					printf("boooooooom same column	num: %d column: %d num_box: %d\n", num, column, num_box + 1);

				}
			#endif

		}*/


		//Box
		for(int box = 1; box < 10; box++){

			if(getBoxPossibility(num, box) == 0) continue;

			//const unsigned int box_possibilities = getBoxPossibilities(num, box);
			//printf("%d\n", row_possibilities);

			//constexpr unsigned int masks[3] = {
			//	0b111'111'000'0,	//first box
			//	0b111'000'111'0,	//second box
			//	0b000'111'111'0		//third box
			//};

			constexpr unsigned int masks_inv[3] = {
				0b000'000'111'0,	//first box
				0b000'111'000'0,	//second box
				0b111'000'000'0		//third box
			};

			//constexpr int num_box_in_row [9] = {1, 2, 3, 1, 2, 3, 1, 2, 3};

			//all options for num in box
			//are in a single row

			const int num_box = box_index_to_column_lookup[box];
			const unsigned int mask_inv = masks_inv[num_box - 1];

			const int row1_index = boxToRow(box, 1);
			const int row2_index = boxToRow(box, 4);
			const int row3_index = boxToRow(box, 7);

			const unsigned int row1 = getRowPossibilities(num, row1_index);
			const unsigned int row2 = getRowPossibilities(num, row2_index);
			const unsigned int row3 = getRowPossibilities(num, row3_index);

			const unsigned int row1_masked = mask_inv & row1;
			const unsigned int row2_masked = mask_inv & row2;
			const unsigned int row3_masked = mask_inv & row3;

			//printf("num: %d box: %d\n", num, box);
			//printf("row1 %d\n", row1);
			//printf("row2 %d\n", row2_masked);
			//printf("row3 %d\n", row3_masked);

			if( (row1_masked | row2_masked) == 0 ){

				#ifdef PRINT_DEBUG
					if( getRowPossibilities(num, row3_index) != (getRowPossibilities(num, row3_index) & mask_inv) )
						printf("boooooooom1 same box	num: %d box: %d row: %d\n", num, box, row3_index);
				#endif

				setPossibilitiesRow(row3_index, getRowPossibilities(num, row3_index) & mask_inv, num);


			}
			else if( (row2_masked | row3_masked) == 0 ){

				#ifdef PRINT_DEBUG
					if( getRowPossibilities(num, row1_index) != (getRowPossibilities(num, row1_index) & mask_inv) )
						printf("boooooooom2 same box	num: %d box: %d row: %d\n", num, box, row1_index);
				#endif

				setPossibilitiesRow(row1_index, getRowPossibilities(num, row1_index) & mask_inv, num);


			}
			else if( (row1_masked | row3_masked) == 0 ){

				#ifdef PRINT_DEBUG
					if( getRowPossibilities(num, row2_index) != (getRowPossibilities(num, row2_index) & mask_inv) )
						printf("boooooooom3 same box	num: %d box: %d row: %d\n", num, box, row2_index);
				#endif

				setPossibilitiesRow(row2_index, getRowPossibilities(num, row2_index) & mask_inv, num);


			}



		}


		//Box
		for(int box = 1; box < 10; box++){

			if(getBoxPossibility(num, box) == 0) continue;

			//const unsigned int box_possibilities = getBoxPossibilities(num, box);
			//printf("%d\n", row_possibilities);

			//constexpr unsigned int masks[3] = {
			//	0b111'111'000'0,	//first box
			//	0b111'000'111'0,	//second box
			//	0b000'111'111'0		//third box
			//};

			constexpr unsigned int masks_inv[3] = {
				0b000'000'111'0,	//first box
				0b000'111'000'0,	//second box
				0b111'000'000'0		//third box
			};

			constexpr int num_box_in_column [9] = {1, 1, 1, 2, 2, 2, 3, 3, 3};

			//all options for num in box
			//are in a single row

			const int num_box = num_box_in_column[box - 1];
			const unsigned int mask_inv = masks_inv[num_box - 1];

			const int column1_index = boxToColumn(box, 1);
			const int column2_index = boxToColumn(box, 2);
			const int column3_index = boxToColumn(box, 3);

			const unsigned int column1 = getColumnPossibilities(num, column1_index);
			const unsigned int column2 = getColumnPossibilities(num, column2_index);		//predelat na +?
			const unsigned int column3 = getColumnPossibilities(num, column3_index);

			const unsigned int column1_masked = mask_inv & column1;
			const unsigned int column2_masked = mask_inv & column2;
			const unsigned int column3_masked = mask_inv & column3;

			//printf("num: %d box: %d\n", num, box);
			//printf("row1 %d\n", row1);
			//printf("row2 %d\n", row2_masked);
			//printf("row3 %d\n", row3_masked);

			if( (column1_masked | column2_masked) == 0 ){

				#ifdef PRINT_DEBUG
					if( getColumnPossibilities(num, column3_index) != (getColumnPossibilities(num, column3_index) & mask_inv) )
						printf("boooooooom4 same box	num: %d box: %d column: %d\n", num, box, column3_index);
				#endif

				setPossibilitiesColumn(column3_index, getColumnPossibilities(num, column3_index) & mask_inv, num);


			}
			else if( (column2_masked | column3_masked) == 0 ){

				#ifdef PRINT_DEBUG
					if( getColumnPossibilities(num, column1_index) != (getColumnPossibilities(num, column1_index) & mask_inv) )
						printf("boooooooom5 same box	num: %d box: %d column: %d\n", num, box, column1_index);
				#endif

				setPossibilitiesColumn(column1_index, getColumnPossibilities(num, column1_index) & mask_inv, num);


			}
			else if( (column1_masked | column3_masked) == 0 ){

				#ifdef PRINT_DEBUG
					if( getColumnPossibilities(num, column2_index) != (getColumnPossibilities(num, column2_index) & mask_inv) )
						printf("boooooooom6 same box	num: %d box: %d column: %d\n", num, box, column2_index);
				#endif

				setPossibilitiesColumn(column2_index, getColumnPossibilities(num, column2_index) & mask_inv, num);


			}



		}

	}

	return;

}
