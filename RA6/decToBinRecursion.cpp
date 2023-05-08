#include <iostream>
#include <string>
//#include <algorithm>
using namespace std;


//string DecToBin(int num){
//	if(num == 0 || num == 1)
//		return to_string(num);
//	else if(num%2==0)
//		return DecToBin(num/2)+"0";
//	else
//		return DecToBin(num/2)+"1";
//}

//101100100
string DecToBin(int num){
    if (num==1)
		return "1";
	else
    	return DecToBin(num / 2) + to_string(num % 2)  ;
}

//string DecToBin(int num){
//	string s = "";
//	while(num >= 1){
//		s+=to_string(num%2);
//		num=num/2;
//	}
//	return s;
//}

int main()
{
	int dec ;
	cout << "Enter a decimal number: " << endl;
	cin >> dec;
	
	string str = DecToBin(dec);
	//reverse(str.begin(),str.end());
	cout<< endl ;
	cout << "result of converting the decimal number " << dec << " to Binary is: " << str << endl;
    
    return 0;
}
