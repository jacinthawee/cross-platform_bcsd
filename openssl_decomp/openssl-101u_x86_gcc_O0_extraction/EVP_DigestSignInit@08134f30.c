
int EVP_DigestSignInit(EVP_MD_CTX *ctx,EVP_PKEY_CTX **pctx,EVP_MD *type,ENGINE *e,EVP_PKEY *pkey)

{
  int iVar1;
  EVP_PKEY_CTX *ctx_00;
  uint uVar2;
  int *ctx_01;
  char *name;
  int in_GS_OFFSET;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ctx_01 = (int *)ctx->pctx;
  if (ctx_01 == (int *)0x0) {
    ctx_01 = (int *)EVP_PKEY_CTX_new(pkey,e);
    ctx->pctx = (EVP_PKEY_CTX *)ctx_01;
    if (ctx_01 == (int *)0x0) {
      uVar2 = 0;
      goto LAB_08134fce;
    }
  }
  if (type == (EVP_MD *)0x0) {
    iVar1 = EVP_PKEY_get_default_digest_nid(pkey,&local_24);
    if (0 < iVar1) {
      name = OBJ_nid2sn(local_24);
      type = EVP_get_digestbyname(name);
      if (type != (EVP_MD *)0x0) {
        ctx_01 = (int *)ctx->pctx;
        goto LAB_08134f6a;
      }
    }
    ERR_put_error(6,0xa1,0x9e,"m_sigver.c",0x53);
  }
  else {
LAB_08134f6a:
    if (*(code **)(*ctx_01 + 0x3c) == (code *)0x0) {
      iVar1 = EVP_PKEY_sign_init((EVP_PKEY_CTX *)ctx_01);
      if (0 < iVar1) {
        ctx_00 = ctx->pctx;
        goto LAB_08134f93;
      }
    }
    else {
      iVar1 = (**(code **)(*ctx_01 + 0x3c))(ctx_01,ctx);
      if (0 < iVar1) {
        ctx_00 = ctx->pctx;
        *(undefined4 *)(ctx_00 + 0x10) = 0x40;
LAB_08134f93:
        iVar1 = EVP_PKEY_CTX_ctrl(ctx_00,-1,0xf8,1,0,type);
        if (0 < iVar1) {
          if (pctx != (EVP_PKEY_CTX **)0x0) {
            *pctx = ctx->pctx;
          }
          iVar1 = EVP_DigestInit_ex(ctx,type,e);
          uVar2 = (uint)(iVar1 != 0);
          goto LAB_08134fce;
        }
      }
    }
  }
  uVar2 = 0;
LAB_08134fce:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

