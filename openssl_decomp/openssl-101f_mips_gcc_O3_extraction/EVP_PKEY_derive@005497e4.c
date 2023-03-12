
int EVP_PKEY_derive(EVP_PKEY_CTX *ctx,uchar *key,size_t *keylen)

{
  int iVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = *(int *)ctx, iVar1 == 0)) ||
     (UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x60), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
    ERR_put_error(6,0x99,0x96,"pmeth_fn.c",0x165);
    iVar1 = -2;
  }
  else if (*(int *)(ctx + 0x10) == 0x400) {
    if ((*(uint *)(iVar1 + 4) & 2) == 0) {
LAB_00549870:
                    /* WARNING: Could not recover jumptable at 0x00549878. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)(ctx);
      return iVar1;
    }
    uVar2 = EVP_PKEY_size(*(EVP_PKEY **)(ctx + 8));
    if (key == (uchar *)0x0) {
      *keylen = uVar2;
      iVar1 = 1;
    }
    else {
      if (uVar2 <= *keylen) {
        UNRECOVERED_JUMPTABLE = *(code **)(*(int *)ctx + 0x60);
        goto LAB_00549870;
      }
      ERR_put_error(6,0x99,0x9b,"pmeth_fn.c",0x16d);
      iVar1 = 0;
    }
  }
  else {
    ERR_put_error(6,0x99,0x97,"pmeth_fn.c",0x16a);
    iVar1 = -1;
  }
  return iVar1;
}

