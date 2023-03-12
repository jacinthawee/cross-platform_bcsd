
int SSL_use_psk_identity_hint(SSL *s,char *identity_hint)

{
  size_t sVar1;
  char *pcVar2;
  uint uVar3;
  SSL_SESSION *pSVar4;
  
  if (s == (SSL *)0x0) {
    return 0;
  }
  pSVar4 = s->session;
  if (pSVar4 == (SSL_SESSION *)0x0) {
    uVar3 = 1;
  }
  else {
    if (identity_hint == (char *)0x0) {
      if ((void *)pSVar4->krb5_client_princ_len != (void *)0x0) {
        CRYPTO_free((void *)pSVar4->krb5_client_princ_len);
        pSVar4 = s->session;
      }
      pSVar4->krb5_client_princ_len = 0;
      return 1;
    }
    sVar1 = strlen(identity_hint);
    if (0x80 < sVar1) {
      ERR_put_error(0x14,0x111,0x92,"ssl_lib.c",0xc56);
      return 0;
    }
    if ((void *)pSVar4->krb5_client_princ_len != (void *)0x0) {
      CRYPTO_free((void *)pSVar4->krb5_client_princ_len);
      pSVar4 = s->session;
    }
    pcVar2 = BUF_strdup(identity_hint);
    pSVar4->krb5_client_princ_len = (uint)pcVar2;
    uVar3 = (uint)(s->session->krb5_client_princ_len != 0);
  }
  return uVar3;
}

