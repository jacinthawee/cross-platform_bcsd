
int X509V3_add_value(char *name,char *value,stack_st_CONF_VALUE **extlist)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  stack_st_CONF_VALUE *psVar6;
  
  if (name == (char *)0x0) {
    iVar2 = 0;
    if (value != (char *)0x0) goto LAB_0058c41c;
LAB_0058c560:
    iVar3 = 0;
LAB_0058c434:
    puVar4 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0xc,"v3_utl.c",0x58);
    if (puVar4 != (undefined4 *)0x0) {
      if (*extlist == (stack_st_CONF_VALUE *)0x0) {
        psVar6 = (stack_st_CONF_VALUE *)(*(code *)PTR_sk_new_null_006a80a4)();
        *extlist = psVar6;
        if (psVar6 != (stack_st_CONF_VALUE *)0x0) goto LAB_0058c464;
      }
      else {
LAB_0058c464:
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
      goto LAB_0058c4bc;
    }
  }
  else {
    iVar2 = (*(code *)PTR_BUF_strdup_006a80dc)();
    if (iVar2 == 0) {
      iVar3 = 0;
    }
    else {
      if (value == (char *)0x0) goto LAB_0058c560;
LAB_0058c41c:
      iVar3 = (*(code *)PTR_BUF_strdup_006a80dc)(value);
      if (iVar3 != 0) goto LAB_0058c434;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x69,0x41,"v3_utl.c",0x60);
LAB_0058c4bc:
  if (iVar2 != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
  }
  if (iVar3 == 0) {
    return 0;
  }
  (*(code *)PTR_CRYPTO_free_006a7f88)(iVar3);
  return 0;
}

