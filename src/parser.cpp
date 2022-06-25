#include "Parser.hpp"

namespace bfi {
	Token parse(std::basic_string<char>::iterator& iter) {

		char c = *iter;

		switch(c) {
			case '+':
				return Token::PLUS;
				
			case '-':
				return Token::MINUS;

			case '>':
				return Token::MOVE_RIGHT;

			case '<':
				return Token::MOVE_LEFT;

			case '.':
				return Token::OUTPUT;

			case ',':
				return Token::INPUT;

			case '[':
				return Token::LOOP_START;

			case ']':
				return Token::LOOP_END;

		}

		return Token::OTHER;
	}
}
