/* LDAP C Defines */

#ifndef _LDAP_CDEFS_H
#define _LDAP_CDEFS_H

#if defined(__cplusplus)
#	define LDAP_BEGIN_DECL	extern "C" {
#	define LDAP_END_DECL	}
#else
#	define LDAP_BEGIN_DECL
#	define LDAP_END_DECL	
#endif

#if defined(__STDC__) || defined(__cplusplus)
	/* ANSI C or C++ */
#	define LDAP_P(protos)	protos
#	define LDAP_CONCAT1(x,y)	x ## y
#	define LDAP_CONCAT(x,y)	LDAP_CONCAT1(x,y)
#	define LDAP_STRING(x)	#x /* stringify without expanding x */
#	define LDAP_XSTRING(x)	LDAP_STRING(x) /* expand x, then stringify */
#else /* ! __STDC__ && ! __cplusplus */
	/* traditional C */
#	define LDAP_P(protos)	()
#	define LDAP_CONCAT(x,y)	x/**/y
#	define LDAP_STRING(x)	"x"
#endif /* __STDC__ || __cplusplus */

#ifndef LDAP_F
#	ifdef _WIN32
#		define LDAP_F	__declspec( dllexport )
#	else /* ! _WIN32 */
#		define LDAP_F	extern
#	endif /* _WIN32 */
#endif /* LDAP_FDECL */

#endif /* _LDAP_CDEFS_H */
