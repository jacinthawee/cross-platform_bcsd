
int EVP_DigestSignInit(EVP_MD_CTX *ctx,EVP_PKEY_CTX **pctx,EVP_MD *type,ENGINE *e,EVP_PKEY *pkey)

{
  int *ctx_00;
  int iVar1;
  EVP_PKEY_CTX *ctx_01;
  char *name;
  int local_1c;
  
  ctx_00 = (int *)ctx->pctx;
  if (ctx_00 == (int *)0x0) {
    ctx_00 = (int *)EVP_PKEY_CTX_new(pkey,e);
    ctx->pctx = (EVP_PKEY_CTX *)ctx_00;
    if (ctx_00 == (int *)0x0) {
      return 0;
    }
  }
  if (type == (EVP_MD *)0x0) {
    iVar1 = EVP_PKEY_get_default_digest_nid(pkey,&local_1c);
    if (0 < iVar1) {
      name = OBJ_nid2sn(local_1c);
      type = EVP_get_digestbyname(name);
      if (type != (EVP_MD *)0x0) {
        ctx_00 = (int *)ctx->pctx;
        goto LAB_000af4ea;
      }
    }
    ERR_put_error(6,0xa1,0x9e,"m_sigver.c",0x53);
  }
  else {
LAB_000af4ea:
    if (*(code **)(*ctx_00 + 0x3c) == (code *)0x0) {
      iVar1 = EVP_PKEY_sign_init((EVP_PKEY_CTX *)ctx_00);
      if (iVar1 < 1) {
        return 0;
      }
      ctx_01 = ctx->pctx;
    }
    else {
      iVar1 = (**(code **)(*ctx_00 + 0x3c))(ctx_00,ctx);
      if (iVar1 < 1) {
        return 0;
      }
      ctx_01 = ctx->pctx;
      *(undefined4 *)(ctx_01 + 0x10) = 0x40;
    }
    iVar1 = EVP_PKEY_CTX_ctrl(ctx_01,-1,0xf8,1,0,type);
    if (0 < iVar1) {
      if (pctx != (EVP_PKEY_CTX **)0x0) {
        *pctx = ctx->pctx;
      }
      iVar1 = EVP_DigestInit_ex(ctx,type,e);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      return iVar1;
    }
  }
  return 0;
}

