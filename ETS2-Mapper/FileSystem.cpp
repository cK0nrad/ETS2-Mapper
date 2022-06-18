#include <vector>
#include <map>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstdint>
#include "ArchiveFile.h"
#include "Entry.h"
#include "File.h"
#include "Folder.h"
#include "FileSystem.h"
#include "HashArchiveFile.h"
#include "constant.h"


namespace fs = std::filesystem;
using std::map;
using std::string;
using std::map;
using std::vector;

 void FileSystem::AddDir(string path) {
	 //Check if the directory exist
	 if (!fs::is_directory(path)) {
		 std::cout << "Directory :" << path << "not found" << "\n";
		 return;
	 }

	 //For each entry of the directory we add the file to the loader
	 for (const auto& entry : fs::directory_iterator(path)){
		 FileSystem::AddFile(entry.path());
		 break;
	 }

}

 void FileSystem::AddFile(fs::path path) {
	 //Define the buffer
	 char buffer[4];
	 
	 //Read first 4 bytes of the file
	 std::ifstream currentFile(path, std::ios::binary);
	 currentFile.seekg(0, std::ios_base::beg);
	 currentFile.read(buffer, 4);

	 //Convert the buffer to 32bits uint
	 uint32_t fileMagic;
	 memcpy(&fileMagic, buffer, 4);

	 //Check if the file is a SCS file
	 if (fileMagic != SCS_MAGIC) return;
	 HashArchiveFile test;
	 test.Parse(&currentFile, this);

	
}

 Folder FileSystem::GetFolder(uint64_t hash) {
	if(folders.count(hash))	return folders[hash];
	
	Folder newFolder;
	folders.emplace(hash, newFolder);
	
	return newFolder;
 }