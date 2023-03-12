
int TXT_DB_create_index(TXT_DB *db,int field,qual *qual,LHASH_HASH_FN_TYPE hash,
                       LHASH_COMP_FN_TYPE cmp)

{
  qual *pqVar1;
  _LHASH *lh;
  qual *pqVar2;
  OPENSSL_STRING *data;
  int iVar3;
  void *pvVar4;
  lhash_st_OPENSSL_STRING **pplVar5;
  qual *pqVar6;
  
  if (db->num_fields <= field) {
    db->error = 3;
    return 0;
  }
  lh = lh_new(hash,cmp);
  if (lh == (_LHASH *)0x0) {
    db->error = 1;
    return 0;
  }
  pqVar2 = (qual *)sk_num((_STACK *)db->data);
  if (0 < (int)pqVar2) {
    pqVar6 = qual;
    pqVar1 = (qual *)0x0;
    if (qual == (qual *)0x0) {
      do {
        pvVar4 = sk_value((_STACK *)db->data,(int)pqVar6);
        pvVar4 = lh_insert(lh,pvVar4);
        if (pvVar4 != (void *)0x0) goto LAB_000d959a;
        pqVar6 = pqVar6 + 1;
      } while (pqVar6 != pqVar2);
    }
    else {
      do {
        pqVar6 = pqVar1;
        data = (OPENSSL_STRING *)sk_value((_STACK *)db->data,(int)pqVar6);
        iVar3 = (*qual)(data);
        if ((iVar3 != 0) && (pvVar4 = lh_insert(lh,data), pvVar4 != (void *)0x0)) {
LAB_000d959a:
          db->error = 2;
          iVar3 = sk_find((_STACK *)db->data,pvVar4);
          db->arg2 = (long)pqVar6;
          db->arg1 = iVar3;
          lh_free(lh);
          return 0;
        }
        pqVar1 = pqVar6 + 1;
      } while (pqVar6 + 1 != pqVar2);
    }
  }
  pplVar5 = db->index;
  if ((_LHASH *)pplVar5[field] != (_LHASH *)0x0) {
    lh_free((_LHASH *)pplVar5[field]);
    pplVar5 = db->index;
  }
  pplVar5[field] = (lhash_st_OPENSSL_STRING *)lh;
  *(qual **)(db->qual + field * 4) = qual;
  return 1;
}

