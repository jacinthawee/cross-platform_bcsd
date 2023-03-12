
void X509_STORE_CTX_free(X509_STORE_CTX *ctx)

{
  if (ctx->cleanup != (_func_1866 *)0x0) {
    (*ctx->cleanup)(ctx);
  }
  if (ctx->param != (X509_VERIFY_PARAM *)0x0) {
    if (ctx->parent == (X509_STORE_CTX *)0x0) {
      X509_VERIFY_PARAM_free(ctx->param);
    }
    ctx->param = (X509_VERIFY_PARAM *)0x0;
  }
  if (ctx->tree != (X509_POLICY_TREE *)0x0) {
    X509_policy_tree_free(ctx->tree);
    ctx->tree = (X509_POLICY_TREE *)0x0;
  }
  if ((_STACK *)ctx->chain != (_STACK *)0x0) {
    sk_pop_free((_STACK *)ctx->chain,X509_free);
    ctx->chain = (stack_st_X509 *)0x0;
  }
  CRYPTO_free_ex_data(5,ctx,&ctx->ex_data);
  (ctx->ex_data).sk = (stack_st_void *)0x0;
  (ctx->ex_data).dummy = 0;
  CRYPTO_free(ctx);
  return;
}

