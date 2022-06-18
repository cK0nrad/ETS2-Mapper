#include <fstream>
#include "DataReader.h"

using std::ifstream;

uint16_t DataReader::Read16(ifstream* stream, long offset) {
	uint16_t output = 0;
	stream->seekg(offset);
	stream->read(reinterpret_cast<char*>(&output), 2);
	return output;
}

uint32_t DataReader::Read32(ifstream *stream, long offset) {
	uint32_t output = 0;
	stream->seekg(offset);
	stream->read(reinterpret_cast<char*>(&output), 4);
	return output;
}

uint64_t DataReader::Read64(ifstream* stream, long offset) {
	uint64_t output = 0;
	stream->seekg(offset);
	stream->read(reinterpret_cast<char*>(&output), 8);
	return output;
}

uint32_t DataReader::Read32A(unsigned char* data, long offset) {
	uint32_t output = 0;
	memcpy(&output, data + offset, 4);
	return output;
}

uint64_t DataReader::Read64A(unsigned char* data, long offset) {
	uint64_t output = 0;
	memcpy(&output, data + offset, 8);
	return output;
}