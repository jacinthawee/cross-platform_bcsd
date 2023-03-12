
int X509V3_add_value_bool(char *name,int asn1_bool,stack_st_CONF_VALUE **extlist)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  stack_st_CONF_VALUE *psVar6;
  
  if (asn1_bool != 0) {
    iVar2 = X509V3_add_value(name,"TRUE",extlist);
    return iVar2;
  }
  if (name == (char *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (*(code *)PTR_BUF_strdup_006a6fdc)();
    if (iVar2 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x69,0x41,"v3_utl.c",0x66);
      return 0;
    }
  }
  iVar3 = (*(code *)PTR_BUF_strdup_006a6fdc)("FALSE");
  if (iVar3 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x69,0x41,"v3_utl.c",0x66);
    if (iVar2 == 0) {
      return 0;
    }
  }
  else {
    puVar4 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0xc,"v3_utl.c",0x5b);
    if (puVar4 == (undefined4 *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x69,0x41,"v3_utl.c",0x66);
    }
    else {
      if (*extlist == (stack_st_CONF_VALUE *)0x0) {
        psVar6 = (stack_st_CONF_VALUE *)(*(code *)PTR_sk_new_null_006a6fa4)();
        *extlist = psVar6;
        if (psVar6 != (stack_st_CONF_VALUE *)0x0) goto LAB_00589ab4;
      }
      else {
LAB_00589ab4:
        puVar1 = PTR_sk_push_006a6fa8;
        *puVar4 = 0;
        puVar4[1] = iVar2;
        puVar4[2] = iVar3;
        iVar5 = (*(code *)puVar1)(*extlist,puVar4);
        if (iVar5 != 0) {
          return 1;
        }
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x69,0x41,"v3_utl.c",0x66);
      (*(code *)PTR_CRYPTO_free_006a6e88)(puVar4);
    }
    if (iVar2 == 0) goto LAB_00589b28;
  }
  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar2);
  if (iVar3 == 0) {
    return 0;
  }
LAB_00589b28:
  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar3);
  return 0;
}

