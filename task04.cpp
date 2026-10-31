#include <iomanip>
#include <iostream>
using namespace std;
class Money{
 long long paise;
public:
 Money(long long r=0,int p=0):paise(r*100+p){}
 Money operator+(const Money& m)const{return Money(0,static_cast<int>(paise+m.paise));}
 bool operator==(const Money& m)const{return paise==m.paise;}
 friend ostream& operator<<(ostream& out,const Money& m){long long v=m.paise;if(v<0){v=-v;out<<"-Rs ";}else out<<"Rs ";out<<v/100<<'.'<<setw(2)<<setfill('0')<<v%100<<setfill(' ');return out;}
};
int main(){Money a(120,75),b(79,25);Money c=a+b;cout<<c<<'\\n'<<boolalpha<<(c==Money(200))<<'\\n';Money x(0,75),y(0,50);cout<<x+y<<'\\n';}
