
void value_free_stack_LHASH_DOALL(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1[1] != 0) {
    return;
  }
  iVar3 = param_1[2];
  iVar1 = (*(code *)PTR_sk_num_006a7f2c)(iVar3);
  iVar2 = iVar1 + -1;
  if (-1 < iVar1 + -1) {
    do {
      iVar1 = iVar2 + -1;
      iVar2 = (*(code *)PTR_sk_value_006a7f24)(iVar3,iVar2);
      (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar2 + 8));
      (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar2 + 4));
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
      iVar2 = iVar1;
    } while (iVar1 != -1);
  }
  if (iVar3 != 0) {
    (*(code *)PTR_sk_free_006a7f80)(iVar3);
  }
  (*(code *)PTR_CRYPTO_free_006a7f88)(*param_1);
                    /* WARNING: Could not recover jumptable at 0x0059e330. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a7f88)(param_1);
  return;
}

