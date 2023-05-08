#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <string>

using namespace std;
bool inLanguage(string & inputString){
    stack<char>revin;
    string revstr;
    for(int i=0;i<inputString.length();i++)
        revin.push(inputString[i]);
    for(int i=0;i<inputString.length();i++){
        revstr+=revin.top();
        revin.pop();
    }
        
    if(inputString.length()%2==1){
        cout << "A string with an odd number of characters is not in the Language." << endl;
        return false;
    }
    else if(inputString.empty()){
        cout << "Empty string is not in the Language." << endl;
        return false;
    }
    else if(inputString==string(revstr))
        return true;
    else
        return false;
}

int main(int argc, char *argv [])
{
	string sentence;
	bool isInLanguage;
	int Lcount=0;
	
	ifstream file;
	if( argc >= 2 ) {
		file.open(argv[1]);
		if( !file) 
		{
			/* error */ 
			cerr << "File cannot be opened: " << argv[1] << endl;
			exit (1);
        }
				
	}
	else
	{
		cerr << "No file is found" << endl;
		exit (1);
	}
	
	     
    while ( !file.eof()) {
        getline(file, sentence);
       	Lcount++;
        //cout<< "in while stmt" << endl;
       	isInLanguage = inLanguage(sentence);
        //cout<< "return from call ti inLanguage" << endl;
        
       	if (isInLanguage)
       	{
       		cout << "\"" << sentence << "\"" << " is a sentence in the Language." << endl;
		}
		else
		{
			if(sentence.length() != 0)
				cout << "\"" << sentence << "\"" << " is not a sentence in the Language." << endl;
		}
		 	
		//getline(file, sentence); 
	}
}

