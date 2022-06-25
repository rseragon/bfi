#include <iostream>
#include <string>

#include "Config.hpp"
#include "Interpreter.hpp"

int main(int argc, char** argv) {

	bfi::Config config = bfi::Config::parse(argc, argv);

	bfi::fuck(std::move(config));

	return 0;
}
