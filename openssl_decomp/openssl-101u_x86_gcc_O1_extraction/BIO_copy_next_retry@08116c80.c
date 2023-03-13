
void BIO_copy_next_retry(BIO *b)

{
  b->flags = b->flags | b->next_bio->flags & 0xfU;
  b->retry_reason = b->next_bio->retry_reason;
  return;
}

