#include <iostream>
using namespace std;

//command line args
//	int main(inta argc, char **argv){
//	cout<<argc<<endl<<argv[0]<<argv[1]<<argv[2];
//}



int main(){
	/*
	int x=1;
	int *y; //y pointer to an integer
	y=&x;
	//x=2;
	cout<<"Valuse at address "<<x<<" is: "<<*y;
	cout<<"Valuse at address "<<y<<" is: "<<*y;
	*/
	
	/*
	int *x = new int;
	(*x).x=1;
//	cout<<(*x).x;
//same as above
	cout<<x->x;
	delete x;
	*/
	
	int y=1;
	int *x=&y;
	cout<<*x;
	
	int x[10];
	int *y = x;
	cout<<x<<endl<<y;<<endl;
	
	
	
	return 0;
}
