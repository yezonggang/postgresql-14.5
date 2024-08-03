/*-------------------------------------------------------------------------
 *
 * pg_test_catalog.h
 *	  definition of the "database" system catalog (pg_test_catalog)
 *
 *
 * Portions Copyright (c) 1996-2021, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/pg_test_catalog.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_TEST_CATALOG_H
#define PG_TEST_CATALOG_H

#include "catalog/genbki.h"
#include "catalog/pg_test_catalog_d.h"

/* ----------------
 *		pg_test_catalog definition.  cpp turns this into
 *		typedef struct FormData_pg_test_catalog
 * ----------------
 */
CATALOG(pg_test_catalog,6666,TestCatalogRelationId)
{
	Oid			oid;
	char        name;
	char	    sex;
} FormData_pg_test_catalog;


typedef FormData_pg_test_catalog *Form_pg_test_catalog;

DECLARE_UNIQUE_INDEX_PKEY(pg_test_catalog_oid_index, 6667, on pg_test_catalog using btree(oid oid_ops));
#define TestCatalogOidIndexId	6667

#endif							/* pg_test_catalog_H */
