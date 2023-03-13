
void free_dir(int param_1)

{
  BUF_MEM **ptr;
  
  ptr = *(BUF_MEM ***)(param_1 + 0xc);
  if ((_STACK *)ptr[1] != (_STACK *)0x0) {
    sk_pop_free((_STACK *)ptr[1],by_dir_entry_free);
  }
  if (*ptr != (BUF_MEM *)0x0) {
    BUF_MEM_free(*ptr);
  }
  CRYPTO_free(ptr);
  return;
}

