
void BUF_MEM_free(BUF_MEM *a)

{
  if (a != (BUF_MEM *)0x0) {
    if (a->data != (char *)0x0) {
      memset(a->data,0,a->max);
      CRYPTO_free(a->data);
    }
    CRYPTO_free(a);
    return;
  }
  return;
}

