
int EVP_PKEY_sign(EVP_PKEY_CTX *ctx,uchar *sig,size_t *siglen,uchar *tbs,size_t tbslen)

{
  int iVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = *(int *)ctx, iVar1 == 0)) ||
     (UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x28), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
    ERR_put_error(6,0x8c,0x96,"pmeth_fn.c",0x6a);
    iVar1 = -2;
  }
  else if (*(int *)(ctx + 0x10) == 8) {
    if ((*(uint *)(iVar1 + 4) & 2) == 0) {
LAB_00545a30:
                    /* WARNING: Could not recover jumptable at 0x00545a40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)(ctx,sig,siglen,tbs);
      return iVar1;
    }
    uVar2 = EVP_PKEY_size(*(EVP_PKEY **)(ctx + 8));
    if (sig == (uchar *)0x0) {
      *siglen = uVar2;
      iVar1 = 1;
    }
    else {
      if (uVar2 <= *siglen) {
        UNRECOVERED_JUMPTABLE = *(code **)(*(int *)ctx + 0x28);
        goto LAB_00545a30;
      }
      ERR_put_error(6,0x8c,0x9b,"pmeth_fn.c",0x71);
      iVar1 = 0;
    }
  }
  else {
    ERR_put_error(6,0x8c,0x97,"pmeth_fn.c",0x6e);
    iVar1 = -1;
  }
  return iVar1;
}

