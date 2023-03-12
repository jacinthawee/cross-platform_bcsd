
int EVP_PKEY_encrypt_init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  code *pcVar2;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = *(int *)ctx, iVar1 == 0)) ||
     (*(int *)(iVar1 + 0x50) == 0)) {
    ERR_put_error(6,0x8b,0x96,"pmeth_fn.c",0xc6);
    iVar1 = -2;
  }
  else {
    pcVar2 = *(code **)(iVar1 + 0x4c);
    *(undefined4 *)(ctx + 0x10) = 0x100;
    if (pcVar2 == (code *)0x0) {
      return 1;
    }
    iVar1 = (*pcVar2)();
    if (iVar1 < 1) {
      *(undefined4 *)(ctx + 0x10) = 0;
      return iVar1;
    }
  }
  return iVar1;
}

