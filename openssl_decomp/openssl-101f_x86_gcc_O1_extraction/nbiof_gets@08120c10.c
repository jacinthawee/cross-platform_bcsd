
int nbiof_gets(int param_1,char *param_2,int param_3)

{
  int iVar1;
  
  if (*(BIO **)(param_1 + 0x24) != (BIO *)0x0) {
    iVar1 = BIO_gets(*(BIO **)(param_1 + 0x24),param_2,param_3);
    return iVar1;
  }
  return 0;
}

