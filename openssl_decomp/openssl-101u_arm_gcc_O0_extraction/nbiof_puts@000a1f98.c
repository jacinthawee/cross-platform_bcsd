
void nbiof_puts(int param_1,char *param_2)

{
  if (*(BIO **)(param_1 + 0x24) != (BIO *)0x0) {
    BIO_puts(*(BIO **)(param_1 + 0x24),param_2);
    return;
  }
  return;
}

