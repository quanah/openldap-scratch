/* modrdn.c - ldap backend modrdn function */
/* $OpenLDAP$ */
/*
 * Copyright 1998-1999 The OpenLDAP Foundation, All Rights Reserved.
 * COPYING RESTRICTIONS APPLY, see COPYRIGHT file
 */
/* This is an altered version */
/*
 * Copyright 1999, Howard Chu, All rights reserved. <hyc@highlandsun.com>
 * 
 * Permission is granted to anyone to use this software for any purpose
 * on any computer system, and to alter it and redistribute it, subject
 * to the following restrictions:
 * 
 * 1. The author is not responsible for the consequences of use of this
 *    software, no matter how awful, even if they arise from flaws in it.
 * 
 * 2. The origin of this software must not be misrepresented, either by
 *    explicit claim or by omission.  Since few users ever read sources,
 *    credits should appear in the documentation.
 * 
 * 3. Altered versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.  Since few users
 *    ever read sources, credits should appear in the documentation.
 * 
 * 4. This notice may not be removed or altered.
 *
 *
 *
 * Copyright 2000, Pierangelo Masarati, All rights reserved. <ando@sys-net.it>
 * 
 * This software is being modified by Pierangelo Masarati.
 * The previously reported conditions apply to the modified code as well.
 * Changes in the original code are highlighted where required.
 * Credits for the original code go to the author, Howard Chu.
 */

#include "portable.h"

#include <stdio.h>

#include <ac/socket.h>
#include <ac/string.h>

#include "slap.h"
#include "back-ldap.h"

int
ldap_back_modrdn(
    Backend	*be,
    Connection	*conn,
    Operation	*op,
    const char	*dn,
    const char	*ndn,
    const char	*newrdn,
    int		deleteoldrdn,
    const char	*newSuperior
)
{
	struct ldapinfo	*li = (struct ldapinfo *) be->be_private;
	struct ldapconn *lc;

	char *mdn, *mnewSuperior;

	lc = ldap_back_getconn( li, conn, op );
	if ( !lc ) {
		return( -1 );
	}

	if (newSuperior) {
		int version = LDAP_VERSION3;
		ldap_set_option( lc->ld, LDAP_OPT_PROTOCOL_VERSION, &version);
		
		mnewSuperior = ldap_back_dn_massage( li,
			ch_strdup( newSuperior ), 0 );
		if ( mnewSuperior == NULL ) {
			return( -1 );
		}
	}

	if ( !ldap_back_dobind(lc, op) ) {
		return( -1 );
	}

	mdn = ldap_back_dn_massage( li, ch_strdup( dn ), 0 );
	if ( mdn == NULL ) {
		return( -1 );
	}

	ldap_rename2_s( lc->ld, mdn, newrdn, mnewSuperior, deleteoldrdn );

	free( mdn );
	if ( mnewSuperior ) free( mnewSuperior );
	
	return( ldap_back_op_result( lc, op ) );
}
