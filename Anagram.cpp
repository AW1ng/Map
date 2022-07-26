#include <iostream>
#include <map>
#include <string>
using namespace std;


class Anagram {
	public:
		map<char, int> CharCounter(const string &str) {
			map<char, int> anagram;
			for( const auto &ch : str) {
				anagram[ch]++;
			}
			return anagram;
		}
		
		bool IsAnagram(string first, string second) {
			return ( CharCounter(second) == CharCounter(first) );
		}
};


int main() {
	Anagram A;
	if( A.IsAnagram("evil", "veil") ) cout << "Yes";
	else cout << "No";
}
