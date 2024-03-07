#include <iostream>
#include <stack>
using namespace std;

float findNeededResistor(float R1, float Rtot) {
        float R2 = -R1*Rtot/(Rtot-R1);
        return R2;
}


int main()
{
    float Rtotal = 0;
    cout << "What is the Total Resistance? \n";
    cin >> Rtotal;
    cout << "\nList Available Resistors Greater than Total Resistance\n";
    
    float input = 1;
    while (input != 0) {
        cin >> input;
        cout << "\n";
	if (input != 0) {
        cout << "For " << input << " Ohms you need " << findNeededResistor(input,Rtotal) << " Ohms.\n";
}
    }
	cout << "\nEnding...\n";
	
    
    return 0;
}
