#pragma once
#include "memory.h"
#include "offsets.h"
#include "config.h"
#include <thread>
#include <random>

class Triggerbot {
public:
    Triggerbot(const Memory& mem)
        : memory(mem) {
    }

    int GetRandomTriggerDelay() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(Config::TRIGGER_DELAY_MIN, Config::TRIGGER_DELAY_MAX);
        return distr(gen);
    }

    void Run() {
        if (!(GetAsyncKeyState(Config::TRIGGER_KEY) & 0x8000)) {
            return;
        }

        uintptr_t clientBase = mem.GetModuleAddress("client.dll");
        uintptr_t localPlayer = mem.Read<uintptr_t>(clientBase + offsets::signatures::dwLocalPlayer);
        int localPlayerTeam = mem.Read<int>(localPlayer + offsets::netvars::m_iTeamNum);
        uintptr_t crosshairId = mem.Read<uintptr_t>(localPlayer + offsets::netvars::m_iCrosshairId);
        uintptr_t target = mem.Read<uintptr_t>(clientBase + offsets::signatures::dwEntityList + (crosshairId - 1) * 0x10);

        if (!target) {
            return;
        }

        int targetHealth = mem.Read<int>(target + offsets::netvars::m_iHealth);
        int targetTeam = mem.Read<int>(target + offsets::netvars::m_iTeamNum);

        if (targetHealth <= 0 || targetTeam == localPlayerTeam) {
            return;
        }

        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        std::this_thread::sleep_for(std::chrono::milliseconds(GetRandomTriggerDelay()));
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
    }

private:
    const Memory& memory;
};
