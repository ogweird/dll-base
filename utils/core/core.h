#pragma once

#include <memory>

class c_core {
private:
	bool m_debug_mode = false;

public:
	void init(bool debug);
	void end();
	void swap_buffers();
};

inline auto g_core = std::make_unique<c_core>();