#pragma once
struct Vector2 {
	float x;
	float y;
	Vector2(float _x, float _y) {
		x = _x;
		y = _y;
	}
	Vector2() {
		x = 0;
		y = 0;
	}
	Vector2 operator+(Vector2 const& vec1) {
		Vector2 vec2;
		vec2.x = vec1.x + x;
		vec2.y = vec1.y + y;
		return vec2;
	}
	Vector2 operator-(Vector2 const& vec1) {
		Vector2 vec2;
		vec2.x = vec1.x - x;
		vec2.y = vec1.y - y;
		return vec2;
	}
};