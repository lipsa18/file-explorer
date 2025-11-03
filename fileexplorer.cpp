
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

class FileExplorer {
private:
    fs::path currentDir;

public:
    FileExplorer() {
        currentDir = fs::current_path();
    }

    void listFiles() {
        cout << "\nContents of: " << currentDir << "\n";
        for (const auto& entry : fs::directory_iterator(currentDir)) {
            if (fs::is_directory(entry))
                cout << "[DIR]  " << entry.path().filename().string() << "\n";
            else
                cout << "       " << entry.path().filename().string() << "\n";
        }
    }

    void changeDirectory(const string& dir) {
        fs::path newPath = currentDir / dir;
        if (fs::exists(newPath) && fs::is_directory(newPath)) {
            currentDir = fs::canonical(newPath);
            fs::current_path(currentDir);
            cout << "Changed directory to: " << currentDir << "\n";
        } else {
            cout << "Directory not found: " << dir << "\n";
        }
    }

    void makeDirectory(const string& name) {
        try {
            fs::create_directory(currentDir / name);
            cout << "Directory created: " << name << "\n";
        } catch (const exception& e) {
            cout << "Error creating directory: " << e.what() << "\n";
        }
    }

    void createFile(const string& name) {
        ofstream file(currentDir / name);
        if (file) {
            cout << "File created: " << name << "\n";
        } else {
            cout << "Error creating file.\n";
        }
    }

    void deleteFileOrDir(const string& name) {
        fs::path target = currentDir / name;
        try {
            if (fs::exists(target)) {
                fs::remove_all(target);
                cout << "Deleted: " << name << "\n";
            } else {
                cout << "File or directory not found.\n";
            }
        } catch (const exception& e) {
            cout << "Error deleting: " << e.what() << "\n";
        }
    }

    void copyFileOrDir(const string& src, const string& dest) {
        try {
            fs::path srcPath = currentDir / src;
            fs::path destPath = currentDir / dest;
            if (fs::is_directory(srcPath))
                fs::copy(srcPath, destPath, fs::copy_options::recursive);
            else
                fs::copy_file(srcPath, destPath, fs::copy_options::overwrite_existing);
            cout << "Copied " << src << " to " << dest << "\n";
        } catch (const exception& e) {
            cout << "Error copying: " << e.what() << "\n";
        }
    }

    void moveFileOrDir(const string& src, const string& dest) {
        try {
            fs::rename(currentDir / src, currentDir / dest);
            cout << "Moved " << src << " to " << dest << "\n";
        } catch (const exception& e) {
            cout << "Error moving: " << e.what() << "\n";
        }
    }

    void search(const string& name) {
        cout << "Searching for: " << name << "\n";
        for (auto& p : fs::recursive_directory_iterator(currentDir)) {
            if (p.path().filename().string().find(name) != string::npos) {
                cout << "Found: " << p.path().string() << "\n";
            }
        }
    }

    void showFileInfo(const string& file) {
        fs::path filePath = currentDir / file;
        if (!fs::exists(filePath)) {
            cout << "File not found.\n";
            return;
        }

        cout << "\nFile Info for: " << file << "\n";
        cout << "Full Path: " << filePath << "\n";
        cout << "Type: " << (fs::is_directory(filePath) ? "Directory" : "File") << "\n";
        cout << "Size: " << fs::file_size(filePath) << " bytes\n";
        auto lastWriteTime = fs::last_write_time(filePath);
        cout << "Last Modified: " << static_cast<long long>(lastWriteTime.time_since_epoch().count()) << "\n";
    }

    void printHelp() {
        cout << "\nAvailable Commands:\n";
        cout << "  ls                 - List files and directories\n";
        cout << "  cd <dir>           - Change directory\n";
        cout << "  mkdir <name>       - Create directory\n";
        cout << "  touch <file>       - Create empty file\n";
        cout << "  rm <name>          - Delete file or directory\n";
        cout << "  cp <src> <dest>    - Copy file or directory\n";
        cout << "  mv <src> <dest>    - Move or rename file/directory\n";
        cout << "  info <file>        - Show file details\n";
        cout << "  search <keyword>   - Search for a file or folder\n";
        cout << "  help               - Show available commands\n";
        cout << "  exit               - Exit the explorer\n";
    }

    void run() {
        cout << "📂 Welcome to Simple File Explorer (Windows Compatible)\n";
        cout << "Type 'help' to see available commands.\n\n";

        string line, cmd;
        vector<string> args;

        while (true) {
            cout << currentDir.string() << " > ";
            getline(cin, line);
            if (line.empty()) continue;

            args.clear();
            istringstream iss(line);
            while (iss >> cmd) args.push_back(cmd);

            string command = args[0];

            if (command == "ls") listFiles();
            else if (command == "cd" && args.size() > 1) changeDirectory(args[1]);
            else if (command == "mkdir" && args.size() > 1) makeDirectory(args[1]);
            else if (command == "touch" && args.size() > 1) createFile(args[1]);
            else if (command == "rm" && args.size() > 1) deleteFileOrDir(args[1]);
            else if (command == "cp" && args.size() > 2) copyFileOrDir(args[1], args[2]);
            else if (command == "mv" && args.size() > 2) moveFileOrDir(args[1], args[2]);
            else if (command == "info" && args.size() > 1) showFileInfo(args[1]);
            else if (command == "search" && args.size() > 1) search(args[1]);
            else if (command == "help") printHelp();
            else if (command == "exit") break;
            else cout << "Unknown command. Type 'help' for options.\n";
        }
    }
};

int main() {
    FileExplorer explorer;
    explorer.run();
    return 0;
}
