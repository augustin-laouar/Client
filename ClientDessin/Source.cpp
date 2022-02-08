#include <iostream>
#include "Trait.h"
#include "Cercle.h"
#include "Polygone.h"
#include "Vecteur2D.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Point2D p1(10, 11);
    Point p2(10);
    Point2D p3(p1);
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
    Trait t3(t2);
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

   
    Vecteur2D u1(2, 3), u2(2, 3),  v1(35, -63), u3(3, 4), u4(3, -4);
    cout << " u1 = " << u1 << endl;
    cout << " u2 = " << u2 << endl;
    //cout << " u1 - u2 = " << u1 - u2 << endl;
    cout << " 5*u1 = " <<  u1*5 << endl;
    cout << po1 << endl;
    po1.translation(u2);
    cout << po1 << endl;


}

