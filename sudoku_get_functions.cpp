
#ifndef SUDOKU_GET_FUNCTIONS
	#define SUDOKU_GET_FUNCTIONS
	#include "define.h"
#endif

//#define FAST_POSSIBILITY

//square
[[nodiscard]] constexpr int sudoku::getVal(int row, int column) const noexcept {

	return sudoku_pole[row][column];

}

[[nodiscard]] constexpr unsigned int sudoku::getSquarePossibility(int num, int row, int column) const noexcept {

	#ifdef FAST_POSSIBILITY

	const unsigned int mask = 1 << column;

	return (unsigned int)__builtin_popcount(sudoku_possibilities[num][row] & mask);

	#else

	return 1 & (sudoku_possibilities[num][row] >> column);

	#endif

}

[[nodiscard]] constexpr unsigned int sudoku::getSquarePossibilities(int row, int column) const noexcept {

	const unsigned int mask = 1 << column;
	unsigned int possibilities = 0;

	for(int num = 9; num > 0; num--){

		const unsigned int bit = (unsigned int)__builtin_popcount(sudoku_possibilities[num][row] & mask);

		possibilities = possibilities | bit;

		possibilities = possibilities << 1;

	}

	return possibilities;

}


//row
[[nodiscard]] constexpr unsigned int sudoku::getRowPossibility(int num, int row) const noexcept {

	#ifdef FAST_POSSIBILITY

	const unsigned int mask = 1 << num;

	return (unsigned int)__builtin_popcount(rows_mask[row] & mask);

	#else

	return 1 & (rows_mask[row] >> num);

	#endif

}

[[nodiscard]] constexpr unsigned int sudoku::getRowPossibilities(int num, int row) const noexcept {

	return sudoku_possibilities[num][row];

}

//column

[[nodiscard]] constexpr unsigned int sudoku::getColumnPossibility(int num, int column) const noexcept {

	#ifdef FAST_POSSIBILITY

	const unsigned int mask = 1 << num;

	return (unsigned int)__builtin_popcount(columns_mask[column] & mask);

	#else

	return 1 & (columns_mask[column] >> num);

	#endif

}

[[nodiscard]] constexpr unsigned int sudoku::getColumnPossibilities(int num, int column_index) const noexcept {

	unsigned int column = 0;
	const unsigned int mask = 1 << column_index;

	for(int row = 9; row > 0; row--){

		const unsigned int bit = (unsigned int)__builtin_popcount(getRowPossibilities(num, row) & mask);

		column = column | bit;

		column = column << 1;

	}

	return column;

}

constexpr void sudoku::getColumns(int num, unsigned int columns[]) noexcept {

	for(int row = 9; row > 0; row--){

		const unsigned int row_possibilities = getRowPossibilities(num, row);

		columns[1] = (columns[1] | (unsigned int)__builtin_popcount(row_possibilities & 2)) << 1;
		columns[2] = (columns[2] | (unsigned int)__builtin_popcount(row_possibilities & 4)) << 1;
		columns[3] = (columns[3] | (unsigned int)__builtin_popcount(row_possibilities & 8)) << 1;
		columns[4] = (columns[4] | (unsigned int)__builtin_popcount(row_possibilities & 16)) << 1;
		columns[5] = (columns[5] | (unsigned int)__builtin_popcount(row_possibilities & 32)) << 1;
		columns[6] = (columns[6] | (unsigned int)__builtin_popcount(row_possibilities & 64)) << 1;
		columns[7] = (columns[7] | (unsigned int)__builtin_popcount(row_possibilities & 128)) << 1;
		columns[8] = (columns[8] | (unsigned int)__builtin_popcount(row_possibilities & 256)) << 1;
		columns[9] = (columns[9] | (unsigned int)__builtin_popcount(row_possibilities & 512)) << 1;

	}

	return;

}


//box
[[nodiscard]] constexpr unsigned int sudoku::getBoxPossibility(int num, int box) const noexcept {

	#ifdef FAST_POSSIBILITY

	const unsigned int mask = 1 << num;

	return (unsigned int)__builtin_popcount(box_mask[box] & mask);

	#else

	return 1 & (box_mask[box] >> num);

	#endif

}

[[nodiscard]] constexpr unsigned int sudoku::getBoxPossibilities(int num, int box_index) const noexcept {

	const int row_index1 = boxToRow(box_index, 1);
	const int row_index2 = boxToRow(box_index, 4);
	const int row_index3 = boxToRow(box_index, 7);

	constexpr unsigned int start[10] = {0, 1, 4, 7, 1, 4, 7, 1, 4, 7};
	const unsigned int mask = (3 << 8) | start[box_index];

	const unsigned int row1 = __builtin_ia32_bextr_u32(sudoku_possibilities[num][row_index1], mask);
	const unsigned int row2 = __builtin_ia32_bextr_u32(sudoku_possibilities[num][row_index2], mask);
	const unsigned int row3 = __builtin_ia32_bextr_u32(sudoku_possibilities[num][row_index3], mask);

	return (row3 << 7) | (row2 << 4) | (row1 << 1);

}


//count
[[nodiscard]] constexpr int sudoku::getCount(int num) const noexcept {

	return count[num];

}


//mask
[[nodiscard]] constexpr unsigned int sudoku::getRowMask(int row) const noexcept {

	return rows_mask[row];

}

[[nodiscard]] constexpr unsigned int sudoku::getColumnMask(int column) const noexcept {

	return columns_mask[column];

}

[[nodiscard]] constexpr unsigned int sudoku::getBoxMask(int box) const noexcept {

	return box_mask[box];

}
