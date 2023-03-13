
void EC_GROUP_clear_free(EC_GROUP *group)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  
  if (group != (EC_GROUP *)0x0) {
    pcVar3 = *(code **)(*(int *)group + 0x10);
    if ((pcVar3 == (code *)0x0) && (pcVar3 = *(code **)(*(int *)group + 0xc), pcVar3 == (code *)0x0)
       ) {
      piVar1 = *(int **)(group + 0x44);
    }
    else {
      (*pcVar3)();
      piVar1 = *(int **)(group + 0x44);
    }
    while (piVar1 != (int *)0x0) {
      iVar2 = *piVar1;
      (*(code *)piVar1[4])(piVar1[1]);
      (*(code *)PTR_CRYPTO_free_006a6e88)(piVar1);
      piVar1 = (int *)iVar2;
    }
    piVar1 = *(int **)(group + 4);
    *(undefined4 *)(group + 0x44) = 0;
    if (piVar1 != (int *)0x0) {
      pcVar3 = *(code **)(*piVar1 + 0x30);
      if ((pcVar3 != (code *)0x0) || (pcVar3 = *(code **)(*piVar1 + 0x2c), pcVar3 != (code *)0x0)) {
        (*pcVar3)(piVar1);
      }
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(piVar1,0x44);
      (*(code *)PTR_CRYPTO_free_006a6e88)(piVar1);
    }
    BN_clear_free((BIGNUM *)(group + 8));
    BN_clear_free((BIGNUM *)(group + 0x1c));
    if (*(int *)(group + 0x3c) != 0) {
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(*(int *)(group + 0x3c),*(undefined4 *)(group + 0x40));
      (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(group + 0x3c));
    }
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(group,0xac);
                    /* WARNING: Could not recover jumptable at 0x00500f10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(group);
    return;
  }
  return;
}

