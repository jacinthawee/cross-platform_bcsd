
int EVP_DigestSignFinal(EVP_MD_CTX *ctx,uchar *sigret,size_t *siglen)

{
  bool bVar1;
  int iVar2;
  size_t tbslen;
  code *pcVar3;
  code *pcVar4;
  size_t local_80;
  EVP_MD_CTX EStack_7c;
  uchar auStack_64 [64];
  int local_24;
  
  local_24 = __TMC_END__;
  pcVar4 = *(code **)(*(int *)ctx->pctx + 0x40);
  pcVar3 = pcVar4;
  if (pcVar4 != (code *)0x0) {
    pcVar3 = (code *)0x1;
  }
  if (sigret == (uchar *)0x0) {
    if (pcVar3 == (code *)0x0) {
      tbslen = EVP_MD_size(ctx->digest);
      if (-1 < (int)tbslen) {
        iVar2 = EVP_PKEY_sign(ctx->pctx,(uchar *)0x0,siglen,(uchar *)0x0,tbslen);
        pcVar3 = (code *)(uint)(0 < iVar2);
      }
    }
    else {
      iVar2 = (*pcVar4)();
      pcVar3 = (code *)(uint)(0 < iVar2);
    }
    goto LAB_000b21cc;
  }
  EVP_MD_CTX_init(&EStack_7c);
  iVar2 = EVP_MD_CTX_copy_ex(&EStack_7c,ctx);
  if (iVar2 != 0) {
    if (pcVar3 == (code *)0x0) {
      pcVar4 = (code *)EVP_DigestFinal_ex(&EStack_7c,auStack_64,&local_80);
    }
    else {
      pcVar4 = (code *)(**(code **)(*(int *)EStack_7c.pctx + 0x40))
                                 (EStack_7c.pctx,sigret,siglen,&EStack_7c);
    }
    if (pcVar4 == (code *)0x0) {
      pcVar3 = (code *)((uint)pcVar3 | 1);
    }
    EVP_MD_CTX_cleanup(&EStack_7c);
    bVar1 = pcVar3 != (code *)0x0;
    pcVar3 = pcVar4;
    if (bVar1) goto LAB_000b21cc;
    iVar2 = EVP_PKEY_sign(ctx->pctx,sigret,siglen,auStack_64,local_80);
    if (0 < iVar2) {
      pcVar3 = (code *)0x1;
      goto LAB_000b21cc;
    }
  }
  pcVar3 = (code *)0x0;
LAB_000b21cc:
  if (local_24 != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)pcVar3;
}

