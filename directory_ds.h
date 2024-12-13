#include <iostream>
#include <filesystem>

#include "path.h"

/// @brief Функция которая рекурсивно просматривает в глубь все содержимое в указанном каталоге
/// @param path - строка путь
/// @param level - глубина поиска
void traversal(Path path, std::uint16_t level);