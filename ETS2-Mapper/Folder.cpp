#include <vector>
#include <string>
#include "Entry.h"
#include "File.h"
#include "Folder.h"

using std::string;
using std::vector;


void Folder::addEntry(Entry entry) {
	entries.push_back(entry);
}

void Folder::addSubDirectory(string subDirectory) {
	this->subDirectory.push_back(subDirectory);
}

void Folder::addSubFiles(string subFiles) {
	this->subFiles.push_back(subFiles);
}

vector<string> Folder::getFiles(string filter="") {
	if(filter == "")
		return subFiles;
	else {
		vector<string> filteredFiles;
		for(int i = 0; i < subFiles.size(); i++) {
			if(subFiles[i].find(filter) != string::npos)
				filteredFiles.push_back(subFiles[i]);
		}
		return filteredFiles;
	}
}

