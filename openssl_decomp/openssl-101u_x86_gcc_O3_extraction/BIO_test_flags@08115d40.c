
int BIO_test_flags(BIO *b,int flags)

{
  return flags & b->flags;
}

