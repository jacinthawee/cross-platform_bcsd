
undefined4 * SRP_VBASE_get_by_user(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  iVar3 = 0;
  do {
    iVar2 = (*(code *)PTR_sk_num_006a6e2c)(*param_1);
    if (iVar2 <= iVar3) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(*param_1,iVar3);
    iVar2 = (*(code *)PTR_strcmp_006a9b18)(*puVar1,param_2);
    iVar3 = iVar3 + 1;
  } while (iVar2 != 0);
  return puVar1;
}

