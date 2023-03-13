
int TXT_DB_insert(TXT_DB *db,OPENSSL_STRING *value)

{
  int iVar1;
  OPENSSL_STRING *ppcVar2;
  _LHASH *p_Var3;
  int iVar4;
  
  iVar4 = 0;
  iVar1 = db->num_fields;
  if (0 < iVar1) {
    do {
      p_Var3 = (_LHASH *)db->index[iVar4];
      if (p_Var3 != (_LHASH *)0x0) {
        if (*(code **)(db->qual + iVar4 * 4) == (code *)0x0) {
LAB_0817a0ce:
          ppcVar2 = (OPENSSL_STRING *)lh_retrieve(p_Var3,value);
          if (ppcVar2 != (OPENSSL_STRING *)0x0) {
            db->arg_row = ppcVar2;
            db->error = 2;
            db->arg1 = iVar4;
            return 0;
          }
        }
        else {
          iVar1 = (**(code **)(db->qual + iVar4 * 4))(value);
          if (iVar1 != 0) {
            p_Var3 = (_LHASH *)db->index[iVar4];
            goto LAB_0817a0ce;
          }
        }
        iVar1 = db->num_fields;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  iVar1 = sk_push((_STACK *)db->data,value);
  if (iVar1 == 0) {
    db->error = 1;
    return 0;
  }
  iVar1 = db->num_fields;
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      while (p_Var3 = (_LHASH *)db->index[iVar4], p_Var3 != (_LHASH *)0x0) {
        if (*(code **)(db->qual + iVar4 * 4) != (code *)0x0) {
          iVar1 = (**(code **)(db->qual + iVar4 * 4))(value);
          if (iVar1 == 0) {
            iVar1 = db->num_fields;
            break;
          }
          p_Var3 = (_LHASH *)db->index[iVar4];
        }
        iVar4 = iVar4 + 1;
        lh_insert(p_Var3,value);
        iVar1 = db->num_fields;
        if (iVar1 <= iVar4) {
          return 1;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  return 1;
}

