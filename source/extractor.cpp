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
					versions.push_back(file.filename().string());
				}
		
		}
	}
	catch (boost::filesystem::filesystem_error& e) { cout << e.what(); }

	return versions;
}

/**
Constructs an extractor object
@param root path to the minecraft root directory
@param definition path to the output folder
@param version string representing the minecraft version to extract

Values are assumed to be correct, invalid paths or versions will cause exceptions.
*/
extractor::extractor(string& root, string& destination, string& version) {
	this->root = root;
	this->destination = destination;
	this->version = version;
}

