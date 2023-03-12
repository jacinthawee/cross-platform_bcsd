
void X509_STORE_CTX_cleanup(X509_STORE_CTX *ctx)

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
  if (ctx->chain != (stack_st_X509 *)0x0) {
    (*(code *)PTR_sk_pop_free_006a8158)(ctx->chain,PTR_X509_free_006a7f90);
    ctx->chain = (stack_st_X509 *)0x0;
  }
  (*(code *)PTR_CRYPTO_free_ex_data_006a9414)(5,ctx,&ctx->ex_data);
  *(undefined *)&(ctx->ex_data).sk = 0;
  *(undefined *)((int)&(ctx->ex_data).sk + 1) = 0;
  *(undefined *)((int)&(ctx->ex_data).sk + 2) = 0;
  *(undefined *)((int)&(ctx->ex_data).sk + 3) = 0;
  *(undefined *)&(ctx->ex_data).dummy = 0;
  *(undefined *)((int)&(ctx->ex_data).dummy + 1) = 0;
  *(undefined *)((int)&(ctx->ex_data).dummy + 2) = 0;
  *(undefined *)((int)&(ctx->ex_data).dummy + 3) = 0;
  return;
}
