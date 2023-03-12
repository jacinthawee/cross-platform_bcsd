
int SSL_set_ssl_method(SSL *s,SSL_METHOD *method)

{
  int iVar1;
  SSL_METHOD *pSVar2;
  uint uVar3;
  
  pSVar2 = s->method;
  if (pSVar2 == method) {
    iVar1 = 1;
  }
  else {
    uVar3 = 0xffffffff;
    if (s->handshake_func != (_func_3149 *)0x0) {
      uVar3 = count_leading_zeroes((int)s->handshake_func - (int)pSVar2->ssl_connect);
      uVar3 = uVar3 >> 5;
    }
    if (pSVar2->version == method->version) {
      s->method = method;
      iVar1 = 1;
    }
    else {
      (*pSVar2->ssl_free)(s);
      s->method = method;
      iVar1 = (*method->ssl_new)(s);
    }
    if (uVar3 == 1) {
      s->handshake_func = (_func_3149 *)method->ssl_connect;
      return iVar1;
    }
    if (uVar3 == 0) {
      s->handshake_func = (_func_3149 *)method->ssl_accept;
      return iVar1;
    }
  }
  return iVar1;
}

