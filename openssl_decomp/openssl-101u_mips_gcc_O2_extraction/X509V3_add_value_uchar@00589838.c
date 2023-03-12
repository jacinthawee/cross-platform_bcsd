
int X509V3_add_value_uchar(char *name,uchar *value,stack_st_CONF_VALUE **extlist)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  stack_st_CONF_VALUE *psVar6;
  
  if (name == (char *)0x0) {
    iVar2 = 0;
    if (value != (uchar *)0x0) goto LAB_0058988c;
LAB_005899d0:
    iVar3 = 0;
LAB_005898a4:
    puVar4 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0xc,"v3_utl.c",0x5b);
    if (puVar4 != (undefined4 *)0x0) {
      if (*extlist == (stack_st_CONF_VALUE *)0x0) {
        psVar6 = (stack_st_CONF_VALUE *)(*(code *)PTR_sk_new_null_006a6fa4)();
        *extlist = psVar6;
        if (psVar6 != (stack_st_CONF_VALUE *)0x0) goto LAB_005898d4;
      }
      else {
LAB_005898d4:
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
      goto LAB_0058992c;
    }
  }
  else {
    iVar2 = (*(code *)PTR_BUF_strdup_006a6fdc)();
    if (iVar2 == 0) {
      iVar3 = 0;
    }
    else {
      if (value == (uchar *)0x0) goto LAB_005899d0;
LAB_0058988c:
      iVar3 = (*(code *)PTR_BUF_strdup_006a6fdc)(value);
      if (iVar3 != 0) goto LAB_005898a4;
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x69,0x41,"v3_utl.c",0x66);
LAB_0058992c:
  if (iVar2 != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar2);
  }
  if (iVar3 == 0) {
    return 0;
  }
  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar3);
  return 0;
}

