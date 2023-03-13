
int SSL_CTX_set_ssl_version(SSL_CTX *ctx,SSL_METHOD *meth)

{
  _STACK *p_Var1;
  int iVar2;
  char *pcVar3;
  
  pcVar3 = "SSLv2";
  iVar2 = meth->version;
  ctx->method = meth;
  if (iVar2 != 2) {
    pcVar3 = "ALL:!EXPORT:!LOW:!aNULL:!eNULL:!SSLv2";
  }
  p_Var1 = (_STACK *)ssl_create_cipher_list(meth,&ctx->cipher_list,&ctx->cipher_list_by_id,pcVar3);
  if (p_Var1 != (_STACK *)0x0) {
    iVar2 = sk_num(p_Var1);
    if (0 < iVar2) {
      return 1;
    }
  }
  ERR_put_error(0x14,0xaa,0xe6,"ssl_lib.c",0x117);
  return 0;
}

