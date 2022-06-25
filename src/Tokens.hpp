#pragma once

namespace bfi {
	enum class Token {
		PLUS,		// +
		MINUS,		// -
		MOVE_RIGHT, // >
		MOVE_LEFT,  // <
		OUTPUT,		// .
		INPUT,		// ,
		LOOP_START, // [
		LOOP_END,   // ]
		END,		// EOF
		OTHER,
	};
}
