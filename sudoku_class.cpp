
#ifndef SUDOKU_CLASS
	#define SUDOKU_CLASS
	#include "define.h"
#endif

/*

		┌───────┬───────┬───────┐
		│       │       │       │
		│       │       │       │
		│       │       │       │
		├───────┼───────┼───────┤
		│       │       │       │
		│       │       │       │
		│       │       │       │
		├───────┼───────┼───────┤
		│       │       │       │
		│       │       │       │
		│       │       │       │
		└───────┴───────┴───────┘


	Box:
		Box 0 :
		┌───────┬───────┬───────┐
		│       │       │       │
		│   1   │   2   │   3   │
		│       │       │       │
		├───────┼───────┼───────┤
		│       │       │       │
		│   4   │   5   │   6   │
		│       │       │       │
		├───────┼───────┼───────┤
		│       │       │       │
		│   7   │   8   │   9   │
		│       │       │       │
		└───────┴───────┴───────┘


	Row:
		  0
		┌───────┬───────┬───────┐
		│ 1     │       │       │
		│ 2     │       │       │
		│ 3     │       │       │
		├───────┼───────┼───────┤
		│ 4     │       │       │
		│ 5     │       │       │
		│ 6     │       │       │
		├───────┼───────┼───────┤
		│ 7     │       │       │
		│ 8     │       │       │
		│ 9     │       │       │
		└───────┴───────┴───────┘


	Column:
		┌───────┬───────┬───────┐
	  0 │ 1 2 3 │ 4 5 6 │ 7 8 9 │
		│       │       │       │
		│       │       │       │
		├───────┼───────┼───────┤
		│       │       │       │
		│       │       │       │
		│       │       │       │
		├───────┼───────┼───────┤
		│       │       │       │
		│       │       │       │
		│       │       │       │
		└───────┴───────┴───────┘



	Possibilities:

	short int sudoku_possibilities[10][10];			//[number][row]
									    98 7654 321
	sudoku_possibilities[1][1] = 0000 0011 1111 1110;

		╔═════════════════╦═════════════════╦═════════════════╗
		║ x23 │ 123 │ 123 ║ 123 │ 123 │ 123 ║ 123 │ 123 │ 123 ║
		║ 456 │ 456 │ 456 ║ 456 │ 456 │ 456 ║ 456 │ 456 │ 456 ║
		║ 789 │ 789 │ 789 ║ 789 │ 789 │ 789 ║ 789 │ 789 │ 789 ║
		║ ────┼─────┼──── ║ ────┼─────┼──── ║ ────┼─────┼──── ║
        ║ 123 │ 123 │ 123 ║ 123 │ 123 │ 123 ║ 123 │ 123 │ 123 ║
        ║ 456 │ 456 │ 456 ║ 456 │ 456 │ 456 ║ 456 │ 456 │ 456 ║
		║ 789 │ 789 │ 789 ║ 789 │ 789 │ 789 ║ 789 │ 789 │ 789 ║
		║ ────┼─────┼──── ║ ────┼─────┼──── ║ ────┼─────┼──── ║
		║ 123 │ 123 │ 123 ║ 123 │ 123 │ 123 ║ 123 │ 123 │ 123 ║
		║ 456 │ 456 │ 456 ║ 456 │ 456 │ 456 ║ 456 │ 456 │ 456 ║
		║ 789 │ 789 │ 789 ║ 789 │ 789 │ 789 ║ 789 │ 789 │ 789 ║
		╠═════════════════╬═════════════════╬═════════════════╣
		║ 123 │ 123 │ 123 ║ 123 │ 123 │ 123 ║ 123 │ 123 │ 123 ║
		║ 456 │ 456 │ 456 ║ 456 │ 456 │ 456 ║ 456 │ 456 │ 456 ║
		║ 789 │ 789 │ 789 ║ 789 │ 789 │ 789 ║ 789 │ 789 │ 789 ║
		║ ────┼─────┼──── ║ ────┼─────┼──── ║ ────┼─────┼──── ║
		║ 123 │ 123 │ 123 ║ 123 │ 123 │ 123 ║ 123 │ 123 │ 123 ║
		║ 456 │ 456 │ 456 ║ 456 │ 456 │ 456 ║ 456 │ 456 │ 456 ║
		║ 789 │ 789 │ 789 ║ 789 │ 789 │ 789 ║ 789 │ 789 │ 789 ║
		║ ────┼─────┼──── ║ ────┼─────┼──── ║ ────┼─────┼──── ║
		║ 123 │ 123 │ 123 ║ 123 │ 123 │ 123 ║ 123 │ 123 │ 123 ║
		║ 456 │ 456 │ 456 ║ 456 │ 456 │ 456 ║ 456 │ 456 │ 456 ║
		║ 789 │ 789 │ 789 ║ 789 │ 789 │ 789 ║ 789 │ 789 │ 789 ║
		╠═════════════════╬═════════════════╬═════════════════╣
		║ 123 │ 123 │ 123 ║ 123 │ 123 │ 123 ║ 123 │ 123 │ 123 ║
        ║ 456 │ 456 │ 456 ║ 456 │ 456 │ 456 ║ 456 │ 456 │ 456 ║
        ║ 789 │ 789 │ 789 ║ 789 │ 789 │ 789 ║ 789 │ 789 │ 789 ║
		║ ────┼─────┼──── ║ ────┼─────┼──── ║ ────┼─────┼──── ║
		║ 123 │ 123 │ 123 ║ 123 │ 123 │ 123 ║ 123 │ 123 │ 123 ║
		║ 456 │ 456 │ 456 ║ 456 │ 456 │ 456 ║ 456 │ 456 │ 456 ║
		║ 789 │ 789 │ 789 ║ 789 │ 789 │ 789 ║ 789 │ 789 │ 789 ║
		║ ────┼─────┼──── ║ ────┼─────┼──── ║ ────┼─────┼──── ║
		║ 123 │ 123 │ 123 ║ 123 │ 123 │ 123 ║ 123 │ 123 │ 123 ║
		║ 456 │ 456 │ 456 ║ 456 │ 456 │ 456 ║ 456 │ 456 │ 456 ║
		║ 789 │ 789 │ 789 ║ 789 │ 789 │ 789 ║ 789 │ 789 │ 789 ║
		╚═════════════════╩═════════════════╩═════════════════╝



*/

/*struct row{

	short int mask = 0x3fe;
	char values

};*/

//#define PRINT_DEBUG
#define FAST_BOX_TO_ROW_COLUMN
#define EVEN_FASTER_BOX_TO_ROW_COLUMN

class sudoku{

	private:

		int sudoku_pole[10][10];						//[row][column]
		unsigned int sudoku_possibilities[10][10];			//[number][row]

		unsigned int rows_mask[10] = {	0x3fe, 0x3fe, 0x3fe, 0x3fe, 0x3fe,
										0x3fe, 0x3fe, 0x3fe, 0x3fe, 0x3fe};

		unsigned int columns_mask[10] = {	0x3fe, 0x3fe, 0x3fe, 0x3fe, 0x3fe,
											0x3fe, 0x3fe, 0x3fe, 0x3fe, 0x3fe};

		unsigned int box_mask[10] = {	0x3fe, 0x3fe, 0x3fe, 0x3fe, 0x3fe,
										0x3fe, 0x3fe, 0x3fe, 0x3fe, 0x3fe};

		int count[10] = {0, 9, 9, 9, 9,
						 9, 9, 9, 9, 9};

		/*int guess;
		int guess_cordinates[2];*/

		#ifdef EVEN_FASTER_BOX_TO_ROW_COLUMN

		constexpr static char box_to_row_lookup[10] = 		{0, 0, 0, 0, 3, 3, 3, 6, 6, 6};
		constexpr static char box_index_to_row_lookup[10] =	{0, 1, 1, 1, 2, 2, 2, 3, 3, 3};

		constexpr static char box_to_column_lookup[10] = 		{0, 0, 3, 6, 0, 3, 6, 0, 3, 6};
		constexpr static char box_index_to_column_lookup[10] =	{0, 1, 2, 3, 1, 2, 3, 1, 2, 3};

		constexpr static char column_to_box_lookup[10] = 	{0, 1, 1, 1, 2, 2, 2, 3, 3, 3};
		constexpr static char row_to_box_lookup[10] =		{0, 0, 0, 0, 3, 3, 3, 6, 6, 6};

		#else
		#ifdef FAST_BOX_TO_ROW_COLUMN

									// box box_index
		constexpr static char box_to_row_lookup[10][10] =
		{
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//box 0
			{0, 1, 1, 1, 2, 2, 2, 3, 3, 3},	//box 1
			{0, 1, 1, 1, 2, 2, 2, 3, 3, 3},	//box 2
			{0, 1, 1, 1, 2, 2, 2, 3, 3, 3},	//box 3
			{0, 4, 4, 4, 5, 5, 5, 6, 6, 6},	//box 4
			{0, 4, 4, 4, 5, 5, 5, 6, 6, 6},	//box 5
			{0, 4, 4, 4, 5, 5, 5, 6, 6, 6},	//box 6
			{0, 7, 7, 7, 8, 8, 8, 9, 9, 9},	//box 7
			{0, 7, 7, 7, 8, 8, 8, 9, 9, 9},	//box 8
			{0, 7, 7, 7, 8, 8, 8, 9, 9, 9},	//box 9

		};

										// box box_index
		constexpr static char box_to_column_lookup[10][10] =
		{
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//box 0
			{0, 1, 2, 3, 1, 2, 3, 1, 2, 3},	//box 1
			{0, 4, 5, 6, 4, 5, 6, 4, 5, 6},	//box 2
			{0, 7, 8, 9, 7, 8, 9, 7, 8, 9},	//box 3
			{0, 1, 2, 3, 1, 2, 3, 1, 2, 3},	//box 4
			{0, 4, 5, 6, 4, 5, 6, 4, 5, 6},	//box 5
			{0, 7, 8, 9, 7, 8, 9, 7, 8, 9},	//box 6
			{0, 1, 2, 3, 1, 2, 3, 1, 2, 3},	//box 7
			{0, 4, 5, 6, 4, 5, 6, 4, 5, 6},	//box 8
			{0, 7, 8, 9, 7, 8, 9, 7, 8, 9},	//box 9

		};

											// box box_index
		constexpr static char row_column_to_box[10][10] =
		{
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//box 0
			{0, 1, 1, 1, 2, 2, 2, 3, 3, 3},	//box 1
			{0, 1, 1, 1, 2, 2, 2, 3, 3, 3},	//box 2
			{0, 1, 1, 1, 2, 2, 2, 3, 3, 3},	//box 3
			{0, 4, 4, 4, 5, 5, 5, 6, 6, 6},	//box 4
			{0, 4, 4, 4, 5, 5, 5, 6, 6, 6},	//box 5
			{0, 4, 4, 4, 5, 5, 5, 6, 6, 6},	//box 6
			{0, 7, 7, 7, 8, 8, 8, 9, 9, 9},	//box 7
			{0, 7, 7, 7, 8, 8, 8, 9, 9, 9},	//box 8
			{0, 7, 7, 7, 8, 8, 8, 9, 9, 9},	//box 9

		};

		#endif
		#endif

		constexpr static unsigned int box_masks[4] = {
			0b000'000'000'0,
			0b111'111'000'0,	//first box
			0b111'000'111'0,	//second box
			0b000'111'111'0		//third box
		};

		unsigned int checksum_value;

	public:

		//Print
		//sudoku_print.cpp
		void print_grid();
		void print_debug();
		void print_debug2();
		void print_possibilities();


		//Solving techniques
		//sudoku_solving_techniques.cpp
		void naked_single() noexcept;
		void only_option() noexcept;
		void sameRowColumnBox() noexcept;
		void pair() noexcept;
		void x_wing() noexcept;
		void hidden_triple() noexcept;
		void hidden_quadrouple() noexcept;

		//Get functions
		//sudoku_get_functions.cpp

			//square
			[[nodiscard]] constexpr int getVal(int row, int column) const noexcept;
			[[nodiscard]] constexpr unsigned int getSquarePossibility(int num, int row, int column) const noexcept;
			[[nodiscard]] constexpr unsigned int getSquarePossibilities(int row, int column) const noexcept;

			//row
			[[nodiscard]] constexpr unsigned int getRowPossibility(int num, int row) const noexcept;
			[[nodiscard]] constexpr unsigned int getRowPossibilities(int num, int row) const noexcept;

			//column
			[[nodiscard]] constexpr unsigned int getColumnPossibility(int num, int column) const noexcept;
			[[nodiscard]] constexpr unsigned int getColumnPossibilities(int num, int column) const noexcept;
			constexpr void getColumns(int num, unsigned int columns[]) noexcept;

			//box
			[[nodiscard]] constexpr unsigned int getBoxPossibility(int num, int box) const noexcept;
			[[nodiscard]] constexpr unsigned int getBoxPossibilities(int num, int box_index) const noexcept;

			//count
			[[nodiscard]] constexpr int getCount(int num) const noexcept;

			//masks
			[[nodiscard]] constexpr unsigned int getRowMask(int row) const noexcept;
			[[nodiscard]] constexpr unsigned int getColumnMask(int column) const noexcept;
			[[nodiscard]] constexpr unsigned int getBoxMask(int box) const noexcept;


		explicit sudoku(unsigned int initial_values[9]) noexcept {

			/*
			line[1] = 900027050;
			line[2] =  50000904;
			line[3] = 000000000;
			line[4] = 800075649;
			line[5] = 100040000;
			line[6] =      9800;
			line[7] =    400000;
			line[8] =     30010;
			line[9] = 501002037;
			*/

			for(int number = 1; number < 10; number++){

				for(int row = 1; row < 10; row++){

					sudoku_possibilities[number][row] = 0x3fe;

				}

			}

			for(int row = 1; row < 10; row++){

				for(int column = 9; column > 0; column--){

					int num = (int)initial_values[row - 1] % 10;

					setVal(row, column, num);

					initial_values[row - 1] = initial_values[row - 1] / 10;

				}

			}

		}

		explicit sudoku(std::ifstream& file) noexcept {

			for(int number = 1; number < 10; number++){

				for(int row = 1; row < 10; row++){

					sudoku_possibilities[number][row] = 0x3fe;

				}

			}

			std::string str;
			std::getline(file, str);

			auto it = str.begin();

			for(int row = 1; row < 10; row++){

				for(int column = 9; column > 0; column--){

					const int num = *it - '0';
					setVal(row, column, num);

					it++;

				}

			}

		}

		/*explicit sudoku() = default;

		explicit sudoku(const sudoku &original) noexcept = default;

		sudoku& operator = (const sudoku* original){

			memcpy(sudoku_pole, original->sudoku_pole, sizeof(sudoku_pole));
			memcpy(sudoku_possibilities, original->sudoku_possibilities, sizeof(sudoku_possibilities));
			memcpy(rows_mask, original->rows_mask, sizeof(rows_mask));
			memcpy(columns_mask, original->columns_mask, sizeof(columns_mask));
			memcpy(box_mask, original->box_mask, sizeof(box_mask));
			memcpy(count, original->count, sizeof(count));

			return *this;

		};

		void solve() noexcept{

			update_checksum();

			while(1){

				naked_single();
				only_option();

				if(did_checksum_change_update()){
					if(get_checksum() != 0) continue;
					break;
				}
				else if(get_checksum() == 0){
					break;
				}

				pair();

				if(did_checksum_change_update()){
					if(get_checksum() != 0) continue;
					break;
				}
				else if(get_checksum() == 0){
					break;
				}

				sameRowColumnBox();

				if(did_checksum_change_update()){
					if(get_checksum() != 0) continue;
					break;
				}
				else if(get_checksum() == 0){
					break;
				}

				sudoku sudoku_guess;

				sudoku_guess = this;

				sudoku_guess.guess();
				sudoku_guess.solve();

				break;

			}

		}

		void guess(){

			for(int i = 1; i < 10; i++){

				unsigned int row = getRowPossibilities(i);

				if(__builtin_popcount(row) == 2) {



				}

			}

		};*/

		constexpr void setVal(int row, int column, int num) noexcept {

			sudoku_pole[row][column] = num;

			if(num != 0) clearPossibilities(row, column);

			count[num]--;

			const int box = rowColumnToBox(row, column);
			const unsigned int mask = ~(1U << num);

			rows_mask[row] = rows_mask[row] & mask;
			columns_mask[column] = columns_mask[column] & mask;
			box_mask[box] = box_mask[box] & mask;

			//Same Row
			clearRowPossibilities(num, row);

			//Same Column
			clearColumnPossibilities(num, column);

			//Same Box
			clearBoxPossibilities(num, row, column);

			return;

		}

		constexpr int is_bad() const noexcept {

			int valid = 0;

			for(int num = 1; num < 10; num++){

				valid = valid | count[num];

			}

			if(valid != 0) return 1;

			for(int column = 1; column < 10; column++){

				for(int row = 1; row < 10; row++){

					const int num = getVal(row, column);

					if(num == 0) return 1;

					for(int row2 = row + 1; row2 < 10; row2++){

						const int num2 = getVal(row2, column);

						if(num2 == 0) return 1;

						if(num == num2) return 1;

					}

				}

			}

			for(int row = 1; row < 10; row++){

				for(int column = 1; column < 10; column++){

					const int num = getVal(row, column);

					if(num == 0) return 1;

					for(int column2 = column + 1; column2 < 10; column2++){

						const int num2 = getVal(row, column2);

						if(num2 == 0) return 1;

						if(num == num2) return 1;

					}

				}

			}

			return 0;

		}

		constexpr unsigned int checksum() const noexcept {

			unsigned int chksm = 0;

			for(int num = 1; num < 10; num++){

				chksm += sudoku_possibilities[num][1];
				chksm += sudoku_possibilities[num][2];
				chksm += sudoku_possibilities[num][3];
				chksm += sudoku_possibilities[num][4];
				chksm += sudoku_possibilities[num][5];
				chksm += sudoku_possibilities[num][6];
				chksm += sudoku_possibilities[num][7];
				chksm += sudoku_possibilities[num][8];
				chksm += sudoku_possibilities[num][9];

			}

			return chksm;

		}

		constexpr unsigned int get_checksum() const noexcept {

			return checksum_value;

		}

		constexpr unsigned int update_checksum() noexcept {

			unsigned int chksm = 0;

			for(int num = 1; num < 10; num++){

				chksm += sudoku_possibilities[num][1];
				chksm += sudoku_possibilities[num][2];
				chksm += sudoku_possibilities[num][3];
				chksm += sudoku_possibilities[num][4];
				chksm += sudoku_possibilities[num][5];
				chksm += sudoku_possibilities[num][6];
				chksm += sudoku_possibilities[num][7];
				chksm += sudoku_possibilities[num][8];
				chksm += sudoku_possibilities[num][9];

			}

			checksum_value = chksm;

			return checksum_value;

		}

		constexpr unsigned int did_checksum_change() const noexcept {

			unsigned int chksm = 0;

			for(int num = 1; num < 10; num++){

				chksm += sudoku_possibilities[num][1];
				chksm += sudoku_possibilities[num][2];
				chksm += sudoku_possibilities[num][3];
				chksm += sudoku_possibilities[num][4];
				chksm += sudoku_possibilities[num][5];
				chksm += sudoku_possibilities[num][6];
				chksm += sudoku_possibilities[num][7];
				chksm += sudoku_possibilities[num][8];
				chksm += sudoku_possibilities[num][9];

			}

			return (checksum_value != chksm);

		}

		constexpr unsigned int did_checksum_change_update() noexcept {

			unsigned int chksm = 0;

			for(int num = 1; num < 10; num++){

				chksm += sudoku_possibilities[num][1];
				chksm += sudoku_possibilities[num][2];
				chksm += sudoku_possibilities[num][3];
				chksm += sudoku_possibilities[num][4];
				chksm += sudoku_possibilities[num][5];
				chksm += sudoku_possibilities[num][6];
				chksm += sudoku_possibilities[num][7];
				chksm += sudoku_possibilities[num][8];
				chksm += sudoku_possibilities[num][9];

			}

			const unsigned int changed = checksum_value != chksm;

			checksum_value = chksm;

			return changed;

		}

		/*char getValBox(int box, int box_index){

			int index_row = 0;

			if(box > 3) index_row = 3;
			else if(box > 6) index_row = 6;

			if(box_index > 3) index_row++;
			if(box_index > 6) index_row++;


			int index_column = 0;

			if( (box == 2) || (box == 5) || (box == 8) ) index_column = 3;
			else if( (box == 3) || (box == 6) || (box == 9) ) index_column = 6;

			if(box_index > 3) index_row++;
			if(box_index > 6) index_row++;


			return sudoku_pole[column][row];

		}*/

		constexpr void clearPossibilitiesNum(int row, int column, int num) noexcept {

			//nastavi possibility pro dany num v dane row a column na 0

			rows_mask[row] = rows_mask[row] & ~(1U << num);
			columns_mask[column] = columns_mask[column] & ~(1U << num);

			unsigned int mask = 1 << (column - 1);
			mask = ~mask;

			for(int i = 1; i < 10; i++){

				sudoku_possibilities[i][row] = sudoku_possibilities[i][row] & mask;

			}

		}

		/*void setPossibilitiesNums(int num_possibilities, int row, int column){

			for(int i = 1; i < 10; i++){

				short int mask = 1 << (i - 1);
				mask = mask;

				sudoku_possibilities[num][row] = sudoku_possibilities[i][row] & mask;
			}

		}*/

		constexpr void setRowPossibilities(int num, int row_index, unsigned int possibilities) noexcept {

			sudoku_possibilities[num][row_index] = possibilities;

		}

		constexpr void clearRowPossibilities(int num, int row_index) noexcept {

			sudoku_possibilities[num][row_index] = 0;

		}

		constexpr void clearColumnPossibilities(int num, int column_index) noexcept {

			const unsigned int mask = ~(1U << column_index);

			for(int row = 1; row < 10; row++){

				sudoku_possibilities[num][row] = sudoku_possibilities[num][row] & mask;

			}

		}

		/*constexpr void clearBoxPossibilities(int num, int box_index) noexcept {

			unsigned int mask;
			int row;

			switch(box_index){

				case 1: case 4: case 7:

					mask = 0b000'111'111'0;

				break;

				case 2: case 5: case 8:

					mask = 0b111'000'111'0;

				break;

				case 3: case 6: case 9:

					mask = 0b111'111'000'0;

				break;


			}

			switch(box_index){

				case 1: case 2: case 3:
					row = 0;

				break;

				case 6: case 5: case 4:

					row = 1;

				break;

				case 7: case 8: case 9:

					row = 2;

				break;


			}

			sudoku_possibilities[num][row * 3 + 1] = sudoku_possibilities[num][row * 3 + 1] & mask;
			sudoku_possibilities[num][row * 3 + 2] = sudoku_possibilities[num][row * 3 + 2] & mask;
			sudoku_possibilities[num][row * 3 + 3] = sudoku_possibilities[num][row * 3 + 3] & mask;

		}*/

		constexpr void clearBoxPossibilities(int num, int row, int column) noexcept {

			const int column_index = column_to_box_lookup[column];
			const unsigned int mask = box_masks[column_index];

			const int third = row_to_box_lookup[row];

			sudoku_possibilities[num][third + 1] = sudoku_possibilities[num][third + 1] & mask;
			sudoku_possibilities[num][third + 2] = sudoku_possibilities[num][third + 2] & mask;
			sudoku_possibilities[num][third + 3] = sudoku_possibilities[num][third + 3] & mask;

		}

		constexpr void clearPossibilities(int row, int column) noexcept {

			const unsigned int mask = ~(1U << column);

			for(int num = 1; num < 10; num++){

				sudoku_possibilities[num][row] = sudoku_possibilities[num][row] & mask;

			}

		}

		constexpr void setPossibilities(int row, int column, unsigned int possibilities) noexcept {

			const unsigned int mask = 1U << column;

			for(int num = 1; num < 10; num++){

				possibilities = possibilities >> 1;

				unsigned int bit = !(possibilities & 1);

				bit = ~(mask * bit);

				bit = bit & (4294967294);		//set 0th bit to 0

				sudoku_possibilities[num][row] = sudoku_possibilities[num][row] & bit;

			}

		}

		constexpr void setPossibilitiesColumn(int column_index, unsigned int possibilities, int num) noexcept {

			unsigned int mask = 1 << column_index;

			for(int row = 1; row < 10; row++){

				unsigned int bit = possibilities & (1U << row);

				bit = (unsigned int) __builtin_popcount(bit);

				sudoku_possibilities[num][row] = sudoku_possibilities[num][row] & ~mask;
				sudoku_possibilities[num][row] = sudoku_possibilities[num][row] | bit * mask;

			}

		}

		constexpr void setPossibilitiesRow(int row_index, unsigned int possibilities, int num) noexcept {

			sudoku_possibilities[num][row_index] = possibilities;

		}


		[[nodiscard]] constexpr int boxToRow(int box, int box_index) const noexcept {

			#ifdef EVEN_FASTER_BOX_TO_ROW_COLUMN

			return (int)box_to_row_lookup[box] + box_index_to_row_lookup[box_index];

			#else
			#ifdef FAST_BOX_TO_ROW_COLUMN

			return (int)box_to_row_lookup[box][box_index];

			#else

			int row;

			box_index = box_index - 1;
			box_index = box_index / 3;

			box = box - 1;
			box = box / 3;

			row = box * 3 + box_index;

			return row + 1;

			#endif
			#endif

		}

		[[nodiscard]] constexpr int boxToColumn(int box, int box_index) const noexcept {

			#ifdef EVEN_FASTER_BOX_TO_ROW_COLUMN

			return (int)box_to_column_lookup[box] + box_index_to_column_lookup[box_index];

			#else
			#ifdef FAST_BOX_TO_ROW_COLUMN

			return (int)box_to_column_lookup[box][box_index];

			#else

			int column;

			box_index = box_index - 1;
			box_index = box_index % 3;

			box = box - 1;
			box = box % 3;

			column = box * 3 + box_index;

			return column + 1;

			#endif
			#endif

		}

		[[nodiscard]] constexpr int rowColumnToBox(int row, int column) const noexcept {

			#ifdef EVEN_FASTER_BOX_TO_ROW_COLUMN

			return (int)row_to_box_lookup[row] + column_to_box_lookup[column];

			#else
			#ifdef FAST_BOX_TO_ROW_COLUMN

			return (int)row_column_to_box[row][column];

			#else

			int box;

			column = column - 1;
			column = column / 3;

			row = row - 1;
			row = row / 3;

			box = row * 3 + column;

			return box + 1;

			#endif
			#endif

		}

};
