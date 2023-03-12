
int HMAC_Init(HMAC_CTX *ctx,void *key,int len,EVP_MD *md)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  uchar *puVar4;
  undefined4 uVar5;
  HMAC_CTX *pHVar6;
  HMAC_CTX **ppHVar7;
  HMAC_CTX **ppHVar8;
  uchar *puVar9;
  EVP_MD_CTX *pEVar10;
  HMAC_CTX *local_a4 [32];
  HMAC_CTX *local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(HMAC_CTX **)PTR___stack_chk_guard_006a9ae8;
  if (key == (void *)0x0) {
    pHVar6 = ctx;
    if (md == (EVP_MD *)0x0) goto LAB_004d2278;
    if (md != ctx->md) goto LAB_004d2014;
  }
  else {
    if (md == (EVP_MD *)0x0) {
      md = ctx->md;
      if (md == (EVP_MD *)0x0) {
        uVar3 = 0;
        goto LAB_004d2018;
      }
    }
    else {
      (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(&ctx->i_ctx);
      (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(&ctx->o_ctx);
      (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(&ctx->md_ctx);
      if (len < 0) {
        ctx->md = (EVP_MD *)0x0;
        goto LAB_004d2014;
      }
      ctx->md = md;
    }
    iVar2 = (*(code *)PTR_EVP_MD_block_size_006a84c0)(md);
    if (iVar2 < 0x81) {
      if (iVar2 < len) goto LAB_004d204c;
LAB_004d2008:
      if (0x80 < (uint)len) goto LAB_004d2014;
      (*(code *)PTR_memcpy_006a9aec)(ctx->key,key,len);
      ctx->key_length = len;
    }
    else {
      OpenSSLDie("hmac.c",0x6a,"j <= (int)sizeof(ctx->key)");
      if (len <= iVar2) goto LAB_004d2008;
LAB_004d204c:
      pEVar10 = &ctx->md_ctx;
      iVar2 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(pEVar10,md,0);
      if (((iVar2 == 0) ||
          (iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(pEVar10,key,len), iVar2 == 0)) ||
         (iVar2 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(pEVar10,ctx->key,&ctx->key_length),
         iVar2 == 0)) goto LAB_004d2014;
      len = ctx->key_length;
    }
    if (len != 0x80) {
      (*(code *)PTR_memset_006a99f4)(ctx->key + len,0,0x80 - len);
    }
  }
  puVar9 = ctx->key;
  puVar4 = puVar9;
  ppHVar7 = local_a4;
  do {
    uVar3 = *(uint *)puVar4;
    puVar4 = puVar4 + 4;
    *ppHVar7 = (HMAC_CTX *)(uVar3 ^ 0x36363636);
    ppHVar7 = ppHVar7 + 1;
  } while ((HMAC_CTX *)puVar4 != ctx + 1);
  pEVar10 = &ctx->i_ctx;
  iVar2 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(pEVar10,md,0);
  if (iVar2 != 0) {
    uVar5 = (*(code *)PTR_EVP_MD_block_size_006a84c0)(md);
    iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(pEVar10,local_a4,uVar5);
    if (iVar2 != 0) {
      ppHVar7 = local_a4;
      do {
        uVar3 = *(uint *)puVar9;
        ppHVar8 = ppHVar7 + 1;
        puVar9 = puVar9 + 4;
        *ppHVar7 = (HMAC_CTX *)(uVar3 ^ 0x5c5c5c5c);
        ppHVar7 = ppHVar8;
      } while (&local_24 != ppHVar8);
      iVar2 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(&ctx->o_ctx,md,0);
      if (iVar2 != 0) {
        uVar5 = (*(code *)PTR_EVP_MD_block_size_006a84c0)(md);
        iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(&ctx->o_ctx,local_a4,uVar5);
        if (iVar2 != 0) goto LAB_004d221c;
      }
    }
  }
LAB_004d2014:
  do {
    uVar3 = 0;
LAB_004d2018:
    while( true ) {
      if (local_24 == *(HMAC_CTX **)puVar1) {
        return uVar3;
      }
      pHVar6 = local_24;
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004d2278:
      pEVar10 = &pHVar6->i_ctx;
      if (pHVar6->md == (EVP_MD *)0x0) break;
LAB_004d221c:
      iVar2 = (*(code *)PTR_EVP_MD_CTX_copy_ex_006a8104)(&ctx->md_ctx,pEVar10);
      uVar3 = (uint)(iVar2 != 0);
    }
  } while( true );
}

