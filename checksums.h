#ifndef CHECKSUMS_H
#define CHECKSUMS_H

#include <vector>

extern uint8_t parity_bits_vertical(std::vector<uint8_t> data);
extern uint16_t fletcher16(std::vector<uint8_t> data);

#endif
