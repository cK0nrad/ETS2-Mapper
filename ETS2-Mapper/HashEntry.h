#pragma once
class HashEntry: Entry
{
private:
	uint32_t Flags, Crc;
	
public:
	HashEntry(uint64_t, uint64_t, uint32_t, uint32_t, uint32_t, uint32_t);
	uint32_t GetFlags() { return Flags; }
	bool IsDirectory() { return (Flags & (1 << 0)) != 0; }
	bool IsCompressed() { return  (Flags & (1 << 1)) != 0; }
	uint64_t GetHash() { return Hash; }
	unsigned char* Read(std::ifstream* stream);
};

