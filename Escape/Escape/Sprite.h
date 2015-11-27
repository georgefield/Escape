#pragma once
#include <vector>
#include <array>

typedef std::array<float, 3> triangleVerts;
typedef std::array<float, 4> squareVerts;

class Sprite
{
public:
	Sprite();
	void addTriangle(triangleVerts vertexes);
	void addSquare(squareVerts vertexes)
	void drawSprite();

	std::vector<triangleVerts> _vertexes;
};

