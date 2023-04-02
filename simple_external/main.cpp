#include "memory.h"
#include "trigger.h"

int main() {
	Memory mem("csgo.exe");

	std::cout << "Process ID: " << mem.GetProcessId() << std::endl;

	const auto client = mem.GetModuleAddress("client.dll");
	std::cout << "client.dll -> " << "0x" << std::hex << client << std::dec << std::endl;

	const auto engine = mem.GetModuleAddress("engine.dll");
	std::cout << "engine.dll -> " << "0x" << std::hex << engine << std::dec << std::endl;

	Triggerbot triggerbot(mem);

	while (true) {
		Sleep(10);
		triggerbot.Run();
	}
}