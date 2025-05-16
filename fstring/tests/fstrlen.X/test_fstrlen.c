/*============================================================================
* ET: embedded test;
============================================================================*/
#include "fstring.h" /* Code Under Test (CUT) */
#include "et.h" /* ET: embedded test */

void setup(void) {
    /* executed before *every* non-skipped test */
}

void teardown(void) {
    /* executed after *every* non-skipped and non-failing test */
}

/* test group --------------------------------------------------------------*/
TEST_GROUP("fstrlen") {

TEST("string = \"\\0\" test (passing)") {
	size_t result;
	result = fstrlen("\0");
	
	VERIFY(result == 0);
}

TEST("string = \"hola\" test (passing)") {
	size_t result;
	result = fstrlen("hola");
	
	VERIFY(result == 4);
}

}