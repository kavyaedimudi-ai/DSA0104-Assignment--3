#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;
class Complex{
 double re,im;
public:
 Complex():re(0),im(0){}
 Complex(double r):re(r),im(0){}
 Complex(double r,double i):re(r),im(i){}
 Complex operator+(const Complex& z)const{return Complex(re+z.re,im+z.im);}
 Complex operator-(const Complex& z)const{return Complex(re-z.re,im-z.im);}
 Complex operator*(const Complex& z)const{return Complex(re*z.re-im*z.im,re*z.im+im*z.re);}
 Complex operator/(const Complex& z)const{double d=z.re*z.re+z.im*z.im;if(d==0)throw runtime_error("Division by zero impedance");return Complex((re*z.re+im*z.im)/d,(im*z.re-re*z.im)/d);}
 bool operator==(const Complex& z)const{return re==z.re&&im==z.im;}
 double magnitude()const{return sqrt(re*re+im*im);}
 friend ostream& operator<<(ostream& o,const Complex& z){o<<z.re<<(z.im<0?" - j":" + j")<<abs(z.im);return o;}
};
int main(){const double pi=acos(-1.0),w=2*pi*50,L=.01,C=100e-6;Complex R(10),ZL(0,w*L),ZC(0,-1/(w*C));Complex series=R+ZL+ZC;Complex parallel=(R*ZL)/(R+ZL);cout<<"Resistor: "<<R<<"\\nInductor: "<<ZL<<"\\nCapacitor: "<<ZC<<"\\nSeries impedance: "<<series<<"\\nSeries magnitude: "<<series.magnitude()<<"\\nParallel (R and L): "<<parallel<<'\\n';try{Complex zero;cout<<R/zero;}catch(const runtime_error& e){cout<<e.what()<<'\\n';}}
