#include "directory_ds.h"

void add_sort(Path* path, std::vector<Path*>* vec, int n) {
    vec->push_back(path);

    if (vec->size() == 1) return;
    else {
        int current_pos = vec->size() - 1;
        while (current_pos >= 1 && vec->at(current_pos)->content_size > vec->at(current_pos - 1)->content_size) {
            Path* temp = vec->at(current_pos - 1);
            vec->at(current_pos - 1) = vec->at(current_pos);
            vec->at(current_pos) = temp;
            current_pos -= 1;
        }
    }

    while (vec->size() > n) {
        vec->pop_back();
    }
}

void traversal(Path* path, uint16_t level, std::vector<Path*>* top_n, int n) {
    path->trim();

    for (const auto & entry : fs::directory_iterator(path->value)) {
        fs::path current_path = entry.path();

        Path* new_path = new Path(current_path.string());
        path->children.push_back(new_path);
        if (fs::is_directory(current_path)) { 
            traversal(new_path, level+1, top_n, n);
        }
        else {
            new_path->content_size = fs::file_size(current_path);
            add_sort(new_path, top_n, n);
        }
        
        path->content_size += new_path->content_size;
    }
}