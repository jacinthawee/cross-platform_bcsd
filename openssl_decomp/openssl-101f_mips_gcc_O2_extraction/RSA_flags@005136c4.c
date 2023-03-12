
int RSA_flags(RSA *r)

{
  if (r != (RSA *)0x0) {
    return r->meth->flags;
  }
  return 0;
}

