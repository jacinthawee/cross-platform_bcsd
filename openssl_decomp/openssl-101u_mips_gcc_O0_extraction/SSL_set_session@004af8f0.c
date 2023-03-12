
int SSL_set_session(SSL *to,SSL_SESSION *session)

{
  SSL_METHOD *method;
  int iVar1;
  SSL_SESSION *pSVar2;
  
  if (session == (SSL_SESSION *)0x0) {
    pSVar2 = to->session;
    if (pSVar2 != (SSL_SESSION *)0x0) {
      iVar1 = CRYPTO_add_lock((int *)(pSVar2->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c);
      if (iVar1 < 1) {
        SSL_SESSION_free_part_2(pSVar2);
      }
      to->session = (SSL_SESSION *)0x0;
    }
    if (*(SSL_METHOD **)to->psk_server_callback == to->method) {
      return 1;
    }
    iVar1 = SSL_set_ssl_method(to,*(SSL_METHOD **)to->psk_server_callback);
    return (uint)(iVar1 != 0);
  }
  method = (SSL_METHOD *)(**(code **)(*(int *)to->psk_server_callback + 0x5c))(session->ssl_version)
  ;
  if ((method == (SSL_METHOD *)0x0) &&
     (method = (*to->method->get_ssl_method)(session->ssl_version), method == (ssl_method_st *)0x0))
  {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xc3,0xf0,"ssl_sess.c",0x3aa);
    return 0;
  }
  if ((to->method != method) && (iVar1 = SSL_set_ssl_method(to,method), iVar1 == 0)) {
    return 0;
  }
  CRYPTO_add_lock((int *)(session->krb5_client_princ + 0x14),1,0xe,"ssl_sess.c",0x3be);
  pSVar2 = to->session;
  if ((pSVar2 == (SSL_SESSION *)0x0) ||
     (iVar1 = CRYPTO_add_lock((int *)(pSVar2->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c),
     0 < iVar1)) {
    iVar1 = *(int *)(session->krb5_client_princ + 0x10);
  }
  else {
    SSL_SESSION_free_part_2(pSVar2);
    iVar1 = *(int *)(session->krb5_client_princ + 0x10);
  }
  to->session = session;
  to->debug = iVar1;
  return 1;
}

