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
TEST_GROUP("fmemchr") {

TEST("maxn = 0 test, match on [0..3] (passing)") {
    char buf[5] = "aaaa";
	char *p;
	p = fmemchr(buf, 'a', 0);
	
	VERIFY(p == NULL);
}

TEST("maxn = 4, no matches test (passing)") {
	char buf[5] = "....";
	char *p;
	p = fmemchr(buf, 'a', 4);
	
	VERIFY(p == NULL);
}

TEST("maxn = 4, match on [1] test (passing)") {
	char buf[5] = ".a..";
	char *p;
	p = fmemchr(buf, 'a', 4);
	
	VERIFY(p == &buf[1]);
}

TEST("maxn = 3, match on [1..2] test (passing)") {
	char buf[5] = ".aa.";
	char *p;
	p = fmemchr(buf, 'a', 3);
	
	VERIFY(p == &buf[1]);
}

}