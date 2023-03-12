
int _CONF_add_string(CONF *conf,CONF_VALUE *section,CONF_VALUE *value)

{
  undefined *puVar1;
  int iVar2;
  char *pcVar3;
  
  puVar1 = PTR_sk_push_006a6fa8;
  pcVar3 = section->value;
  value->section = section->section;
  iVar2 = (*(code *)puVar1)(pcVar3,value);
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_lh_insert_006a7414)(conf->data,value);
    if (iVar2 != 0) {
      (*(code *)PTR_sk_delete_ptr_006a8f00)(pcVar3,iVar2);
      (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(iVar2 + 4));
      (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(iVar2 + 8));
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar2);
      return 1;
    }
    iVar2 = 1;
  }
  return iVar2;
}

