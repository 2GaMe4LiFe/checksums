#include <iostream>
#include <vector>
#include <cstdint>
#include <bitset>
#include <cmath>

using namespace std;


uint8_t parity_bits_vertical(vector<uint8_t> data) {

	uint8_t erg = 0;

	for (auto item : data) {

		erg ^= item;
	}

	return erg;	
}


uint16_t fletcher16(vector<uint8_t> data) {

	uint16_t sum1{};
	uint16_t sum2{};

	for (auto item : data) {
		sum1 = (sum1 + item) % 255;
		sum2 = (sum1 + sum2) % 255;
	}

	return (sum2 << 8) | sum1;
}