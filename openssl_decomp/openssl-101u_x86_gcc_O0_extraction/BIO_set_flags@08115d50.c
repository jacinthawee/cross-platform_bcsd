
void BIO_set_flags(BIO *b,int flags)

{
  b->flags = b->flags | flags;
  return;
}

