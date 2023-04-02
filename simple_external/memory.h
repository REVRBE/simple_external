#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <cstdint>
#include <stdexcept>
#include <iostream>

class Memory {
public:
    Memory(const char* processName);

    ~Memory();

    uintptr_t GetModuleAddress(const char* moduleName) const;

    template <typename T>
    T Read(uintptr_t address) const {
        T buffer;
        if (!ReadProcessMemory(this->processHandle, reinterpret_cast<LPCVOID>(address), &buffer, sizeof(buffer), nullptr)) {
            throw std::runtime_error("Failed to read memory");
        }
        return buffer;
    }

    template <typename T>
    void Write(uintptr_t address, const T& value) const {
        DWORD oldProtect;
        if (!VirtualProtectEx(this->processHandle, reinterpret_cast<LPVOID>(address), sizeof(value), PAGE_EXECUTE_READWRITE, &oldProtect)) {
            throw std::runtime_error("Failed to change protection flags");
        }

        if (!WriteProcessMemory(this->processHandle, reinterpret_cast<LPVOID>(address), &value, sizeof(value), nullptr)) {
            throw std::runtime_error("Failed to write memory");
        }

        if (!VirtualProtectEx(this->processHandle, reinterpret_cast<LPVOID>(address), sizeof(value), oldProtect, &oldProtect)) {
            throw std::runtime_error("Failed to restore protection flags");
        }
    }

    DWORD GetProcessId() const {
        return this->processId;
    }

private:
    HANDLE processHandle = NULL;
    DWORD processId = 0;
    mutable DWORD protectFlag = 0;
};
extern Memory mem;
