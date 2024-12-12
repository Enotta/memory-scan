#include<iostream>
#include<string>
#include<filesystem>
#include <sys/stat.h>

using namespace std;

bool validate_path(string path) {
    struct stat sb;
    return stat(path.substr(1, path.length()-2).c_str(), &sb) == 0;
}

int main() {
    string path = "";

    while (path == "" || !validate_path(path)) {
        cout << "Введите путь до директории (самый простой способ - скопировать в проводнике): ";
        cin >> path;
    }

    cout << "Путь валиден!";

    return 0;
}