
void SSL_CTX_set_client_CA_list(SSL_CTX *ctx,stack_st_X509_NAME *name_list)

{
  if ((_STACK *)ctx->client_CA != (_STACK *)0x0) {
    sk_pop_free((_STACK *)ctx->client_CA,X509_NAME_free + 1);
  }
  ctx->client_CA = name_list;
  return;
}

