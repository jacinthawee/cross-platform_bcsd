
int EVP_DigestSignFinal(EVP_MD_CTX *ctx,uchar *sigret,size_t *siglen)

{
  undefined *puVar1;
  int iVar2;
  EVP_MD_CTX *pEVar3;
  size_t tbslen;
  code *pcVar4;
  size_t local_80;
  EVP_MD_CTX EStack_7c;
  uchar auStack_64 [64];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar4 = *(code **)(*(int *)ctx->pctx + 0x40);
  if (pcVar4 == (code *)0x0) {
    if (sigret != (uchar *)0x0) goto LAB_00547160;
    tbslen = EVP_MD_size(ctx->digest);
    if (-1 < (int)tbslen) {
      iVar2 = EVP_PKEY_sign(ctx->pctx,(uchar *)0x0,siglen,(uchar *)0x0,tbslen);
      pEVar3 = (EVP_MD_CTX *)(uint)(0 < iVar2);
      goto LAB_00547090;
    }
  }
  else {
    if (sigret == (uchar *)0x0) {
      iVar2 = (*pcVar4)();
      pEVar3 = (EVP_MD_CTX *)(uint)(0 < iVar2);
      goto LAB_00547090;
    }
    EVP_MD_CTX_init(&EStack_7c);
    iVar2 = EVP_MD_CTX_copy_ex(&EStack_7c,ctx);
    if (iVar2 != 0) {
      pEVar3 = (EVP_MD_CTX *)
               (**(code **)(*(int *)EStack_7c.pctx + 0x40))(EStack_7c.pctx,sigret,siglen,&EStack_7c)
      ;
      EVP_MD_CTX_cleanup(&EStack_7c);
      ctx = pEVar3;
      goto LAB_00547090;
    }
  }
  do {
    pEVar3 = (EVP_MD_CTX *)0x0;
LAB_00547090:
    while( true ) {
      if (local_24 == *(int *)puVar1) {
        return (int)pEVar3;
      }
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00547160:
      EVP_MD_CTX_init(&EStack_7c);
      iVar2 = EVP_MD_CTX_copy_ex(&EStack_7c,ctx);
      if (iVar2 == 0) break;
      iVar2 = EVP_DigestFinal_ex(&EStack_7c,auStack_64,&local_80);
      EVP_MD_CTX_cleanup(&EStack_7c);
      if (iVar2 == 0) break;
      iVar2 = EVP_PKEY_sign(ctx->pctx,sigret,siglen,auStack_64,local_80);
      if (iVar2 < 1) break;
      pEVar3 = (EVP_MD_CTX *)0x1;
    }
  } while( true );
}

