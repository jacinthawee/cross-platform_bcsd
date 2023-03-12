
void BIO_ssl_shutdown(BIO *ssl_bio)

{
  int iVar1;
  
  if (ssl_bio != (BIO *)0x0) {
    iVar1 = ssl_bio->method->type;
    while( true ) {
      if (iVar1 == 0x207) {
                    /* WARNING: Load size is inaccurate */
        SSL_shutdown(*ssl_bio->ptr);
        return;
      }
      ssl_bio = ssl_bio->next_bio;
      if (ssl_bio == (bio_st *)0x0) break;
      iVar1 = ssl_bio->method->type;
    }
  }
  return;
}

