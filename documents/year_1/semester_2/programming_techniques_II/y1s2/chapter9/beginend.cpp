#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec{1,2,3,4,5};
    for(auto i=vec.begin();i!=vec.end();i++){
        cout<<*i<<endl;//1 2 3 4 5
    }
}

/*#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        std::cout << *it << " ";//5 4 3 2 1
    }
    std::cout << std::endl;
    return 0;
}
*/