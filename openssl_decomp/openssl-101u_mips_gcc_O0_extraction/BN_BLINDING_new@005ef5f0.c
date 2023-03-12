
BN_BLINDING * BN_BLINDING_new(BIGNUM *A,BIGNUM *Ai,BIGNUM *mod)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x2c,"bn_blind.c",0x8d);
  if (piVar2 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x66,0x41,"bn_blind.c",0x8e);
    return (BN_BLINDING *)0x0;
  }
  (*(code *)PTR_memset_006a99f4)(piVar2,0,0x2c);
  if (A != (BIGNUM *)0x0) {
    iVar3 = (*(code *)PTR_BN_dup_006a8218)(A);
    *piVar2 = iVar3;
    if (iVar3 == 0) goto LAB_005ef71c;
  }
  if (Ai == (BIGNUM *)0x0) {
LAB_005ef698:
    iVar3 = (*(code *)PTR_BN_dup_006a8218)(mod);
    piVar2[3] = iVar3;
    if (iVar3 != 0) {
      if ((mod->flags & 4U) != 0) {
        *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) | 4;
      }
      puVar1 = PTR_CRYPTO_THREADID_current_006a848c;
      piVar2[7] = -1;
      (*(code *)puVar1)(piVar2 + 5);
      return (BN_BLINDING *)piVar2;
    }
  }
  else {
    iVar3 = (*(code *)PTR_BN_dup_006a8218)(Ai);
    piVar2[1] = iVar3;
    if (iVar3 != 0) goto LAB_005ef698;
  }
  if (*piVar2 != 0) {
    (*(code *)PTR_BN_free_006a701c)(*piVar2);
  }
LAB_005ef71c:
  if (piVar2[1] != 0) {
    (*(code *)PTR_BN_free_006a701c)();
  }
  if (piVar2[2] != 0) {
    (*(code *)PTR_BN_free_006a701c)();
  }
  if (piVar2[3] != 0) {
    (*(code *)PTR_BN_free_006a701c)();
  }
  (*(code *)PTR_CRYPTO_free_006a6e88)(piVar2);
  return (BN_BLINDING *)0x0;
}

