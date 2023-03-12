
BIO * BIO_next(BIO *b)

{
  if (b != (BIO *)0x0) {
    return b->next_bio;
  }
  return (BIO *)0x0;
}

