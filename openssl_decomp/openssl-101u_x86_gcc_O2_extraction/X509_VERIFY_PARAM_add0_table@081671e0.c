
int X509_VERIFY_PARAM_add0_table(X509_VERIFY_PARAM *param)

{
  int iVar1;
  undefined4 *ptr;
  
  if (param_table == (_STACK *)0x0) {
    param_table = sk_new(param_cmp);
    if (param_table == (_STACK *)0x0) {
      return 0;
    }
  }
  else {
    iVar1 = sk_find(param_table,param);
    if (iVar1 != -1) {
      ptr = (undefined4 *)sk_value(param_table,iVar1);
      if (ptr != (undefined4 *)0x0) {
        *ptr = 0;
        ptr[4] = 0;
        ptr[5] = 0;
        ptr[2] = 0;
        ptr[3] = 0;
        ptr[6] = 0xffffffff;
        if ((_STACK *)ptr[7] != (_STACK *)0x0) {
          sk_pop_free((_STACK *)ptr[7],ASN1_OBJECT_free);
          ptr[7] = 0;
        }
        CRYPTO_free(ptr);
      }
      sk_delete(param_table,iVar1);
    }
  }
  iVar1 = sk_push(param_table,param);
  return (uint)(iVar1 != 0);
}

