#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

std::vector<int> get_from_file(const char * name_of_file)
{
	std::vector<int> values;

	std::fstream mFile(name_of_file, std::ios::in);
	
    if (mFile.good()) {
		std::cout << "File opened\n";
		std::string buffer;
		while (std::getline(mFile, buffer))
		{
			values.push_back(std::atoi(buffer.c_str()));
		}
		mFile.close();
	}
	else{
        std::cerr << "error 404: file not found\n";
    } 
	return values;
}

std::vector<int> multiplication_of_polynomials(std::vector<int> const& first, std::vector<int> const& second)
{
	std::vector<int> result;
	if (first.size() == second.size()) {

		for (auto i = 0; i < first.size(); i++)
		{
			int partly_result = 0;
			for (auto j = 0; j < second.size(); j++)
			{
				partly_result += first[i] * second[j];
			}
			result.push_back(partly_result);
		}

	}
	else {
		std::cerr << "[ERROR] Please  use vector of same size. Result vector is empty.\n";
	}
	return result;
}

void save_to_file(const char* file_name, std::vector<int> const& vec)
{
	std::ofstream mFile(file_name);
	
	for (auto i = 0; i < vec.size(); i++)
	{
		mFile << std::to_string(vec[i]) << "\n";
	}
	mFile.close();
}

int main()
{
	std::vector<int> v1 = get_from_file("a.txt");
	std::vector<int> v2 = get_from_file("b.txt");
	std::vector<int> v3 = multiplication_of_polynomials(v1, v2);

    save_to_file("c.txt", v3);
	
    for (auto const& el : v3)
	{
		std::cout << el << '\n';
	}

	return 0;
}







