#include <iostream>
#include "Trait.h"
#include "Cercle.h"
#include "Polygone.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Point2D p1(10, 11);
    Point p2(10);
    Point p3(p1);
    Point2D p4(20,22);
    Point2D p5;
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << p4 << endl;
    cout << p5 << endl;
    Trait t1(&p1, &p4);
    cout << t1 << endl;
    Trait t2(&p1, &p4);
    cout << t2.getP1()->x << endl;
    cout << t2.getP1()->y << endl;
    Cercle c1(&p1, 15);
    cout << c1 << endl;
    Cercle c2(c1);
    cout << c2 << endl;
    vector<Point2D*> v;
    v.push_back(&p1);
    v.push_back(&p4);
    v.push_back(&p5);
    Polygone po1(v);
    cout << po1 << endl;
    Polygone po2(po1);
    cout << po2 << endl;

}

