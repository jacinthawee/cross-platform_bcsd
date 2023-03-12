
void x509_name_ex_free(undefined4 *param_1)

{
  _STACK **ptr;
  
  if ((param_1 != (undefined4 *)0x0) && (ptr = (_STACK **)*param_1, ptr != (_STACK **)0x0)) {
    BUF_MEM_free((BUF_MEM *)ptr[2]);
    sk_pop_free(*ptr,X509_NAME_ENTRY_free + 1);
    if (ptr[3] != (_STACK *)0x0) {
      CRYPTO_free(ptr[3]);
    }
    CRYPTO_free(ptr);
    *param_1 = 0;
  }
  return;
}

