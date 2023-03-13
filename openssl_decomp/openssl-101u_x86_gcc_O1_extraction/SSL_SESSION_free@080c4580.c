
void SSL_SESSION_free(SSL_SESSION *ses)

{
  int iVar1;
  
  if (ses != (SSL_SESSION *)0x0) {
    iVar1 = CRYPTO_add_lock((int *)(ses->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c);
    if (iVar1 < 1) {
      SSL_SESSION_free_part_2();
      return;
    }
  }
  return;
}

