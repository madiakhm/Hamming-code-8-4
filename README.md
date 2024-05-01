# Hamming (8,4) Code Implementation in C++

## Introduction
This C++ program demonstrates the implementation of the Hamming (8,4) code, a type of error-correcting code used for detecting and correcting errors in data transmissions. The Hamming (8,4) code adds 4 parity bits to a 4-bit data word to form an 8-bit codeword. This allows the detection and correction of single-bit errors.

## Files
- `hamming.cpp`: This file contains the implementation of encoding, decoding, and error correction using the Hamming (8,4) code.
- `README.md`: This file provides information about the program.

## Implementation Details
### `encodeHamming84`
This function encodes a 4-bit data word into an 8-bit codeword using the Hamming (8,4) code. It calculates parity bits based on the data bits and inserts them at specific positions in the codeword.

### `findErrorBit`
This function identifies the position of the error bit in a received 8-bit codeword by calculating parity bits and comparing them with the received data.

### `decodeHamming84`
This function decodes a received 8-bit codeword into a 4-bit data word. If an error is detected, it corrects the error by flipping the corresponding bit in the codeword.

### `main`
The `main` function demonstrates the usage of the implemented encoding and decoding functions. It encodes a 4-bit data word, simulates transmission by decoding the codeword (possibly introducing an error), and then decodes the received codeword to recover the original data.

## Usage
To compile and run the program, follow these steps:

1. Ensure you have a C++ compiler installed on your system.
2. Open a terminal or command prompt.
3. Navigate to the directory containing the `hamming.cpp` file.
4. Compile the program using the following command:
g++ -o hamming hamming.cpp
5. Run the compiled executable:

## Example
Suppose we want to encode the 4-bit data word `1010`. After encoding and decoding, the program should correctly recover the original data.

Initial data: 1010

Encoded data: 10110100

Decoded data: 1010

## Notes
- This implementation assumes a single-bit error model, where only one bit in the codeword is flipped during transmission.
- For practical applications, additional error detection and correction mechanisms may be required for robustness.



