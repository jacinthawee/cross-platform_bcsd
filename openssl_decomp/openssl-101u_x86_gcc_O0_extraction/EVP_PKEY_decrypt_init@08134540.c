
int EVP_PKEY_decrypt_init(EVP_PKEY_CTX *ctx)

{
  code *pcVar1;
  int iVar2;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar2 = *(int *)ctx, iVar2 == 0)) ||
     (*(int *)(iVar2 + 0x58) == 0)) {
    ERR_put_error(6,0x8a,0x96,"pmeth_fn.c",0xdf);
    iVar2 = -2;
  }
  else {
    pcVar1 = *(code **)(iVar2 + 0x54);
    *(undefined4 *)(ctx + 0x10) = 0x200;
    iVar2 = 1;
    if (pcVar1 != (code *)0x0) {
      iVar2 = (*pcVar1)(ctx);
      if (iVar2 < 1) {
        *(undefined4 *)(ctx + 0x10) = 0;
        return iVar2;
      }
    }
  }
  return iVar2;
}

