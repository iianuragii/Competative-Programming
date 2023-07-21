#include <string.h>
#include <iostream>
#include <stdlib.h>
class thinking_cap
{
    public:
    void slots(char new_green[ ], char new_red[ ]) 
    {
        if(strlen(new_green)>50)
            std::cout<<"Error"<< std::endl; 
        strcpy(green_string, new_green);
        strcpy(red_string, new_red); 
    }
        void push_green( ) const { std::cout<<green_string<<
        std::endl; }
        void push_red( ) const { std::cout<<red_string<< std::endl;
        }
        private:
        char green_string[50];
        char red_string[50];
};
int main() 
{
    thinking_cap student;
    thinking_cap fan;
    student.slots( "Hello", "Goodbye");
    fan.slots( "Go Teams!", "Boo!");
    student.push_green( );
    fan.push_green( );
    student.push_red( );
    fan.push_red( );
}
