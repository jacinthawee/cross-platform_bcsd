
int X509_VERIFY_PARAM_add0_table(X509_VERIFY_PARAM *param)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_table == 0) {
    param_table = (*(code *)PTR_sk_new_006a806c)(param_cmp);
    if (param_table == 0) {
      return 0;
    }
  }
  else {
    iVar1 = (*(code *)PTR_sk_find_006a8044)(param_table,param);
    if (iVar1 != -1) {
      puVar2 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(param_table,iVar1);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = 0;
        puVar2[4] = 0;
        puVar2[5] = 0;
        puVar2[2] = 0;
        puVar2[3] = 0;
        puVar2[6] = 0xffffffff;
        if (puVar2[7] != 0) {
          (*(code *)PTR_sk_pop_free_006a7058)(puVar2[7],PTR_ASN1_OBJECT_free_006a7004);
          puVar2[7] = 0;
        }
        (*(code *)PTR_CRYPTO_free_006a6e88)(puVar2);
      }
      (*(code *)PTR_sk_delete_006a7288)(param_table,iVar1);
    }
  }
  iVar1 = (*(code *)PTR_sk_push_006a6fa8)(param_table,param);
  return (uint)(iVar1 != 0);
}

