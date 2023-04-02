# simple_external
GitHub README for CSGO Triggerbot

This project is a simple triggerbot for the popular first-person shooter game, Counter-Strike: Global Offensive (CSGO). The triggerbot is written in C++ and uses memory reading/writing to automate the shooting process when a player's crosshair is over an enemy target.
How it Works

The triggerbot scans for the user-specified trigger key to be pressed, then proceeds to read memory for the player's current state, including their local player object, crosshair ID, and the entity that the crosshair is currently pointing at. If the entity is an enemy and has not already died, the triggerbot uses the mouse_event function to simulate a mouse click, causing the player to shoot at the target.

The triggerbot also has a configurable random delay between shots to avoid detection.
Usage

To use this code, simply clone or download the repository and compile the source code using a C++ compiler. This project requires the Windows API, specifically the Windows.h and TlHelp32.h libraries.

Before running the triggerbot, make sure to configure the trigger key and delay settings in config.h file.
Code Structure
memory.h

This file contains the Memory class, which is responsible for reading and writing memory to the CSGO process. It uses the Windows API to open the process and get its handle, then allows the user to read or write any value to a specified memory address. This class also includes a method to get the process ID and another method to get the base address of a specified module in the process.
trigger.h

This file contains the Triggerbot class, which is responsible for scanning the game state and simulating mouse clicks. It uses the Memory class to read memory values and includes a method to generate a random delay between shots.
main.cpp

This file contains the main() function, which initializes the Memory object and the Triggerbot object, then loops infinitely while calling the Run() method on the Triggerbot object.
Disclaimer

This triggerbot is for educational purposes only and is not intended for use in actual gameplay. Using cheats in games violates the terms of service and can result in a ban or other penalties. Use this code at your own risk.
