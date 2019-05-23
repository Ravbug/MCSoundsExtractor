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

using namespace std;
using namespace boost::filesystem;

/**
 Loads the Minecraft versions in a folder
 @param root string path of the minecraft install directory to search
 @return vector of strings of installed versions, or empty array if no versions found
 */
vector<string> extractor::LoadMcVersions(string &root){
	vector<string> versions;
	//create a path object
	path p(root);
	
	//cycle through the directory
	directory_iterator end_itr;
	for (directory_iterator itr(p); itr != end_itr; itr++){
		//if this is not a directory or other special file
		path file = itr->path();
		if (is_regular_file(file) && p.extension() == ".json"){
			versions.push_back(p.filename().string());
		}
	}
	return versions;
}

