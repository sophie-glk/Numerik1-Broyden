/*
   'lrmp.c' Obfuscated by COBF (Version 1.06 2006-01-07 by BB) at Thu Nov 24 09:52:47 2011
*/
#include<stdio.h>
#include<stdlib.h>
#include"lrmp.h"
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
lt lh lp=1.0e-8;lg lv(lg ld,lh* *lc,lg*lk){lg la,lb,le;lh lj;lf(la=0;
la<ld;la++)lk[la]=la;lf(lb=0;lb<ld-1;lb++){lj=lm(lc[lb][lb]);le=lb;lf
(la=lb+1;la<ld;la++){lo(lj<lm(lc[la][lb])){le=la;lj=lm(lc[la][lb]);}}
la=lk[le];lk[le]=lk[lb];lk[lb]=la;lf(la=0;la<ld;la++){lj=lc[le][la];
lc[le][la]=lc[lb][la];lc[lb][la]=lj;}lo(lm(lc[lb][lb])<lp){ln("\n\x20"
"\x44\x61\x73\x20\x44\x69\x61\x67\x6f\x6e\x61\x6c\x65\x6c\x65\x6d\x65"
"\x6e\x74\x20\x69\x73\x74\x20\x6d\x69\x74\x20\x25\x32\x30\x2e\x31\x36"
"\x65\x20\x7a\x75\x20\x6b\x6c\x65\x69\x6e\x2e",lc[lb][lb]);ln("\n\x20"
"\x64\x65\x72\x20\x25\x33\x64\x2e\x20\x53\x63\x68\x72\x69\x74\x74\x20"
"\x64\x65\x72\x20\x4c\x52\x2d\x5a\x65\x72\x6c\x65\x67\x75\x6e\x67\x20"
"\x6b\x61\x6e\x6e\x20\x6e\x69\x63\x68\x74\x20\x61\x75\x73\x67\x65\x66"
"\x75\x65\x68\x72\x74\x20\x77\x65\x72\x64\x65\x6e",lb+1);ll 1;}lf(la=
lb+1;la<ld;la++){lc[la][lb]=lc[la][lb]/lc[lb][lb];lf(le=lb+1;le<ld;le
++)lc[la][le]=lc[la][le]-lc[la][lb] *lc[lb][le];}}ll 0;}lg ly(lg ld,
lh* *lc,lh*li,lg*lk){lg la;lh*lj;lo(!(lv(ld,lc,lk))){lj=(lh* )l0(ld*
l1(lh));lf(la=0;la<ld;la++)lj[la]=li[lk[la]];ls(ld,lc,lj);lw(ld,lc,lj
);lf(la=0;la<ld;la++)li[la]=lj[la];lz(lj);ll 0;}lx ll 1;}
