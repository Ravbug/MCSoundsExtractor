# MCSoundsExtractorCPP
## Information
This is a simple utility which extracts the hashed and scattered sound files from Minecraft and dumps them wherever you want. This works for any Minecraft version newer than 1.7.2. The sound files for older Minecraft versions are located inside ``minecraft/assets`` (if 1.7.0 is the newest version installed) or ``minecraft/assets/virtual/legacy`` if you have newer versions.

This is a C++ rewrite of my Java version of this application. If for some reason this app is not working on your system, you can
use the legacy (unmaintained) Java version here: [https://github.com/Ravbug/MCSoundsExtractor](https://github.com/Ravbug/MCSoundsExtractor)

![Screenshot](https://i.imgur.com/qInTOb4.png)

## How to use:
1. [Download](https://github.com/Ravbug/MCSoundsExtractorCPP/releases) the application from the releases section of this repository.
2. To open the program, double-click the executable file (.exe, .app, etc) in your file browser.
3. If Minecraft is installed in its default location, then all you have to do is choose where you want to place the sound files and choose the version of the game you want. If Minecraft is not installed in the default location, you will likely get an error message and you must direct the program to where you installed Minecraft.
4. Press Extract. The progress bar will fill up and when complete, you will get a dialog stating the export finished successfully.
5. Once the program completes, go to the folder you picked as the output folder. Inside it you will find a folder named ``minecraft``, with subfolder ``sounds``, with multiple subdirectories. Inside these are .ogg audio files. If you cannot open .ogg audio, I recommend the [MediaHuman Audio converter](https://www.mediahuman.com/audio-converter/) which can batch-convert them into .wav, .mp3, .acc, among others.

## Compiling it yourself
Clone the repository as a zip, extract it, then use CMake:
```sh
mkdir -p build && cd build
cmake ..
cmake --build . --config Release --target install
```
Note for Linux users: You need a C++ compiler and the gtk3-dev package for your system.


**To make release builds, refer to this page:** [https://github.com/Ravbug/wxWidgetsTemplate/wiki/Creating-Release-Builds](https://github.com/Ravbug/wxWidgetsTemplate/wiki/Creating-Release-Builds)

## Issue reporting
Use the issues section on this repository to report bugs. Include as many details as you can.
