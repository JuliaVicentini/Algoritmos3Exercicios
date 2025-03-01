#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // Colinear
    return (val > 0) ? 1 : 2; // Horário ou Anti-horário
}

bool onSegment(Point p, Point q, Point r) {
    return (r.x >= min(p.x, q.x) && r.x <= max(p.x, q.x) &&
            r.y >= min(p.y, q.y) && r.y <= max(p.y, q.y));
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, q1, p2)) return true;
    if (o2 == 0 && onSegment(p1, q1, q2)) return true;
    if (o3 == 0 && onSegment(p2, q2, p1)) return true;
    if (o4 == 0 && onSegment(p2, q2, q1)) return true;

    return false;
}

bool isInside(Point polygon[], int n, Point p) {
    Point extreme = {1000, p.y};

    int count = 0;
    for (int i = 0; i < n; i++) {
        Point current = polygon[i];
        Point next = polygon[(i + 1) % n];

        if (doIntersect(current, next, p, extreme)) {
            if (orientation(current, next, p) == 0)
                return onSegment(current, next, p);
            count++;
        }
    }

    return (count % 2 == 1);
}

int main() {
    int n;
    cin >> n; 

    Point polygon[n];
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y; 
    }

    Point p;
    cin >> p.x >> p.y; 

    if (isInside(polygon, n, p))
        cout << "DENTRO" << endl;
    else
        cout << "!(DENTRO)" << endl;

    return 0;
}