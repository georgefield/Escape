#include "Sprite.h"



Sprite::Sprite(){

	std::fill(_vertexes.begin, _vertexes.end, NULL);
}


void Sprite::addTriangle(triangleVerts vertexes) {

	_vertexes.push_back(vertexes);
}


void Sprite::addSquare(squareVerts vertexes) {

	triangleVerts tmpTriVert1 = { vertexes[0], vertexes[1], vertexes[2] };
	addTriangle(tmpTriVert1);

	triangleVerts tmpTriVert2 = { vertexes[1], vertexes[2], vertexes[3] };
	addTriangle(tmpTriVert2);
}


void Sprite::drawSprite() {


}
