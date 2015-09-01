#include "ex01_15.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<Rectangle> vr(10);
    for (int i = 0; i < vr.size(); ++i) {
	vr[i].setLW(i,i);
	vr[i].print();
    }

    findMax( vr, areaCom{} ).print(); // 打印最大值，按照面积
    findMax( vr, perimetCom{} ).print();
    return 0;
}
