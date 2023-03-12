
undefined4 ssl_prepare_serverhello_tlsext(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  if ((((*(uint *)(iVar3 + 0xc) & 0xe0) != 0) || (*(int *)(iVar3 + 0x10) << 0x19 < 0)) &&
     (*(int *)(*(int *)(param_1 + 0xc0) + 0xd8) != 0)) {
    if (*(void **)(param_1 + 0x148) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0x148));
    }
    puVar1 = (undefined *)CRYPTO_malloc(3,"t1_lib.c",0x725);
    *(undefined **)(param_1 + 0x148) = puVar1;
    if (puVar1 == (undefined *)0x0) {
      ERR_put_error(0x14,0x11a,0x41,"t1_lib.c",0x727);
      uVar2 = 0xffffffff;
    }
    else {
      *(undefined4 *)(param_1 + 0x144) = 3;
      *puVar1 = 0;
      uVar2 = 1;
      *(undefined *)(*(int *)(param_1 + 0x148) + 1) = 1;
      *(undefined *)(*(int *)(param_1 + 0x148) + 2) = 2;
    }
    return uVar2;
  }
  return 1;
}

