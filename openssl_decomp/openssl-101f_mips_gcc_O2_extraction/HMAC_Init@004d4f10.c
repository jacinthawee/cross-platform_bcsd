
int HMAC_Init(HMAC_CTX *ctx,void *key,int len,EVP_MD *md)

{
  undefined *puVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uchar *puVar7;
  EVP_MD_CTX *pEVar8;
  uchar *puVar9;
  uint local_ac [32];
  uint local_2c [2];
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c[0] = *(uint *)PTR___stack_chk_guard_006aabf0;
  if (key == (void *)0x0) {
    if (md != (EVP_MD *)0x0) {
      ctx->md = md;
      goto LAB_004d5014;
    }
LAB_004d513c:
    iVar2 = (*(code *)PTR_EVP_MD_CTX_copy_ex_006a922c)(&ctx->md_ctx,&ctx->i_ctx);
    uVar6 = (uint)(iVar2 != 0);
  }
  else {
    if (md == (EVP_MD *)0x0) {
      md = ctx->md;
    }
    else {
      (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(&ctx->i_ctx);
      (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(&ctx->o_ctx);
      (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(&ctx->md_ctx);
      ctx->md = md;
    }
    iVar2 = (*(code *)PTR_EVP_MD_block_size_006a95e0)(md);
    if (iVar2 < 0x81) {
      if (iVar2 < len) goto LAB_004d5158;
LAB_004d4fc0:
      if (0x80 < (uint)len) {
        OpenSSLDie("hmac.c",0x75,"len>=0 && len<=(int)sizeof(ctx->key)");
      }
      (*(code *)PTR_memcpy_006aabf4)(ctx->key,key,len);
      ctx->key_length = len;
LAB_004d4ff0:
      if (len != 0x80) {
        (*(code *)PTR_memset_006aab00)(ctx->key + len,0,0x80 - len);
      }
LAB_004d5014:
      puVar9 = ctx->key;
      puVar3 = local_ac;
      puVar7 = puVar9;
      do {
        uVar6 = *(uint *)puVar7;
        puVar4 = puVar3 + 1;
        puVar7 = puVar7 + 4;
        *puVar3 = uVar6 ^ 0x36363636;
        puVar3 = puVar4;
      } while (puVar4 != local_2c);
      iVar2 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(&ctx->i_ctx,md,0);
      if (iVar2 != 0) {
        uVar5 = (*(code *)PTR_EVP_MD_block_size_006a95e0)(md);
        iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(&ctx->i_ctx,local_ac,uVar5);
        puVar3 = local_ac;
        if (iVar2 != 0) {
          do {
            uVar6 = *(uint *)puVar9;
            puVar4 = puVar3 + 1;
            puVar9 = puVar9 + 4;
            *puVar3 = uVar6 ^ 0x5c5c5c5c;
            puVar3 = puVar4;
          } while (puVar4 != local_2c);
          iVar2 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(&ctx->o_ctx,md,0);
          if (iVar2 != 0) {
            uVar5 = (*(code *)PTR_EVP_MD_block_size_006a95e0)(md);
            iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(&ctx->o_ctx,local_ac,uVar5);
            if (iVar2 != 0) goto LAB_004d513c;
          }
        }
      }
    }
    else {
      OpenSSLDie("hmac.c",0x68,"j <= (int)sizeof(ctx->key)");
      if (len <= iVar2) goto LAB_004d4fc0;
LAB_004d5158:
      pEVar8 = &ctx->md_ctx;
      iVar2 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(pEVar8,md,0);
      if (((iVar2 != 0) &&
          (iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(pEVar8,key,len), iVar2 != 0)) &&
         (iVar2 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(pEVar8,ctx->key,&ctx->key_length),
         iVar2 != 0)) {
        len = ctx->key_length;
        goto LAB_004d4ff0;
      }
    }
    uVar6 = 0;
  }
  if (local_2c[0] != *(uint *)puVar1) {
    uVar6 = local_2c[0];
    (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x004d5244. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(uVar6 + 4);
    return iVar2;
  }
  return uVar6;
}

