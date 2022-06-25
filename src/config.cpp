#include "Config.hpp"
#include <fstream>

namespace bfi {
	Config Config::parse(int argc, char **argv) {
		if (argc < 2) {
			ERR("Invalid usage");
			std::cout << "Usage:\n"
				<< argv[0] << " <file> [-a,-s]\n\n"
				<< "\t<file>\t\tFile to read from (for stdin use '-')\n"
				<< "\t-a [NUMBER]\tsets the max array size\n"
				<< "\t-s [NUMBER]\tsets the max stack size\n"
				<< std::endl;
			exit(__LINE__);
		}

		// TODO: -a -s, -(stdin)
		char* file_to_read = argv[1];
		INFO("Input file: %s", file_to_read);

		Config conf = Config(file_to_read);

		if(!conf.input_stream) {
			ERR("Failed to open file: %s", file_to_read);
			exit(__LINE__);
		}

		return conf;
	}
} 
