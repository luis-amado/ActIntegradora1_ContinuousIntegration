#include <catch2/catch_test_macros.hpp>

#include "parte1_1.h"

TEST_CASE("zAlg1") {
    vector<int> zAlgResult = ZAlg1("test", "fulltestfull");
    int foundPos = -1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == len) {
            foundPos = i - len - 1;
            break;
        }
    }
    REQUIRE(foundPos == 4);
}
