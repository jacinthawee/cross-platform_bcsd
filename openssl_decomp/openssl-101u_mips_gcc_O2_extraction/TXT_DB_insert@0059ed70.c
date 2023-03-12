
int TXT_DB_insert(TXT_DB *db,OPENSSL_STRING *value)

{
  OPENSSL_STRING *ppcVar1;
  lhash_st_OPENSSL_STRING *plVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = db->num_fields;
  if (0 < iVar3) {
    do {
      plVar2 = db->index[iVar4];
      if (plVar2 != (lhash_st_OPENSSL_STRING *)0x0) {
        if (*(code **)(db->qual + iVar4 * 4) == (code *)0x0) {
LAB_0059edf0:
          ppcVar1 = (OPENSSL_STRING *)(*(code *)PTR_lh_retrieve_006a73b0)(plVar2,value);
          if (ppcVar1 != (OPENSSL_STRING *)0x0) {
            db->arg1 = iVar4;
            db->arg_row = ppcVar1;
            db->error = 2;
            return 0;
          }
        }
        else {
          iVar3 = (**(code **)(db->qual + iVar4 * 4))(value);
          if (iVar3 != 0) {
            plVar2 = db->index[iVar4];
            goto LAB_0059edf0;
          }
        }
        iVar3 = db->num_fields;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  iVar3 = (*(code *)PTR_sk_push_006a6fa8)(db->data,value);
  if (iVar3 == 0) {
    db->error = 1;
    return 0;
  }
  iVar3 = db->num_fields;
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      plVar2 = db->index[iVar4];
      if (plVar2 != (lhash_st_OPENSSL_STRING *)0x0) {
        if (*(code **)(db->qual + iVar4 * 4) == (code *)0x0) {
LAB_0059ee88:
          (*(code *)PTR_lh_insert_006a7414)(plVar2,value);
        }
        else {
          iVar3 = (**(code **)(db->qual + iVar4 * 4))(value);
          if (iVar3 != 0) {
            plVar2 = db->index[iVar4];
            goto LAB_0059ee88;
          }
        }
        iVar3 = db->num_fields;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  return 1;
}

