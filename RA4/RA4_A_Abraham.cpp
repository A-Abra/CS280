#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;
//using std::cout;

int main(int argc, char *argv []) {
	string file;
	if(argc < 2)
		cout << "No file is found" << endl;
	else if(argc >= 2){
		file = argv[1];
		ifstream inFile;
		inFile.open(file.c_str());
	
		string maxword;
		int cntwords=0,maxfreq=-1;
		
		map<string,int> prepcnt;
		prepcnt["in"] = 0; prepcnt["on"] = 0; prepcnt["to"] = 0; prepcnt["at"] = 0;
		prepcnt["after"] = 0; prepcnt["with"] = 0; prepcnt["over"] = 0;
		prepcnt["by"] = 0; prepcnt["between"] = 0; prepcnt["into"] = 0;		
		
		if(inFile.is_open()){
			
			string word = "";
			while(inFile>>word){
				//go through whole word to change word to lower case
                word[0]=tolower(word[0]);
				cntwords++;
				//if not found in map continue
				if(prepcnt.find(word)==prepcnt.end())
					continue;
				//else increment
				else{
					prepcnt[word]++;
				}
			}
		}
		else{
			cerr << "File cannot be opened: " << file << endl;
    	    exit( 1 );
		}
		inFile.close();
       
        if(cntwords==0)
			cout<<"File is empty."<<endl;
	    else{
            cout<<"List of Prepositions seen in the file and their number of occurrences:"<<endl<<endl;
			for(auto itr = prepcnt.begin(); itr!=prepcnt.end(); itr++){
                if(itr->second > maxfreq){
					maxword = itr->first;
					maxfreq = itr->second;
				}
				cout << itr->first << ": " << itr->second << endl;
			}
			cout<<"The preposition with maximum occurrences is \"" << maxword
				<< "\" found " << maxfreq << " times."<<endl;
        }
	}
	return 0;
}
