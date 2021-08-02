#include <iostream>

using namespace std;

class Person{
public:
   virtual void introduce()=0;

};

void Person :: introduce(){
cout << "hey from person"<<endl;
}

class Student : public Person{
public:
   void introduce(){
    cout << "hi i am a student"<<endl;
    Person ::introduce();
    }
};

int main()
{
Student anil;
anil.introduce();
    return 0;
}
