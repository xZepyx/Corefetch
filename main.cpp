#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/utsname.h>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <array>
#include <sys/stat.h>

using namespace std;

string exec(const char* cmd) {
    array<char, 128> buffer{};
    string result;
    FILE* pipe = popen(cmd, "r");
    if (!pipe) {
        cerr << "Error: popen failed for command: " << cmd << endl;
        return "Unknown";
    }
    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result += buffer.data();
    }
    pclose(pipe);
    result.erase(result.find_last_not_of(" \n\r\t")+1);
    return result;
}

string expandHome(const string& path) {
    if (!path.empty() && path[0] == '~') {
        const char* home = getenv("HOME");
        if (home) return string(home) + path.substr(1);
    }
    return path;
}

vector<string> loadAsciiArt() {
    string configDir = expandHome("~/.config/corefetch");
    string configPath = configDir + "/ascii";

    // Create directory if not exists
    mkdir(configDir.c_str(), 0755);

    ifstream asciiFile(configPath);
    if (!asciiFile.good()) {
        ofstream outFile(configPath);
        if (outFile) {
            vector<string> defaultArt = {
                "                 -`",
                "                .o+`",
                "               `ooo/",
                "              `+oooo:",
                "             `+oooooo:",
                "             -+oooooo+:",
                "           `/:-:++oooo+:",
                "          `/++++/+++++++:",
                "         `/++++++++++++++:",
                "        `/+++ooooooooooooo/`",
                "       ./ooosssso++osssssso+`",
                "      .oossssso-````/ossssss+`",
                "     -osssssso.      :ssssssso.",
                "    :osssssss/        osssso+++.",
                "   /ossssssss/        +ssssooo/-",
                "  `/ossssso+/:-        -:/+ossss+`",
                " `+sso+:-`                 `.-/+oso:",
                "`++:.                           `-/+/",
                ".`                                 `/"
            };
            for (const auto& line : defaultArt) {
                outFile << line << "\n";
            }
            outFile.close();
        }
        asciiFile.open(configPath); // Reopen after writing
    }

    vector<string> art;
    string line;
    while (getline(asciiFile, line)) {
        art.push_back(line);
    }
    return art;
}

string getUsername() {
    const char* user = getenv("USER");
    return user ? string(user) : "Unknown";
}

string getHostname() {
    char hostname[1024];
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        return string(hostname);
    }
    return "Unknown";
}

string getOSName() {
    ifstream osFile("/etc/os-release");
    string line;
    while (getline(osFile, line)) {
        if (line.find("PRETTY_NAME") != string::npos) {
            size_t first_quote = line.find("\"");
            size_t last_quote = line.rfind("\"");
            if (first_quote != string::npos && last_quote != string::npos && last_quote > first_quote) {
                return line.substr(first_quote + 1, last_quote - first_quote - 1);
            }
        }
    }
    return "Unknown OS";
}

string getKernel() {
    struct utsname buffer;
    if (uname(&buffer) == 0) {
        return buffer.release;
    }
    return "Unknown";
}

string getUptime() {
    ifstream file("/proc/uptime");
    double uptime;
    if (file >> uptime) {
        int h = static_cast<int>(uptime) / 3600;
        int m = (static_cast<int>(uptime) % 3600) / 60;
        return to_string(h) + "h " + to_string(m) + "m";
    }
    return "Unknown";
}

string getShell() {
    string cmdline = exec("ps -p $$ -o comm=");
    if (!cmdline.empty()) {
        return cmdline;
    }
    const char* shell_env = getenv("SHELL");
    return shell_env ? string(shell_env) : "Unknown";
}

string getTerminal() {
    const char* term = getenv("TERM");
    if (term) return string(term);
    string tty = exec("tty");
    if (!tty.empty() && tty != "not a tty") {}
    return "Unknown";
}

string getDE() {
    char* de = getenv("XDG_CURRENT_DESKTOP");
    if (de) return string(de);
    de = getenv("DESKTOP_SESSION");
    if (de) return string(de);
    return "Unknown";
}

string getWM() {
    string wm_name = exec("wmctrl -m | grep Name | cut -d ':' -f2");
    if (!wm_name.empty()) {
        size_t first = wm_name.find_first_not_of(" \t\n\r");
        size_t last = wm_name.find_last_not_of(" \t\n\r");
        return (first == string::npos) ? "" : wm_name.substr(first, last - first + 1);
    }
    return "Unknown";
}

string getCPU() {
    string cpu_info = exec("grep 'model name' /proc/cpuinfo | head -n 1 | cut -d ':' -f2");
    if (!cpu_info.empty()) {
        size_t first = cpu_info.find_first_not_of(" \t");
        size_t last = cpu_info.find_last_not_of(" \t");
        if (string::npos == first) return "";
        return cpu_info.substr(first, (last - first + 1));
    }
    return "Unknown";
}

string getRAM() {
    ifstream mem("/proc/meminfo");
    string line;
    long total = 0, free = 0, buffers = 0, cached = 0;

    while (getline(mem, line)) {
        if (line.find("MemTotal:") == 0) {
            total = stol(line.substr(line.find(":") + 1));
        } else if (line.find("MemAvailable:") == 0) {
            free = stol(line.substr(line.find(":") + 1));
        } else if (line.find("MemFree:") == 0 && free == 0) {
            free = stol(line.substr(line.find(":") + 1));
        } else if (line.find("Buffers:") == 0 && free == 0) {
            buffers = stol(line.substr(line.find(":") + 1));
        } else if (line.find("Cached:") == 0 && free == 0) {
            cached = stol(line.substr(line.find(":") + 1));
        }
    }

    if (total > 0) {
        if (free > 0 && line.find("MemAvailable:") != string::npos) {
            return to_string((total - free) / 1024) + "MiB / " + to_string(total / 1024) + "MiB";
        } else if (free > 0) {
            return to_string((total - (free + buffers + cached)) / 1024) + "MiB / " + to_string(total / 1024) + "MiB";
        }
    }
    return "Unknown";
}

string getGPU() {
    string gpu_info = exec("lspci | grep -i 'vga\\|3d\\|2d' | head -n 1 | cut -d ':' -f3");
    if (!gpu_info.empty()) {
        size_t first = gpu_info.find_first_not_of(" \t");
        size_t last = gpu_info.find_last_not_of(" \t");
        if (string::npos == first) return "";
        return gpu_info.substr(first, (last - first + 1));
    }
    return "Unknown";
}

int main() {
    vector<pair<string, string>> info = {
        {"User", getUsername()},
        {"Host", getHostname()},
        {"OS", getOSName()},
        {"Kernel", getKernel()},
        {"Uptime", getUptime()},
        {"Shell", getShell()},
        {"Terminal", getTerminal()},
        {"DE", getDE()},
        {"WM", getWM()},
        {"CPU", getCPU()},
        {"Memory", getRAM()},
        {"GPU", getGPU()}
    };

    vector<string> art = loadAsciiArt();

    size_t maxLabelLen = 0;
    for (const auto& entry : info) {
        if (entry.first.length() > maxLabelLen) {
            maxLabelLen = entry.first.length();
        }
    }

    size_t art_width = 0;
    for (const string& line : art) {
        if (line.length() > art_width) {
            art_width = line.length();
        }
    }

    const size_t PADDING = 4;

    for (size_t i = 0; i < max(art.size(), info.size()); ++i) {
        if (i < art.size()) {
            cout << "\033[1;34m" << art[i] << "\033[0m";
            cout << string(art_width - art[i].length() + PADDING, ' ');
        } else {
            cout << string(art_width + PADDING, ' ');
        }

        if (i < info.size()) {
            if (i == 13) {
                cout << "\033[1;33m" << setw(maxLabelLen) << left << "CoreFetch" << "\033[0m : " << info[i].second;
            } else {
                printf("\033[1;33m%-*s\033[0m : %s", (int)maxLabelLen, info[i].first.c_str(), info[i].second.c_str());
            }
        }
        cout << "\n";
    }

    return 0;
}

