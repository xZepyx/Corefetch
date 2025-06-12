cl# 🌀 CoreFetch (C++ Edition)

A blazing-fast, minimal, and customizable Neofetch alternative written in C++.

Displays clean system info with ASCII art directly in your terminal — no dependencies required.

---

## 📸 Preview

```yaml
                   -`                     User     : aditya
                  .o+`                    Host     : ArchLinux
                 `ooo/                    OS       : Arch Linux
                `+oooo:                   Kernel   : 6.14.10-arch1-1
               `+oooooo:                  Uptime   : 25h 3m
               -+oooooo+:                 Shell    : ps
             `/:-:++oooo+:                Terminal : xterm-kitty
            `/++++/+++++++:               DE       : Hyprland
           `/++++++++++++++:              WM       : Hyprland
          `/+++ooooooooooooo/`            CPU      : Intel(R) Core(TM) i3-1005G1 CPU @ 1.20
         ./ooosssso++osssssso+`           Memory   : 1763MiB / 3679MiB
        .oossssso-````/ossssss+`          GPU      : Intel UHD 620
       -osssssso.      :ssssssso. 
      :osssssss/        osssso+++. 
     /ossssssss/        +ssssooo/- 
   `/ossssso+/:-        -:/+osssso+- 
  `+sso+:-`                 `.-/+oso: 
 `++:.                           `-/+/
 .`                                 `/ 
 
 ```
 
 #How to Install
 
 Run the install.sh script by:
 
 ```bash
 ./install.sh
 ```
 
 #📁 Configuration
 
 Config file at:
```bash
 ~/.config/corefetch/ascii
```

## Currently, CoreFetch supports ASCII customization.

    Future plans include a config file at ~/.config/corefetch/config to toggle:

    Colors

    Field order

    Minimal mode

    Preset logos per distro


#🧠 Planned Features

    --no-color flag

    Auto-pick ASCII based on distro

    Support for multiple themes

    User-defined order of info rows

#📜 License

This project is open-source and free to use under the MIT License.
🛠️ Built With

    💻 C++

    🧠 Standard Linux system files: /proc, /etc/os-release

    🐧 Compatible with any Linux distribution
    
    
#📄 License

 MIT License
 
#💬 Contributing

Pull requests and feedback, welcome.
If you like it, don't forget to ⭐ star the repo!
