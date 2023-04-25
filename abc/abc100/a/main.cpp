#include <iostream>

using namespace std;

int main()
{
   int A, B;

    cin >> A >> B;
    
    if (A > 8 or B > 8) {
        cout << ":(" << endl;
    } else {
        cout << "Yay!" << endl;
    }
}