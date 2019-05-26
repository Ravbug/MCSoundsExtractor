//
//  extractor.cpp
//  mac
//
//  Created by Main on 5/17/19.
//  Copyright © 2019 Ravbug. All rights reserved.
//

#include "extractor.hpp"
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <iostream>
#include <utility>
#include <set>

using namespace std;
using namespace boost::filesystem;

/**
 Loads the Minecraft versions in a folder
 @param root string path of the minecraft install directory to search
 @return vector of strings of installed versions, or empty vector if no versions found
 */
vector<string> extractor::LoadMcVersions(string &root){
	vector<string> versions;
	//create a path object
	path p = path(root) / path("assets") / path("indexes");
	
	//cycle through the directory
	directory_iterator end_itr;
	try {
		for (directory_iterator itr(p); itr != end_itr; itr++){
		
				//if this is not a directory or other special file
				path file = itr->path();
				if (is_regular_file(file) && file.extension() == ".json") {
					versions.push_back(file.stem().string());
				}
		
		}
	}
	catch (boost::filesystem::filesystem_error& e) { cout << e.what(); }

	return versions;
}

/**
Constructs an extractor object
@param root path to the minecraft root directory
@param destination path to the output folder
@param version string representing the minecraft version to extract

Values are assumed to be correct, invalid paths or versions will cause exceptions.
*/
extractor::extractor(string& root, string& destination, string& version) {
	this->root = root;
	this->destination = destination;
	this->version = version;
}

/**
 Tests write priviledges of a folder by attempting to write to that folder
 @param directory path to the folder
 @return true if write and delete was successful, false otherwise
 */
bool extractor::hasWritePriviledges(string &directory){
	path testpath = path(directory) / path("write_test_mcextractor");
	//attempt to write file
	boost::filesystem::ofstream(path(testpath));
	
	//is file there?
	if (exists(testpath)){
		remove(testpath);
		return true;
	}
	return false;
}

/**
 Extracts the minecraft sounds on a background thread
 @param progress function(float) to call on progress updates
 @param error function(string) to call if there are errors
 */
void extractor::Extract(function<void(float)> progress,function<void(string)> error){
	
	//spawn thread which calls thread_extract with the progress handler
	worker = thread([&](function<void(float)> progress, function<void(string)> error,string root, string destination, string version){

		//make a map with the format filename:full_path
		//this is used to look up the real name of the file using the hashed name in assets/indexes/version.json
		//using this it can regenerate the correct folder structure and names of files
		map<string, string> dirMap;
		{
			//get the path of every item in the directory, including subfolders, and load into a vector of path objects
			recursive_directory_iterator b(path(root) / path("assets") / path("objects")), e;
			vector<path> paths(b, e);

			//add the items to the map
			for (path p : paths) {	
				dirMap.insert(pair<string, string>(p.filename().string(), p.string()));			
			}
		}

		//use scope to delete objects when they are no longer needed
		Document doc;
		{
			//read the file (all in at once, which doesn't matter in this case because the file is small)
			path asset = path(root) / path("assets") / path("indexes") / path(version + ".json");
			std::ifstream t(asset.string());
			string data((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
			
			//parse into a JSON structure
			doc.Parse(data.c_str());
		}

		//count the number of files to process (for progress)
		const string soundsPath = "minecraft/sounds/";
		set<string> to_copy;
		for (auto& m : doc["objects"].GetObject()) {
			string name = m.name.GetString();
			if (name.find(soundsPath) != string::npos) {
				to_copy.insert(name);
			}
		}

		//make a 'minecraft' directory at the destination
		create_directory(path(destination) / path("minecraft"));
		int count = to_copy.size();
		
		//perform the copies
		for (auto& m : doc["objects"].GetObject()) {
			string name = m.name.GetString();
			if (to_copy.count(name)) {
				//get real path from hash

				//construct the fully qualified path using destination

				//make necessary subfolders

				//attempt copy, and abort with error dialog if exception occurs
			}
		}
		
		progress(10);
		error("EEEEEEEEEE An error occcurred REEEEEE");
	},progress,error,root,destination,version);
	worker.detach();
}
