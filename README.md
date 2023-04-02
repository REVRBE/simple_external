# simple_external
 Triggerbot

This is a simple C++ program that demonstrates how to implement a triggerbot for the game Counter-Strike: Global Offensive (CS:GO) using the WinAPI. The program uses memory reading and mouse event generation to simulate an automated trigger finger.
Dependencies

    Windows.h
    TlHelp32.h
    cstdint
    stdexcept
    iostream
    thread
    random
    chrono

Usage

    Compile the program using your preferred C++ compiler.
    Launch CS:GO and navigate to a game.
    Run the compiled executable as administrator.
    The triggerbot will now be active and will automatically fire when an enemy is under the player's crosshair.

Implementation
trigger.h

This header file contains the implementation of the Triggerbot class, which encapsulates the logic for the triggerbot.
public

    Triggerbot(const Memory& mem): Constructor that takes a Memory object and initializes the triggerbot with it.
    int GetRandomTriggerDelay(): Generates a random number between TRIGGER_DELAY_MIN and TRIGGER_DELAY_MAX.
    void Run(): Main function that reads memory and generates mouse events to simulate an automated trigger finger.

private

    const Memory& memory: Reference to the Memory object used to read memory.

config.h

This header file contains the configuration for the triggerbot. It allows the user to change the trigger key and the delay between shots.
memory.h

This header file contains the implementation of the Memory class, which encapsulates the logic for reading and writing memory from the game process.
public

    Memory(const char* processName): Constructor that takes the name of the process to attach to and initializes the Memory object with it.
    ~Memory(): Destructor that releases the process handle.
    uintptr_t GetModuleAddress(const char* moduleName) const: Returns the base address of the specified module.
    template <typename T> T Read(uintptr_t address) const: Reads the value of type T from the specified memory address.
    template <typename T> void Write(uintptr_t address, const T& value) const: Writes the value of type T to the specified memory address.
    DWORD GetProcessId() const: Returns the process ID of the attached process.

private

    HANDLE processHandle: Handle to the attached process.
    DWORD processId: ID of the attached process.
    mutable DWORD protectFlag: Current protection flags for the memory.

main.cpp

This file contains the main function that initializes the Memory object and the Triggerbot object and runs the triggerbot indefinitely.
Disclaimer

This program is intended for educational purposes only. Use of this program in online gameplay is strictly prohibited and may result in consequences such as account bans or legal action. The author and publisher of this code assume no responsibility for any misuse or damage caused by this program.
