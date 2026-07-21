#pragma once

#include <cassert>
#include <cmath>

struct vec2 {
	float x{};
	float y{};

	constexpr vec2() : x(0), y(0) {}
	explicit constexpr vec2(float s) : x(s), y(s) {}
	constexpr vec2(float _x, float _y) : x(_x), y(_y) {}

	constexpr vec2 operator+(const vec2& vec) const { return vec2(x + vec.x, y + vec.y); }
	constexpr vec2 operator+(float s) const { return vec2(x + s, y + s); }
	friend constexpr vec2 operator+(float s, const vec2& vec) { return vec + s; }

	constexpr vec2 operator-(const vec2& vec) const { return vec2(x - vec.x, y - vec.y); }
	constexpr vec2 operator-(float s) const { return vec2(x - s, y - s); }
	friend constexpr vec2 operator-(float s, const vec2& vec) { return vec2(s - vec.x, s - vec.y); }
	constexpr vec2 operator-() const { return vec2(-x, -y); }

	constexpr vec2 operator*(const vec2& vec) const { return vec2(x * vec.x, y * vec.y); }
	constexpr vec2 operator*(float s) const { return vec2(x * s, y * s); }
	friend constexpr vec2 operator*(float s, const vec2& vec) { return vec * s; }

	constexpr vec2 operator/(const vec2& vec) const { assert(vec.x != 0.f); assert(vec.y != 0.f); return vec2(x / vec.x, y / vec.y); }
	constexpr vec2 operator/(float s) const { assert(s != 0.f); return vec2(x / s, y / s); }
	friend constexpr vec2 operator/(float s, const vec2& vec) { assert(vec.x != 0.f); assert(vec.y != 0.f); vec2(s / vec.x, s / vec.y); }

	constexpr vec2& operator+=(const vec2& vec) { x += vec.x; y += vec.y; return *this; }
	constexpr vec2& operator+=(float s) { x += s; y += s; return *this; }

	constexpr vec2& operator-=(const vec2& vec) { x -= vec.x; y -= vec.y; return *this; }
	constexpr vec2& operator-=(float s) { x -= s; y -= s; return *this; }

	constexpr vec2& operator*=(const vec2& vec) { x *= vec.x; y *= vec.y; return *this; }
	constexpr vec2& operator*=(float s) { x *= s; y *= s; return *this; }

	constexpr vec2& operator/=(const vec2& vec) { assert(vec.x != 0.f); assert(vec.y != 0.f); x /= vec.x; y /= vec.y; return *this; }
	constexpr vec2& operator/=(float s) { assert(s != 0.f); x /= s; y /= s; return *this; }

	constexpr bool operator==(const vec2& vec) const { return x == vec.x && y == vec.y; }
	constexpr bool operator!=(const vec2& vec) const { return x != vec.x || y != vec.y; }

	inline float& operator[] (size_t i) { assert(i < 2); return (&x)[i]; }
	inline float operator[] (size_t i) const { assert(i < 2); return (&x)[i]; }

	float length() const {
		return std::sqrt(x * x + y * y);
	}

	float length_squared() const {
		return x * x + y * y;
	}

	float dot(const vec2& vec) const {
		return x * vec.x + y * vec.y;
	}

	vec2 normalized() const {
		float len = length();

		if (len == 0.f) {
			return vec2();
		}

		return *this / len;
	}

	float distance(const vec2& vec) const {
		return (*this - vec).length();
	}
};

struct vec3 {
	float x{};
	float y{};
	float z{};

	constexpr vec3() : x(0), y(0), z(0) {}
	explicit constexpr vec3(float s) : x(s), y(s), z(s) {}
	constexpr vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	constexpr vec3(const vec2& vec, float _z = 0.f) : x(vec.x), y(vec.y), z(_z) {}

	constexpr vec3 operator+(const vec3& vec) const { return vec3(x + vec.x, y + vec.y, z + vec.z); }
	constexpr vec3 operator+(float s) const { return vec3(x + s, y + s, z + s); }
	friend constexpr vec3 operator+(float s, const vec3& vec) { return vec + s; }

	constexpr vec3 operator-(const vec3& vec) const { return vec3(x - vec.x, y - vec.y, z - vec.z); }
	constexpr vec3 operator-(float s) const { return vec3(x - s, y - s, z - s); }
	friend constexpr vec3 operator-(float s, const vec3& vec) { return vec3(s - vec.x, s - vec.y, s - vec.z); }
	constexpr vec3 operator-() const { return vec3(-x, -y, -z); }

	constexpr vec3 operator*(const vec3& vec) const { return vec3(x * vec.x, y * vec.y, z * vec.z); }
	constexpr vec3 operator*(float s) const { return vec3(x * s, y * s, z * s); }
	friend constexpr vec3 operator*(float s, const vec3& vec) { return vec * s; }

	constexpr vec3 operator/(const vec3& vec) const { assert(vec.x != 0.f); assert(vec.y != 0.f); assert(vec.z != 0.f); return vec3(x / vec.x, y / vec.y, z / vec.z); }
	constexpr vec3 operator/(float s) const { assert(s != 0.f); return vec3(x / s, y / s, z / s); }
	friend constexpr vec3 operator/(float s, const vec3& vec) { assert(vec.x != 0.f); assert(vec.y != 0.f); assert(vec.z != 0.f); vec3(s / vec.x, s / vec.y, s / vec.z); }

	constexpr vec3& operator+=(const vec3& vec) { x += vec.x; y += vec.y; z += vec.z; return *this; }
	constexpr vec3& operator+=(float s) { x += s; y += s; z += s; return *this; }

	constexpr vec3& operator-=(const vec3& vec) { x -= vec.x; y -= vec.y; z -= vec.z; return *this; }
	constexpr vec3& operator-=(float s) { x -= s; y -= s; z -= s; return *this; }

	constexpr vec3& operator*=(const vec3& vec) { x *= vec.x; y *= vec.y; z *= vec.z; return *this; }
	constexpr vec3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }

	constexpr vec3& operator/=(const vec3& vec) { assert(vec.x != 0.f); assert(vec.y != 0.f); assert(vec.z != 0.f); x /= vec.x; y /= vec.y; z /= vec.z; return *this; }
	constexpr vec3& operator/=(float s) { assert(s != 0.f); x /= s; y /= s; z /= s; return *this; }

	constexpr bool operator==(const vec3& vec) const { return x == vec.x && y == vec.y && z == vec.z; }
	constexpr bool operator!=(const vec3& vec) const { return x != vec.x || y != vec.y || z != vec.z; }

	inline float& operator[] (size_t i) { assert(i < 3); return (&x)[i]; }
	inline float operator[] (size_t i) const { assert(i < 3); return (&x)[i]; }

	constexpr vec2 to_2d() const {
		return vec2(x, y);
	}

	float length() const {
		return std::sqrt(x * x + y * y + z * z);
	}

	float length_squared() const {
		return x * x + y * y + z * z;
	}

	float length_2d() const {
		return std::sqrt(x * x + y * y);
	}

	float length_2d_squared() const {
		return x * x + y * y;
	}	

	float dot(const vec3& vec) const {
		return x * vec.x + y * vec.y + z * vec.z;
	}

	vec3 normalized() const {
		float len = length();

		if (len == 0.f) {
			return vec3();
		}

		return *this / len;
	}

	float distance(const vec3& vec) const {
		return (*this - vec).length();
	}

	float distance_squared(const vec3& vec) const {
		return (*this - vec).length_squared();
	}

	float distance_2d(const vec3& vec) const {
		return (*this - vec).length_2d();
	}

	float distance_2d_squared(const vec3& vec) const {
		return (*this - vec).length_2d_squared();
	}

	vec3 cross(const vec3& vec) const {
		return vec3(
			y * vec.z - z * vec.y,
			z * vec.x - x * vec.z,
			x * vec.y - y * vec.x
		);
	}
};

struct vec4 {
	float x{};
	float y{};
	float z{};
	float w{};

	constexpr vec4() : x(0), y(0), z(0), w(0) {}
	explicit constexpr vec4(float s) : x(s), y(s), z(s), w(s) {}
	constexpr vec4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}
	constexpr vec4(const vec2& vec, float _z = 0.f, float _w = 0.f) : x(vec.x), y(vec.y), z(_z), w(_w) {}
	constexpr vec4(const vec3& vec, float _w = 0.f) : x(vec.x), y(vec.y), z(vec.z), w(_w) {}

	constexpr vec4 operator+(const vec4& vec) const { return vec4(x + vec.x, y + vec.y, z + vec.z, w + vec.w); }
	constexpr vec4 operator+(float s) const { return vec4(x + s, y + s, z + s, w + s); }
	friend constexpr vec4 operator+(float s, const vec4& vec) { return vec + s; }

	constexpr vec4 operator-(const vec4& vec) const { return vec4(x - vec.x, y - vec.y, z - vec.z, w - vec.w); }
	constexpr vec4 operator-(float s) const { return vec4(x - s, y - s, z - s, w - s); }
	friend constexpr vec4 operator-(float s, const vec4& vec) { return vec4(s - vec.x, s - vec.y, s - vec.z, s - vec.w); }
	constexpr vec4 operator-() const { return vec4(-x, -y, -z, -w); }

	constexpr vec4 operator*(const vec4& vec) const { return vec4(x * vec.x, y * vec.y, z * vec.z, w * vec.w); }
	constexpr vec4 operator*(float s) const { return vec4(x * s, y * s, z * s, w * s); }
	friend constexpr vec4 operator*(float s, const vec4& vec) { return vec * s; }

	constexpr vec4 operator/(const vec4& vec) const { assert(vec.x != 0.f); assert(vec.y != 0.f); assert(vec.z != 0.f); assert(vec.w != 0.f); return vec4(x / vec.x, y / vec.y, z / vec.z, w / vec.w); }
	constexpr vec4 operator/(float s) const { assert(s != 0.f); return vec4(x / s, y / s, z / s, w / s); }
	friend constexpr vec4 operator/(float s, const vec4& vec) { assert(vec.x != 0.f); assert(vec.y != 0.f); assert(vec.z != 0.f); assert(vec.w != 0.f); return vec4(s / vec.x, s / vec.y, s / vec.z, s / vec.w); }

	constexpr vec4& operator+=(const vec4& vec) { x += vec.x; y += vec.y; z += vec.z; w += vec.w; return *this; }
	constexpr vec4& operator+=(float s) { x += s; y += s; z += s; w += s; return *this; }

	constexpr vec4& operator-=(const vec4& vec) { x -= vec.x; y -= vec.y; z -= vec.z; w -= vec.w; return *this; }
	constexpr vec4& operator-=(float s) { x -= s; y -= s; z -= s; w -= s; return *this; }

	constexpr vec4& operator*=(const vec4& vec) { x *= vec.x; y *= vec.y; z *= vec.z; w *= vec.w; return *this; }
	constexpr vec4& operator*=(float s) { x *= s; y *= s; z *= s; w *= s; return *this; }

	constexpr vec4& operator/=(const vec4& vec) { assert(vec.x != 0.f); assert(vec.y != 0.f); assert(vec.z != 0.f); assert(vec.w != 0.f); x /= vec.x; y /= vec.y; z /= vec.z; w /= vec.w; return *this; }
	constexpr vec4& operator/=(float s) { assert(s != 0.f); x /= s; y /= s; z /= s; w /= s; return *this; }

	constexpr bool operator==(const vec4& vec) const { return x == vec.x && y == vec.y && z == vec.z && w == vec.w; }
	constexpr bool operator!=(const vec4& vec) const { return x != vec.x || y != vec.y || z != vec.z || w != vec.w; }

	inline float& operator[] (size_t i) { assert(i < 4); return (&x)[i]; }
	inline float operator[] (size_t i) const { assert(i < 4); return (&x)[i]; }

	constexpr vec2 to_2d() const {
		return vec2(x, y);
	}

	constexpr vec3 to_3d() const {
		return vec3(x, y, z);
	}

	float length() const {
		return std::sqrt(x * x + y * y + z * z + w * w);
	}

	float length_squared() const {
		return x * x + y * y + z * z + w * w;
	}

	float length_3d() const {
		return std::sqrt(x * x + y * y + z * z);
	}

	float length_3d_squared() const {
		return x * x + y * y + z * z;
	}

	float length_2d() const {
		return std::sqrt(x * x + y * y);
	}

	float length_2d_squared() const {
		return x * x + y * y;
	}

	float dot(const vec4& vec) const {
		return x * vec.x + y * vec.y + z * vec.z + w * vec.w;
	}

	vec4 normalized() const {
		float len = length();

		if (len == 0.f) {
			return vec4();
		}

		return *this / len;
	}

	float distance(const vec4& vec) const {
		return (*this - vec).length();
	}

	float distance_squared(const vec4& vec) const {
		return (*this - vec).length_squared();
	}

	float distance_3d(const vec4& vec) const {
		return (*this - vec).length_3d();
	}

	float distance_3d_squared(const vec4& vec) const {
		return (*this - vec).length_3d_squared();
	}

	float distance_2d(const vec4& vec) const {
		return (*this - vec).length_2d();
	}

	float distance_2d_squared(const vec4& vec) const {
		return (*this - vec).length_2d_squared();
	}
};