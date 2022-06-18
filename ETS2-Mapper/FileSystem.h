#pragma once

class FileSystem
{
	std::map<uint64_t, File> files;
	std::map<uint64_t, Folder> folders;
	std::map<uint64_t, ArchiveFile> archives;
	
public:
	void AddDir(std::string);
	void AddFile(std::filesystem::path);
	Folder GetFolder(uint64_t);
};
