
void SSL_free(SSL *ssl)

{
  int iVar1;
  
  if ((ssl != (SSL *)0x0) &&
     (iVar1 = CRYPTO_add_lock((int *)&ssl->client_CA,-1,0x10,"ssl_lib.c",0x203), iVar1 < 1)) {
    SSL_free_part_7(ssl);
    return;
  }
  return;
}

