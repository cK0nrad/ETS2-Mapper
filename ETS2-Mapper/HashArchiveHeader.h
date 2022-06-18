#pragma once
class HashArchiveHeader
{
private:
	uint32_t Magic, HashMethod, EntryCount, StartOffset;
	uint16_t Version, Salt;
	

public:
	uint32_t getMagic();
	uint32_t getHashMethod();
	uint32_t getStartOffset();
	uint32_t getEntryCount();
	uint16_t getVersion();
	HashArchiveHeader(uint32_t Magic, uint16_t Version, uint16_t Salt, uint32_t HashMethod, uint32_t EntryCount, uint32_t StartOffset)
		: Magic(Magic),
		HashMethod(HashMethod),
		EntryCount(EntryCount),
		StartOffset(StartOffset),
		Version(Version),
		Salt(Salt) {};
};

