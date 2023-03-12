
int SSL_CTX_use_psk_identity_hint(SSL_CTX *ctx,char *identity_hint)

{
  uint uVar1;
  char *pcVar2;
  
  if (identity_hint == (char *)0x0) {
    if (ctx->psk_identity_hint == (char *)0x0) {
      ctx->psk_identity_hint = (char *)0x0;
    }
    else {
      CRYPTO_free(ctx->psk_identity_hint);
      ctx->psk_identity_hint = (char *)0x0;
    }
    return 1;
  }
  uVar1 = (*(code *)PTR_strlen_006a9a24)(identity_hint);
  if (uVar1 < 0x81) {
    if (ctx->psk_identity_hint != (char *)0x0) {
      CRYPTO_free(ctx->psk_identity_hint);
    }
    pcVar2 = (char *)(*(code *)PTR_BUF_strdup_006a6fdc)(identity_hint);
    ctx->psk_identity_hint = pcVar2;
    return (uint)(pcVar2 != (char *)0x0);
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x110,0x92,"ssl_lib.c",0xc60);
  return 0;
}

