
int X509_STORE_CTX_init(X509_STORE_CTX *ctx,X509_STORE *store,X509 *x509,stack_st_X509 *chain)

{
  undefined *puVar1;
  X509_VERIFY_PARAM *pXVar2;
  int iVar3;
  undefined4 uVar4;
  _func_1865 *p_Var5;
  _func_1857 *p_Var6;
  code *pcVar7;
  _func_1864 *p_Var8;
  _func_1866 *p_Var9;
  _func_1860 *p_Var10;
  _func_1862 *p_Var11;
  X509_VERIFY_PARAM *pXVar12;
  
  ctx->ctx = store;
  ctx->current_method = 0;
  ctx->cert = x509;
  ctx->untrusted = chain;
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
  pXVar2 = X509_VERIFY_PARAM_new();
  ctx->param = pXVar2;
  if (pXVar2 == (X509_VERIFY_PARAM *)0x0) {
    uVar4 = 0x7f3;
    goto LAB_0057e3cc;
  }
  if (store == (X509_STORE *)0x0) {
    pXVar2->inh_flags = pXVar2->inh_flags | 0x11;
    ctx->cleanup = (_func_1866 *)0x0;
    pXVar12 = X509_VERIFY_PARAM_lookup("default");
    iVar3 = X509_VERIFY_PARAM_inherit(pXVar2,pXVar12);
    puVar1 = PTR_X509_STORE_CTX_get1_issuer_006aa03c;
    if (iVar3 != 0) {
      ctx->get_crl = (_func_1860 *)0x0;
      ctx->get_issuer = (_func_1857 *)puVar1;
      ctx->lookup_certs = (_func_1864 *)PTR_X509_STORE_get1_certs_006aa040;
      ctx->check_issued = check_issued;
      ctx->verify_cb = null_callback;
      ctx->verify = internal_verify;
      ctx->check_revocation = check_revocation;
      ctx->check_crl = check_crl;
      ctx->cert_crl = cert_crl;
      p_Var5 = (_func_1865 *)PTR_X509_STORE_get1_crls_006aa044;
      goto LAB_0057e498;
    }
  }
  else {
    iVar3 = X509_VERIFY_PARAM_inherit(pXVar2,store->param);
    p_Var9 = (_func_1866 *)store->cleanup;
    ctx->verify_cb = (_func_1856 *)store->verify_cb;
    ctx->cleanup = p_Var9;
    if (iVar3 != 0) {
      pXVar12 = ctx->param;
      pXVar2 = X509_VERIFY_PARAM_lookup("default");
      iVar3 = X509_VERIFY_PARAM_inherit(pXVar12,pXVar2);
      if (iVar3 != 0) {
        if (store->check_issued == (_func_1846 *)0x0) {
          ctx->check_issued = check_issued;
        }
        else {
          ctx->check_issued = (_func_1858 *)store->check_issued;
        }
        p_Var6 = (_func_1857 *)store->get_issuer;
        if (store->get_issuer == (_func_1845 *)0x0) {
          p_Var6 = (_func_1857 *)PTR_X509_STORE_CTX_get1_issuer_006aa03c;
        }
        ctx->get_issuer = p_Var6;
        pcVar7 = store->verify_cb;
        if (pcVar7 == (_func_1856 *)0x0) {
          pcVar7 = null_callback;
        }
        ctx->verify_cb = pcVar7;
        pcVar7 = store->verify;
        if (pcVar7 == (_func_1855 *)0x0) {
          pcVar7 = internal_verify;
        }
        ctx->verify = pcVar7;
        pcVar7 = store->check_revocation;
        if (pcVar7 == (_func_1859 *)0x0) {
          pcVar7 = check_revocation;
        }
        p_Var10 = (_func_1860 *)store->get_crl;
        ctx->check_revocation = pcVar7;
        pcVar7 = store->check_crl;
        ctx->get_crl = p_Var10;
        p_Var11 = (_func_1862 *)store->cert_crl;
        if (pcVar7 == (_func_1861 *)0x0) {
          pcVar7 = check_crl;
        }
        ctx->check_crl = pcVar7;
        if (p_Var11 == (_func_1862 *)0x0) {
          ctx->cert_crl = cert_crl;
          p_Var8 = (_func_1864 *)store->lookup_certs;
          if (p_Var8 == (_func_1864 *)0x0) goto LAB_0057e620;
LAB_0057e5f0:
          ctx->lookup_certs = p_Var8;
        }
        else {
          p_Var8 = (_func_1864 *)store->lookup_certs;
          ctx->cert_crl = p_Var11;
          if (p_Var8 != (_func_1864 *)0x0) goto LAB_0057e5f0;
LAB_0057e620:
          ctx->lookup_certs = (_func_1864 *)PTR_X509_STORE_get1_certs_006aa040;
        }
        p_Var5 = (_func_1865 *)store->lookup_crls;
        if (store->lookup_crls == (_func_1852 *)0x0) {
          p_Var5 = (_func_1865 *)PTR_X509_STORE_get1_crls_006aa044;
        }
LAB_0057e498:
        puVar1 = PTR_CRYPTO_new_ex_data_006a9430;
        ctx->lookup_crls = p_Var5;
        ctx->check_policy = check_policy;
        iVar3 = (*(code *)puVar1)(5,ctx,&ctx->ex_data);
        if (iVar3 != 0) {
          return 1;
        }
        (*(code *)PTR_CRYPTO_free_006a7f88)(ctx);
        (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x8f,0x41,"x509_vfy.c",0x850);
        return 0;
      }
    }
  }
  uVar4 = 0x80f;
LAB_0057e3cc:
  (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x8f,0x41,"x509_vfy.c",uVar4);
  return 0;
}

