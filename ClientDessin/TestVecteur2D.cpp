#include "Vecteur2D.h"
using namespace std;
int main() {
	Vecteur2D v1(3, 2), v2(4, -5), v3;
	v3 = v1 + v2; // v3 = v1.operator +(v2)
	v3 = v1 - v2;
	v3 = v1 * 3;
	v3 = 4 * v1; // 4.operator*(v1) : echec, autre solution : v3=operator * (4,v1)
	v3 = 5 * v1 - 2 * v2 + 11 * v3;
	return 0;
}