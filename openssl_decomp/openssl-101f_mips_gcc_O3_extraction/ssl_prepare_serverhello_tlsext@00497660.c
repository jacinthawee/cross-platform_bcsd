
undefined4 ssl_prepare_serverhello_tlsext(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  if ((((*(uint *)(iVar3 + 0xc) & 0xe0) != 0) || ((*(uint *)(iVar3 + 0x10) & 0x40) != 0)) &&
     (*(int *)(*(int *)(param_1 + 0xc0) + 0xd8) != 0)) {
    if (*(int *)(param_1 + 0x148) != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    puVar1 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(3,"t1_lib.c",0x731);
    *(undefined **)(param_1 + 0x148) = puVar1;
    if (puVar1 == (undefined *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x11a,0x41,"t1_lib.c",0x733);
      uVar2 = 0xffffffff;
    }
    else {
      *(undefined4 *)(param_1 + 0x144) = 3;
      uVar2 = 1;
      *puVar1 = 0;
      *(undefined *)(*(int *)(param_1 + 0x148) + 1) = 1;
      *(undefined *)(*(int *)(param_1 + 0x148) + 2) = 2;
    }
    return uVar2;
  }
  return 1;
}

