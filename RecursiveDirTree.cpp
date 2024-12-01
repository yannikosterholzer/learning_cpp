#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = filesystem;


void DisplayDirTree(const fs::path& current_path, int depth) {
    try {
        for (const auto& entry : fs::directory_iterator(current_path)) {
            for (int i = 0; i < depth; i++) {
                cout << "-";
            }
            if (is_directory(entry)) {
                cout << "[" << entry.path().filename().string() << "]" << endl;
                DisplayDirTree(entry, depth + 1);
            }
            else {
                cout << entry.path().filename().string() << endl;
            }
        }
    }
    catch (const fs::filesystem_error& e) {
        cerr << "Error accessing directory " << current_path << ": " << e.what() << endl;
    }

}

int main() {
    DisplayDirTree(fs::current_path(), 0);
    return 0;
}
