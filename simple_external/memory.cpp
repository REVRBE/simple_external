#include "memory.h"
#include <cstring>
#include <iostream>
#include <psapi.h>

Memory mem("csgo.exe");

Memory::Memory(const char* processName) {
    this->processHandle = NULL;  // initialize processHandle to NULL

    DWORD processIds[1024], bytesReturned;
    if (!EnumProcesses(processIds, sizeof(processIds), &bytesReturned)) {
        throw std::runtime_error("Failed to enumerate processes");
    }
    const auto processCount = bytesReturned / sizeof(DWORD);
    wchar_t wideProcessName[MAX_PATH];
    MultiByteToWideChar(CP_UTF8, 0, processName, -1, wideProcessName, MAX_PATH);
    bool found = false;
    for (size_t i = 0; i < processCount; i++) {
        HANDLE processHandle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, processIds[i]);        if (processHandle != NULL) {
            HMODULE hMod;
            DWORD cbNeeded;
            TCHAR name[MAX_PATH];
            if (EnumProcessModules(processHandle, &hMod, sizeof(hMod), &cbNeeded)) {
                if (GetModuleBaseName(processHandle, hMod, name, sizeof(name) / sizeof(TCHAR))) {
                    wchar_t wideName[MAX_PATH];
                    MultiByteToWideChar(CP_UTF8, 0, name, -1, wideName, MAX_PATH);
                    if (wcscmp(wideName, wideProcessName) == 0) {
                        this->processHandle = processHandle;
                        this->processId = processIds[i];
                        found = true;
                        break;
                    }
                }
            }
            CloseHandle(processHandle);
        }
    }
    if (!found) {
        throw std::runtime_error("Process not found");
    }
    this->protectFlag = PAGE_EXECUTE_READWRITE;
    VirtualProtectEx(this->processHandle, reinterpret_cast<LPVOID>(0x400000), 0x1000000, this->protectFlag, &this->protectFlag);
}


Memory::~Memory() {
    if (this->processHandle) {
        CloseHandle(this->processHandle);
    }
}

uintptr_t Memory::GetModuleAddress(const char* moduleName) const {
    uintptr_t moduleBase = 0;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, this->processId);
    if (snapshot != INVALID_HANDLE_VALUE) {
        MODULEENTRY32 moduleEntry;
        moduleEntry.dwSize = sizeof(moduleEntry);
        if (Module32First(snapshot, &moduleEntry)) {
            do {
                if (_stricmp(moduleEntry.szModule, moduleName) == 0) {
                    moduleBase = (uintptr_t)moduleEntry.modBaseAddr;
                    break;
                }
            } while (Module32Next(snapshot, &moduleEntry));
        }
        CloseHandle(snapshot);
    }
    return moduleBase;
}