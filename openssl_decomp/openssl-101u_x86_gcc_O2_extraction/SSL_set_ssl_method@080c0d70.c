
int SSL_set_ssl_method(SSL *s,SSL_METHOD *method)

{
  SSL_METHOD *pSVar1;
  int iVar2;
  uint uVar3;
  
  pSVar1 = s->method;
  if (pSVar1 == method) {
    return 1;
  }
  if (s->handshake_func == (_func_3149 *)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = (uint)(pSVar1->ssl_connect == (_func_3057 *)s->handshake_func);
  }
  if (pSVar1->version == method->version) {
    s->method = method;
    iVar2 = 1;
  }
  else {
    (*pSVar1->ssl_free)(s);
    s->method = method;
    iVar2 = (*method->ssl_new)(s);
  }
  if (uVar3 != 1) {
    if (uVar3 == 0) {
      s->handshake_func = (_func_3149 *)method->ssl_accept;
    }
    return iVar2;
  }
  s->handshake_func = (_func_3149 *)method->ssl_connect;
  return iVar2;
}

