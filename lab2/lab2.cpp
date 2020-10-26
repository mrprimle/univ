#include <iostream>
#include <vector>
using namespace std;

vector<double> twoDotsToLine(double x1, double y1, double x2, double y2) {
    double a = y1 - y2;
    double b = x2 - x1;
    double c = x2 * y1 - x1 * y2;

    // ax + by = c
    return { a, b, c };
}
double twoDotsToDictance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
vector<double> twoDotsToMidNorm(double x1, double y1, double x2, double y2) {
    // y = slope * x + b
    // slope * x - y = -b
    double xMid = (x1 + x2) / 2.0;
    double yMid = (y1 + y2) / 2.0;
    double slope = -(x2 - x1) / (y2 - y1);
    double b = yMid - slope * xMid;
    return {slope, -1, -b};
}
vector<double> twoLinesToBiss(double a, double b, double c, double d, double e, double f) {
    return { (a + d) / 2, (b + e) / 2, (c + f) / 2 };
}






// ax + by = c
// dx + ey = f
vector<double> lab5(double a, double b, double c, double d, double e, double f) {
    bool zeroSol = (a / b == b / e) && (a / b != c / f);
    bool infSol = (a / b == b / e) && (a / b == c / f);
    if (zeroSol || infSol) {
        return {};
    }

    double divisor = a * e - b * d;
    double x = (c * e - b * f) / divisor;
    double y = (a * f - c * d) / divisor;

    return { x, y };
}




void lab10(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = twoDotsToDictance(x1, y1, x2, y2);
    double b = twoDotsToDictance(x2, y2, x3, y3);
    double c = twoDotsToDictance(x3, y3, x1, y1);
    double p = (a + b + c) / 2;
    double part = (p - a) * (p - b) * (p - c);

    double rOut = a * b * c / (4 * sqrt(p * part));
    double rIn = sqrt(part / p);
    
    vector<double> norm1 = twoDotsToMidNorm(x1, y1, x2, y2);
    vector<double> norm2 = twoDotsToMidNorm(x2, y2, x3, y3);
    vector<double> centerOut = lab5(norm1[0], norm1[1], norm1[2], norm2[0], norm2[1], norm2[2]);

    vector<double> line1 = twoDotsToLine(x1, y1, x2, y2);
    vector<double> line2 = twoDotsToLine(x2, y2, x3, y3);
    vector<double> line3 = twoDotsToLine(x3, y3, x1, y1);
    vector<double> biss1 = twoLinesToBiss(line1[0], line1[1], line1[2], line2[0], line2[1], line2[2]);
    vector<double> biss2 = twoLinesToBiss(line1[0], line1[1], line1[2], line3[0], line3[1], line3[2]);
    vector<double> centerIn = lab5(biss1[0], biss1[1], biss1[2], biss2[0], biss2[1], biss2[2]);

    cout << "R: " << rOut << endl;
    cout << "r: " << rIn << endl;
    cout << "Outter center: ";
    copy(centerOut.begin(),
        centerOut.end(),
        ostream_iterator<double>(cout, " ")
    );

    cout << endl;
    cout << "Inner center: ";
    copy(centerIn.begin(),
        centerIn.end(),
        ostream_iterator<double>(cout, " ")
    );
}













int main()
{
    /*
    vector<double> arr = lab5(2, 3, 5, 3, 1, -4);
    copy(arr.begin(),
        arr.end(),
        ostream_iterator<double>(cout, " ")   
    );
    */

    // lab10(1, 1, 5, 4, 2, 6);
    return 0;
}