#include <cstdint>
#include <cassert> 
#include <iostream>
#include "CompressionManager.h"
#include "zlib.h"

unsigned char* CompressionManager::Inflate(unsigned char *input, uint32_t compressed_size) {
	unsigned char* uncompressed = new unsigned char[compressed_size]();
	uLong destLen = compressed_size;

	//TODO: Check if we have errors
	uncompress(uncompressed, &destLen, input, compressed_size);
	return uncompressed;
}