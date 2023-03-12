
void BIO_copy_next_retry(BIO *b)

{
  int iVar1;
  
  iVar1 = b->next_bio->retry_reason;
  b->flags = b->flags | b->next_bio->flags & 0xfU;
  b->retry_reason = iVar1;
  return;
}

