#pragma once

#include <string>
#include <memory>
#include <iostream>

class c_console {
public:
	void init(const std::string& title);

	template <typename msg>
	void print(msg message) {
		std::cout << message << std::endl;
	}

	void end();
};

inline auto g_console = std::make_unique<c_console>();