#include <iostream>
#include <stdio.h>

using namespace std;

class Anurag{
	public:
		void disturb()
		{
			cout<<"Anurag is being disturbed by Ishita"<<endl;
		}
		void scam()
		{
			cout<<"Anurag is being scamed by Ishita"<<endl;
		}
		void love()
		{
			cout<<"Anurag is being loved by Ishita"<<endl;
		}
};
class Ishita:public Anurag{
	public:
		void love()
		{
			cout<<"Anurag is being bitched by Ishita"<<endl;
		}
};
int main()
{
	Ishita ob;
	ob.disturb();
	ob.scam();
	ob.love();
	//ob.bitch();
	return 0;
}
