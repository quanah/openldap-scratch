/*
 * Generic Regex
 */
#ifndef _AC_REGEX_H_
#define _AC_REGEX_H_

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#ifndef HAVE_REGEX_H
/*	NO POSIX REGEX!!
	you'll need to install a POSIX compatible REGEX library.
	Either Henry Spencer's or GNU regex will do.

	For NT: http://people.delphi.com/gjc/hs_regex.html
*/
#else
	/* have regex.h, assume it's POSIX compliant */
#	include <regex.h>
#endif /* regex.h */

#endif /* _AC_REGEX_H_ */
