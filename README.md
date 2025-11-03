 🗂️ Simple File Explorer (C++)
A **command-line based File Explorer** built in **C++17** using the `<filesystem>` library.
It allows users to navigate directories, manage files, and perform basic file system operations — similar to a mini shell file manager.

🚀 Features
✅ **List Files & Directories**
✅ **Navigate Between Folders (cd)**
✅ **Create New Folders and Files (mkdir, touch)**
✅ **Delete Files and Directories (rm)**
✅ **Copy and Move Files/Directories (cp, mv)**
✅ **Search Files or Folders Recursively**
✅ **View File Information (size, type, path, last modified)**
✅ **Cross-platform (Windows, Linux, macOS)**
✅ **Error Handling & User-friendly Commands**

🧰 Commands
| Command            | Description                                          | Example                |
| ------------------ | ---------------------------------------------------- | ---------------------- |
| `ls`               | List all files and directories in the current folder | `ls`                   |
| `cd <dir>`         | Change directory                                     | `cd Documents`         |
| `mkdir <name>`     | Create a new directory                               | `mkdir Projects`       |
| `touch <file>`     | Create an empty file                                 | `touch notes.txt`      |
| `rm <name>`        | Delete a file or directory                           | `rm notes.txt`         |
| `cp <src> <dest>`  | Copy file or directory                               | `cp file.txt copy.txt` |
| `mv <src> <dest>`  | Move or rename file/directory                        | `mv old.txt new.txt`   |
| `info <file>`      | Show file information                                | `info data.csv`        |
| `search <keyword>` | Search for a file or folder recursively              | `search report`        |
| `help`             | Show all available commands                          | `help`                 |
| `exit`             | Exit the explorer                                    | `exit`                 |

 🧠 How It Works

* The project uses the **C++ `<filesystem>` library** to interact with the local file system.
* Commands are entered in a simple **interactive loop**, parsed, and executed.
* All operations (create, delete, move, copy, etc.) are handled with proper **error checking** and **exception safety**.

🖥️ Example Usage

```
📂 Welcome to Simple File Explorer (Windows Compatible)
Type 'help' to see available commands.

D:\Projects > ls
[DIR]  src
[DIR]  build
       main.cpp

D:\Projects > mkdir test
Directory created: test

D:\Projects > touch example.txt
File created: example.txt

D:\Projects > info example.txt
File Info for: example.txt
Full Path: D:\Projects\example.txt
Type: File
Size: 0 bytes
Last Modified: 132456789000000000
```

---
 ⚙️ Requirements

* **C++17 or later** (for `<filesystem>`)
* A C++ compiler such as:

  * `g++ 9.0+` (Linux / Windows with MinGW)
  * `clang++ 10+`
  * `MSVC (Visual Studio 2019 or newer)`

---
 🧩 Compilation
 🪟 Windows (using Visual Studio Build Tools)

```bash
cl /EHsc file_explorer.cpp
```
 🐧 Linux / macOS

```bash
g++ -std=c++17 file_explorer.cpp -o file_explorer
./file_explorer
```

---
 📁 Project Structure

```
FileExplorer/
│
├── file_explorer.cpp    # Main C++ source file
├── README.md            # Project documentation
└── (optional) examples/ # Example files or folders
```
 📜 License

This project is open-source and available under the **MIT License**.

