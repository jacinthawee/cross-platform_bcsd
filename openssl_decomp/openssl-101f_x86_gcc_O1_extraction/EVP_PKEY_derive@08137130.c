
int EVP_PKEY_derive(EVP_PKEY_CTX *ctx,uchar *key,size_t *keylen)

{
  uint uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar2 = *(int *)ctx, iVar2 == 0)) ||
     (UNRECOVERED_JUMPTABLE = *(code **)(iVar2 + 0x60), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
    ERR_put_error(6,0x99,0x96,"pmeth_fn.c",0x165);
    iVar2 = -2;
  }
  else if (*(int *)(ctx + 0x10) == 0x400) {
    if ((*(byte *)(iVar2 + 4) & 2) == 0) {
LAB_08137186:
                    /* WARNING: Could not recover jumptable at 0x08137195. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (*UNRECOVERED_JUMPTABLE)();
      return iVar2;
    }
    uVar1 = EVP_PKEY_size(*(EVP_PKEY **)(ctx + 8));
    if (key == (uchar *)0x0) {
      *keylen = uVar1;
      iVar2 = 1;
    }
    else {
      if (uVar1 < *keylen || uVar1 == *keylen) {
        UNRECOVERED_JUMPTABLE = *(code **)(*(int *)ctx + 0x60);
        goto LAB_08137186;
      }
      ERR_put_error(6,0x99,0x9b,"pmeth_fn.c",0x16d);
      iVar2 = 0;
    }
  }
  else {
    ERR_put_error(6,0x99,0x97,"pmeth_fn.c",0x16a);
    iVar2 = -1;
  }
  return iVar2;
}

