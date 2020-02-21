/*
2001-05-04 DL_dbTyp__dli,DL_get_dbi,DL_GetTrInd zu.
*/



// #define GR_TAB_SIZ       25000
#define GR_ATT_TAB_SIZ   45          // DL_base_PtAtt - DL_base_LnAtt
#define GR_DIT_TAB_SIZ   1000


// DL_IS_HIDDEN ((DL_Att)dla)     test if obj is hidden
//   returns 0=visible; else 1=hidden
// int DL_IS_HIDDEN (DL_Att);
#define DL_IS_HIDDEN(dla)\
 ((dla.disp == 1)&&(dla.hili == 1))
 // ((dla->disp == 1)&&(dla->hili == 1))


// DL_OBJ_IS_ACTMDL ((DL_Att)dla)     test if obj belongs to active model
//   returns 0 if(dla.modInd >= 0)  - subModel
//   returns 1 if(dla.modInd == -1) - active Model
// int DL_OBJ_IS_ACTMDL (DL_Att);
#define DL_OBJ_IS_ACTMDL(dla)\
 ((INT_16)dla.modInd != -1)


// DL_OBJ_IS_HIDDEN ((long)dli)     test if obj is hidden
//   returns 0=visible; else 1=hidden
//   hidden if: disp=1, hili=1;
// int DL_OBJ_IS_HIDDEN (long);
#define DL_OBJ_IS_HIDDEN(dli)\
 ((dli >= 0)&&(GR_ObjTab[dli].disp == 1)&&(GR_ObjTab[dli].hili == 1))


// DL_OBJ_IS_HILITE ((long)dli)     test if obj is hilited
//   returns 0=normal; else 1=hilited
//   hilite if: disp=1, hili=0;
// int DL_OBJ_IS_HILITE (long);
#define DL_OBJ_IS_HILITE(dli)\
 ((GR_ObjTab[dli].disp == 1)&&(GR_ObjTab[dli].hili == 0))


// DL_OBJ_IS_NORMAL ((long)dli)     test if obj is hilited
//   returns 0=hili|hidden; else 1=normal
//   normal if: disp=0, hili=1;
// int DL_OBJ_IS_NORMAL (long);
#define DL_OBJ_IS_NORMAL(dli)\
 ((GR_ObjTab[dli].disp == 0)&&(GR_ObjTab[dli].hili == 1))



// DL_OBJ_IS_TRANSP ((long)dli)     test if obj is transparent
//   returns 0=visible; else 1=hilited
// int DL_OBJ_IS_TRANSP (long);
#define DL_OBJ_IS_TRANSP(dli)\
 (((ColRGB*)&GR_ObjTab[dli].iatt)->vtra != 0)




void DL_Init ();
void DL_InitAttTab   ();
int  DL_InitAttRec   (int ind, int col, int ltyp, int lthick);

int  DL_SetObj       (long *dli, int typ, long dbi, int iAtt);
long DL_StoreObj     (int Typ, long DBInd, int AttInd);
int  DL_SetInd       (long dli);
long DL_SetTmpObj    (int typ, long dbi);

long DL_get__        (DL_Att **dl);

void DL_DumpObjTab   (char *fInf);
// int  DL_StoreAtt     (long Ind, GR_Att* att1);
int  DL_Redraw       ();
int  DL_ReScale__    ();
// int  DL_save_DYNAMIC_AREA ();

int  DL_dbTyp__dli       (long dli);
long DL_get_dbi      (long dli);
long DL_GetTrInd     (long dli);
// int  DL_Get_GrAtt    (GR_Att* att1, long Ind);
// DL_Att DL_GetAtt     (long dli);
unsigned int DL_get_iatt (long dli);
ColRGB* DL_get_col (long dli);

long DL_find_smObj (int typ, long DBind, long DLend, int imod);
long DL_dli__dbo (int typ, long ind, long DLend);
// int  DL_find_sel (int *typ, long *ind);

int  DL_hili_on           (long);
int  DL_hili_off         (long);

int  DL_pick_set   (long ind, int mode);
int  DL_grp1_set   (long ind, int mode);

int  DL_hide_chg   ();
void DL_hide__   (long ind, int mode);

void DL_Lay_act_g1 (int layNr, int mode);
void DL_Lay_typ_g1 (int typ, int mode);
void DL_Lay_col_g1 (int col, int mode);
void DL_Lay_ltyp_g1 (int ltyp, int mode);
void DL_Lay_thk_g1 (int thk, int mode);
int  DL_Lay_mod (int layNr, int func, int mode);
int  DL_Lay_add (int layNr);



/*============= EOF ===============*/

