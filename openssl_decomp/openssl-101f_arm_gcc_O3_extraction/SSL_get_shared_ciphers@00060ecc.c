
char * SSL_get_shared_ciphers(SSL *s,char *buf,int len)

{
  void *pvVar1;
  size_t __n;
  int iVar2;
  int iVar3;
  char *__dest;
  char *pcVar4;
  _STACK *p_Var5;
  
  if (s->session == (SSL_SESSION *)0x0) {
    return (char *)0x0;
  }
  p_Var5 = *(_STACK **)(s->session->krb5_client_princ + 0x2c);
  if (p_Var5 != (_STACK *)0x0) {
    if (len < 2) {
      return (char *)0x0;
    }
    iVar3 = 0;
    __dest = buf;
    while( true ) {
      iVar2 = sk_num(p_Var5);
      if (iVar2 <= iVar3) {
        __dest[-1] = '\0';
        return buf;
      }
      pvVar1 = sk_value(p_Var5,iVar3);
      pcVar4 = *(char **)((int)pvVar1 + 4);
      __n = strlen(pcVar4);
      if (len <= (int)__n) break;
      memcpy(__dest,pcVar4,__n);
      pcVar4 = __dest + __n;
      __dest = pcVar4 + 1;
      len = len + ~__n;
      *pcVar4 = ':';
      iVar3 = iVar3 + 1;
    }
    if (__dest != buf) {
      __dest = __dest + -1;
    }
    *__dest = '\0';
    return buf;
  }
  return (char *)0x0;
}

