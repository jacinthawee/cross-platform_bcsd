
void TXT_DB_free(TXT_DB *db)

{
  _LHASH **pp_Var1;
  void *pvVar2;
  lhash_st_OPENSSL_STRING **ptr;
  void *ptr_00;
  int iVar3;
  int iVar4;
  int iVar5;
  void **ppvVar6;
  void *pvVar7;
  
  if (db != (TXT_DB *)0x0) {
    ptr = db->index;
    if (ptr != (lhash_st_OPENSSL_STRING **)0x0) {
      iVar3 = db->num_fields + -1;
      if (-1 < iVar3) {
        iVar5 = iVar3 * 4;
        do {
          pp_Var1 = (_LHASH **)((int)ptr + iVar5);
          iVar3 = iVar3 + -1;
          iVar5 = iVar5 + -4;
          if (*pp_Var1 != (_LHASH *)0x0) {
            lh_free(*pp_Var1);
            ptr = db->index;
          }
        } while (iVar3 != -1);
      }
      CRYPTO_free(ptr);
    }
    if (db->qual != (_func_4743 *)0x0) {
      CRYPTO_free(db->qual);
    }
    if ((_STACK *)db->data != (_STACK *)0x0) {
      iVar3 = sk_num((_STACK *)db->data);
      iVar3 = iVar3 + -1;
      if (-1 < iVar3) {
        do {
          pvVar2 = sk_value((_STACK *)db->data,iVar3);
          iVar5 = db->num_fields;
          pvVar7 = *(void **)((int)pvVar2 + iVar5 * 4);
          if (pvVar7 == (void *)0x0) {
            if (0 < iVar5) {
              ppvVar6 = (void **)((int)pvVar2 + -4);
              do {
                ppvVar6 = ppvVar6 + 1;
                pvVar7 = (void *)((int)pvVar7 + 1);
                if (*ppvVar6 != (void *)0x0) {
                  CRYPTO_free(*ppvVar6);
                  iVar5 = db->num_fields;
                }
              } while ((int)pvVar7 < iVar5);
            }
          }
          else if (0 < iVar5) {
            ppvVar6 = (void **)((int)pvVar2 + -4);
            iVar4 = 0;
            do {
              ppvVar6 = ppvVar6 + 1;
              ptr_00 = *ppvVar6;
              iVar4 = iVar4 + 1;
              if (((ptr_00 < pvVar2) || (pvVar7 < ptr_00)) && (ptr_00 != (void *)0x0)) {
                CRYPTO_free(ptr_00);
                iVar5 = db->num_fields;
              }
            } while (iVar4 < iVar5);
          }
          pvVar2 = sk_value((_STACK *)db->data,iVar3);
          iVar3 = iVar3 + -1;
          CRYPTO_free(pvVar2);
        } while (iVar3 != -1);
      }
      sk_free((_STACK *)db->data);
    }
    CRYPTO_free(db);
    return;
  }
  return;
}

