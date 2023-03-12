
BN_BLINDING * BN_BLINDING_new(BIGNUM *A,BIGNUM *Ai,BIGNUM *mod)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x2c,"bn_blind.c",0x8f);
  if (piVar2 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(3,0x66,0x41,"bn_blind.c",0x91);
    return (BN_BLINDING *)0x0;
  }
  (*(code *)PTR_memset_006aab00)(piVar2,0,0x2c);
  if (A != (BIGNUM *)0x0) {
    iVar3 = (*(code *)PTR_BN_dup_006a9100)(A);
    *piVar2 = iVar3;
    if (iVar3 == 0) goto LAB_005f174c;
  }
  if (Ai == (BIGNUM *)0x0) {
LAB_005f16c8:
    iVar3 = (*(code *)PTR_BN_dup_006a9100)(mod);
    piVar2[3] = iVar3;
    if (iVar3 != 0) {
      if ((mod->flags & 4U) != 0) {
        *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) | 4;
      }
      puVar1 = PTR_CRYPTO_THREADID_current_006a95ac;
      piVar2[7] = -1;
      (*(code *)puVar1)(piVar2 + 5);
      return (BN_BLINDING *)piVar2;
    }
  }
  else {
    iVar3 = (*(code *)PTR_BN_dup_006a9100)(Ai);
    piVar2[1] = iVar3;
    if (iVar3 != 0) goto LAB_005f16c8;
  }
  if (*piVar2 != 0) {
    (*(code *)PTR_BN_free_006a811c)(*piVar2);
  }
LAB_005f174c:
  if (piVar2[1] != 0) {
    (*(code *)PTR_BN_free_006a811c)();
  }
  if (piVar2[2] != 0) {
    (*(code *)PTR_BN_free_006a811c)();
  }
  if (piVar2[3] != 0) {
    (*(code *)PTR_BN_free_006a811c)();
  }
  (*(code *)PTR_CRYPTO_free_006a7f88)(piVar2);
  return (BN_BLINDING *)0x0;
}

