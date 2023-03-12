
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CONF_modules_free(void)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  while( true ) {
    iVar3 = (*(code *)PTR_sk_num_006a6e2c)(initialized_modules);
    if (iVar3 < 1) break;
    piVar2 = (int *)(*(code *)PTR_sk_pop_006a8da4)(initialized_modules);
    iVar3 = *piVar2;
    if (*(code **)(iVar3 + 0xc) != (code *)0x0) {
      (**(code **)(iVar3 + 0xc))(piVar2);
      iVar3 = *piVar2;
    }
    puVar1 = PTR_CRYPTO_free_006a6e88;
    iVar4 = piVar2[1];
    *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + -1;
    (*(code *)puVar1)(iVar4);
    (*(code *)PTR_CRYPTO_free_006a6e88)(piVar2[2]);
    (*(code *)PTR_CRYPTO_free_006a6e88)(piVar2);
  }
  (*(code *)PTR_sk_free_006a6e80)(initialized_modules);
  initialized_modules = 0;
  CONF_modules_unload(1);
  return;
}

