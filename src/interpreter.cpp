#include "Interpreter.hpp"

namespace bfi {

	void fuck(bfi::Config config) {

		while(!config.input_stream.eof()) {
			std::string s;
			config.input_stream >> s;
			std::cout << s;
		}

	}

}
