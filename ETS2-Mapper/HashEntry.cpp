#include <iostream>
#include <fstream>
#include "Entry.h"
#include "HashEntry.h"

using std::ifstream;

HashEntry::HashEntry(uint64_t Hash, uint64_t Offset, uint32_t Flags, uint32_t Crc, uint32_t Size, uint32_t CompressedSize) {
	this->Hash = Hash;
	this->Offset = Offset;
	this->Flags = Flags;
	this->Crc = Crc;
	this->Size = Size;
	this->CompressedSize = CompressedSize;
	
}

unsigned char* HashEntry::Read(ifstream* stream) {
	stream->seekg(Offset, stream->beg);
	unsigned char* buffer = new unsigned char[CompressedSize];
	stream->read((char*)buffer, CompressedSize);
	return buffer;
}