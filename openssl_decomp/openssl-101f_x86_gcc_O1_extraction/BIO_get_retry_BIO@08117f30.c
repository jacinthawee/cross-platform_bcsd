
BIO * BIO_get_retry_BIO(BIO *bio,int *reason)

{
  bio_st **ppbVar1;
  BIO *pBVar2;
  
  pBVar2 = bio;
  do {
    if ((*(byte *)&pBVar2->flags & 8) == 0) break;
    ppbVar1 = &pBVar2->next_bio;
    bio = pBVar2;
    pBVar2 = *ppbVar1;
  } while (*ppbVar1 != (bio_st *)0x0);
  if (reason != (int *)0x0) {
    *reason = bio->retry_reason;
  }
  return bio;
}

