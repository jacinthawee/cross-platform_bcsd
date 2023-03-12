
int TXT_DB_insert(TXT_DB *db,OPENSSL_STRING *value)

{
  OPENSSL_STRING *ppcVar1;
  int iVar2;
  _LHASH *p_Var3;
  int iVar4;
  
  iVar2 = db->num_fields;
  if (0 < iVar2) {
    iVar4 = 0;
    do {
      p_Var3 = (_LHASH *)db->index[iVar4];
      if (p_Var3 != (_LHASH *)0x0) {
        if (*(code **)(db->qual + iVar4 * 4) == (code *)0x0) {
LAB_000d9710:
          ppcVar1 = (OPENSSL_STRING *)lh_retrieve(p_Var3,value);
          if (ppcVar1 != (OPENSSL_STRING *)0x0) {
            db->arg_row = ppcVar1;
            db->arg1 = iVar4;
            db->error = 2;
            return 0;
          }
        }
        else {
          iVar2 = (**(code **)(db->qual + iVar4 * 4))(value);
          if (iVar2 != 0) {
            p_Var3 = (_LHASH *)db->index[iVar4];
            goto LAB_000d9710;
          }
        }
        iVar2 = db->num_fields;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  iVar2 = sk_push((_STACK *)db->data,value);
  if (iVar2 == 0) {
    db->error = 1;
    return 0;
  }
  iVar2 = db->num_fields;
  if (0 < iVar2) {
    iVar4 = 0;
    do {
      p_Var3 = (_LHASH *)db->index[iVar4];
      if (p_Var3 != (_LHASH *)0x0) {
        if (*(code **)(db->qual + iVar4 * 4) == (code *)0x0) {
LAB_000d9752:
          lh_insert(p_Var3,value);
        }
        else {
          iVar2 = (**(code **)(db->qual + iVar4 * 4))(value);
          if (iVar2 != 0) {
            p_Var3 = (_LHASH *)db->index[iVar4];
            goto LAB_000d9752;
          }
        }
        iVar2 = db->num_fields;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  return 1;
}

