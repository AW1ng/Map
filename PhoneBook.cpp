#include <iostream>
#include <map>
#include <vector>
using namespace std;


vector<string> Split(string Data, string Delimiter = " ") {
	cout << "\nSplitting string: >" << Data <<"< by delimiter >" << Delimiter <<"<\n";
	string CurrSubs;
	vector<string> result;
	auto start = 0U;
	auto end = Data.find(Delimiter);
	while( end != string::npos ) {
		string CurrSubs = Data.substr(start, end - start);
		result.push_back(CurrSubs);
		start = end + Delimiter.length();
		end = Data.find(Delimiter, start);
	}
	CurrSubs = Data.substr(start, end - start);
	result.push_back(CurrSubs);
	return result;
}

class FamPhones {
	protected:
		map<string, vector<string> > Data;
		map<string, string> PhoneFam;
	public:
		void AddInfo(string famname, string phones) {
			Data[ famname ].push_back(phones);
			PhoneFam[ phones ] = famname;
		}
		string ToStr( string curFam, vector<string> curPhones ) {
			string result = curFam + " ";
			for( int i = 0; i < curPhones.size(); i++) {
				result += " " + curPhones[i];
			}
			return result;
		}
		void Print() {
			for (auto n :Data) {
				string curFam = n.first;
				vector<string> curPhones = n.second;
				cout << ToStr( curFam, curPhones ) << endl;
			}
		}
		bool Interpret(string command) {
			if(command == "!") {
				cout << "\nQit\n";
				return false;
			}
			if(command == "?") {
				Print();
				return true;
			}
			if(command.find(" ") != -1) {
				vector<string> PF = Split(command);
				AddInfo(PF[1], PF[0]);
			}
			else if(command.find("-") != -1 ) {
				cout << "\nGot Phone\n";
				cout <<  command + " " + PhoneFam[command] + "\n";
			}
			else {
				cout << "\nGot Surname\n";
				cout << ToStr(command, Data[command]) << endl;
			}
			return true;
						
		}
};


int main() {
	FamPhones FP;
	FP.AddInfo("Ivanov", "11-11-11");
	FP.AddInfo("Petrov", "12-12-12");
	FP.AddInfo("Ivanov", "11-11-14");
	FP.AddInfo("luzkov", "11-19-19");
//	FP.Print();
	string command;
	do {
        cout<<"\nYour command: ";
        //cin>>command;
        getline(std::cin, command);
    } while( FP.Interpret(command) );
}
