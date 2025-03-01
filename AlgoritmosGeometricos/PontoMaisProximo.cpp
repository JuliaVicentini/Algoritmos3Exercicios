#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

int squaredDistance(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    int n;
    cin >> n;

    Point points[100];
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    Point user;
    cin >> user.x >> user.y;

    Point closest = points[0];
    int minDist = squaredDistance(user, points[0]);

    for (int i = 1; i < n; i++) {
        int dist = squaredDistance(user, points[i]);

        if (dist < minDist || 
           (dist == minDist && points[i].x < closest.x) || 
           (dist == minDist && points[i].x == closest.x && points[i].y < closest.y)) {
            closest = points[i];
            minDist = dist;
        }
    }

    cout << closest.x << " " << closest.y << endl;

    return 0;
}