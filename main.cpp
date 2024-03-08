#include <iostream>
#include "UsefulFunctions.h"
#include <fstream>
#include<math.h>
#include <set>
#include<vector>
#include<cctype>
using namespace std;

//Some Functions here to for the 3rd choice in the program
//Calculate the size of n resistors in parallel
float ParallelResistorsMultiple(vector<float> Resistances, int size) {
    float sum = 0;
    //add inverses
    for (int i = 0; i < size; i++) {
        sum += 1/Resistances[i];
    }
    if (sum == 0) {
        return INT32_MIN;
    }
    //invert and return final sum
    return 1/sum;
}

//This code comes from geeksforgeeks.org bc I refuse to spend hours thinking abt this one part of the system.
void solve(vector<float>& arr, int n,
           set<vector<float> >& ans,
           vector<float> v, int i)
{
    if (i >= n) {
        ans.insert(v);
        return;
    }
 
    // Not pick
    solve(arr, n, ans, v, i + 1);
 
    // Pick
    v.push_back(arr[i]);
    solve(arr, n, ans, v, i + 1);
}
 
vector<vector<float> > AllSubsets(
    vector<float> arr, int n)
{
 
    // Set of vectors to store
    // required unique subsets
    set<vector<float> > ans;
 
    sort(arr.begin(), arr.end());
    vector<float> v;
    solve(arr, n, ans, v, 0);
 
    // Vector of vectors to store final result
    vector<vector<float> > res;
    while (!ans.empty()) {
        res.push_back(*ans.begin());
        ans.erase(ans.begin());
    }
    return res;
}
 
// Print Function
void print(int N, vector<float>& A)
{
    vector<vector<float> > result = AllSubsets(A, N);
 
    // printing the output
    for (int i = 0; i < result.size(); i++) {
        cout << '(';
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1)
                cout << " ";
        }
        cout << "), ";
    }
    cout << "\n";
}
//End of geeksforgeeks code



// This code is contained in a single file for intentional obfuscation :)
int main()
{

    // Get updated database info (resistance values) and store it
    ifstream InputFileForCount("ResistorDatabase.txt");
    string resistance;
    if (!InputFileForCount.is_open())
    {
        cout << "Error Opening File" << endl;
    }
    int countLines = 0;
    // Count Number of Lines
    while (getline(InputFileForCount, resistance))
    {
        countLines++;
    }
    ifstream InputFileForParse("ResistorDatabase.txt");
    float *Database = new float[countLines];
    // Add each line to an array
    for (int i = 0; i < countLines; i++)
    {
        getline(InputFileForParse, resistance);
        Database[i] = stof(resistance);
    }
    cout << "\n"
         << "Database Collected!" << endl;

    vector<float> databaseVector;
    for (int z = 0; z < countLines; z++) {
        databaseVector.push_back(Database[z]);
    }
    float userInput = 4;

    // Initiate Program until user input is 0:
    while (userInput != 0)
    {
        cout << "\n";
        cout << "Enter 0 to exit program" << endl;
        cout << endl;
        cout << "Choose from the following Menu:" << endl;
        cout << "1. Parallel Resistor Calculator" << endl;
        cout << "2. Voltage Divider Calaculator" << endl;
        cout << "3. Optimized Resistor Pair from Database" << endl;

        cin >> userInput;

        // Parallel Resistor Mode
        if (userInput == 1)
        {
            cout << endl
                 << endl;
            cout << "You have chosen Parallel Resistor Calculator." << endl;
            cout << "Enter -1 to exit back to menu" << endl;
            float Rtotal = 0;
            cout << "What is the Total Resistance? \n";
            cin >> Rtotal;
            cout << "\nList Available Resistors Greater than Total Resistance\n";

            float input = 1;
            while (input != -1)
            {
                cin >> input;
                cout << "\n";
                if (input != -1)
                {
                    cout << "For " << input << " Ohms you need " << UsefulFunctions::findNeededResistorParallel(input, Rtotal) << " Ohms.\n";
                }
            }
        }

        // Voltage Divider Calculator
        if (userInput == 2)
        {
            cout << "You have chosen Voltage Divider Calculator." << endl;
            cout << "Enter -1 to exit back to menu" << endl;
            float voltageWanted = 0;
            float VCC = 0;
            cout << "\nWhat voltage do you need in the middle?\n";
            cin >> voltageWanted;
            cout << "\nWhat is Vcc?\n";
            cin >> VCC;
            cout << "\nR1 goes to VCC and R2 goes to ground.\n";
            cout << "Your R2/R1 Ratio is " << 1.0 / (VCC / voltageWanted - 1) << endl;
            int input = 0;
            while (input != 1 && input != 2)
            {
                cout << "Type 1 to choose R1 & calculate R2\n Type 2 to choose R2 & calculate R1" << endl;
                cin >> input;
                if (input == -1)
                {
                    break;
                }
            }
            float Rinput = 1;
            if (input == 1)
            {
                cout << "You are choosing the resistor to Vcc" << endl;
                while (Rinput != -1)
                {
                    cin >> Rinput;
                    cout << "\nResistance to ground is: " << 1.0 / (VCC / voltageWanted - 1) * Rinput << endl;
                }
            }
            if (input == 2)
            {
                cout << "You are choosing the resistor to ground" << endl;
                while (Rinput != -1)
                {
                    cin >> Rinput;
                    cout << "\nResistance to Vcc is: " << Rinput / (1.0 / (VCC / voltageWanted - 1)) << endl;
                }
            }
        }

        // Optimized Resistor Pair
        if (userInput == 3)
        {
            cout << "This program will find the most optimal resistor pair based on the database of values you have." << endl;
            cout << "Enter -1 to exit back to menu" << endl << endl;

            float Rtotal = 0;
 
            //2^n - 1 non empty subsets of any set, where n is the size of the set
            cout << "There are " << pow(2,countLines)-1 << " non-empty subsets of resistors. " << endl;

            cout << "Would you like to see every combination? (y/n)" << endl;
            char userResponse = 'a';
            while (tolower(userResponse) != 'y' && tolower(userResponse) != 'n') {
                cin >> userResponse;
            }
            if (tolower(userResponse) == 'y') {
            cout << "The Combinations are: " << endl;
            cout << "\n";
            print(countLines,databaseVector);
            }
            while (Rtotal != -1) {
            cout << "What total Resistance do you need?" << endl;
            cin >> Rtotal;
            if(Rtotal < 0) {
                break;
            }
            //set of vectors of floats to contain all combinations
            
            
            //Each element of the first dimension contains a subset, and each element of the second dimension contains a resistance value within that subset
            vector<vector<float> > EveryCombination = AllSubsets(databaseVector,countLines);
            int BestSubsetIndex = -1;
            float BestResistanceValue = 0;
            float ResistanceOffset = MAXFLOAT;
            vector<vector<float> > duplicateResistances;
            //check for the best combination of resistors
            for (int i = 0; i < EveryCombination.size(); i++) {
                float tempResistance = ParallelResistorsMultiple(EveryCombination[i],EveryCombination[i].size()); 
                if (tempResistance != INT32_MIN) {
                    //if one resistance is closer to the desired value, clear duplicate resistance vector and set current resistance as best value
                    if (abs(Rtotal - tempResistance) < ResistanceOffset) {
                        BestSubsetIndex = i;
                        BestResistanceValue = tempResistance;
                        ResistanceOffset = abs(Rtotal-tempResistance);
                        duplicateResistances.clear();
                    }
                    //if 2 resistances are equally close to the desired value, add to duplicate vector to check lowest number of resistors later.
                    if (abs(Rtotal-tempResistance) == ResistanceOffset) {
                        duplicateResistances.push_back(EveryCombination[i]);
                    }
                }
                
            }
            int currentLowestSize = EveryCombination[BestSubsetIndex].size();
            bool duplicateSituation = false;
            for (int i = 0; i < duplicateResistances.size(); i++) {
                if (duplicateResistances[i].size() < currentLowestSize) {
                    BestSubsetIndex = i;
                    duplicateSituation = true;
                    currentLowestSize = duplicateResistances[i].size();

                }
            }
            if (duplicateSituation) {
                cout << "\n" << "The closest resistance is " << BestResistanceValue << " Ohms." << endl;
                cout << "\n" << "The combination of resistors is: " << endl;
                for (int i = 0; i < duplicateResistances[BestSubsetIndex].size(); i++) {
                    cout << duplicateResistances[BestSubsetIndex][i] << " ";
                }
                cout << endl;
            }
            else {
                cout << "The closest resistance is " << BestResistanceValue << " Ohms." << endl;
                cout << "The combination of resistors is: " << endl;
                for (int i = 0; i < EveryCombination[BestSubsetIndex].size(); i++) {
                    cout << EveryCombination[BestSubsetIndex][i] << " ";
                }
                cout << endl;
            }


        
    }
    cout << "\n"
             << "Exiting..." << endl;
        }
}
cout << "\n"
<< "Ending Program";
    return 0;
}
