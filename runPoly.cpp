#include <iostream>
#include <stdio.h>

using namespace std;

class Anurag
{
	public:
		void bla()
		{
			cout<<"Boom Boom"<<endl;
		}
		virtual void show()
		{
			cout<<"Alpha"<<endl;
		}
};

class child:public Anurag
{
	public:
		void show()
		{
			cout<<"child"<<endl;
		}
};

int main()
{
	Anurag *anu;
	child i;
	anu=&i;
	anu->show();
	//i.show();
}
