#include <iostream>
#include <map>
#include <string>
using namespace std;




class Reception {
	int i = 0;
	public:
		map<string, int> queue;
		Reception() { }
		~Reception() { queue.clear(); }
		
		void add( string name ) {
			queue.insert( pair<string, int>( name, i ) );
			i++;
		}
		
		void from_string() {
			for( map<string, int>::iterator it = queue.begin(); it != queue.end(); it++ ) {
				cout << it->first << " " << it->second << "\n";
			}
		}
		
		void erase_user( string n ) {
			map<string, int>::iterator user = queue.find( n );
			queue.erase( n );
		}
		
		void Next() {
		
			
			for( map<string, int>::iterator it = queue.begin(); it != queue.end(); it++ ) {
				cout << it->first << "\n";
				erase_user( it->first );
				break;
			}
		}
};


int main() {
	Reception R;
	R.add("Sidorov");
	R.add("Ivanov");
	R.add("Ivanov");
	R.add("Petrov");

//	R.from_string();
	cout << "==============\n";
	R.Next();
	R.Next();
	R.Next();
	
}

