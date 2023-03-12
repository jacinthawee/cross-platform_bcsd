
char * SSL_get_cipher_list(SSL *s,int n)

{
  int iVar1;
  stack_st_SSL_CIPHER *psVar2;
  
  if (s == (SSL *)0x0) {
    return (char *)0x0;
  }
  psVar2 = s->cipher_list;
  if ((((psVar2 != (stack_st_SSL_CIPHER *)0x0) ||
       ((s->psk_server_callback != (_func_3154 *)0x0 &&
        (psVar2 = *(stack_st_SSL_CIPHER **)(s->psk_server_callback + 4),
        psVar2 != (stack_st_SSL_CIPHER *)0x0)))) &&
      (iVar1 = (*(code *)PTR_sk_num_006a7f2c)(psVar2), n < iVar1)) &&
     (iVar1 = (*(code *)PTR_sk_value_006a7f24)(psVar2,n), iVar1 != 0)) {
    return *(char **)(iVar1 + 4);
  }
  return (char *)0x0;
}

