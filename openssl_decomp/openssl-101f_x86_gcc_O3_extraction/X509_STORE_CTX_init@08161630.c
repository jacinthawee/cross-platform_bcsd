
int X509_STORE_CTX_init(X509_STORE_CTX *ctx,X509_STORE *store,X509 *x509,stack_st_X509 *chain)

{
  X509_VERIFY_PARAM *pXVar1;
  int iVar2;
  code *pcVar3;
  _func_1862 *p_Var4;
  
  ctx->cert = x509;
  ctx->ctx = store;
  ctx->current_method = 0;
  ctx->crls = (stack_st_X509_CRL *)0x0;
  ctx->last_untrusted = 0;
  ctx->untrusted = chain;
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
  ctx->param = pXVar1;
  if (pXVar1 == (X509_VERIFY_PARAM *)0x0) {
    iVar2 = 0x7f3;
    goto LAB_081616fc;
  }
  if (store == (X509_STORE *)0x0) {
    pXVar1->inh_flags = pXVar1->inh_flags | 0x11;
    ctx->cleanup = (_func_1866 *)0x0;
    pXVar1 = X509_VERIFY_PARAM_lookup("default");
    iVar2 = X509_VERIFY_PARAM_inherit(ctx->param,pXVar1);
    if (iVar2 == 0) goto LAB_081616f4;
    ctx->check_issued = check_issued;
    ctx->get_issuer = X509_STORE_CTX_get1_issuer;
    ctx->verify_cb = null_callback;
    ctx->verify = internal_verify;
    ctx->check_revocation = check_revocation;
    ctx->get_crl = (_func_1860 *)0x0;
    ctx->check_crl = check_crl;
    ctx->cert_crl = cert_crl;
    ctx->lookup_certs = X509_STORE_get1_certs;
LAB_08161789:
    pcVar3 = X509_STORE_get1_crls;
LAB_0816178e:
    ctx->lookup_crls = pcVar3;
    ctx->check_policy = check_policy;
    iVar2 = CRYPTO_new_ex_data(5,ctx,&ctx->ex_data);
    if (iVar2 == 0) {
      CRYPTO_free(ctx);
      ERR_put_error(0xb,0x8f,0x41,"x509_vfy.c",0x850);
      return 0;
    }
    return 1;
  }
  iVar2 = X509_VERIFY_PARAM_inherit(pXVar1,store->param);
  ctx->verify_cb = (_func_1856 *)store->verify_cb;
  ctx->cleanup = (_func_1866 *)store->cleanup;
  if (iVar2 != 0) {
    pXVar1 = X509_VERIFY_PARAM_lookup("default");
    iVar2 = X509_VERIFY_PARAM_inherit(ctx->param,pXVar1);
    if (iVar2 != 0) {
      pcVar3 = store->check_issued;
      if (pcVar3 == (_func_1858 *)0x0) {
        pcVar3 = check_issued;
      }
      ctx->check_issued = pcVar3;
      pcVar3 = store->get_issuer;
      if (pcVar3 == (_func_1857 *)0x0) {
        pcVar3 = X509_STORE_CTX_get1_issuer;
      }
      ctx->get_issuer = pcVar3;
      pcVar3 = store->verify_cb;
      if (pcVar3 == (_func_1856 *)0x0) {
        pcVar3 = null_callback;
      }
      ctx->verify_cb = pcVar3;
      pcVar3 = store->verify;
      if (pcVar3 == (_func_1855 *)0x0) {
        pcVar3 = internal_verify;
      }
      ctx->verify = pcVar3;
      pcVar3 = store->check_revocation;
      if (pcVar3 == (_func_1859 *)0x0) {
        pcVar3 = check_revocation;
      }
      ctx->check_revocation = pcVar3;
      ctx->get_crl = (_func_1860 *)store->get_crl;
      if (store->check_crl == (_func_1849 *)0x0) {
        p_Var4 = (_func_1862 *)store->cert_crl;
        ctx->check_crl = check_crl;
        if (p_Var4 != (_func_1862 *)0x0) goto LAB_0816188f;
LAB_081618c0:
        ctx->cert_crl = cert_crl;
      }
      else {
        ctx->check_crl = (_func_1861 *)store->check_crl;
        p_Var4 = (_func_1862 *)store->cert_crl;
        if (p_Var4 == (_func_1862 *)0x0) goto LAB_081618c0;
LAB_0816188f:
        ctx->cert_crl = p_Var4;
      }
      if (store->lookup_certs == (_func_1851 *)0x0) {
        ctx->lookup_certs = X509_STORE_get1_certs;
      }
      else {
        ctx->lookup_certs = (_func_1864 *)store->lookup_certs;
      }
      pcVar3 = store->lookup_crls;
      if (pcVar3 != (_func_1865 *)0x0) goto LAB_0816178e;
      goto LAB_08161789;
    }
  }
LAB_081616f4:
  iVar2 = 0x80f;
LAB_081616fc:
  ERR_put_error(0xb,0x8f,0x41,"x509_vfy.c",iVar2);
  return 0;
}

