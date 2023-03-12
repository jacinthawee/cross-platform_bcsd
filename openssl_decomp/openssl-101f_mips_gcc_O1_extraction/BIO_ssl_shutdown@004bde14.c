
void BIO_ssl_shutdown(BIO *ssl_bio)

{
  if (ssl_bio != (BIO *)0x0) {
    if (ssl_bio->method->type == 0x207) {
LAB_004bde60:
                    /* WARNING: Load size is inaccurate */
      SSL_shutdown(*ssl_bio->ptr);
      return;
    }
    for (ssl_bio = ssl_bio->next_bio; ssl_bio != (BIO *)0x0; ssl_bio = ssl_bio->next_bio) {
      if (ssl_bio->method->type == 0x207) goto LAB_004bde60;
    }
  }
  return;
}

