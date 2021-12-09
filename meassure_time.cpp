
#ifndef TIME
	#define TIME
	#include "define.h"
#endif

#include <chrono>  // for high_resolution_clock

class timer{

	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> time;

	public:

		explicit timer(){

			time = std::chrono::high_resolution_clock::now();

		}

		auto get_time(){

			auto total = std::chrono::high_resolution_clock::now();

			double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double> >(total - time).count();

			return elapsed_seconds;

		}

		void reset(){

			time = std::chrono::high_resolution_clock::now();

		}

		void print_time(){

			auto total = std::chrono::high_resolution_clock::now();

			double elapsed_miliseconds = 1000 * std::chrono::duration_cast<std::chrono::duration<double> >(total - time).count();

			printf("%f\n", elapsed_miliseconds);

			return;

		}

		void print_time(const char* string){

			auto total = std::chrono::high_resolution_clock::now();

			double elapsed_miliseconds = 1000 * std::chrono::duration_cast<std::chrono::duration<double> >(total - time).count();

			printf("%s %f\n", string, elapsed_miliseconds);

			return;

		}

};
