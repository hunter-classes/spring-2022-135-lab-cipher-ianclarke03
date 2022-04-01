#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "coord3d.h"


// add your tests here
TEST_CASE("FixLength Function"){
    Coord3D p = {10, 20, 30};
	CHECK(fixLength(length(&p), 3) == 37.416);
	p = {0,0,0};

	CHECK(fixLength(length(&p), 3) == 0.000);
	p = {20, 50, 100};
}
TEST_CASE("Farther From Origin"){
	Coord3D p = {10, 20, 30};
	Coord3D o = {20, 50, 100};
	CHECK(fartherFromOrigin(&p, &o) == &o);
}
TEST_CASE("Check Move Function"){
	Coord3D pos = {49, 18, 20};
	Coord3D vel = {1,1,1};
	move(&pos, &vel, 23);
	CHECK(pos.x == 72);
	CHECK(pos.y == 41);
	CHECK(pos.z == 43);
}
TEST_CASE("Check createCoord3D"){
	Coord3D *temp1 = createCoord3D(10, 20, 30);
	CHECK(temp1->x == 10);
	CHECK(temp1->y == 20);
	CHECK(temp1->z == 30);
}