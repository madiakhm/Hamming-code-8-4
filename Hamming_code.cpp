#include <iostream>
#include <bitset>

std::bitset<8> encodeHamming84(const std::bitset<4>& data) {
    std::bitset<8> encodedData;
    
    encodedData[0] = (data[0] + data[1] + data[3]) % 2;
    encodedData[1] = (data[0] + data[2] + data[3]) % 2;
    encodedData[3] = (data[1] + data[2] + data[3]) % 2;
    
    encodedData[2] = data[0];
    encodedData[4] = data[1];
    encodedData[5] = data[2];
    encodedData[6] = data[3];
    
    encodedData[7] = (encodedData[0] + encodedData[1] + encodedData[2] + encodedData[3] +
                      encodedData[4] + encodedData[5] + encodedData[6]) % 2;
    
    return encodedData;
}

int findErrorBit(const std::bitset<8>& receivedData) {
    int p1 = (receivedData[0] + receivedData[2] + receivedData[4] + receivedData[6]) % 2;
    int p2 = (receivedData[1] + receivedData[2] + receivedData[5] + receivedData[6]) % 2;
    int p3 = (receivedData[3] + receivedData[4] + receivedData[5] + receivedData[6]) % 2;

    return p1 * 1 + p2 * 2 + p3 * 4;
}

std::bitset<4> decodeHamming84(const std::bitset<8>& receivedData) {
    std::bitset<4> decodedData;

    int errorBit = findErrorBit(receivedData);

    if (errorBit > 0) {
        std::bitset<8> correctedData = receivedData;
        correctedData.flip(errorBit - 1);

        correctedData[7] = (correctedData[0] + correctedData[1] + correctedData[2] + correctedData[3] +
                            correctedData[4] + correctedData[5] + correctedData[6]) % 2;

        decodedData[0] = correctedData[2];
        decodedData[1] = correctedData[4];
        decodedData[2] = correctedData[5];
        decodedData[3] = correctedData[6];
    } else {
        decodedData[0] = receivedData[2];
        decodedData[1] = receivedData[4];
        decodedData[2] = receivedData[5];
        decodedData[3] = receivedData[6];
    }

    return decodedData;
}


int main() {
    std::bitset<4> data(0b1010);
    
    std::cout << "Initial data: " << data << std::endl;
    
    std::bitset<8> encodedData = encodeHamming84(data);
    
    std::cout << "Encoded data: " << encodedData << std::endl;
    
    
    std::bitset<4> decodedData = decodeHamming84(encodedData);
    
    std::cout << "Decoded data: " << decodedData << std::endl;
    
    return 0;
}
