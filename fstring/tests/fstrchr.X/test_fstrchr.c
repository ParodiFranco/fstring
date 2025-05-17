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
TEST_GROUP("fstrchr") {

TEST("string = \"hola\\0\", c = 'x' test (passing)") {
	char str[5] = "hola";
	char *p = fstrchr(str, 'x');
	
	VERIFY(p == NULL);
}

TEST("string = \"hola\\0\", c = 'h' test (passing)") {
	char str[5] = "hola";
	char *p = fstrchr(str, 'h');
	
	VERIFY(p == &str[0]);
}

TEST("string = \"hola\\0\", c = 'a' test (passing)") {
	char str[5] = "hola";
	char *p = fstrchr(str, 'a');
	
	VERIFY(p == &str[3]);
}

TEST("string = \"hola\\0\", c = '\\0' test (passing)") {
	char str[5] = "hola";
	char *p = fstrchr(str, '\0');
	
	VERIFY(p == &str[4]);
}

}