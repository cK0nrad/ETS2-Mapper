#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <filesystem>
#include "Entry.h"
#include "File.h"
#include "ArchiveFile.h"
#include "Folder.h"
#include "FileSystem.h"

using std::string;

int main() {
	FileSystem files;
	string test = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\Euro Truck Simulator 2";
	files.AddDir(test);

	return 0;
}