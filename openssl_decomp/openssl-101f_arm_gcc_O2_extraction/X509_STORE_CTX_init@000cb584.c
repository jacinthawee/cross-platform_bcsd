
int X509_STORE_CTX_init(X509_STORE_CTX *ctx,X509_STORE *store,X509 *x509,stack_st_X509 *chain)

{
  X509_VERIFY_PARAM *pXVar1;
  int iVar2;
  _func_1865 *p_Var3;
  _func_1866 *p_Var4;
  _func_1857 *p_Var5;
  _func_1856 *p_Var6;
  _func_1855 *p_Var7;
  _func_1859 *p_Var8;
  _func_1861 *p_Var9;
  _func_1862 *p_Var10;
  _func_1864 *p_Var11;
  X509_VERIFY_PARAM *pXVar12;
  
  ctx->cert = x509;
  ctx->untrusted = chain;
  ctx->ctx = store;
  ctx->current_method = 0;
  ctx->crls = (stack_st_X509_CRL *)0x0;
  ctx->last_untrusted = 0;
  ctx->other_ctx = (void *)0x0;
  ctx->valid = 0;
  ctx->chain = (stack_st_X509 *)0x0;
  ctx->error = 0;
  ctx->explicit_policy = 0;
  ctx->error_depth = 0;
  ctx->current_cert = (X509 *)0x0;
  ctx->current_issuer = (X509 *)0x0;
  ctx->current_crl = (X509_CRL *)0x0;
  ctx->current_crl_score = 0;
  ctx->current_reasons = 0;
  ctx->tree = (X509_POLICY_TREE *)0x0;
  ctx->parent = (X509_STORE_CTX *)0x0;
  pXVar1 = X509_VERIFY_PARAM_new();
  iVar2 = 0x7f3;
  ctx->param = pXVar1;
  if (pXVar1 == (X509_VERIFY_PARAM *)0x0) goto LAB_000cb5e2;
  if (store == (X509_STORE *)0x0) {
    pXVar1->inh_flags = pXVar1->inh_flags | 0x11;
    ctx->cleanup = (_func_1866 *)0x0;
    pXVar12 = X509_VERIFY_PARAM_lookup("default");
    iVar2 = X509_VERIFY_PARAM_inherit(pXVar1,pXVar12);
    if (iVar2 != 0) {
      ctx->get_crl = (_func_1860 *)0x0;
      ctx->check_issued = check_issued + 1;
      ctx->get_issuer = X509_STORE_CTX_get1_issuer + 1;
      ctx->verify_cb = null_callback + 1;
      ctx->verify = internal_verify + 1;
      ctx->check_revocation = check_revocation + 1;
      ctx->check_crl = check_crl + 1;
      ctx->cert_crl = cert_crl + 1;
      ctx->lookup_certs = X509_STORE_get1_certs + 1;
LAB_000cb672:
      p_Var3 = X509_STORE_get1_crls + 1;
LAB_000cb67a:
      ctx->lookup_crls = p_Var3;
      ctx->check_policy = check_policy + 1;
      iVar2 = CRYPTO_new_ex_data(5,ctx,&ctx->ex_data);
      if (iVar2 == 0) {
        CRYPTO_free(ctx);
        ERR_put_error(0xb,0x8f,0x41,"x509_vfy.c",0x850);
        return 0;
      }
      return 1;
    }
  }
  else {
    iVar2 = X509_VERIFY_PARAM_inherit(pXVar1,store->param);
    p_Var4 = (_func_1866 *)store->cleanup;
    ctx->verify_cb = (_func_1856 *)store->verify_cb;
    ctx->cleanup = p_Var4;
    if (iVar2 != 0) {
      pXVar12 = ctx->param;
      pXVar1 = X509_VERIFY_PARAM_lookup("default");
      iVar2 = X509_VERIFY_PARAM_inherit(pXVar12,pXVar1);
      if (iVar2 != 0) {
        if (store->check_issued == (_func_1846 *)0x0) {
          ctx->check_issued = check_issued + 1;
        }
        else {
          ctx->check_issued = (_func_1858 *)store->check_issued;
        }
        p_Var5 = (_func_1857 *)store->get_issuer;
        if (p_Var5 == (_func_1857 *)0x0) {
          p_Var5 = X509_STORE_CTX_get1_issuer + 1;
        }
        ctx->get_issuer = p_Var5;
        p_Var6 = (_func_1856 *)store->verify_cb;
        if (p_Var6 == (_func_1856 *)0x0) {
          p_Var6 = null_callback + 1;
        }
        ctx->verify_cb = p_Var6;
        p_Var7 = (_func_1855 *)store->verify;
        if (p_Var7 == (_func_1855 *)0x0) {
          p_Var7 = internal_verify + 1;
        }
        ctx->verify = p_Var7;
        p_Var8 = (_func_1859 *)store->check_revocation;
        if (p_Var8 == (_func_1859 *)0x0) {
          p_Var8 = check_revocation + 1;
        }
        ctx->check_revocation = p_Var8;
        p_Var9 = (_func_1861 *)store->check_crl;
        ctx->get_crl = (_func_1860 *)store->get_crl;
        if (p_Var9 == (_func_1861 *)0x0) {
          p_Var9 = check_crl + 1;
        }
        ctx->check_crl = p_Var9;
        p_Var10 = (_func_1862 *)store->cert_crl;
        if (p_Var10 == (_func_1862 *)0x0) {
          p_Var10 = cert_crl + 1;
        }
        ctx->cert_crl = p_Var10;
        p_Var11 = (_func_1864 *)store->lookup_certs;
        if (p_Var11 == (_func_1864 *)0x0) {
          p_Var11 = X509_STORE_get1_certs + 1;
        }
        p_Var3 = (_func_1865 *)store->lookup_crls;
        ctx->lookup_certs = p_Var11;
        if (p_Var3 != (_func_1865 *)0x0) goto LAB_000cb67a;
        goto LAB_000cb672;
      }
    }
  }
  iVar2 = 0x80f;
LAB_000cb5e2:
  ERR_put_error(0xb,0x8f,0x41,"x509_vfy.c",iVar2);
  return 0;
}

