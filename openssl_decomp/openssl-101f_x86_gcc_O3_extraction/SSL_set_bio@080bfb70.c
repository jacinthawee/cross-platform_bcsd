
void SSL_set_bio(SSL *s,BIO *rbio,BIO *wbio)

{
  BIO *pBVar1;
  
  pBVar1 = s->bbio;
  if ((pBVar1 != (BIO *)0x0) && (pBVar1 == s->wbio)) {
    s->wbio = pBVar1->next_bio;
    pBVar1->next_bio = (bio_st *)0x0;
  }
  pBVar1 = s->rbio;
  if ((pBVar1 != (BIO *)0x0) && (pBVar1 != rbio)) {
    BIO_free_all(pBVar1);
  }
  pBVar1 = s->wbio;
  if (((pBVar1 != wbio) && (pBVar1 != (BIO *)0x0)) && (pBVar1 != s->rbio)) {
    BIO_free_all(pBVar1);
  }
  s->rbio = rbio;
  s->wbio = wbio;
  return;
}

