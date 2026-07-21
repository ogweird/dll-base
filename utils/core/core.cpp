#include "core.h"

#include "../console/console.h"

void c_core::init(bool debug) {
	if (debug) {
		m_debug_mode = true;
	
		g_console->init("Hack CMD");

		g_console->print("LIFE HACK BITCH");
	}
}

void c_core::end() {
	if (m_debug_mode) {
		g_console->end();
	}
}

void c_core::swap_buffers() {

}
