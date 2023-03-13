
int TXT_DB_create_index(TXT_DB *db,int field,qual *qual,LHASH_HASH_FN_TYPE hash,
                       LHASH_COMP_FN_TYPE cmp)

{
  _LHASH *lh;
  qual *pqVar1;
  OPENSSL_STRING *data;
  int iVar2;
  void *pvVar3;
  _LHASH **pp_Var4;
  qual *pqVar5;
  
  if (db->num_fields == field || db->num_fields < field) {
    db->error = 3;
  }
  else {
    lh = lh_new(hash,cmp);
    if (lh != (_LHASH *)0x0) {
      pqVar1 = (qual *)sk_num((_STACK *)db->data);
      if (0 < (int)pqVar1) {
        pqVar5 = qual;
        if (qual == (qual *)0x0) {
          do {
            pvVar3 = sk_value((_STACK *)db->data,(int)pqVar5);
            pvVar3 = lh_insert(lh,pvVar3);
            if (pvVar3 != (void *)0x0) goto LAB_08179e14;
            pqVar5 = pqVar5 + 1;
          } while (pqVar1 != pqVar5);
        }
        else {
          pqVar5 = (qual *)0x0;
          do {
            data = (OPENSSL_STRING *)sk_value((_STACK *)db->data,(int)pqVar5);
            iVar2 = (*qual)(data);
            if ((iVar2 != 0) && (pvVar3 = lh_insert(lh,data), pvVar3 != (void *)0x0)) {
LAB_08179e14:
              db->error = 2;
              iVar2 = sk_find((_STACK *)db->data,pvVar3);
              db->arg2 = (long)pqVar5;
              db->arg1 = iVar2;
              lh_free(lh);
              return 0;
            }
            pqVar5 = pqVar5 + 1;
          } while (pqVar1 != pqVar5);
        }
      }
      pp_Var4 = (_LHASH **)(db->index + field);
      if (*pp_Var4 != (_LHASH *)0x0) {
        lh_free(*pp_Var4);
        pp_Var4 = (_LHASH **)(db->index + field);
      }
      *pp_Var4 = lh;
      *(qual **)(db->qual + field * 4) = qual;
      return 1;
    }
    db->error = 1;
  }
  return 0;
}

