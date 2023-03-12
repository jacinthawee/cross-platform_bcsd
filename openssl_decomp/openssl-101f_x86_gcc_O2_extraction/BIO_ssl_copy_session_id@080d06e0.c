
int BIO_ssl_copy_session_id(BIO *to,BIO *from)

{
  SSL *from_00;
  BIO *pBVar1;
  BIO *pBVar2;
  
  pBVar1 = BIO_find_type(to,0x207);
  pBVar2 = BIO_find_type(from,0x207);
                    /* WARNING: Load size is inaccurate */
  if (((pBVar1 != (BIO *)0x0) && (pBVar2 != (BIO *)0x0)) && (*pBVar1->ptr != (SSL *)0x0)) {
                    /* WARNING: Load size is inaccurate */
    from_00 = *pBVar2->ptr;
    if (from_00 != (SSL *)0x0) {
      SSL_copy_session_id(*pBVar1->ptr,from_00);
    }
    return (uint)(from_00 != (SSL *)0x0);
  }
  return 0;
}

