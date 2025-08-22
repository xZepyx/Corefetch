# Corefetch (C++ Edition)

**Corefetch** is a blazing-fast, minimal, and customizable Neofetch alternative written in C++.

> **Note:**  
> Corefetch was built as a learning project and is not meant to compete with Neofetch or Fastfetch. It’s a simple, lightweight alternative for displaying system info with ASCII art in your terminal—no dependencies required.

---

## 🚀 Preview

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

---

## ⚡ Installation

Run the install script:
```bash
chmod +x install.sh
sudo ./install.sh
```

---

## ⚙️ Configuration

Customize your ASCII art:
```bash
~/.config/corefetch/ascii
```
Just edit the file to change the displayed logo.

### Planned Configuration Options

- Colors
- Field order
- Minimal mode
- Preset logos per distro

Future config file location:  
```bash
~/.config/corefetch/config
```

---

> ![status: discontinued](https://img.shields.io/badge/status-discontinued-red)
> ![maintenance: none](https://img.shields.io/badge/maintenance-none-lightgrey)


---

## 🛠️ Tech

- Written in **C++**
- Uses standard Linux system files: `/proc`, `/etc/os-release`
- Compatible with any Linux distribution

---

## 📜 License

MIT License — free to use, modify, and share.

---

## 🤝 Contributing

Pull requests and feedback are welcome!  
If you enjoy Corefetch, please ⭐ star the repo.

---

## 🚫 Discontinued

This project is officially discontinued as of July 12, 2025.  
No further updates or bug fixes will be provided.  
Feel free to fork and build upon it—just credit the base!
