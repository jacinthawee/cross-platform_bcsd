
int SSL_CTX_set_ssl_version(SSL_CTX *ctx,SSL_METHOD *meth)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = meth->version;
  ctx->method = meth;
  if (iVar1 == 2) {
    pcVar2 = "SSLv2";
  }
  else {
    pcVar2 = "ALL:!aNULL:!eNULL:!SSLv2";
  }
  iVar1 = ssl_create_cipher_list(meth,&ctx->cipher_list,&ctx->cipher_list_by_id,pcVar2);
  if (iVar1 != 0) {
    iVar1 = (*(code *)PTR_sk_num_006a7f2c)(iVar1);
    if (0 < iVar1) {
      return 1;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xaa,0xe6,"ssl_lib.c",0x10d);
  return 0;
}

