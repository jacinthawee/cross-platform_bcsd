
void EC_GROUP_free(EC_GROUP *group)

{
  int *piVar1;
  int iVar2;
  
  if (group == (EC_GROUP *)0x0) {
    return;
  }
  if (*(code **)(*(int *)group + 0xc) != (code *)0x0) {
    (**(code **)(*(int *)group + 0xc))();
  }
  piVar1 = (int *)*(int *)(group + 0x44);
  while (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    (*(code *)piVar1[3])(piVar1[1]);
    (*(code *)PTR_CRYPTO_free_006a7f88)(piVar1);
    piVar1 = (int *)iVar2;
  }
  piVar1 = *(int **)(group + 4);
  *(undefined4 *)(group + 0x44) = 0;
  if (piVar1 != (int *)0x0) {
    if (*(code **)(*piVar1 + 0x2c) != (code *)0x0) {
      (**(code **)(*piVar1 + 0x2c))(piVar1);
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(piVar1);
  }
  BN_free((BIGNUM *)(group + 8));
  BN_free((BIGNUM *)(group + 0x1c));
  if (*(int *)(group + 0x3c) != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
                    /* WARNING: Could not recover jumptable at 0x00503128. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a7f88)(group);
  return;
}

