#include <iostream>
#include <string>
#include <algorithm>

int toNum(char first) {

	switch (first) {
	case 'M':
		return 1000;
	case 'D':
		return 500;
	case 'C':
		return 100;
	case 'L':
		return 50;
	case 'X':
		return 10;
	case 'V':
		return 5;
	case 'I':
		return 1;
	default:
		std::cout << "Incorrect Number" << std::endl;
		return 0;
	}
}


int main() {
	while (true) {
		std::string str;

		std::cin >> str;

		std::transform(str.begin(), str.end(), str.begin(), ::toupper);

		int pos = 0;
		int num = 0;

		while (pos < str.size())
			switch (str[pos]) {
			case 'M':
				num += 1000;
				pos++;
				continue;
			default:
			{
				int tempnum = toNum(str[pos]);
				if (pos < str.size() - 1) {
					if (toNum(str[pos + 1]) > tempnum) {
						num -= tempnum;
						pos++;
						continue;
					}
				}
				num += tempnum;
				pos++;

			}
			}

		std::cout << num << std::endl;
	}
}
