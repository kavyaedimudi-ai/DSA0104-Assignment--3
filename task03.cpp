#include <iostream>
#include <string>
using namespace std;
class Event{
 string name;int rows,seats;bool** booked;
public:
 Event(const string& n,int r,int s):name(n),rows(r>0?r:0),seats(s>0?s:0),booked(rows?new bool*[rows]:nullptr){
  for(int i=0;i<rows;i++)booked[i]=seats?new bool[seats]():nullptr;
  cout<<"Created "<<name<<'\\n';
 }
 bool book(int r,int s){if(r<0||r>=rows||s<0||s>=seats||booked[r][s])return false;booked[r][s]=true;return true;}
 bool cancel(int r,int s){if(r<0||r>=rows||s<0||s>=seats||!booked[r][s])return false;booked[r][s]=false;return true;}
 ~Event(){int count=0;for(int i=0;i<rows;i++){for(int j=0;j<seats;j++)if(booked[i][j])count++;delete[] booked[i];}delete[] booked;cout<<"Closing "<<name<<"; booked seats: "<<count<<'\\n';}
};
int main(){Event a("Morning",2,3);a.book(0,1);{Event b("Afternoon",1,2);b.book(0,0);}Event* c=new Event("Evening",2,2);c->book(1,1);delete c;Event z("Empty",0,5);}
