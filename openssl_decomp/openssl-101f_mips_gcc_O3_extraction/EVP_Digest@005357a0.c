
int EVP_Digest(void *data,size_t count,uchar *md,uint *size,EVP_MD *type,ENGINE *impl)

{
  undefined *puVar1;
  int iVar2;
  EVP_MD *pEVar3;
  EVP_MD_CTX *ctx;
  uint uVar4;
  EVP_MD_CTX local_44;
  EVP_MD_CTX *local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_44.digest = (EVP_MD *)0x0;
  local_44.engine = (ENGINE *)0x0;
  local_44.flags = 0;
  local_44.md_data = (void *)0x0;
  local_44.pctx = (EVP_PKEY_CTX *)0x0;
  local_44.update = (_func_1088 *)0x0;
  local_2c = *(EVP_MD_CTX **)PTR___stack_chk_guard_006aabf0;
  EVP_MD_CTX_set_flags(&local_44,1);
  iVar2 = EVP_DigestInit_ex(&local_44,type,impl);
  if (iVar2 == 0) {
LAB_00535840:
    uVar4 = 0;
  }
  else {
    iVar2 = (*local_44.update)(&local_44,data,count);
    if (iVar2 == 0) goto LAB_00535840;
    if (0x40 < (local_44.digest)->md_size) {
      (*(code *)PTR_OpenSSLDie_006a8d4c)("digest.c",0x10f,"ctx->digest->md_size <= EVP_MAX_MD_SIZE")
      ;
    }
    iVar2 = (*(local_44.digest)->final)(&local_44,md);
    if (size != (uint *)0x0) {
      *size = (local_44.digest)->md_size;
    }
    if ((local_44.digest)->cleanup != (_func_1082 *)0x0) {
      (*(local_44.digest)->cleanup)(&local_44);
      EVP_MD_CTX_set_flags(&local_44,2);
    }
    uVar4 = (uint)(iVar2 != 0);
    (*(code *)PTR_memset_006aab00)(local_44.md_data,0,(local_44.digest)->ctx_size);
  }
  if (local_44.digest != (EVP_MD *)0x0) {
    if ((local_44.digest)->cleanup != (_func_1082 *)0x0) {
      iVar2 = EVP_MD_CTX_test_flags(&local_44,2);
      if (iVar2 == 0) {
        (*(local_44.digest)->cleanup)(&local_44);
      }
      if (local_44.digest == (EVP_MD *)0x0) goto LAB_00535888;
    }
    if (((local_44.digest)->ctx_size != 0) && (local_44.md_data != (void *)0x0)) {
      iVar2 = EVP_MD_CTX_test_flags(&local_44,4);
      if (iVar2 == 0) {
        (*(code *)PTR_OPENSSL_cleanse_006a8174)(local_44.md_data,(local_44.digest)->ctx_size);
        (*(code *)PTR_CRYPTO_free_006a7f88)(local_44.md_data);
      }
    }
  }
LAB_00535888:
  if (local_44.pctx != (EVP_PKEY_CTX *)0x0) {
    EVP_PKEY_CTX_free(local_44.pctx);
  }
  if (local_44.engine != (ENGINE *)0x0) {
    ENGINE_finish(local_44.engine);
  }
  if (local_2c == *(EVP_MD_CTX **)puVar1) {
    return uVar4;
  }
  ctx = local_2c;
  iVar2 = (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (ctx == (EVP_MD_CTX *)0x0) {
    return iVar2;
  }
  pEVar3 = ctx->digest;
  if (pEVar3 != (EVP_MD *)0x0) {
    if (pEVar3->cleanup != (_func_1082 *)0x0) {
      iVar2 = EVP_MD_CTX_test_flags(ctx,2);
      if (iVar2 == 0) {
        (*ctx->digest->cleanup)(ctx);
      }
      pEVar3 = ctx->digest;
      if (pEVar3 == (EVP_MD *)0x0) goto LAB_00535a88;
    }
    if ((pEVar3->ctx_size != 0) && (ctx->md_data != (void *)0x0)) {
      iVar2 = EVP_MD_CTX_test_flags(ctx,4);
      if (iVar2 == 0) {
        (*(code *)PTR_OPENSSL_cleanse_006a8174)(ctx->md_data,ctx->digest->ctx_size);
        (*(code *)PTR_CRYPTO_free_006a7f88)(ctx->md_data);
      }
    }
  }
LAB_00535a88:
  if (ctx->pctx != (EVP_PKEY_CTX *)0x0) {
    EVP_PKEY_CTX_free(ctx->pctx);
  }
  if (ctx->engine != (ENGINE *)0x0) {
    ENGINE_finish(ctx->engine);
  }
  (*(code *)PTR_memset_006aab00)(ctx,0,0x18);
                    /* WARNING: Could not recover jumptable at 0x00535ae0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(code *)PTR_CRYPTO_free_006a7f88)(ctx);
  return iVar2;
}

