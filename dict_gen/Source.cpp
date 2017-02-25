#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iterator>
#include <sstream>
#include <map>
#include <locale>
#include <algorithm>
#include <vector>

int main()
{
	setlocale(LC_ALL, "ru");// for russian words
	std::ifstream ifs("in.txt", std::ifstream::in); 

	if (ifs)
	{
		std::string s(std::istreambuf_iterator<char>(ifs.rdbuf()), std::istreambuf_iterator<char>());
		for (std::string::iterator it = s.begin(); it != s.end(); ++it)
		{
			if (!isalpha(*it))
			{
				*it = ' ';
			}
			else if (isupper(*it))
			{
				*it = tolower(*it);
			}
		}


		std::map<std::string, std::size_t> map;
		std::istringstream iss(s);
		while (iss >> s)
		{
			++map[s];
		}


		
		std::vector<std::pair<std::string, std::size_t>> values(map.begin(), map.end());
		auto cmp = [](const std::pair<std::string, std::size_t>& l, std::pair<std::string, std::size_t>& r) { return l.second > r.second; };
		std::sort(values.begin(), values.end(), cmp);


		std::ofstream fout("out.txt");
		for (auto it = values.begin(); it != values.end(); ++it)
		{
			fout << it->first << ' ' << it->second << std::endl;
		}
		fout.close();
	}
	else
	{
		std::cerr << "File not found\n";
	}
	ifs.close();
	return 0;
}