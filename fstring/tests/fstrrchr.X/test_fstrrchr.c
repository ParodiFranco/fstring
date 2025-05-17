/*============================================================================
* ET: embedded test;
============================================================================*/
#include "fstring.h" /* Code Under Test (CUT) */
#include "et.h" /* ET: embedded test */

#include <stddef.h> /* NULL */

void setup(void) {
    /* executed before *every* non-skipped test */
}

void teardown(void) {
    /* executed after *every* non-skipped and non-failing test */
}

/* test group --------------------------------------------------------------*/
TEST_GROUP("fstrrchr") {

TEST("string = \"balsa\\0\", c = 'x' test (passing)") {
	char str[6] = "balsa";
	char *p = fstrrchr(str, 'x');
	
	VERIFY(p == NULL);
}

TEST("string = \"balsa\\0\", c = 'b' test (passing)") {
	char str[6] = "balsa";
	char *p = fstrrchr(str, 'b');
	
	VERIFY(p == &str[0]);
}

TEST("string = \"balsa\\0\", c = 's' test (passing)") {
	char str[6] = "balsa";
	char *p = fstrrchr(str, 's');
	
	VERIFY(p == &str[3]);
}

TEST("string = \"balsa\\0\", c = 'a' test (passing)") {
	char str[6] = "balsa";
	char *p = fstrrchr(str, 'a');
	
	VERIFY(p == &str[4]);
}

TEST("string = \"balsa\\0\", c = '\\0' test (passing)") {
	char str[6] = "balsa";
	char *p = fstrrchr(str, '\0');
	
	VERIFY(p == &str[5]);
}

}