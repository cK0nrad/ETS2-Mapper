#pragma once
class DataReader
{
public:
	static uint16_t Read16(std::ifstream*, long);
	static uint32_t Read32(std::ifstream*, long);
	static uint64_t Read64(std::ifstream*, long);
	static uint32_t Read32A(unsigned char*, long);
	static uint64_t Read64A(unsigned char*, long);
};

