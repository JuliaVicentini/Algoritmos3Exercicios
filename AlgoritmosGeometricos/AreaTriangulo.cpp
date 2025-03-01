#include <iostream>
#include <cmath>
using namespace std;

double calculateArea(int x1, int y1, int x2, int y2, int x3, int y3) {
    return 0.5 * fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    cout.precision(1);
    cout << fixed << calculateArea(x1, y1, x2, y2, x3, y3) << endl;
    
    return 0;
}