
void SSL_SESSION_free(SSL_SESSION *ses)

{
  int iVar1;
  
  if (ses != (SSL_SESSION *)0x0) {
    iVar1 = CRYPTO_add_lock((int *)(ses->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c);
    if (iVar1 < 1) {
      CRYPTO_free_ex_data(3,ses,(CRYPTO_EX_DATA *)(ses->krb5_client_princ + 0x30));
      OPENSSL_cleanse(ses->key_arg,8);
      OPENSSL_cleanse(ses->master_key,0x30);
      OPENSSL_cleanse(ses->session_id,0x20);
      if (*(int *)(ses->krb5_client_princ + 8) != 0) {
        ssl_sess_cert_free();
      }
      if (*(X509 **)(ses->krb5_client_princ + 0xc) != (X509 *)0x0) {
        X509_free(*(X509 **)(ses->krb5_client_princ + 0xc));
      }
      if (*(_STACK **)(ses->krb5_client_princ + 0x2c) != (_STACK *)0x0) {
        sk_free(*(_STACK **)(ses->krb5_client_princ + 0x2c));
      }
      if (*(void **)(ses->krb5_client_princ + 0x40) != (void *)0x0) {
        CRYPTO_free(*(void **)(ses->krb5_client_princ + 0x40));
      }
      if (*(void **)(ses->krb5_client_princ + 0x54) != (void *)0x0) {
        CRYPTO_free(*(void **)(ses->krb5_client_princ + 0x54));
      }
      *(undefined4 *)(ses->krb5_client_princ + 0x44) = 0;
      if (*(void **)(ses->krb5_client_princ + 0x48) != (void *)0x0) {
        CRYPTO_free(*(void **)(ses->krb5_client_princ + 0x48));
      }
      *(undefined4 *)(ses->krb5_client_princ + 0x4c) = 0;
      if (*(void **)(ses->krb5_client_princ + 0x50) != (void *)0x0) {
        CRYPTO_free(*(void **)(ses->krb5_client_princ + 0x50));
      }
      if ((void *)ses->krb5_client_princ_len != (void *)0x0) {
        CRYPTO_free((void *)ses->krb5_client_princ_len);
      }
      if (*(void **)ses->krb5_client_princ != (void *)0x0) {
        CRYPTO_free(*(void **)ses->krb5_client_princ);
      }
      if (*(void **)(ses->krb5_client_princ + 0x60) != (void *)0x0) {
        CRYPTO_free(*(void **)(ses->krb5_client_princ + 0x60));
      }
      OPENSSL_cleanse(ses,0xf4);
      CRYPTO_free(ses);
      return;
    }
  }
  return;
}

