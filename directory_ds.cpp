#include "directory_ds.h"

void traversal(Path path, uint16_t level) {
    path.trim();

    std::string level_string = "";
    for (const auto & entry : std::filesystem::directory_iterator(path.value)) {
        std::filesystem::path local_path = entry.path();
        level_string.clear();
        for (int i = 0; i < level; ++i) level_string += "--";
        std::cout << level_string << " " << local_path << std::endl;

        if (std::filesystem::is_directory(local_path)) traversal(Path(local_path.string()), level+1);
    }
}