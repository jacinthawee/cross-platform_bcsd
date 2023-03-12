
int SSL_use_psk_identity_hint(SSL *s,char *identity_hint)

{
  uint uVar1;
  SSL_SESSION *pSVar2;
  SSL_SESSION *pSVar3;
  
  if (s == (SSL *)0x0) {
    return 0;
  }
  pSVar3 = s->session;
  if (pSVar3 == (SSL_SESSION *)0x0) {
    uVar1 = 1;
  }
  else {
    if (identity_hint == (char *)0x0) {
      if ((void *)pSVar3->krb5_client_princ_len == (void *)0x0) {
        pSVar3->krb5_client_princ_len = 0;
      }
      else {
        CRYPTO_free((void *)pSVar3->krb5_client_princ_len);
        s->session->krb5_client_princ_len = 0;
      }
      return 1;
    }
    uVar1 = (*(code *)PTR_strlen_006aab30)(identity_hint);
    if (0x80 < uVar1) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x111,0x92,"ssl_lib.c",0xc56);
      return 0;
    }
    if ((void *)pSVar3->krb5_client_princ_len != (void *)0x0) {
      CRYPTO_free((void *)pSVar3->krb5_client_princ_len);
      pSVar3 = s->session;
    }
    uVar1 = (*(code *)PTR_BUF_strdup_006a80dc)(identity_hint);
    pSVar2 = s->session;
    pSVar3->krb5_client_princ_len = uVar1;
    uVar1 = (uint)(pSVar2->krb5_client_princ_len != 0);
  }
  return uVar1;
}

