#include "path.h"

Path::Path(std::string path) {
    this->value = path;
    this->children = std::vector<Path*>();
    this->type = PathType::Unknown;
    this->content_size = 0.0;
}

Path::~Path() {
    for (int i = 0; i < this->children.size(); ++i) {
        delete this->children[i];
    }
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
