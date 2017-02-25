#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	wcout.imbue(locale(".866"));
	wcout << L"¬водите текст" << endl;
	string s;
	vector<string> vec;
	while (cin >> s)
		vec.push_back(s);
	wcout << L"„астота с какой встречаютс€ слова" << endl;
	vector<int> v;
	for (size_t i = 0; i<vec.size(); ++i) {
		int count = 0;
		vector<string>::iterator it = find(vec.begin(), vec.end(), vec);
		for (vector<string>::iterator iter = vec.begin();
			iter != vec.end(); ++iter) {
			if (*iter == *it) ++count;
		}
		v.push_back(count);
	}
	map<string, int> m_map;
	for (size_t i = 0; i<vec.size(); ++i)
		m_map[vec] = v;
	for (map<string, int>::iterator iter = m_map.begin(); iter !=
		m_map.end(); ++iter) {
		cout << iter->first << ' ' << iter->second << endl;
	}
	return 0;
}