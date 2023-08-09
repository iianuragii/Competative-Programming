// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class anurag{
    int val=1;
    public:
        anurag()
        {
            val=5;
            cout<<"Object is now "<<val<<endl;
        }
        ~anurag()
        {
            cout<<"Object Destroyed"<<endl;
        }
};
int main()
{
    anurag ob;  //static call does automatic call to destructor
    anurag *oc = new anurag();  //dynamic declaration
    delete oc;  //destructor for dynamic declaration
}
