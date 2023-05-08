#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cctype>
using namespace std;

int main(int argc, char *argv []) {
	string file;
	if(argc < 2)
		cout << "No file is found" << endl;
	else if(argc >= 2){
		file = argv[1];
		ifstream inFile;
		inFile.open(file.c_str());
	
		string line;
		int lines=0, chars=0, digits=0, letters=0, punct=0, words=0, nums=0;
		if(inFile.is_open()){
			while (getline(inFile,line)) {
			    lines++;
                chars += line.length();
                for(int i=0; i<line.length(); i++){
                    if(isdigit(line[i]))
                        digits++;
                    if(isalpha(line[i]))
                        letters++;   
                    if(ispunct(line[i]))
                        punct++;
                    if(ispunct(line[i]) && isdigit(line[i-1]) && isdigit(line[i+1]))
                        nums++;
			    }
                istringstream mystring(line);
			    string word;
	    	    while(mystring >> word){
		    	   	words++;
                    for(int i=0; i<word.length(); i++){
                        if(isdigit(word[i])){
                            nums++;
                            break;
                        }
                    }
                }
	    	}
			
		}
		else{
			cerr << "CANNOT OPEN the File " << file << endl;
    	    exit( 1 );
		}
        if(lines==0)
			cout<<"File is empty."<<endl;
	    else{
    		cout << "LINES: " << lines << endl;
    		cout << "CHARS: " << chars+lines << endl;
    		cout << "DIGITS: " << digits << endl;
	    	cout << "LETTERS: " << letters << endl;
    		cout << "PUNCTUATIONS: " << punct << endl;
	    	cout << "WORDS: " << words << endl;
		    cout << "INTEGERS: " << nums << endl;
        }
	}
	
	return 0;
}
