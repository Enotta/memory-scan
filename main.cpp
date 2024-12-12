#include<iostream>
#include<string>
#include<filesystem>
#include <sys/stat.h>

using namespace std;

void trim_path(string* path) {
    if ((*path).rfind('"', 0) == 0)
        *path = path->substr(1, path->length()-2);
}

void tds_folder_contents(string path, uint16_t level) {
    trim_path(&path);

    string level_string = "";
    for (const auto & entry : filesystem::directory_iterator(path)) {
        filesystem::path local_path = entry.path();
        level_string.clear();
        for (int i = 0; i < level; ++i) level_string += "--";
        std::cout << level_string << " " << local_path << std::endl;

        if (filesystem::is_directory(local_path)) tds_folder_contents(local_path.string(), level+1);
    }
}

bool validate_path(string* path) {
    trim_path(path);

    struct stat sb;
    return stat(path->c_str(), &sb) == 0;
}

int main() {
    string path = "";

    // Проверка пути на существование
    while (path == "" || !validate_path(&path)) {
        cout << "Введите путь до директории (самый простой способ - скопировать в проводнике): ";
        cin >> path;
    }

    // Поиск в глубину всего, что есть в папке
    tds_folder_contents(path, 0);

    return 0;
}