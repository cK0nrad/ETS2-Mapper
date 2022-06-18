#pragma once

class Folder
{
	std::vector<Entry> entries;
	std::vector<std::string> subDirectory;
	std::vector<std::string> subFiles;
	
public:
	void addEntry(Entry);
	void addSubDirectory(std::string);
	void addSubFiles(std::string);
	std::vector<std::string> getFiles(std::string);
	std::vector<std::string> getFilesByExtension(std::string, std::string[]);
};

