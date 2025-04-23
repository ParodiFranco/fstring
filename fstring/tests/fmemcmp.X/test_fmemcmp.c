/*============================================================================
* ET: embedded test;
============================================================================*/
#include "fstring.h" /* Code Under Test (CUT) */
#include "et.h" /* ET: embedded test */

#include <string.h> /* memcmp */

void setup(void) {
    /* executed before *every* non-skipped test */
}

void teardown(void) {
    /* executed after *every* non-skipped and non-failing test */
}

/* test group --------------------------------------------------------------*/
TEST_GROUP("fmemcmp") {

TEST("Different data, size = 0 test (passing)") {
	int dif = fmemcmp("hola", "wwww", 0);
	
	VERIFY(dif == 0);
}

TEST("Different data, size = 2 test (passing)") {
	int dif = fmemcmp("hola", "hwww", 2);
	
	VERIFY(dif == 'o' - 'w');
}

TEST("Different data, size = 3 test (passing)") {
	int dif = fmemcmp("hola", "hwww", 3);
	
	VERIFY(dif == 'o' - 'w');
}

TEST("Same data, size = 0 test (passing)") {
	int dif = fmemcmp("hola", "hola", 0);
	
	VERIFY(dif == 0);
}

TEST("Same data, size = 2 test (passing)") {
	int dif = fmemcmp("hola", "hola", 2);
	
	VERIFY(dif == 0);
}

}