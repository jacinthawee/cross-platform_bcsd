
char * SSL_get_shared_ciphers(SSL *s,char *buf,int len)

{
  _STACK *p_Var1;
  int iVar2;
  void *pvVar3;
  size_t __n;
  int iVar4;
  char *pcVar5;
  char *__dest;
  
  if (((s->session != (SSL_SESSION *)0x0) &&
      (p_Var1 = *(_STACK **)(s->session->krb5_client_princ + 0x2c), p_Var1 != (_STACK *)0x0)) &&
     (1 < len)) {
    iVar2 = sk_num(p_Var1);
    if (iVar2 != 0) {
      iVar2 = 0;
      __dest = buf;
      while( true ) {
        iVar4 = sk_num(p_Var1);
        if (iVar4 <= iVar2) {
          __dest[-1] = '\0';
          return buf;
        }
        pvVar3 = sk_value(p_Var1,iVar2);
        pcVar5 = *(char **)((int)pvVar3 + 4);
        __n = strlen(pcVar5);
        if (len <= (int)__n) break;
        iVar2 = iVar2 + 1;
        memcpy(__dest,pcVar5,__n);
        pcVar5 = __dest + __n;
        __dest = __dest + __n + 1;
        len = len - (__n + 1);
        *pcVar5 = ':';
      }
      pcVar5 = __dest + -1;
      if (__dest == buf) {
        pcVar5 = buf;
      }
      *pcVar5 = '\0';
      return buf;
    }
  }
  return (char *)0x0;
}

