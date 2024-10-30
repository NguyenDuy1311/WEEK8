#include <iostream>
using namespace std;
struct Node {
    float heso;
    int somu;
    Node* link;
};
struct ListDT {
    Node* first, * last;
};
void initDT(ListDT* l) {
    l->first = l->last = NULL;
}
Node* callNode(float hs, int sm) {
    Node* p = new Node;
    if (p == NULL) return NULL;
    p->heso = hs;
    p->somu = sm;
    p->link = NULL;
    return p;
}
void addN(ListDT* lDT, float hs, int sm) {
    if (hs == 0) return;
    Node* newNode = callNode(hs, sm);
    if (!lDT->first) {
        lDT->first = lDT->last = newNode;
    }
    else {
        lDT->last->link = newNode;
        lDT->last = newNode;
    }
}
void taoDT(ListDT* lDT) {
    float hs;
    int sm;
    int i = 0;
    cout << "Nhap da thuc (nhap he so 0 de ket thuc) : " << endl;
    do {
        i++;
        cout << "Nhap phan tu thu " << i << endl;
        cout << "Nhap he so: ";
        cin >> hs;
        if (hs == 0) break;
        cout << "Nhap so mu: ";
        cin >> sm;
        addN(lDT, hs, sm);
    } while (true);
    cout << "Ket thuc nhap" << endl;
}
void inDT(const ListDT& lDT) {
    Node* p = lDT.first;
    cout << "\nf(x) = ";
    while (p != NULL) {
        cout << p->heso << "*x^" << p->somu;
        if (p->link != NULL) cout << " + ";
        p = p->link;
    }
    cout << endl;
}
void freeDT(ListDT* lDT) {
    Node* p = lDT->first;
    while (p != NULL) {
        Node* temp = p;
        p = p->link;
        delete temp;
    }
    lDT->first = lDT->last = NULL;
}
int main() {
    ListDT DT1;
    initDT(&DT1);
    taoDT(&DT1);
    inDT(DT1);
    freeDT(&DT1);
    return 0;
}
