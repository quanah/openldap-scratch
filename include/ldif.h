/*
 * Copyright (c) 1996 Regents of the University of Michigan.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of Michigan at Ann Arbor. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 */

#ifndef _LDIF_H
#define _LDIF_H

#include <ldap_cdefs.h>

LDAP_BEGIN_DECL

#define LINE_WIDTH      76      /* maximum length of LDIF lines */

/*
 * Macro to calculate maximum number of bytes that the base64 equivalent
 * of an item that is "vlen" bytes long will take up.  Base64 encoding
 * uses one byte for every six bits in the value plus up to two pad bytes.
 */
#define LDIF_BASE64_LEN(vlen)	(((vlen) * 4 / 3 ) + 3)

/*
 * Macro to calculate maximum size that an LDIF-encoded type (length
 * tlen) and value (length vlen) will take up:  room for type + ":: " +
 * first newline + base64 value + continued lines.  Each continued line
 * needs room for a newline and a leading space character.
 */
#define LDIF_SIZE_NEEDED(tlen,vlen) \
    ((tlen) + 4 + LDIF_BASE64_LEN(vlen) \
    + ((LDIF_BASE64_LEN(vlen) + (tlen) + 3) / LINE_WIDTH * 2 ))

int str_parse_line LDAP_P(( char *line, char **type, char **value, int *vlen));
char * str_getline LDAP_P(( char **next ));
void put_type_and_value LDAP_P(( char **out, char *t, char *val, int vlen ));
char *ldif_type_and_value LDAP_P(( char *type, char *val, int vlen ));

LDAP_END_DECL

#endif /* _LDIF_H */
