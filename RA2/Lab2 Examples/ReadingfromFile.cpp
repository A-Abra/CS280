#include <iostream>
#include <fstream>       
#include <cstdlib>  // exit prototype
#include <iomanip>

    using namespace std;
    
    int main()
	{
    	ifstream inClientFile( "clients.dat", ios::in );
    
       // exit program if unable to create file
       if ( !inClientFile ) {  // overloaded ! operator
          cerr << "File could not be opened" << endl;
          exit( 1 );
       } 
	
		cout << left << setw( 10 ) << "Account" << setw( 13 ) 
            << "Name" << "Balance" << endl << fixed << showpoint;
    
       int account;
       char name[ 30 ];
       double balance;
    	
    	// display each record in file
       while ( inClientFile >> account >> name >> balance )
       {
		   	cout << left << setw( 10 ) << account << setw( 13 ) << name
            << setw( 8 ) << setprecision( 2 ) << right << balance
            << endl;
       } // end while
    
       return 0;  // ifstream destructor closes file
    
    } // end main
