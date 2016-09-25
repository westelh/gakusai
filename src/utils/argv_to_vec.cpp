#include "utils/utils.h"

const std::vector<std::string> argv_to_vec(int argc, const char ** argv) {
	std::vector<std::string> ret;
	for (int i = 0; i < argc; ++i) {
		ret.push_back(argv[i]);
	}
	return ret;
}