/*
$Id: result_sort.h,v 1.19 2003/07/25 06:36:30 whmoseley Exp $
**
** This program and library is free software; you can redistribute it and/or
** modify it under the terms of the GNU (Library) General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU (Library) General Public License for more details.
**
** You should have received a copy of the GNU (Library) General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
**
**
**
** 2001-01  jose   initial coding
**
*/



#ifndef __HasSeenModule_ResultSort
#define __HasSeenModule_ResultSort	1

#ifdef __cplusplus
extern "C" {
#endif

/*
   -- global module data structure
*/

struct MOD_ResultSort
{

	    /* sorted index flag */
	    /* TRUE - Use sorted index */
	int isPreSorted;
	    /* structure for presorted properties - used by index proccess */
    struct swline *presortedindexlist;

        /* Sortorder Translation table arrays */
              /* case sensitive translation table */
    int iSortTranslationTable[256];
              /* Ignore Case translarion table */
    int iSortCaseTranslationTable[256];
    
};





void initModule_ResultSort (SWISH *);
void freeModule_ResultSort (SWISH *);
int configModule_ResultSort (SWISH *sw, StringList *sl);


int compare_results(const void *s1, const void *s2);


int     sortresults(RESULTS_OBJECT *results);



int *CreatePropSortArray(IndexFILE *indexf, struct metaEntry *m, FileRec *fi, int free_cache );
void sortFileProperties(SWISH *sw, IndexFILE *indexf);


void initStrCmpTranslationTable(int *);
void initStrCaseCmpTranslationTable(int *);

int sw_strcasecmp(unsigned char *,unsigned char *, int *);
int sw_strcmp(unsigned char *,unsigned char *, int *);

int *LoadSortedProps( IndexFILE *indexf, struct metaEntry *m );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __HasSeenModule_ResultSort  */
