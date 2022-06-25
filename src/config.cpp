#include "Config.hpp"
#include <cstdlib>
#include <fstream>

namespace bfi {
	Config Config::parse(int argc, char **argv) {
		if (argc < 2) {
			ERR("Invalid usage");
			print_help(argv[0]);
			exit(__LINE__);
		}

		// TODO: -a -s, -(stdin)
		int array_size = Config::DEFAULT_ARRAY_SIZE;
		int stack_size = Config::DEFAULT_STACK_SIZE;
		char* file_to_read;

		for(int i = 1; i < argc; i++) {
			if(strcmp(argv[i], "-a") == 0) {
				if(i + 1 == argc) {
					ERR("No option provided for -a\n refer usage `%s -h`", argv[0]);
					exit(__LINE__);
				}
				array_size = atoi(argv[i + 1]);
				i++;
			}
			else if (strcmp(argv[i], "-s") == 0) {
				if(i+1 == argc) {
					ERR("No option provided for -s\n refer usage `%s -h`", argv[0]);
					exit(__LINE__);
				}
				stack_size = atoi(argv[i+1]);
				i++;
			}
			else if (strcmp(argv[i], "-h") == 0) {
				print_help(argv[0]);
				exit(__LINE__);
			}
			else {
				file_to_read = argv[i];
			}
		}


		if(array_size < 1) {
			ERR("Invalid `-a` option value provided: %d", array_size);
			exit(__LINE__);
		}
		if(stack_size < 1) {
			ERR("Invalid `-s` option value provided: %d", stack_size);
			exit(__LINE__);
		}

		if(!file_to_read) {
			ERR("Input file not provided");
			exit(__LINE__);
		}


		Config conf = Config(file_to_read, stack_size, array_size);

		if(!conf.input_stream) {
			ERR("Failed to open file: %s", file_to_read);
			exit(__LINE__);
		}

		return conf;
	}

	void print_help(char* exec_name) {
		std::cout << "Usage:\n"
			<< exec_name << " <file> [-a,-s]\n\n"
			<< "\t<file>\t\tFile to read from \n"
			<< "\t-a [NUMBER]\tsets the max array size\n"
			<< "\t-s [NUMBER]\tsets the max stack size\n"
			<< "\t-h\t\tprints this help message\n"
			<< std::endl;
		exit(__LINE__);

	}
} 
