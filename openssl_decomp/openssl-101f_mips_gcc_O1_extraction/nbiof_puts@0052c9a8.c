
int nbiof_puts(int param_1,char *param_2)

{
  int iVar1;
  
  if (*(BIO **)(param_1 + 0x24) != (BIO *)0x0) {
    iVar1 = BIO_puts(*(BIO **)(param_1 + 0x24),param_2);
    return iVar1;
  }
  return 0;
}

