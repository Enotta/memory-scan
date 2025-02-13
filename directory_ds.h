#pragma once

#include <iostream>
#include <vector>
#include <filesystem>

#include "path.h"

namespace fs = std::filesystem;

/// @brief Функция которая рекурсивно просматривает в глубь все содержимое в указанном каталоге
/// @param path строка путь
/// @param level глубина поиска
void traversal(Path* path, std::uint16_t level, std::vector<Path*>* top_n, int n);