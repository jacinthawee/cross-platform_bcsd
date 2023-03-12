
int SSL_CTX_set_ssl_version(SSL_CTX *ctx,SSL_METHOD *meth)

{
  _STACK *p_Var1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = meth->version;
  ctx->method = meth;
  pcVar2 = "ALL:!EXPORT:!LOW:!aNULL:!eNULL:!SSLv2";
  if (iVar3 == 2) {
    pcVar2 = "SSLv2";
  }
  p_Var1 = (_STACK *)ssl_create_cipher_list(meth,&ctx->cipher_list,&ctx->cipher_list_by_id,pcVar2);
  if ((p_Var1 != (_STACK *)0x0) && (iVar3 = sk_num(p_Var1), 0 < iVar3)) {
    return 1;
  }
  ERR_put_error(0x14,0xaa,0xe6,"ssl_lib.c",0x117);
  return 0;
}

