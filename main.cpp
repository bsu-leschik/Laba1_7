#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

int main() {

    int k, c;
    double x;
    double result = 1;
    double temp_result, ideal_result;
    double limit;
    bool plus = false;


    cout << "Write x, k and amount of numbers after comma(only in this order)" << endl;
    cin >> x >> k >> c;
    if (x > 1 || x < -1) { return 1; }

    double i = 2;
    limit = pow(k, -10);

    do {
        temp_result = (i * (i + 1) * pow(x, i - 1)) / 2;

        if (plus) {
            result = result + temp_result;
            plus = false;
        } else {
            result = result - temp_result;
            plus = true;
        }
        i++;
    } while (temp_result > limit || temp_result < 0);

    ideal_result = 1/pow((1+x),3);

    cout << "Result calculated with help of Taylor series: " << fixed << setprecision(c) <<  result << endl;
    cout << "Result calculated with simple formula: " << fixed << setprecision(c) << ideal_result << endl;
    cout << "Difference: " << fixed << setprecision(c) << result - ideal_result << endl;
    return 0;
}
