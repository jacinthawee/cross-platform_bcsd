
int SSL_set_session(SSL *to,SSL_SESSION *session)

{
  SSL_METHOD *method;
  int iVar1;
  
  if (session == (SSL_SESSION *)0x0) {
    if (to->session != (SSL_SESSION *)0x0) {
      iVar1 = CRYPTO_add_lock((int *)(to->session->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",
                              0x36c);
      if (iVar1 < 1) {
        SSL_SESSION_free_part_2();
      }
      to->session = (SSL_SESSION *)0x0;
    }
    if (*(SSL_METHOD **)to->psk_server_callback != to->method) {
      iVar1 = SSL_set_ssl_method(to,*(SSL_METHOD **)to->psk_server_callback);
      return (uint)(iVar1 != 0);
    }
  }
  else {
    method = (SSL_METHOD *)
             (**(code **)(*(int *)to->psk_server_callback + 0x5c))(session->ssl_version);
    if ((method == (SSL_METHOD *)0x0) &&
       (method = (*to->method->get_ssl_method)(session->ssl_version), method == (ssl_method_st *)0x0
       )) {
      ERR_put_error(0x14,0xc3,0xf0,"ssl_sess.c",0x3aa);
      return 0;
    }
    if ((to->method != method) && (iVar1 = SSL_set_ssl_method(to,method), iVar1 == 0)) {
      return 0;
    }
    CRYPTO_add_lock((int *)(session->krb5_client_princ + 0x14),1,0xe,"ssl_sess.c",0x3be);
    if ((to->session != (SSL_SESSION *)0x0) &&
       (iVar1 = CRYPTO_add_lock((int *)(to->session->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",
                                0x36c), iVar1 < 1)) {
      SSL_SESSION_free_part_2();
    }
    iVar1 = *(int *)(session->krb5_client_princ + 0x10);
    to->session = session;
    to->debug = iVar1;
  }
  return 1;
}

