
char * SSL_get_cipher_list(SSL *s,int n)

{
  int iVar1;
  void *pvVar2;
  _STACK *p_Var3;
  
  if ((s != (SSL *)0x0) &&
     ((p_Var3 = (_STACK *)s->cipher_list, p_Var3 != (_STACK *)0x0 ||
      ((s->psk_server_callback != (_func_3154 *)0x0 &&
       (p_Var3 = *(_STACK **)(s->psk_server_callback + 4), p_Var3 != (_STACK *)0x0)))))) {
    iVar1 = sk_num(p_Var3);
    if (n < iVar1) {
      pvVar2 = sk_value(p_Var3,n);
      if (pvVar2 != (void *)0x0) {
        return *(char **)((int)pvVar2 + 4);
      }
    }
  }
  return (char *)0x0;
}

