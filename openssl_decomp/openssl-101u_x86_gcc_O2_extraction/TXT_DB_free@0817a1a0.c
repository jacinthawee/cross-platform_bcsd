
void TXT_DB_free(TXT_DB *db)

{
  void *ptr;
  void *pvVar1;
  void *pvVar2;
  lhash_st_OPENSSL_STRING **ptr_00;
  int iVar3;
  int iVar4;
  int local_20;
  
  if (db == (TXT_DB *)0x0) {
    return;
  }
  ptr_00 = db->index;
  if (ptr_00 != (lhash_st_OPENSSL_STRING **)0x0) {
    iVar3 = db->num_fields + -1;
    if (-1 < iVar3) {
      iVar4 = iVar3 * 4;
      do {
        if (*(_LHASH **)((int)ptr_00 + iVar4) != (_LHASH *)0x0) {
          lh_free(*(_LHASH **)((int)ptr_00 + iVar4));
          ptr_00 = db->index;
        }
        iVar3 = iVar3 + -1;
        iVar4 = iVar4 + -4;
      } while (iVar3 != -1);
    }
    CRYPTO_free(ptr_00);
  }
  if (db->qual != (_func_4743 *)0x0) {
    CRYPTO_free(db->qual);
  }
  if ((_STACK *)db->data != (_STACK *)0x0) {
    local_20 = sk_num((_STACK *)db->data);
    local_20 = local_20 + -1;
    if (-1 < local_20) {
      do {
        pvVar1 = sk_value((_STACK *)db->data,local_20);
        iVar3 = db->num_fields;
        pvVar2 = *(void **)((int)pvVar1 + iVar3 * 4);
        if (pvVar2 == (void *)0x0) {
          if (0 < iVar3) {
            iVar4 = 0;
            do {
              pvVar2 = *(void **)((int)pvVar1 + iVar4 * 4);
              if (pvVar2 != (void *)0x0) {
                CRYPTO_free(pvVar2);
                iVar3 = db->num_fields;
              }
              iVar4 = iVar4 + 1;
            } while (iVar4 < iVar3);
          }
        }
        else {
          iVar4 = 0;
          if (0 < iVar3) {
            do {
              while (((ptr = *(void **)((int)pvVar1 + iVar4 * 4), ptr <= pvVar2 && (pvVar1 <= ptr))
                     || (ptr == (void *)0x0))) {
                iVar4 = iVar4 + 1;
                if (iVar3 <= iVar4) goto LAB_0817a294;
              }
              iVar4 = iVar4 + 1;
              CRYPTO_free(ptr);
              iVar3 = db->num_fields;
            } while (iVar4 < iVar3);
          }
        }
LAB_0817a294:
        pvVar2 = sk_value((_STACK *)db->data,local_20);
        CRYPTO_free(pvVar2);
        local_20 = local_20 + -1;
      } while (local_20 != -1);
    }
    sk_free((_STACK *)db->data);
  }
  CRYPTO_free(db);
  return;
}

