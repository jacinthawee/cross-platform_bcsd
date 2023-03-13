
void CRYPTO_THREADID_set_pointer(CRYPTO_THREADID *id,void *ptr)

{
  id->ptr = ptr;
  id->val = (ulong)ptr;
  return;
}

