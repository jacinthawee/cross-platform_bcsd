
void X509_STORE_CTX_free(X509_STORE_CTX *ctx)

{
  if (ctx != (X509_STORE_CTX *)0x0) {
    if (ctx->cleanup != (_func_1866 *)0x0) {
      (*ctx->cleanup)(ctx);
      ctx->cleanup = (_func_1866 *)0x0;
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
      sk_pop_free((_STACK *)ctx->chain,X509_free + 1);
      ctx->chain = (stack_st_X509 *)0x0;
    }
    CRYPTO_free_ex_data(5,ctx,&ctx->ex_data);
    *(undefined *)&(ctx->ex_data).sk = 0;
    *(undefined *)((int)&(ctx->ex_data).sk + 1) = 0;
    *(undefined *)((int)&(ctx->ex_data).sk + 2) = 0;
    *(undefined *)((int)&(ctx->ex_data).sk + 3) = 0;
    *(undefined *)&(ctx->ex_data).dummy = 0;
    *(undefined *)((int)&(ctx->ex_data).dummy + 1) = 0;
    *(undefined *)((int)&(ctx->ex_data).dummy + 2) = 0;
    *(undefined *)((int)&(ctx->ex_data).dummy + 3) = 0;
    CRYPTO_free(ctx);
    return;
  }
  return;
}

