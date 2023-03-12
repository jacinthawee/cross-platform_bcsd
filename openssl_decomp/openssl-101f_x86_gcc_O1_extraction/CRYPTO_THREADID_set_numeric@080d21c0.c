
void CRYPTO_THREADID_set_numeric(CRYPTO_THREADID *id,ulong val)

{
  id->ptr = (void *)0x0;
  id->val = val;
  return;
}

