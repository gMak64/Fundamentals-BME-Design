#include <iostream>
#include <vector>
#include <cctype>
#include <math.h>
#include <array>

using namespace std;
double findFreq(double c, double r1, double offset, double r2);
double findResistance2(double c, double r1, double offset, double f);
double findResistance1(double c, double r2, double offset, double f);
double findCapacitance(double r1, double r2, double offset, double f);
void capacitorSet(double capacitor[]);
//vector<float> frequencies;
double capacitor[29] {};
double resistor1[2] {0, pow(10, 4)};
double minMaxF[2] {1, 60};
double resistor2[63] {0, 1, 1.2, 1.5, 2, 2.7, 3.3, 4.3, 5.1, 6.8, 8.2, 10, 12, 15, 20, 27, 33, 43, 51, 68, 82, 100, 120, 150, 200, 270, 330, 430, 510, 680, 820, 1000, 1200, 1500, 2000, 2700, 3300, 4300, 5100, 6800, 8200, 10000, 12000, 15000, 20000, 27000, 33000, 43000, 51000, 68000, 82000, 100000, 120000, 150000, 200000, 270000, 330000, 430000, 510000, 680000, 820000, 1000000, 2000000};

int main()
{
    capacitorSet(capacitor);
    double offset;
    cout << "Enter an offset in Ohms: ";
    cin >> offset;
    /* cout << "POTENIOMETER = R1" << endl;
    cout << "________________________________________________________________________________________" << endl;
    for (int i {0}; i <= 28; i ++) {
        for (int j {0}; j <= 62; j ++) {
                float highf = findFreq(capacitor[i], resistor2[j], resistor1[0]);
                float lowf = findFreq(capacitor[i], resistor2[j], resistor1[1]);
                //frequencies.push_back(lowf);
                //frequencies.push_back(highf);
                cout << capacitor[i] << "F, " << resistor2[j] << " O = [" << lowf << ", " << highf << "]" << endl;
        }
    } 
    cout << endl;
    cout << "POTENIOMETER = R2" << endl;
    cout << "________________________________________________________________________________________" << endl;
    for (int i {0}; i <= 28; i ++) {
        for (int j {0}; j <= 62; j ++) {
                float highf = findFreq(capacitor[i], resistor1[0], resistor2[j]);
                float lowf = findFreq(capacitor[i], resistor1[1], resistor2[j]);
                //frequencies.push_back(lowf);
                //frequencies.push_back(highf);
                cout << capacitor[i] << " F, " << resistor2[j] << " O = [" << lowf << ", " << highf << "]" << endl;
        }
    } */

    /*
    cout << "R2 CALCULATIONS" << endl;
    cout << "________________________________________________________________________________________" << endl;
    for (int i {0}; i <= 28; i ++) {
            double resistorLow = findResistance2(capacitor[i], 0, offset, 1);
            double resistorHigh = findResistance2(capacitor[i], 10000 , offset, 60);
            cout << capacitor[i] << " F " << "[" << resistorLow << ", " << resistorHigh << "] " << resistorLow - resistorHigh << endl;
        }
    cout << endl; */
    /* cout << "R1 CALCULATIONS" << endl;
    cout << "________________________________________________________________________________________" << endl;
    for (int i {0}; i <= 28; i ++) {
            double resistorLow = findResistance1(capacitor[i], 0, offset, 1);
            double resistorHigh = findResistance1(capacitor[i], 10000 , offset, 60);
            cout << capacitor[i] << " F " << "[" << resistorLow << ", " << resistorHigh << "] " << resistorLow - resistorHigh << endl;
        } 
    cout << endl; */

    cout << "CAPACITOR CALCULATIONS" << endl;
    cout << "________________________________________________________________________________________" << endl;
    for (int i {0}; i <= 62; i += 1) {
        double capacitorLow = findCapacitance(0, resistor2[i], offset, 60);
        double capacitorHigh = findCapacitance(10000, resistor2[i], offset, 1);
        cout << resistor2[i] << " O " << "[" << capacitorLow << ", " << capacitorHigh << "]   ";
        //cout << endl;
        cout << "[" << findFreq(capacitorLow, 10000, offset, resistor2[i]) << ", ";
        cout << findFreq(capacitorLow, 0, offset, resistor2[i]) << "]   ";
        cout << "[" << findFreq(capacitorHigh, 10000, offset, resistor2[i]) << ", ";
        cout << findFreq(capacitorHigh, 0, offset, resistor2[i]) << "]   " << endl;
    }
    return 0;
}

double findFreq(double c, double r1, double offset, double r2)
{
    r1 = r1 + offset;
    return 1.44 / (c * (r1 + r2 + r2));
}

double findResistance2(double c, double r1, double offset, double f) {
    r1 = r1 + offset;
    return (1.44 - (f * r1 * c)) / (2 * f * c);
}

double findResistance1(double c, double r2, double offset, double f) {
    r2 = r2 + offset;
    return (1.44 / (f * c)) - (2 * r2);
}

double findCapacitance(double r1, double r2, double offset, double f) {
    r1 = r1 + offset;
    return 1.44 / (f * (r1 + r2 + r2));
}

void capacitorSet(double capacitor[])
{
    capacitor[0] = 15 * pow(10, -12);
    capacitor[1] = 22 * pow(10, -12);
    capacitor[2] = 27 * pow(10, -12);
    capacitor[3] = 33 * pow(10, -12);
    capacitor[4] = 47 * pow(10, -12);
    capacitor[5] = 68 * pow(10, -12);
    capacitor[6] = 82 * pow(10, -12);
    capacitor[7] = 100 * pow(10, -12);
    capacitor[8] = 120 * pow(10, -12);
    capacitor[9] = 150 * pow(10, -12);
    capacitor[10] = 180 * pow(10, -12);
    capacitor[11] = 220 * pow(10, -12);
    capacitor[11] = 330 * pow(10, -12);
    capacitor[11] = 680 * pow(10, -12);
    capacitor[12] = 1 * pow(10, -9);
    capacitor[13] = 1.5 * pow(10, -9);
    capacitor[14] = 4.7 * pow(10, -9);
    capacitor[15] = 10 * pow(10, -9);
    capacitor[16] = 100 * pow(10, -9);
    capacitor[17] = 470 * pow(10, -9);
    capacitor[18] = 0.01 * pow(10, -6);
    capacitor[19] = 0.022 * pow(10, -6);
    capacitor[20] = 0.047 * pow(10, -6);
    capacitor[21] = 0.1 * pow(10, -6);
    capacitor[22] = 0.22 * pow(10, -6);
    capacitor[23] = 0.47 * pow(10, -6);
    capacitor[24] = 0.82 * pow(10, -6);
    capacitor[25] = 1 * pow(10, -6);
    capacitor[26] = 1.2 * pow(10, -6);
    capacitor[16] = 2.2 * pow(10, -6);
    capacitor[27] = 4.7 * pow(10, -6);
    capacitor[28] = 10 * pow(10, -6);
    capacitor[29] = 100 * pow(10, -6);
}