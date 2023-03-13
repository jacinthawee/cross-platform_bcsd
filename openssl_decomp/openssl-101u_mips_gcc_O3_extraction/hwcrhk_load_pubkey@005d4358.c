
int * hwcrhk_load_pubkey(void)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  piVar2 = (int *)hwcrhk_load_privkey();
  if (piVar2 == (int *)0x0) {
    return (int *)0x0;
  }
  if (*piVar2 != 6) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,0x6a,0x67,"e_chil.c",0x37c);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar2);
    return (int *)0x0;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,10,"e_chil.c",0x36e);
  iVar5 = piVar2[5];
  iVar3 = (*(code *)PTR_RSA_new_006a787c)();
  piVar2[5] = iVar3;
  puVar1 = PTR_CRYPTO_lock_006a8144;
  uVar4 = *(undefined4 *)(iVar5 + 0x14);
  *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar5 + 0x10);
  *(undefined4 *)(iVar3 + 0x14) = uVar4;
  *(undefined4 *)(iVar5 + 0x10) = 0;
  *(undefined4 *)(iVar5 + 0x14) = 0;
  (*(code *)puVar1)(10,10,"e_chil.c",0x375);
  (*(code *)PTR_RSA_free_006a7600)(iVar5);
  return piVar2;
}

