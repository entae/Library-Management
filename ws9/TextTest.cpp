#include <iostream>
#include <fstream>
#include "HtmlText.h"
#include "Text.h"
using namespace std;
using namespace sdds;

int main() {
    Text T("test.txt");
    Text Y("whatever.txt"); // whatever.txt can exist or not
    Text Z;
    Y = T;
    Z = Y;
    Text X = Z;
    cout << X << endl;
}