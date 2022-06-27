#pragma once
class CompressionManager
{
public:
	static unsigned char* Inflate(unsigned char* input, uint32_t uncompressed_size);
};

