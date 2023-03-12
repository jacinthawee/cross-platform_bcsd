
int SSL_CTX_use_psk_identity_hint(SSL_CTX *ctx,char *identity_hint)

{
  size_t sVar1;
  char *pcVar2;
  
  if (identity_hint == (char *)0x0) {
    if (ctx->psk_identity_hint != (char *)0x0) {
      CRYPTO_free(ctx->psk_identity_hint);
    }
    ctx->psk_identity_hint = (char *)0x0;
    return 1;
  }
  sVar1 = strlen(identity_hint);
  if (sVar1 < 0x81) {
    if (ctx->psk_identity_hint != (char *)0x0) {
      CRYPTO_free(ctx->psk_identity_hint);
    }
    pcVar2 = BUF_strdup(identity_hint);
    ctx->psk_identity_hint = pcVar2;
    return (uint)(pcVar2 != (char *)0x0);
  }
  ERR_put_error(0x14,0x110,0x92,"ssl_lib.c",0xc3c);
  return 0;
}

