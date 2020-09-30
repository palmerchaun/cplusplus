#include <iostream>

using namespace std;

struct student {
    string name;
    double gpa;
};

int main(){
    student s1;
    s1.name = "Bob";
    s1.gpa = 3.4;

    cout << s1.name << " " << s1.gpa << endl;

    return 0;
}
