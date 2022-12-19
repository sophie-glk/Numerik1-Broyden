/*
   'vorrueckwaertsub.c' Obfuscated by COBF (Version 1.06 2006-01-07 by BB) at Thu Nov 24 09:52:47 2011
*/
#include"vorrueckwaertsub.h"
#define lt static
#define lh double
#define lg int
#define lv LRmP
#define lf for
#define lm fabs
#define lo if
#define ln printf
#define ll return
#define ly Solve
#define l0 malloc
#define l1 sizeof
#define ls vwsubs
#define lw rwsubs
#define lz free
#define lx else
#define l2 LRoP
#define lu void
lu ls(lg ld,lh* *lr,lh*li){lg la,lb;lf(la=0;la<ld;la++){lf(lb=0;lb<la
;lb++)li[la]=li[la]-lr[la][lb] *li[lb];}ll;}lu lw(lg ld,lh* *lq,lh*li
){lg la,lb;lf(la=ld-1;la>=0;la--){lf(lb=la+1;lb<ld;lb++)li[la]=li[la]
-lq[la][lb] *li[lb];li[la]=li[la]/lq[la][la];}ll;}
