
void X509V3_set_conf_lhash(X509V3_CTX *ctx,lhash_st_CONF_VALUE *lhash)

{
  undefined *puVar1;
  
  puVar1 = PTR_conf_lhash_method_000ce884;
  ctx->db = lhash;
  ctx->db_meth = (X509V3_CONF_METHOD *)puVar1;
  return;
}

