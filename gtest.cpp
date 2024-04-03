#include <gtest/gtest.h>
#include "Hamming_code.hpp" 

TEST(HammingCodeTest, EncodeDecodeTest) {
    std::bitset<4> data(0b1010);
    std::bitset<8> encodedData = encodeHamming84(data);
    std::bitset<4> decodedData = decodeHamming84(encodedData);

    EXPECT_EQ(data, decodedData);
}

TEST(HammingCodeTest, ErrorDetectionTest) {
    std::bitset<8> receivedData(0b11010101);
    int errorBit = findErrorBit(receivedData);

    EXPECT_EQ(errorBit, 3);
}

