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
TEST_GROUP("fmemcpy") {

TEST("Size = 0 test (passing)") {
    char buf[5] = "....";
	char *p = fmemcpy(buf, "hola", 0);
	
	VERIFY(memcmp(buf, "....", sizeof(buf)) == 0);
	VERIFY(p == buf);
}

TEST("Size = 2 test (passing)") {
	char buf[5] = "....";
	char *p = fmemcpy(buf, "hola", 2);
	
	VERIFY(memcmp(buf, "ho..", sizeof(buf)) == 0);
	VERIFY(p == buf);
}

}