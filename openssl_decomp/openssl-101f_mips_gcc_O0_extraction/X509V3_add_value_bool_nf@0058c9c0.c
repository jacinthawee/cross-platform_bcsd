
int X509V3_add_value_bool_nf(char *name,int asn1_bool,stack_st_CONF_VALUE **extlist)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  stack_st_CONF_VALUE *psVar6;
  
  if (asn1_bool == 0) {
    return 1;
  }
  if (name == (char *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (*(code *)PTR_BUF_strdup_006a80dc)();
    if (iVar2 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x69,0x41,"v3_utl.c",0x60);
      return 0;
    }
  }
  iVar3 = (*(code *)PTR_BUF_strdup_006a80dc)(&DAT_0066dfd8);
  if (iVar3 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x69,0x41,"v3_utl.c",0x60);
    if (iVar2 == 0) {
      return 0;
    }
  }
  else {
    puVar4 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0xc,"v3_utl.c",0x58);
    if (puVar4 == (undefined4 *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x69,0x41,"v3_utl.c",0x60);
    }
    else {
      if (*extlist == (stack_st_CONF_VALUE *)0x0) {
        psVar6 = (stack_st_CONF_VALUE *)(*(code *)PTR_sk_new_null_006a80a4)();
        *extlist = psVar6;
        if (psVar6 != (stack_st_CONF_VALUE *)0x0) goto LAB_0058ca64;
      }
      else {
LAB_0058ca64:
        puVar1 = PTR_sk_push_006a80a8;
        *puVar4 = 0;
        puVar4[1] = iVar2;
        puVar4[2] = iVar3;
        iVar5 = (*(code *)puVar1)(*extlist,puVar4);
        if (iVar5 != 0) {
          return 1;
        }
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x69,0x41,"v3_utl.c",0x60);
      (*(code *)PTR_CRYPTO_free_006a7f88)(puVar4);
    }
    if (iVar2 == 0) goto LAB_0058cad8;
  }
  (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
  if (iVar3 == 0) {
    return 0;
  }
LAB_0058cad8:
  (*(code *)PTR_CRYPTO_free_006a7f88)(iVar3);
  return 0;
}

