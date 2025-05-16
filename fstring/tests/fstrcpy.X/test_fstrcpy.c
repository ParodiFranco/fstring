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
TEST_GROUP("fstrcpy") {

TEST("string = \"\\0\" test (passing)") {
    char buf[5] = "....";
	char *p = fstrcpy(buf, "\0");
	
	VERIFY(memcmp(buf, "\0...", sizeof(buf)) == 0);
	VERIFY(p == buf);
}

TEST("string = \"ho\\0\" test (passing)") {
	char buf[5] = "....";
	char *p = fstrcpy(buf, "ho");
	
	VERIFY(memcmp(buf, "ho\0.", sizeof(buf)) == 0);
	VERIFY(p == buf);
}

}