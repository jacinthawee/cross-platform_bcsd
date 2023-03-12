
void CONF_modules_unload(int all)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  while (iVar2 = (*(code *)PTR_sk_num_006a6e2c)(initialized_modules), 0 < iVar2) {
    piVar3 = (int *)(*(code *)PTR_sk_pop_006a8da4)(initialized_modules);
    iVar2 = *piVar3;
    if (*(code **)(iVar2 + 0xc) != (code *)0x0) {
      (**(code **)(iVar2 + 0xc))(piVar3);
      iVar2 = *piVar3;
    }
    puVar1 = PTR_CRYPTO_free_006a6e88;
    iVar4 = piVar3[1];
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + -1;
    (*(code *)puVar1)(iVar4);
    (*(code *)PTR_CRYPTO_free_006a6e88)(piVar3[2]);
    (*(code *)PTR_CRYPTO_free_006a6e88)(piVar3);
  }
  (*(code *)PTR_sk_free_006a6e80)(initialized_modules);
  initialized_modules = 0;
  iVar2 = (*(code *)PTR_sk_num_006a6e2c)(supported_modules);
  iVar2 = iVar2 + -1;
  if (-1 < iVar2) {
    if (all == 0) {
      do {
        piVar3 = (int *)(*(code *)PTR_sk_value_006a6e24)(supported_modules,iVar2);
        if ((piVar3[4] < 1) && (*piVar3 != 0)) {
          (*(code *)PTR_sk_delete_006a7288)(supported_modules,iVar2);
          if (*piVar3 != 0) {
            (*(code *)PTR_DSO_free_006a8874)();
          }
          (*(code *)PTR_CRYPTO_free_006a6e88)(piVar3[1]);
          (*(code *)PTR_CRYPTO_free_006a6e88)(piVar3);
        }
        iVar2 = iVar2 + -1;
      } while (iVar2 != -1);
    }
    else {
      do {
        piVar3 = (int *)(*(code *)PTR_sk_value_006a6e24)(supported_modules,iVar2);
        (*(code *)PTR_sk_delete_006a7288)(supported_modules,iVar2);
        if (*piVar3 != 0) {
          (*(code *)PTR_DSO_free_006a8874)(*piVar3);
        }
        iVar2 = iVar2 + -1;
        (*(code *)PTR_CRYPTO_free_006a6e88)(piVar3[1]);
        (*(code *)PTR_CRYPTO_free_006a6e88)(piVar3);
      } while (iVar2 != -1);
    }
  }
  iVar2 = (*(code *)PTR_sk_num_006a6e2c)(supported_modules);
  if (iVar2 == 0) {
    (*(code *)PTR_sk_free_006a6e80)(supported_modules);
    supported_modules = 0;
  }
  return;
}

