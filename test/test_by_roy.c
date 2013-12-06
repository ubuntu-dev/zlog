/*
 * This file is part of the zlog Library.
 *
 * Copyright (C) 2011 by Hardy Simpson <HardySimpson1984@gmail.com>
 *
 * Licensed under the LGPL v2.1, see the file COPYING in base directory.
 */

#include <stdio.h>
#include "zlog.h"

#define MY_CATEGORY  "foo"

int main(int argc, char** argv)
{
	int rc;
	zlog_category_t *zc;

	rc = zlog_init("test_by_roy.conf");
	if (rc) {
		printf("init failed\n");
		return -1;
	}

	zc = zlog_get_category(MY_CATEGORY);
	if (!zc) {
		printf("get cat fail\n");
		zlog_fini();
		return -2;
	}

	zlog_info(zc, "hello, zlog");
	sleep(1);
	zlog_info(zc, "hello, zlog2");
	sleep(2);
	zlog_info(zc, "hello, zlog3");
	zlog_info(zc, "hello, zlog4");

	zlog_fini();
	
	return 0;
}

/*

[~/src/roycyt-s-zlog/test] $ make -C .. clean

[~/src/roycyt-s-zlog/test] $ make -C .. all test

[~/Sources/roycyt-s-zlog/test] $ ./test_by_roy
2013-12-06 10:21:45.326 hello, zlog
2013-12-06 10:21:46.326 hello, zlog2
2013-12-06 10:21:48.326 hello, zlog3
2013-12-06 10:21:48.326 hello, zlog4

[~/Sources/roycyt-s-zlog/test] $ cat test_by_roy.log
2013-12-06 10:21:45.326 hello, zlog
2013-12-06 10:21:46.326 hello, zlog2
2013-12-06 10:21:48.326 hello, zlog3
2013-12-06 10:21:48.326 hello, zlog4

*/

