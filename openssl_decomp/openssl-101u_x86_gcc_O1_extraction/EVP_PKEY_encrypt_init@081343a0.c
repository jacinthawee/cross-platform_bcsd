
int EVP_PKEY_encrypt_init(EVP_PKEY_CTX *ctx)

{
  code *pcVar1;
  int iVar2;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar2 = *(int *)ctx, iVar2 == 0)) ||
     (*(int *)(iVar2 + 0x50) == 0)) {
    ERR_put_error(6,0x8b,0x96,"pmeth_fn.c",0xbd);
    iVar2 = -2;
  }
  else {
    pcVar1 = *(code **)(iVar2 + 0x4c);
    *(undefined4 *)(ctx + 0x10) = 0x100;
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

