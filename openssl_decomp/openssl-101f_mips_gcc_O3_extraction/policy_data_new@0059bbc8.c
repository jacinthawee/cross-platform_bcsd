
undefined4 * policy_data_new(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == (undefined4 *)0x0) {
    if (param_2 == 0) {
      return (undefined4 *)0x0;
    }
  }
  else if (param_2 == 0) {
    iVar1 = 0;
    goto LAB_0059bc14;
  }
  iVar1 = (*(code *)PTR_OBJ_dup_006a95b4)(param_2);
  if (iVar1 == 0) {
    return (undefined4 *)0x0;
  }
LAB_0059bc14:
  puVar2 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x10,"pcy_data.c",100);
  if (puVar2 != (undefined4 *)0x0) {
    iVar3 = (*(code *)PTR_sk_new_null_006a80a4)();
    puVar2[3] = iVar3;
    if (iVar3 != 0) {
      uVar4 = 0x10;
      if (param_3 == 0) {
        uVar4 = 0;
      }
      *puVar2 = uVar4;
      if (iVar1 == 0) {
        puVar2[1] = *param_1;
        *param_1 = 0;
      }
      else {
        puVar2[1] = iVar1;
        if (param_1 == (undefined4 *)0x0) {
          puVar2[2] = 0;
          return puVar2;
        }
      }
      puVar2[2] = param_1[1];
      param_1[1] = 0;
      return puVar2;
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(puVar2);
    if (iVar1 != 0) {
      (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iVar1);
    }
  }
  return (undefined4 *)0x0;
}

