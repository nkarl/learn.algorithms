#include <iostream>
#include <cstring>
#include "../utils.cpp"

using std::cout;
using std::endl;
using std::string;

//enum TYPESWITCH 
//{
    //CHAR   = 'c',
    //INTEGER= 'i',
    //FLOAT  = 'f'
//};

int main() {
    int    a= 2;
    float  b= 1.0;
    char   c= 'c';
    string d= "abc";
    string f= string(d.c_str());

    cout << a << '\t' << typeid(a).name() << "\tint\t="      << (INTEGER == *typeid(a).name() ? "True" : "False") << endl;
    cout << b << '\t' << typeid(b).name() << "\tfloat\t="    << (FLOAT   == *typeid(b).name() ? "True" : "False") << endl;
    cout << c << '\t' << typeid(c).name() << "\tchar\t="     << (CHAR    == *typeid(c).name() ? "True" : "False") << endl;
    cout << typeid(d).name() << endl;
    string name = typeid(f.c_str()).name();
    cout << f << '\t' << typeid(f.c_str()).name() << "\tstring\t=" << (name == "PKc" ? "True" : "False") << endl;

    vector<int> aa = { 1, 2, 3, 4,};
    vector<float> bb = { 1.1, 2.2, 3.3, 4.4,};
    vector<char> cc = { 'a', 'b', 'c', 'd',};
    vector<string> dd = { "aa", "bb", "cc", "dd",};
    myPrintHelp(a);
    myPrintHelp(b);
    myPrintHelp(c);
    myPrintHelp(d);
    myPrint(aa);
    myPrint(bb);
    myPrint(cc);
    myPrint(dd);
}
