
void SSL_CTX_set_client_CA_list(SSL_CTX *ctx,stack_st_X509_NAME *name_list)

{
  undefined4 in_a2;
  undefined4 in_a3;
  
  if (ctx->client_CA != (stack_st_X509_NAME *)0x0) {
    (*(code *)PTR_sk_pop_free_006a8158)(ctx->client_CA,PTR_X509_NAME_free_006a80f8,in_a2,in_a3,&_gp)
    ;
  }
  ctx->client_CA = name_list;
  return;
}

