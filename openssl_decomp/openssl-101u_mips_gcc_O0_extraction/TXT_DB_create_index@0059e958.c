
int TXT_DB_create_index(TXT_DB *db,int field,qual *qual,LHASH_HASH_FN_TYPE hash,
                       LHASH_COMP_FN_TYPE cmp)

{
  undefined *puVar1;
  lhash_st_OPENSSL_STRING *plVar2;
  int iVar3;
  OPENSSL_STRING *ppcVar4;
  int iVar5;
  lhash_st_OPENSSL_STRING **pplVar6;
  undefined4 uVar7;
  long lVar8;
  long lVar9;
  
  if (db->num_fields <= field) {
    db->error = 3;
    return 0;
  }
  plVar2 = (lhash_st_OPENSSL_STRING *)(*(code *)PTR_lh_new_006a740c)(hash,cmp);
  if (plVar2 == (lhash_st_OPENSSL_STRING *)0x0) {
    iVar3 = 0;
    db->error = 1;
  }
  else {
    iVar3 = (*(code *)PTR_sk_num_006a6e2c)(db->data);
    if (0 < iVar3) {
      lVar9 = 0;
      if (qual == (qual *)0x0) {
        do {
          uVar7 = (*(code *)PTR_sk_value_006a6e24)(db->data,lVar9);
          iVar5 = (*(code *)PTR_lh_insert_006a7414)(plVar2,uVar7);
          if (iVar5 != 0) goto LAB_0059ead4;
          lVar9 = lVar9 + 1;
        } while (iVar3 != lVar9);
      }
      else {
        do {
          ppcVar4 = (OPENSSL_STRING *)(*(code *)PTR_sk_value_006a6e24)(db->data,lVar9);
          iVar5 = (*qual)(ppcVar4);
          if ((iVar5 != 0) &&
             (iVar5 = (*(code *)PTR_lh_insert_006a7414)(plVar2,ppcVar4), iVar5 != 0)) {
LAB_0059ead4:
            puVar1 = PTR_sk_find_006a8044;
            db->error = 2;
            lVar8 = (*(code *)puVar1)(db->data,iVar5);
            db->arg1 = lVar8;
            puVar1 = PTR_lh_free_006a7418;
            db->arg2 = lVar9;
            (*(code *)puVar1)(plVar2);
            return 0;
          }
          lVar9 = lVar9 + 1;
        } while (iVar3 != lVar9);
      }
    }
    pplVar6 = db->index + field;
    if (*pplVar6 != (lhash_st_OPENSSL_STRING *)0x0) {
      (*(code *)PTR_lh_free_006a7418)();
      pplVar6 = db->index + field;
    }
    *pplVar6 = plVar2;
    iVar3 = 1;
    *(qual **)(db->qual + field * 4) = qual;
  }
  return iVar3;
}

