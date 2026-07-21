#include "console.h"

#include <Windows.h>

void c_console::init(const std::string& title) {
	AllocConsole();

	FILE* fp;

	freopen_s(&fp, "CONIN$", "r", stdin);
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONOUT$", "w", stderr);

	SetConsoleTitleA(title.c_str());
}

void c_console::end() {
	fclose(static_cast<_iobuf*>(__acrt_iob_func(0)));
	fclose(static_cast<_iobuf*>(__acrt_iob_func(1)));
	fclose(static_cast<_iobuf*>(__acrt_iob_func(2)));

	FreeConsole();
}