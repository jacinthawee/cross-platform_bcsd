
char * SSL_get_shared_ciphers(SSL *s,char *buf,int len)

{
  int iVar1;
  void *pvVar2;
  size_t __n;
  int iVar3;
  char *__dest;
  char *pcVar4;
  _STACK *p_Var5;
  
  if ((((s->session != (SSL_SESSION *)0x0) &&
       (p_Var5 = *(_STACK **)(s->session->krb5_client_princ + 0x2c), p_Var5 != (_STACK *)0x0)) &&
      (1 < len)) && (iVar1 = sk_num(p_Var5), iVar1 != 0)) {
    iVar1 = 0;
    __dest = buf;
    while( true ) {
      iVar3 = sk_num(p_Var5);
      if (iVar3 <= iVar1) {
        __dest[-1] = '\0';
        return buf;
      }
      pvVar2 = sk_value(p_Var5,iVar1);
      pcVar4 = *(char **)((int)pvVar2 + 4);
      __n = strlen(pcVar4);
      if (len <= (int)__n) break;
      memcpy(__dest,pcVar4,__n);
      pcVar4 = __dest + __n;
      __dest = pcVar4 + 1;
      len = len + ~__n;
      *pcVar4 = ':';
      iVar1 = iVar1 + 1;
    }
    if (__dest != buf) {
      __dest = __dest + -1;
    }
    *__dest = '\0';
    return buf;
  }
  return (char *)0x0;
}

