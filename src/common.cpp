// Shared code.
// © John Peterson. License GNU GPL 3
#include "common.h"

// log

void logc(int i, int &c, int &a) {
	c = 37, a = 0;
	switch (i) {
	case 1: c = 30; a = 1; break;
	case 2: c = 36; a = 0; break;
	case 3: c = 34; a = 1; break;
	case 4: c = 35; a = 1; break;
	case 5: c = 32; a = 0; break;
	case 6: c = 33; a = 0; break;
	case 7: c = 31; a = 1; break;
	}
}

void log(int i, char* f, ...) {
	int c, a;
	logc(i, c, a);
	const int len = 0xfff;
	char buf[len];
	va_list l;
	va_start(l, f);
	vsnprintf(buf, len, f, l);
	va_end(l);
	fprintf(stderr, "\033[%d;%dm%s\033[0m\n", a, c, buf);
	fflush(stderr);
}