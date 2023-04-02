#pragma once
#include <Windows.h>

// Here you can define your configuration constants, such as keys or other settings.
namespace Config {
    constexpr int TRIGGER_KEY = VK_XBUTTON1; // Change this to the desired trigger key.
    constexpr int TRIGGER_DELAY_MIN = 5; // Change this to the desired trigger delay.
    constexpr int TRIGGER_DELAY_MAX = 15; // Change this to the desired trigger delay.
}
