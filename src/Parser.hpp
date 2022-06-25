#pragma once

#include "Tokens.hpp"
#include "Config.hpp"

namespace bfi {
	Token parse(std::basic_string<char>::iterator& iter);
}
