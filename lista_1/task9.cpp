#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <exception>

using namespace std;

void get_from_file(const char * file_name, std::map<char,int> & dict)
{
	
	fstream mFile(file_name, ios::in);
	
    if (mFile.good()) {
		cout << "File Opened\n";
		string buffer;
		while (getline(mFile, buffer))
		{
			for (auto i = 0; i < buffer.length(); i++) {
				++dict[buffer[i]];
			}
		}
		mFile.close();
	}
	else cerr << "error 404: file not found\n";	
}

void consoleLog(map<char, int> const& dict) {
	for (auto const& s : dict) {
		cout << s.first << ": " << s.second << '\n';
	}
}

int main()
{
	map<char, int> ASCII;
	
    get_from_file("task9.txt", ASCII);

	consoleLog(ASCII);

	return 0;

}



