#include <iostream>
using namespace std;

int orientation(int x1, int y1, int x2, int y2, int x3, int y3) {
    int val = (y2 - y1) * (x3 - x2) - (x2 - x1) * (y3 - y2);
    if (val == 0) return 0; // colinear
    return (val > 0) ? 1 : 2; // horário ou anti-horário
}

bool onSegment(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x3 >= min(x1, x2) && x3 <= max(x1, x2) && 
            y3 >= min(y1, y2) && y3 <= max(y1, y2));
}

bool doIntersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int o1 = orientation(x1, y1, x2, y2, x3, y3);
    int o2 = orientation(x1, y1, x2, y2, x4, y4);
    int o3 = orientation(x3, y3, x4, y4, x1, y1);
    int o4 = orientation(x3, y3, x4, y4, x2, y2);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && onSegment(x1, y1, x2, y2, x3, y3)) return true;
    if (o2 == 0 && onSegment(x1, y1, x2, y2, x4, y4)) return true;
    if (o3 == 0 && onSegment(x3, y3, x4, y4, x1, y1)) return true;
    if (o4 == 0 && onSegment(x3, y3, x4, y4, x2, y2)) return true;

    return false;
}

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    if (doIntersect(x1, y1, x2, y2, x3, y3, x4, y4))
        cout << "SIM" << endl;
    else
        cout << "NAO" << endl;

    return 0;
}