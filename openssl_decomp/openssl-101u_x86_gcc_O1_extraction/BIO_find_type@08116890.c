
BIO * BIO_find_type(BIO *b,int bio_type)

{
  if (b == (BIO *)0x0) {
    b = (BIO *)0x0;
  }
  else if ((char)bio_type == '\0') {
    while ((b->method == (BIO_METHOD *)0x0 || ((b->method->type & bio_type) == 0))) {
      b = b->next_bio;
      if (b == (BIO *)0x0) {
        return b;
      }
    }
  }
  else {
    while ((b->method == (BIO_METHOD *)0x0 || (bio_type != b->method->type))) {
      b = b->next_bio;
      if (b == (BIO *)0x0) {
        return b;
      }
    }
  }
  return b;
}

