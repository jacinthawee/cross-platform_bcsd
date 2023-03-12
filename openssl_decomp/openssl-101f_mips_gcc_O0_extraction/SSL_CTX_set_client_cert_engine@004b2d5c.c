
int SSL_CTX_set_client_cert_engine(SSL_CTX *ctx,ENGINE *e)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ENGINE_init_006a8e68)(e);
  if (iVar1 != 0) {
    iVar1 = (*(code *)PTR_ENGINE_get_ssl_client_cert_function_006a94c0)(e);
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x122,0x14b,"ssl_sess.c",0x472);
      (*(code *)PTR_ENGINE_finish_006a80c4)(e);
    }
    else {
      ctx->client_cert_engine = e;
    }
    return (uint)(iVar1 != 0);
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x122,0x26,"ssl_sess.c",0x46d);
  return 0;
}

