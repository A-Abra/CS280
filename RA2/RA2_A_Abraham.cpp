#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main() {
	cout << "Enter the name of a file to read from: " << endl;
	string file;
	ifstream inFile;
	
	cin >> file;
	cout << endl;
	inFile.open(file.c_str());
	
	string line, longestLine, longestWord;
	int lines=0, commentLines=0, numWords=0;
	
	if(inFile.is_open()){
		
//		while(inFile){
//			char c;
//			inFile.get(c);
//			cout << c << endl;
////			if(get() == '\n')
////				lines++;
////			else if(get())
//		}
		
		while (getline(inFile,line)) {
			lines++;
						
			if((line[0] == '/' && line[1] == '/') || line[0] == '#'){
				commentLines++;
				continue;
			}
			istringstream mystring(line);
			string word;
			while(mystring >> word){
				numWords++;
				if(word.length() > longestWord.length())
					longestWord = word;
			}
			
			if(line.length() > longestLine.length()){
				longestLine = line;
			}			
		}
		inFile.close();
	}
	else{
		cerr << "File cannot be opened " << file << endl;
        exit( 1 );
	}
		
	cout << "Total Number of Lines: " << lines << endl;
	cout << "Number of non-commented lines: " << lines-commentLines << endl;
	cout << "Line of Maximum Length: \"" << longestLine<< "\"" << endl;
	cout << "Number of Words: " << numWords << endl;
	cout << "Word of Maximum Length: \"" << longestWord << "\"" << endl;

	return 0;
}
