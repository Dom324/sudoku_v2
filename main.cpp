
#include "perf_macros.h"

#ifndef MAIN
	#define MAIN
	#include "define.h"
#endif

//__builtin_popcount()
//bextr_intrinsic(uint64_t src, uint64_t pattern)

int main(){

	std::ifstream file("49ktest.txt");

	const int num_puzzles = [&] {

		int pocet = 0;

		std::string str;
		std::getline(file, str);
		auto it = str.end() - 1;

		int i = 1;

		while(1){

			pocet = pocet + (*it - '0') * i;
			if(it == str.begin()) break;

			i = i * 10;
			it--;

		}

		return pocet;

	}();

	printf("%d\n", num_puzzles);

  	/*while(i < 100 & ()) {

	std::cout << str;
	std::cout << '\n';
		for (it=str.begin(); it!=str.end(); it++)
    	cout << *it;
    	cout << endl;
    	std::cout << str << "\n";

  	}*/

	int num_solved = 0;
	unsigned int num_iter = 0;
	unsigned int num_sameRowColumnBox = 0;
	int solved_bad = 0;

	for(int i = 0; i < num_puzzles; i++){

		/*unsigned int initial_values[9];

		initial_values[0] =  48000906;
		initial_values[1] =    406000;
		initial_values[2] =  56081300;
		initial_values[3] = 800037000;
		initial_values[4] =  97000150;
		initial_values[5] =    210008;
		initial_values[6] =   3160820;
		initial_values[7] =    803000;
		initial_values[8] = 501000600;

		//timer timer;
		sudoku sudoku(initial_values);
		//timer.print_time("inicializace: ");*/

		sudoku sudoku(file);

		sudoku.update_checksum();

		while(1){

			num_iter++;

			sudoku.naked_single();
			sudoku.only_option();

			if(sudoku.did_checksum_change_update()){
				if(sudoku.get_checksum() != 0) continue;
				num_solved++;
				break;
			}
			else if(sudoku.get_checksum() == 0){
				num_solved++;
				break;
			}

			sudoku.pair();

			if(sudoku.did_checksum_change_update()){
				if(sudoku.get_checksum() != 0) continue;
				num_solved++;
				break;
			}
			else if(sudoku.get_checksum() == 0){
				num_solved++;
				break;
			}

			num_sameRowColumnBox++;
			sudoku.sameRowColumnBox();

			if(sudoku.did_checksum_change_update()){
				if(sudoku.get_checksum() != 0) continue;
				num_solved++;
				break;
			}
			else if(sudoku.get_checksum() == 0){
				num_solved++;
				break;
			}

			/*sudoku.hidden_triple();

			if(sudoku.did_checksum_change_update()){
				if(sudoku.get_checksum() != 0) continue;
				num_solved++;
				break;
			}
			else if(sudoku.get_checksum() == 0){
				num_solved++;
				break;
			}

			sudoku.hidden_quadrouple();

			if(sudoku.did_checksum_change_update()){
				if(sudoku.get_checksum() != 0) continue;
				num_solved++;
				break;
			}
			else if(sudoku.get_checksum() == 0){
				num_solved++;
				break;
			}

			sudoku.x_wing();

			if(sudoku.did_checksum_change_update()){
				if(sudoku.get_checksum() != 0) continue;
				num_solved++;
				break;
			}
			else if(sudoku.get_checksum() == 0){
				num_solved++;
				break;
			}*/

			break;

		}

		solved_bad += sudoku.is_bad();

	}

	solved_bad = solved_bad - (num_puzzles - num_solved);

	printf("num solved %d\nnum solved bad %d\navg iter cnt %f\navg sameRowColumnBox cnt %f\n ", num_solved, solved_bad, (double)num_iter/num_puzzles, (double)num_sameRowColumnBox/num_puzzles);

    return 0;
}
