
void SSL_set_bio(SSL *s,BIO *rbio,BIO *wbio)

{
  BIO *pBVar1;
  
  pBVar1 = s->bbio;
  if ((pBVar1 != (BIO *)0x0) && (pBVar1 == s->wbio)) {
    s->wbio = pBVar1->next_bio;
    pBVar1->next_bio = (bio_st *)0x0;
  }
  if ((s->rbio != (BIO *)0x0) && (s->rbio != rbio)) {
    (*(code *)PTR_BIO_free_all_006a7f74)();
  }
  pBVar1 = s->wbio;
  if (((pBVar1 != (BIO *)0x0) && (pBVar1 != wbio)) && (pBVar1 != s->rbio)) {
    (*(code *)PTR_BIO_free_all_006a7f74)();
  }
  s->rbio = rbio;
  s->wbio = wbio;
  return;
}

