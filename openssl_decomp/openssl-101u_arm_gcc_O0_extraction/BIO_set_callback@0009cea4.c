
void BIO_set_callback(BIO *b,callback *callback)

{
  b->callback = (_func_603 *)callback;
  return;
}

