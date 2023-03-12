
int SSL_set_session(SSL *to,SSL_SESSION *session)

{
  SSL_METHOD *method;
  int iVar1;
  
  if (session == (SSL_SESSION *)0x0) {
    if (to->session != (SSL_SESSION *)0x0) {
      SSL_SESSION_free(to->session);
      to->session = (SSL_SESSION *)0x0;
    }
    if (to->method != *(SSL_METHOD **)to->psk_server_callback) {
      iVar1 = SSL_set_ssl_method(to,*(SSL_METHOD **)to->psk_server_callback);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      return iVar1;
    }
    method = (ssl_method_st *)0x1;
  }
  else {
    method = (SSL_METHOD *)
             (**(code **)(*(int *)to->psk_server_callback + 0x5c))(session->ssl_version);
    if ((method == (SSL_METHOD *)0x0) &&
       (method = (*to->method->get_ssl_method)(session->ssl_version), method == (ssl_method_st *)0x0
       )) {
      ERR_put_error(0x14,0xc3,0xf0,"ssl_sess.c",0x31d);
    }
    else if ((to->method == method) ||
            (method = (SSL_METHOD *)SSL_set_ssl_method(to,method), method != (ssl_method_st *)0x0))
    {
      CRYPTO_add_lock((int *)(session->krb5_client_princ + 0x14),1,0xe,"ssl_sess.c",0x333);
      if (to->session != (SSL_SESSION *)0x0) {
        SSL_SESSION_free(to->session);
      }
      iVar1 = *(int *)(session->krb5_client_princ + 0x10);
      method = (ssl_method_st *)0x1;
      to->session = session;
      to->debug = iVar1;
    }
  }
  return (int)method;
}

