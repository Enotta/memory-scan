#pragma once
#include <string>
#include <vector>
#include <filesystem> 
#include <sys/stat.h>

enum PathType {
    Directory,
    File, 
    Unknown
};

struct Path 
{
    std::string value;
    std::vector<Path*> children;
    PathType type;
    double content_size;

    Path(std::string path);
    ~Path();

    /// @brief Проверяет входную строку на то, является ли она актуальным путем к директории
    /// @param path ссылка на строку-путь
    /// @return true, если переданная строка в правильном формате и является актуальным путем в система, иначе - false
    bool validate(); 

    /// @brief Избавляет путь от кавычек с обоих концов
    /// @param path ссылка на строку-путь
    void trim(); 
};
