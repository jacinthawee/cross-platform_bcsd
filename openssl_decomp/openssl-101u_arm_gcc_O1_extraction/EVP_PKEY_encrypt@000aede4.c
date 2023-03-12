
int EVP_PKEY_encrypt(EVP_PKEY_CTX *ctx,uchar *out,size_t *outlen,uchar *in,size_t inlen)

{
  int iVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = *(int *)ctx, iVar1 == 0)) ||
     (UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x50), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
    ERR_put_error(6,0x69,0x96,"pmeth_fn.c",0xcf);
    iVar1 = -2;
  }
  else if (*(int *)(ctx + 0x10) == 0x100) {
    if (-1 < *(int *)(iVar1 + 4) << 0x1e) {
LAB_000aee2c:
                    /* WARNING: Could not recover jumptable at 0x000aee3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)(ctx,out,outlen,in);
      return iVar1;
    }
    uVar2 = EVP_PKEY_size(*(EVP_PKEY **)(ctx + 8));
    if (out == (uchar *)0x0) {
      *outlen = uVar2;
      iVar1 = 1;
    }
    else {
      if (uVar2 <= *outlen) {
        UNRECOVERED_JUMPTABLE = *(code **)(*(int *)ctx + 0x50);
        goto LAB_000aee2c;
      }
      ERR_put_error(6,0x69,0x9b,"pmeth_fn.c",0xd6);
      iVar1 = 0;
    }
  }
  else {
    ERR_put_error(6,0x69,0x97,"pmeth_fn.c",0xd3);
    iVar1 = -1;
  }
  return iVar1;
}

