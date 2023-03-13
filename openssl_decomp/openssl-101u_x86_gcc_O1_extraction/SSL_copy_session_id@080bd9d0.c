
void SSL_copy_session_id(SSL *to,SSL *from)

{
  SSL_METHOD *pSVar1;
  cert_st *pcVar2;
  uint __n;
  SSL_SESSION *session;
  
  session = SSL_get_session(from);
  SSL_set_session(to,session);
  if (to->method != from->method) {
    (*to->method->ssl_free)(to);
    pSVar1 = from->method;
    to->method = pSVar1;
    (*pSVar1->ssl_new)(to);
  }
  pcVar2 = to->cert;
  if (from->cert == (cert_st *)0x0) {
    to->cert = (cert_st *)0x0;
  }
  else {
    CRYPTO_add_lock((int *)(from->cert + 0x90),1,0xd,"ssl_lib.c",0x377);
    to->cert = from->cert;
  }
  if (pcVar2 != (cert_st *)0x0) {
    ssl_cert_free(pcVar2);
  }
  __n = from->sid_ctx_length;
  if (__n < 0x21) {
    to->sid_ctx_length = __n;
    memcpy(to->sid_ctx,from->sid_ctx,__n);
    return;
  }
  ERR_put_error(0x14,0xda,0x111,"ssl_lib.c",0x1a1);
  return;
}

