#include <iostream>
#include <vector>
#include <cctype>
#include <math.h>
#include <array>

using namespace std;
double findFreq(double c, double r1, double r2);
void capacitorSet(double capacitor[]);
//vector<float> frequencies;
double capacitor[17] {};
double resistor1[2] {100, pow(10, 4)};
double resistor2[63] {0, 1, 1.2, 1.5, 2, 2.7, 3.3, 4.3, 5.1, 6.8, 8.2, 10, 12, 15, 20, 27, 33, 43, 51, 68, 82, 100, 120, 150, 200, 270, 330, 430, 510, 680, 820, 1000, 1200, 1500, 2000, 2700, 3300, 4300, 5100, 6800, 8200, 10000, 12000, 15000, 20000, 27000, 33000, 43000, 51000, 68000, 82000, 100000, 120000, 150000, 200000, 270000, 330000, 430000, 510000, 680000, 820000, 1000000, 2000000};

int main()
{
    capacitorSet(capacitor);
    for (int i {0}; i <= 16; i ++) {
        for (int j {0}; j <= 62; j ++) {
                float highf = findFreq(capacitor[i], resistor2[j], resistor1[0]);
                float lowf = findFreq(capacitor[i], resistor2[j], resistor1[1]);
                //frequencies.push_back(lowf);
                //frequencies.push_back(highf);
                cout << capacitor[i] << "F, " << resistor2[j] << "O = [" << lowf << ", " << highf << "]" << endl;
        }
    }
    return 0;
}

double findFreq(double c, double r1, double r2)
{
    return 1.44 / (c * (r1 + r2 + r2));
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
    capacitor[12] = 1 * pow(10, -9);
    capacitor[13] = 10 * pow(10, -9);
    capacitor[14] = 100 * pow(10, -9);
    capacitor[15] = 470 * pow(10, -9);
    capacitor[16] = 1 * pow(10, -6);
}

