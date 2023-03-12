
ulong BIO_number_written(BIO *bio)

{
  if (bio != (BIO *)0x0) {
    return bio->num_write;
  }
  return 0;
}

