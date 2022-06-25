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

		Token tok;

		auto iter = array.begin();

		int input; // This will be used to take input

		while((tok = bfi::parse(config)) != Token::END) {

			switch(tok) {
				case Token::PLUS:
					(*iter)++;
					break;
				case Token::MINUS:
					(*iter)--;
					break;
				case Token::MOVE_RIGHT:
					iter++;
					break;
				case Token::MOVE_LEFT:
					iter--;
					break;
				case Token::OUTPUT:
					std::cout << (char) *iter;
					break;
				case Token::INPUT: 
					std::cin >> input;
					*iter = input;
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
					if(*iter == 0) {
						iter++;
						stack.pop();
						break;
					}
					else {
						int relative_pos = index - stack.top();
						iter -= relative_pos + 1;
						index = stack.top() + 1; 
					}

				}
				case Token::OTHER:
					break;
			}

			index++;
		}

		if(stack.size() != 0) {
			ERR("EOF reached at index %zu: Expected end of loop started at %zu", index, stack.top());
			exit(__LINE__);
		}

	}

}
