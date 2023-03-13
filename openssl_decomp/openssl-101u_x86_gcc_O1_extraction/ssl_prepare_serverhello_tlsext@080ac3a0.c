
undefined4 ssl_prepare_serverhello_tlsext(int param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  if ((((*(byte *)(iVar1 + 0xc) & 0xe0) != 0) || ((*(uint *)(iVar1 + 0x10) & 0x40) != 0)) &&
     (*(int *)(*(int *)(param_1 + 0xc0) + 0xd8) != 0)) {
    if (*(void **)(param_1 + 0x148) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0x148));
    }
    puVar2 = (undefined *)CRYPTO_malloc(3,"t1_lib.c",0x725);
    *(undefined **)(param_1 + 0x148) = puVar2;
    if (puVar2 == (undefined *)0x0) {
      ERR_put_error(0x14,0x11a,0x41,"t1_lib.c",0x727);
      uVar3 = 0xffffffff;
    }
    else {
      *(undefined4 *)(param_1 + 0x144) = 3;
      *puVar2 = 0;
      *(undefined *)(*(int *)(param_1 + 0x148) + 1) = 1;
      *(undefined *)(*(int *)(param_1 + 0x148) + 2) = 2;
      uVar3 = 1;
    }
    return uVar3;
  }
  return 1;
}

