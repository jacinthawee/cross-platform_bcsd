
stack_st_X509 * SSL_get_peer_cert_chain(SSL *s)

{
  stack_st_X509 **ppsVar1;
  
  if (((s != (SSL *)0x0) && (s->session != (SSL_SESSION *)0x0)) &&
     (ppsVar1 = *(stack_st_X509 ***)(s->session->krb5_client_princ + 8),
     ppsVar1 != (stack_st_X509 **)0x0)) {
    return *ppsVar1;
  }
  return (stack_st_X509 *)0x0;
}

