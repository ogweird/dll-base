#include "utils/std.h"

#include <thread>

DWORD WINAPI startup(void* instance) {
	g_core->init(true);

	while (!GetAsyncKeyState(VK_END)) {
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}

	g_core->end();

	FreeLibraryAndExitThread(static_cast<HMODULE>(instance), 0);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dReason, LPVOID lpReserved) {
	DisableThreadLibraryCalls(hModule);

	if (dReason == DLL_PROCESS_ATTACH) {
		if (auto thread = CreateThread(nullptr, 0, startup, hModule, 0, nullptr)) {
			CloseHandle(thread);
		}
	}

	return TRUE;
}