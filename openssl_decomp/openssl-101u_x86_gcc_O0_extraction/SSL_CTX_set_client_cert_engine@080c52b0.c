
int __regparm1 SSL_CTX_set_client_cert_engine(SSL_CTX *ctx,ENGINE *e)

{
  int iVar1;
  ENGINE *e_00;
  bool bVar2;
  ENGINE *in_stack_00000008;
  
  iVar1 = ENGINE_init((ENGINE *)ctx);
  if (iVar1 != 0) {
    e_00 = (ENGINE *)ENGINE_get_ssl_client_cert_function(in_stack_00000008);
    bVar2 = e_00 == (ENGINE *)0x0;
    if (bVar2) {
      ERR_put_error(0x14,0x122,0x14b,"ssl_sess.c",0x4fd);
      ENGINE_finish(e_00);
    }
    else {
      *(ENGINE **)(e + 0xfc) = in_stack_00000008;
    }
    return (uint)!bVar2;
  }
  ERR_put_error(0x14,0x122,0x26,"ssl_sess.c",0x4f8);
  return 0;
}

