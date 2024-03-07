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
    
    stack<float> Resistors;
    float input = 1;
    while (input != 0) {
        cin >> input;
        cout << "\n";
        Resistors.push(input);
        float tempR = Resistors.top();
	if (tempR != 0) {
        Resistors.pop();
        cout << "For " << tempR << " Ohms you need " << findNeededResistor(tempR,Rtotal) << " Ohms.\n";
}
    }
	cout << "\nEnding...\n";
	
    
    return 0;
}
