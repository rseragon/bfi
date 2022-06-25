#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <iostream>

#include "Interpreter.hpp"
#include "Tokens.hpp"
#include "Parser.hpp"

namespace bfi {

	void fuck(bfi::Config config) {

		// C++20 :(
		// using enum bfi::Token;

		std::vector<int> array(config.array_size, 0);
		std::stack<size_t> stack;

		size_t index = 0;

		auto array_iter = array.begin();

		std::string file_str = bfi::read_to_string(config.input_stream);

		auto str_iter = file_str.begin();

		int input; // This will be used to take input

		while(str_iter != file_str.end()) {

			Token tok = bfi::parse(str_iter);

			switch(tok) {
				case Token::PLUS:
					(*array_iter)++;
					break;
				case Token::MINUS:
					(*array_iter)--;
					break;
				case Token::MOVE_RIGHT:
					array_iter++;
					break;
				case Token::MOVE_LEFT:
					array_iter--;
					break;
				case Token::OUTPUT:
					std::cout << (char) *array_iter;
					break;
				case Token::INPUT: 
					std::cin >> input;
					*array_iter = input;
					break;
				case Token::LOOP_START:
					stack.push(index);
					break;
				case Token::LOOP_END:
				{
					if(stack.empty()) {
						ERR("Invalid character ']' found at index: %zu", index);
						exit(__LINE__);
					}

					if(*array_iter == 0) {
						stack.pop();
						break;
					}
					else {
						str_iter = file_str.begin() + stack.top();
						index = stack.top();
					}

				}
				case Token::OTHER:
					break;
				case Token::END:
					break;
			}

			index++;
			str_iter++;
		}

		// cleanup :D
		config.input_stream.close();

		if(stack.size() != 0) {
			ERR("EOF reached at index %zu: Expected end of loop started at %zu", index, stack.top());
			exit(__LINE__);
		}
	}

	std::string read_to_string(std::fstream& stream) {
		std::string str;

		while(!stream.eof()) {
			std::string curr;
			stream >> curr;
			str += std::move(curr);
		}

		return str;
	}

}
