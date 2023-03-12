
ulong BIO_number_read(BIO *bio)

{
  if (bio != (BIO *)0x0) {
    return bio->num_read;
  }
  return 0;
}

