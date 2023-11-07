<br><div>
    <img src="https://img.shields.io/badge/Language%20-C-black.svg" style="max-width: 100%;">
    <img src="https://img.shields.io/badge/Tools%20-Windows API-green.svg" style="max-width: 100%;">
    <img src="https://img.shields.io/badge/Target OS%20-Windows 7..11-blue.svg" style="max-width: 100%;">
    <img src="https://img.shields.io/badge/Project%20-Malware | Process Injection-red.svg" style="max-width: 100%;">
    <img src="https://img.shields.io/badge/Hacking tool | Cybersecurity Awareness%20-teste?style=flat-square style="max-width: 100%;">
</div>


# Simple Windows malware | Process injection

Simple payload for hacking Windows and process injection. Using the windows API for the C programming language. 

* **Windows API:** https://learn.microsoft.com/pt-br/windows/win32/apiindex/windows-api-list

### **Process injection**

![ezgif com-video-to-gif](https://github.com/Jsmoreira02/Wind0wsM4lware_/assets/103542430/60f51a38-4e3a-421b-9dcc-2eb4187484cf)


Process injection is an evasive attack method that hackers use to gain access to the system by executing their malicious code in the address space of a legitimate process, hiding the malware and often not generating any suspicion about an attacker on the system, as the malicious code becomes difficult to detect. Process injections also evade detection by any antivirus, application control, or endpoint detection and response systems running on the network because the infected processes are viewed as legitimate. 

Hackers usually use less suspicious or more important system processes such as: svchost.exe, rundll32.exe or even explorer.exe.

* **Explorer_injection.exe:** Performs a shell connection on the reverse target computer at the execution address of the explorer.exe process. 

#

* **How to find the PID of a running windows process:**

```bash
  tasklist | findstr <process name>
```

=> CMD syntax: `Process_injection.exe <PID>`

# Compiling

* **Compiling the code (Linux):** 
```bash 
x86_64-w64-mingw32-gcc code.c -o code -static-libgcc
```
* **Compiling the code (Windows):**
```bash
gcc code.c -o code
```

# MinGW-w64 Instalation:

**Debian/Ubuntu OS:** 
```bash 
sudo apt install mingw-w64-x86-64 (64-bits)
or
sudo apt install mingw-w64 (32-bits)
```

**Fedora**:
```bash 
sudo dnf install mingw64-gcc
```

**Arch Linux**:
```bash 
sudo pacman -S mingw-w64-gcc
```

=> More Info: https://www.mingw-w64.org/
