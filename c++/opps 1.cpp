# include<iostream>
using namespace std;

class Employee
{
    private:
   int id;
   string name;


    public:
 void putdata()
 {
    cout<<"enter your id "<<endl;
    cin>>id;
    cout<<"enter your name :";
    cin>>name;
 }
void getdata()
{
    cout<<"id number:"<<id<<endl;
    cout<<"name:"<<name;
}
};
   int main()
{
Employee E;
E.putdata();
E.getdata();



    return 0;
}
    

