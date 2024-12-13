#include <iostream>
#include <string>
#include <cstdlib>

#include "path.h"
#include "directory_ds.h"

int main(int argc, char** argv) {
    Path path("");

    // Проверка пути на существование
    while (path.value == "" || !path.validate()) {
        std::cout << "Введите путь до директории (самый простой способ - скопировать в проводнике): ";
        std::cin >> path.value;
    }

    // Поиск в глубину всего, что есть в папке
    traversal(path, 0);

    return 0;
}