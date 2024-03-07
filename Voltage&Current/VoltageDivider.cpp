#include <iostream>
#include <stack>
using namespace std;

int main() {
    float voltageWanted = 0;
    float VCC = 0;
    cout << "\nWhat voltage do you need in the middle?\n";
    cin >> voltageWanted;
    cout << "\nWhat is Vcc?\n";
    cin >> VCC;
    cout << "\nR1 goes to VCC and R2 goes to ground.\n";
    cout << "Your R2/R1 Ratio is " << 1.0/(VCC/voltageWanted-1) << endl;
    int input = 0;
    while (input != 1 && input != 2) {
    cout << "Type 1 to choose R1 & calculate R2\n Type 2 to choose R2 & calculate R1" << endl;
    cin >> input;
    }
        float Rinput = 1;
    if (input == 1) {
        cout << "You are choosing the resistor to Vcc" << endl;
        while (Rinput != 0) {
            cin >> Rinput;
            cout << "\nResistance to ground is: " << 1.0/(VCC/voltageWanted-1)*Rinput << endl;

        }

    }
    if (input == 2) {
        cout << "You are choosing the resistor to ground" << endl;
        while (Rinput != 0) {
            cin >> Rinput;
            cout << "\nResistance to Vcc is: " << Rinput/(1.0/(VCC/voltageWanted-1)) << endl;

        }

    }

    cout << "\nEnding... " << endl;

    return 0;
}
