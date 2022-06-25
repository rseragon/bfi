#pragma once

#ifdef ASCII_TERMINAL
	#define INFO(MSG, ...) \
		fprintf(stdout, "\u001b[36m[INFO ] " MSG " \u001b[0m\n", ##__VA_ARGS__);

	#define WARN(MSG, ...) \
		fprintf(stdout, "\u001b[33m[WARN ] " MSG " \u001b[0m \n", ##__VA_ARGS__);

	#define ERR(MSG, ...) \
		fprintf(stdout, "\u001b[31m[ERROR] " MSG " \u001b[0m\n", ##__VA_ARGS__);
#else
	#define INFO(MSG, ...) \
		fprintf(stdout, "[INFO ] " MSG "\n", ##__VA_ARGS__);

	#define WARN(MSG, ...) \
		fprintf(stdout, "[WARN ] " MSG "\n", ##__VA_ARGS__);

	#define ERR(MSG, ...) \
		fprintf(stdout, "[ERROR] " MSG "\n", ##__VA_ARGS__);
#endif

