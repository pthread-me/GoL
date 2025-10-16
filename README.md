# Game Of Life

### Dependencies
| Requires | Version | Note |
| :------: | :-----: | :--: |
| SFML | v3.0.2 | [link](https://www.sfml-dev.org/download/ "Link to the SFML website")
| Cpp | c++23 | - |
| CMake | v4.0 | Modifying CMakeLists.txt to your cmake version should work fine |

### Usage

| Command | Action |
| :-----: | :----: |
|left mouse click | toggle select/deselect cells |
| Enter | start simulation | 
| q | pause (only while simulation is running)|
| r | reset board |
| Esc | Close program (q fisrt if still running)|

### Todo

| Issue | Note |
| :---: | :--: |
| Fix window resizing | i3 window resizing "stretches" pixels which break the program |
| add drag | not the art, but the ability to select mutiple cells at a time |
| allow circular "shift"/loopback | modulo on cell position basically |
| last cell in col display | last if window size is not divisible by cell size (pixels) the first cell extend to the last column from the right, or smt |
