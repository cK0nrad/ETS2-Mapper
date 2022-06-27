#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Entry.h"
#include "Folder.h"
#include "File.h"
#include "ArchiveFile.h"
#include "HashArchiveHeader.h"
#include "DataReader.h"
#include "constant.h"
#include "HashEntry.h"
#include "FileSystem.h"
#include "HashArchiveFile.h"

using std::ifstream;

void HashArchiveFile::Parse(ifstream* stream, FileSystem* filesystem) {
	HashArchiveHeader headers (
		DataReader::Read32(stream, 0x0),
		DataReader::Read16(stream, 0x04),
		DataReader::Read16(stream, 0x06),
		DataReader::Read32(stream, 0x08),
		DataReader::Read32(stream, 0x0C),
		DataReader::Read32(stream, 0x10)
	);

	if (headers.getHashMethod() != HASH_METHOD) 
		return;

	if (headers.getVersion() != SUPPORTED_VERSION)
		return;
	
	uint32_t entryCount = headers.getEntryCount();
	unsigned char* raw_data = new unsigned char[entryCount * ENTRY_BLOCK_SIZE];

	stream->seekg(headers.getStartOffset(), stream->beg);
	stream->read((char*)(raw_data), entryCount * ENTRY_BLOCK_SIZE);

	for (uint32_t i = 0; i < entryCount; i++) {
		uint32_t offset = i * ENTRY_BLOCK_SIZE;
		HashEntry currentEntry(
			DataReader::Read64A(raw_data, offset),
			DataReader::Read64A(raw_data, offset + 0x08),
			DataReader::Read32A(raw_data, offset + 0x10),
			DataReader::Read32A(raw_data, offset + 0x14),
			DataReader::Read32A(raw_data, offset + 0x18),
			DataReader::Read32A(raw_data, offset + 0x1C)
		);

		if (currentEntry.IsDirectory()) {
			Folder currentDir = filesystem->GetFolder(currentEntry.GetHash());
			unsigned char* lines;
			lines = currentEntry.Read(stream);

		}
	}

}