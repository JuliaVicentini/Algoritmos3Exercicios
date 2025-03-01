#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) * 1.0 + (a.y - b.y) * (a.y - b.y) * 1.0);
}

int orientation(Point p, Point q, Point r) {
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // colinear
    return (val > 0) ? 1 : 2; // horário ou anti-horário
}

void swap(Point &p1, Point &p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

int nextToTop(Point stack[], int top) {
    return top - 1;
}

void convexHull(Point points[], int n) {
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        if ((points[i].y < ymin) || (ymin == points[i].y && points[i].x < points[min].x)) {
            ymin = points[i].y;
            min = i;
        }
    }
    swap(points[0], points[min]);

    Point p0 = points[0];
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (orientation(p0, points[i], points[j]) == 2) {
                swap(points[i], points[j]);
            }
        }
    }

    Point stack[n];
    int top = 2;
    stack[0] = points[0];
    stack[1] = points[1];
    stack[2] = points[2];

    for (int i = 3; i < n; i++) {
        while (orientation(stack[nextToTop(stack, top)], stack[top], points[i]) != 2) {
            top--;
        }
        stack[++top] = points[i];
    }

    double perimeter = 0;
    for (int i = 0; i < top; i++) {
        perimeter += distance(stack[i], stack[i + 1]);
    }
    perimeter += distance(stack[top], stack[0]); // Fechar o ciclo

    cout << ceil(perimeter) << endl;
}

int main() {
    int n;
    cin >> n;
    Point points[n];

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    convexHull(points, n);
    return 0;
}
