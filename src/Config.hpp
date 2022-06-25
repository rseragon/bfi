#pragma once

#include "Utils.hpp"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

namespace bfi {
	struct Config {

		static const size_t DEFAULT_STACK_SIZE = 20;
		static const size_t DEFAULT_ARRAY_SIZE = 30000;

		std::fstream input_stream;
		size_t stack_size;
		size_t array_size;

		Config(char *file_name, size_t stack_size = DEFAULT_STACK_SIZE,
				size_t array_size = DEFAULT_ARRAY_SIZE)
			: input_stream(file_name, std::ios::in), stack_size(stack_size),
			array_size(array_size) {}

		static Config parse(int argc, char **argv);
	};

} // namespace bfi
