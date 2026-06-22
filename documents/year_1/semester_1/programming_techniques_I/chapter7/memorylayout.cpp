#include <iostream>
using namespace std;
int main() {
    int w[5] = {2, 4, 6, 8, 3};
    int *ptr_1 = nullptr;
    int *ptr_2 = nullptr;
    int *ptr_3 = nullptr;

    ptr_3 = &w[0];
    ptr_2 = ptr_3 + 2;
    ptr_1 = ptr_2;

    cout<<ptr_1;

    return 0;
}
