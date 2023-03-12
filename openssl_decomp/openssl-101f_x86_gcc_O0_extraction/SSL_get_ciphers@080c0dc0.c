
stack_st_SSL_CIPHER * SSL_get_ciphers(SSL *s)

{
  if (s == (SSL *)0x0) {
    return (stack_st_SSL_CIPHER *)0x0;
  }
  if ((s->cipher_list == (stack_st_SSL_CIPHER *)0x0) &&
     (s->psk_server_callback != (_func_3154 *)0x0)) {
    return *(stack_st_SSL_CIPHER **)(s->psk_server_callback + 4);
  }
  return s->cipher_list;
}

