
int SSL_set_ssl_method(SSL *s,SSL_METHOD *method)

{
  int iVar1;
  SSL_METHOD *pSVar2;
  uint uVar3;
  _func_3053 *p_Var4;
  
  pSVar2 = s->method;
  if (pSVar2 == method) {
    return 1;
  }
  if (s->handshake_func == (_func_3149 *)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = (uint)(s->handshake_func == (_func_3149 *)pSVar2->ssl_connect);
  }
  if (pSVar2->version == method->version) {
    s->method = method;
    iVar1 = 1;
  }
  else {
    (*pSVar2->ssl_free)(s);
    p_Var4 = method->ssl_new;
    s->method = method;
    iVar1 = (*p_Var4)(s);
  }
  if (uVar3 != 1) {
    if (uVar3 == 0) {
      s->handshake_func = (_func_3149 *)method->ssl_accept;
    }
    return iVar1;
  }
  s->handshake_func = (_func_3149 *)method->ssl_connect;
  return iVar1;
}

