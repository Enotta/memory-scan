#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "path.h"
#include "directory_ds.h"

int main(int argc, char** argv) {
    Path path("");

    // Проверка пути на существование
    while (path.value == "" || !path.validate()) {
        std::cout << "Введите путь до директории (самый простой способ - скопировать в проводнике): ";
        std::getline(std::cin, path.value);  // Используем getline вместо cin
    }

    // Поиск в глубину всего, что есть в папке
    std::vector<Path*> top_n;
    traversal(&path, 0, &top_n, 10);
    int longest_name_size(0);
    for (int i = 0; i < top_n.size(); ++i) {
        if (longest_name_size < top_n.at(i)->value.length()) {
            longest_name_size = top_n.at(i)->value.length();
        }
    }

    std::cout << "Топ 10 самых больших файлов в директории:" << std::endl;
    for (int i = 0; i < top_n.size(); ++i) {
        int spaces = longest_name_size - top_n.at(i)->value.length() + 5;
        std::cout << top_n.at(i)->value;
        while (spaces != 0) {
            std::cout << " ";
            spaces--;
        }
        double size = top_n.at(i)->content_size / 1024;
        std::string name = "KB";
        if (size / 1024 > 1) {
            name = "MB";
            size /= 1024;
        }
        if (size / 1024 > 1) {
            name = "GB";
            size /= 1024;
        }
        std::cout << size << " "  << name << std::endl;
    }

    return 0;
}