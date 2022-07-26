#include <iostream>
#include <map>
#include <string>
using namespace std;

class PhoneBook {
	private:
		string Phone_number, Name;
	public:
		map<string, string> Phone_Book;
		
		PhoneBook() { }
		
		PhoneBook(string p_num, string name) {
			Phone_number = p_num;
			Name = name;
			Phone_Book.insert(pair<string, string>(p_num, name) );
		}
		
		~PhoneBook() {	}
		
		void from_string() {
			for( map<string, string>::iterator it = Phone_Book.begin(); it != Phone_Book.end(); it++ ) {
				cout << it->first << " " << it->second << "\n";
			}
		}
		
		void FindByLastName(string name) {
			for( map<string, string>::iterator i = Phone_Book.begin(); i != Phone_Book.end(); i++ ) {
				map<string, string>::iterator it = Phone_Book.find( name );
				if( i->second == name)cout << i->first << " " << i->second <<'\n';
			}

		}
		
		void FindByNumber(string number) {
			for( map<string, string>::iterator it = Phone_Book.begin(); it != Phone_Book.end(); it++ ) {
				map<string, string>::iterator i = Phone_Book.find( number );
				if( number == it->first ) cout << it->second << "\n";

			}
		}
		
		void add_user( string p_num, string name ) {
			Phone_number = p_num;
			Name = name;
			Phone_Book.insert(pair<string, string>(p_num, name) );
		}
		
		void erase_user( string p_num ) {
			map<string, string>::iterator user = Phone_Book.find(p_num);
			Phone_Book.erase(p_num);
		}
};


int main() {
	PhoneBook PB;
	PB.add_user("12-23-45", "Grey");
	PB.add_user("12-28-48", "Ericson");
	PB.add_user("12-23-35", "Herr");
//	PB.erase_user(n);
	PB.add_user("12-28-45", "Jacos");
	PB.add_user("12-29-45", "Herr");
	cout <<"--------------\n";
//	PB.FindByLastName("Herr");
//	PB.FindByNumber("12-28-48");

	PB.from_string();
	

	
}