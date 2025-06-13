#include <iostream>
#include <ctime>

using namespace std;

int main() {
    std::string texto;
    time_t ahora = time(nullptr);
    cout<<ahora<<endl;

    getline(cin, texto);

     ahora = time(nullptr);
    cout<<ahora<<endl;




    return 0;
}
