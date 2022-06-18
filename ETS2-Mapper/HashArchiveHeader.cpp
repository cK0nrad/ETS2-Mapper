#include <iostream>
#include "HashArchiveHeader.h"

uint32_t HashArchiveHeader::getMagic() {
	return EntryCount;
}

uint32_t HashArchiveHeader::getHashMethod() {
	return HashMethod;
}

uint32_t HashArchiveHeader::getStartOffset() {
	return StartOffset;
}
uint32_t HashArchiveHeader::getEntryCount() {
	return EntryCount;
}

uint16_t HashArchiveHeader::getVersion() {
	return Version;
}

