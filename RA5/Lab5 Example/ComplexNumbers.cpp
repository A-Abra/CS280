
#include <iostream>
#include <cmath>



using namespace std;

class Complex
{    
  float re, im; // by default private
  public:
   Complex(float x = 0, float y = 0)
		: re(x), im(y) { }

   Complex operator*(Complex rhs) const;
   Complex operator*(float k) const;
   
   float GetRe() {
   	return re;
   }
   
   float GetIm() {
   	return im;
   }
   void setRe(float x) { re = x; }
   void setIm(float x) { im = x; }

   friend Complex operator*(float k, Complex c);
   float modulus() const;
   void print() const;
   friend ostream & operator<< (ostream &os, Complex & rhs);
};


Complex Complex::operator*(Complex rhs) const
{
   Complex prod;
   prod.re = (re*rhs.GetRe() - im*rhs.GetIm());
   prod.im = (re*rhs.GetIm() + im*rhs.GetRe());
   return prod;
}
float Complex::modulus() const
{     
    return sqrt(re*re + im*im);
}
void Complex::print() const
{  
    std::cout << "(" << re <<"," << im << ")" << std::endl;
}
Complex Complex::operator*(float k) const
{
   Complex prod;
   prod.re = re * k;
   prod.im = im * k;
   return prod;
}

ostream & operator<< (ostream & out, Complex & rhs)
{  out << "(" << rhs.re <<"," << rhs.im << ")";
   return out;  // allow for concat of << operators
}

Complex operator*(float k, Complex c)
{
   Complex prod;
   prod.re = k * c.re; // Compile Error: cannot access re
   prod.im = k * c.im; // Compile Error: cannot access im
   return prod;
}


int main()
{
   Complex c1, c2(1), c3(1,2);
   float x;
   // overloaded  * operator!!
   c1 = c2 * c3 * c2;
   c2 = c1 * 5;
   

   // OK. Now we use an authorized public function
   x = c1.modulus();
	cout<< "Printing contetns of c1 and c2 complex numbers using the print method of Complext:" << endl;
   c1.print();
   c2.print();
   cout << endl;
   cout<< "Printing contetns of c1, c2, and c3 complex numbers using the friended overloaded function operator<<:" << endl;
   cout << c1 << " " << c2 << " " << c3 << endl;
   
   cout<< "Using the friended function operator* to multiply 8 * c3:" << endl;
   c3 = 8 * c3;
   cout << c3;
	 return 0;
}


