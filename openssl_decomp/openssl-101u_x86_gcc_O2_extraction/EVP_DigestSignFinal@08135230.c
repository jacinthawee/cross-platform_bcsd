
int EVP_DigestSignFinal(EVP_MD_CTX *ctx,uchar *sigret,size_t *siglen)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  size_t tbslen;
  int in_GS_OFFSET;
  size_t local_7c;
  EVP_MD_CTX local_78;
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar1 = *(code **)(*(int *)ctx->pctx + 0x40);
  if (pcVar1 == (code *)0x0) {
    if (sigret == (uchar *)0x0) {
      tbslen = EVP_MD_size(ctx->digest);
      uVar3 = 0;
      if (-1 < (int)tbslen) {
        iVar2 = EVP_PKEY_sign(ctx->pctx,(uchar *)0x0,siglen,(uchar *)0x0,tbslen);
        uVar3 = (uint)(0 < iVar2);
      }
      goto LAB_08135287;
    }
    EVP_MD_CTX_init(&local_78);
    iVar2 = EVP_MD_CTX_copy_ex(&local_78,ctx);
    if (iVar2 != 0) {
      iVar2 = EVP_DigestFinal_ex(&local_78,local_60,&local_7c);
      EVP_MD_CTX_cleanup(&local_78);
      uVar3 = 0;
      if (iVar2 == 0) goto LAB_08135287;
      iVar2 = EVP_PKEY_sign(ctx->pctx,sigret,siglen,local_60,local_7c);
      uVar3 = 1;
      if (0 < iVar2) goto LAB_08135287;
    }
  }
  else {
    if (sigret == (uchar *)0x0) {
      iVar2 = (*pcVar1)(ctx->pctx,0,siglen,ctx);
      uVar3 = (uint)(0 < iVar2);
      goto LAB_08135287;
    }
    EVP_MD_CTX_init(&local_78);
    iVar2 = EVP_MD_CTX_copy_ex(&local_78,ctx);
    if (iVar2 != 0) {
      uVar3 = (**(code **)(*(int *)local_78.pctx + 0x40))(local_78.pctx,sigret,siglen,&local_78);
      EVP_MD_CTX_cleanup(&local_78);
      goto LAB_08135287;
    }
  }
  uVar3 = 0;
LAB_08135287:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}

