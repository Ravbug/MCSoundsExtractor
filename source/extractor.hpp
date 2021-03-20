//
//  extractor.hpp
//  mac
//
//  Created by Main on 5/17/19.
//  Copyright © 2019 Ravbug. All rights reserved.
//

#pragma once

#include <vector>
#include <string>
#include <thread>
#include <map>
#include <functional>
#include <rapidjson/document.h>

using namespace std;
using namespace rapidjson;

class extractor{
public:
	extractor(string& root, string& destination, string& version);
	static vector<string> LoadMcVersions(string &root);
	static bool hasWritePriviledges(string &directory);
	void Extract(function<void(float)> progress,function<void(string)> error);
private:
	string root, destination, version;
	thread worker;
protected:
};
