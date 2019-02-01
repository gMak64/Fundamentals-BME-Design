#include <iostream>
#include <vector>
#include <cctype>
#include <math.h>
#include <array>

using namespace std;
double findFreq(double c, double r1, double r2);
double findResistance(double c, double r1, double f);
void capacitorSet(double capacitor[]);
//vector<float> frequencies;
double capacitor[29] {};
double resistor1[2] {0, pow(10, 4)};
double minMaxF[2] {1, 60};
double resistor2[63] {0, 1, 1.2, 1.5, 2, 2.7, 3.3, 4.3, 5.1, 6.8, 8.2, 10, 12, 15, 20, 27, 33, 43, 51, 68, 82, 100, 120, 150, 200, 270, 330, 430, 510, 680, 820, 1000, 1200, 1500, 2000, 2700, 3300, 4300, 5100, 6800, 8200, 10000, 12000, 15000, 20000, 27000, 33000, 43000, 51000, 68000, 82000, 100000, 120000, 150000, 200000, 270000, 330000, 430000, 510000, 680000, 820000, 1000000, 2000000};

int main()
{
    capacitorSet(capacitor);
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
    for (int i {0}; i <= 28; i ++) {
            float resistorLow = findResistance(capacitor[i], 0, 1);
            float resistorHigh = findResistance(capacitor[i], 10000, 60);
            cout << capacitor[i] << " F, " << "[" << resistorLow << ", " << resistorHigh << "] " << resistorLow - resistorHigh << endl;
        }
    return 0;
}

double findFreq(double c, double r1, double r2)
{
    return 1.44 / (c * (r1 + r2 + r2));
}

double findResistance(double c, double r1, double f) {
    return (0.5) * ((1.44 / (c * f)) - r1);
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