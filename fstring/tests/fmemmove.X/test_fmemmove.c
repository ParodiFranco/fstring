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
TEST_GROUP("fmemmove") {

TEST("dest = src, size = 0 (passing)") {
	char destsrc[5] = "....";
	char *p = fmemmove(destsrc, destsrc, 0);
	
	VERIFY(memcmp(destsrc, "....", sizeof(destsrc)) == 0);
	VERIFY(p == destsrc);
}

TEST("dest = src, size > 0 (passing)") {
	char destsrc[5] = "....";
	char *p = fmemmove(destsrc, destsrc, 2);
	
	VERIFY(memcmp(destsrc, "....", sizeof(destsrc)) == 0);
	VERIFY(p == destsrc);
}

TEST("dest > src, size = 0 (passing)") {
	char buf[5] = "hola";
	const char offset = 2;
	char *dest = &buf[offset];
	char *src = &buf[0];
	char *p = fmemmove(dest, src, 0);
	
	VERIFY(memcmp(buf, "hola", sizeof(buf) - offset) == 0);
	VERIFY(p == dest);
}

TEST("dest > src, size > 0 (passing)") {
	char buf[5] = "hola";
	const size_t offset = 2;
	char *dest = &buf[offset];
	char *src = &buf[0];
	char *p = fmemmove(dest, src, 2);
	
	VERIFY(memcmp(buf, "hoho", sizeof(buf) - offset) == 0);
	VERIFY(p == dest);
}

TEST("dest < src, size = 0 (passing)") {
	char buf[5] = "hola";
	const size_t offset = 2;
	char *dest = &buf[0];
	char *src = &buf[offset];
	char *p = fmemmove(dest, src, 0);
	
	VERIFY(memcmp(buf, "hola", sizeof(buf) - offset) == 0);
	VERIFY(p == dest);
}

TEST("dest < src, size > 0 (passing)") {
	char buf[5] = "hola";
	const size_t offset = 2;
	char *dest = &buf[0];
	char *src = &buf[offset];
	char *p = fmemmove(dest, src, 2);
	
	VERIFY(memcmp(buf, "lala", sizeof(buf) - offset) == 0);
	VERIFY(p == dest);
}

} /* TEST_GROUP() */
