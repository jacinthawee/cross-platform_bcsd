
void BIO_ssl_shutdown(BIO *ssl_bio)

{
  if (ssl_bio != (BIO *)0x0) {
    do {
      if (ssl_bio->method->type == 0x207) {
                    /* WARNING: Load size is inaccurate */
        SSL_shutdown(*ssl_bio->ptr);
        return;
      }
      ssl_bio = ssl_bio->next_bio;
    } while (ssl_bio != (bio_st *)0x0);
  }
  return;
}

