
stack_st_X509_NAME * SSL_get_client_CA_list(SSL *s)

{
  stack_st_X509_NAME *psVar1;
  
  if (s->type != 0x1000) {
    psVar1 = (stack_st_X509_NAME *)(s->ex_data).dummy;
    if (psVar1 != (stack_st_X509_NAME *)0x0) {
      return psVar1;
    }
    return *(stack_st_X509_NAME **)(s->psk_server_callback + 0xa0);
  }
  if ((s->version >> 8 == 3) && (s->s3 != (ssl3_state_st *)0x0)) {
    return (s->s3->tmp).ca_names;
  }
  return (stack_st_X509_NAME *)0x0;
}

