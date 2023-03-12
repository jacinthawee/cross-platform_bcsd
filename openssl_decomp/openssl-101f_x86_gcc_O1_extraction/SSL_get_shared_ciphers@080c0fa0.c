
char * SSL_get_shared_ciphers(SSL *s,char *buf,int len)

{
  _STACK *p_Var1;
  void *pvVar2;
  size_t __n;
  int iVar3;
  char *pcVar4;
  char *__dest;
  int iVar5;
  
  if (((s->session == (SSL_SESSION *)0x0) ||
      (p_Var1 = *(_STACK **)(s->session->krb5_client_princ + 0x2c), p_Var1 == (_STACK *)0x0)) ||
     (len < 2)) {
    buf = (char *)0x0;
  }
  else {
    iVar5 = 0;
    __dest = buf;
    while( true ) {
      iVar3 = sk_num(p_Var1);
      if (iVar3 <= iVar5) break;
      pvVar2 = sk_value(p_Var1,iVar5);
      pcVar4 = *(char **)((int)pvVar2 + 4);
      __n = strlen(pcVar4);
      if (len <= (int)__n) {
        pcVar4 = __dest + -1;
        if (__dest == buf) {
          pcVar4 = buf;
        }
        *pcVar4 = '\0';
        return buf;
      }
      iVar5 = iVar5 + 1;
      memcpy(__dest,pcVar4,__n);
      pcVar4 = __dest + __n;
      __dest = __dest + __n + 1;
      len = len - (__n + 1);
      *pcVar4 = ':';
    }
    __dest[-1] = '\0';
  }
  return buf;
}

