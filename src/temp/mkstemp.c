#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include "libc.h"

char *__mktemp(char *);

int mkstemp(char *template)
{
	int fd;
	for (;;) {
		if (!__mktemp(template)) return 0;
		if ((fd = open(template, O_RDWR | O_CREAT | O_EXCL, 0600))>=0)
			return fd;
		if (errno != EEXIST) return -1;
		/* this is safe because mktemp verified
		 * that we have a valid template string */
		strcpy(template+strlen(template)-6, "XXXXXX");
	}
}

LFS64(mkstemp);
