# MCSoundsExtractorCPP
## Information
This is a simple utility which extracts the hashed and scattered sound files from Minecraft and dumps them wherever you want. This works for any Minecraft version newer than 1.7.2. The sound files for older Minecraft versions are located inside ``minecraft/assets`` (if 1.7.0 is the newest version installed) or ``minecraft/assets/virtual/legacy`` if you have newer versions.

This is a C++ rewrite of my Java version of this application. If for some reason this app is not working on your system, you can
use the Java one here: [https://github.com/Ravbug/MCSoundsExtractor](https://github.com/Ravbug/MCSoundsExtractor)

## How to use:
1. [Download](https://github.com/Ravbug/MCSoundsExtractorCPP/releases) the application from the releases section of this repository.
2. To open the program, double-click the executable file (.exe, .app, etc) in your file browser.
3. If Minecraft is installed in its default location, then all you have to do is choose where you want to place the sound files and choose the version of the game you want. If Minecraft is not installed in the default location, you will likely get an error message and you must direct the program to where you installed Minecraft.
4. Press Extract. The progress bar will fill up and when complete, you will get a dialog stating the export finished successfully.
5. Once the program completes, go to the folder you picked as the output folder. Inside it you will find a folder named ``minecraft``, with subfolder ``sounds``, with multiple subdirectories. Inside these are .ogg audio files. If you cannot open .ogg audio. I recommend the [MediaHuman Audio converter](https://www.mediahuman.com/audio-converter/) which can convert them into .wav, .mp3, .acc, among others.

## Compiling it yourself
Clone the repository as a zip, extract it, and then follow the steps for your OS below.
### macOS
1. Open `mac.xcodeproj` in Xcode.
2. Select `Minecraft Sounds Extractor` from the target selector.
3. Press Build (cmd + b). Everything will compile in one step. 

### Windows
1. Open `wxWidgets\build\msw\` and find the SLN that most closely matches your Visual Studio version. For example, open `wx_vc15.sln` if you are using Visual Studio 2015 or later.
2. Select the configuration you want to build (example: `Debug x86`), and press `Build -> Build Solution` (ctrl + shift + B). 
3. Repeat step 2 for each configuration you want to use. I recommend compiling Debug and Release for x64 at the very least.
   - Alternatively, to build all the possible configurations, go to Build → Batch Build, Select All, and press Build, 
4. In the repository root folder, open `windows.sln` in the template root, select your configuration, and build.

### Linux
1. Ensure you have the required dependencies. If you do not have them, the setup will fail (but it will tell you which one you are missing). Commonly missing packages:
   - autoconf
   - g++
   - gtk3 dev
   - make
   - If you install a library but the setup still fails, try installing the development version of the package. 
2. Open a shell window in the template folder root. 
3. Run `make run`. This will compile the library, the app, and launch it. The object files and the executable will be located inside `linux-build/` which is created when you compile for the first time. The library files will be located inside `wxWidgets/build/linux`.

**To make release builds, refer to this page:** [https://github.com/Ravbug/wxWidgetsTemplate/wiki/Creating-Release-Builds](https://github.com/Ravbug/wxWidgetsTemplate/wiki/Creating-Release-Builds)

## Issue reporting
Use the issues section on this repository to report bugs. Include as many details as you can.
