#include "gtest/gtest.h"
#include "utils/utils.h"

TEST(utils, argv_to_vec_size0) {
	const char* argv[0];
	auto args = argv_to_vec(0, argv);
	ASSERT_EQ(args.size(), 0);
}

TEST(utils, argv_to_vec_size255) {
	const char* argv[255];
	std::fill(argv, argv+255, "wei");
	auto args = argv_to_vec(255, argv);
	ASSERT_EQ(args.size(), 255);
}