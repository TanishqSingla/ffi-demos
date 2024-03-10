#include <cstring>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

std::string trim(std::string& s) {
	std::string::iterator b_it = s.begin();
	std::string::iterator e_it = s.end();

	while(*b_it == ' ') {
		++b_it;
	}

	while(*e_it == ' ') {
		--e_it;
	}

	return std::string(b_it, e_it);
}

void parse_line(std::string line, std::vector<std::pair<std::string, std::string>>& pairs) {
	std::string::iterator it = line.begin();

	while(it != line.end()) {
		if(*it == ':') {
			break;
		}
		++it;
	}

	auto key = std::string(line.begin(), it);
	++it;
	auto value = std::string(it, line.end());
	auto pair = std::make_pair(trim(key), trim(value));

	pairs.push_back(pair);
}

const char* dumpJSON(std::vector<std::pair<std::string, std::string>>& pairs) {
	char json[2048] = "{";

	int it = 1;

	std::string entry;
	for(int i = 0; i < pairs.size(); i++) {
		entry = "\"" + pairs[i].first + "\"" + ":" + pairs[i].second;
		if(i < pairs.size() - 1) {
			entry += ",";
		}

		std::strcat(json, entry.c_str());
	}

	std::strcat(json, "}");

	json[strlen(json) + 1] = '\0';
	char* result = (char*)malloc(strlen(json));
	// EXTREME DANGER
	std::strcpy(result, json);
	return result;
}

extern "C" {
	const char* parseMetadata(const char* filename) {
		if(!fs::exists(filename)) {
			return "Error: File does not exists";
		}

		std::vector<std::pair<std::string, std::string>> pairs;

		std::ifstream in(filename);
		std::string s;

		char flag = 0;
		while(std::getline(in, s)) {
			if(s == "---") {
				if (flag) { break; }

				flag = 1;
				continue;
			}
			parse_line(s, pairs);
		}

		const char* result = dumpJSON(pairs);
		return result;
	}
}
