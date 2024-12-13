#include "path.h"

Path::Path(std::string path) {
    this->value = path;
    this->type = PathType::Unknown;
    this->content_size = 0.0;
}

void Path::trim() {
    if ((this->value).rfind('"', 0) == 0)
        this->value = this->value.substr(1, this->value.length()-2);
}

bool Path::validate() {
    this->trim();

    struct stat sb;
    return stat(this->value.c_str(), &sb) == 0;
}
