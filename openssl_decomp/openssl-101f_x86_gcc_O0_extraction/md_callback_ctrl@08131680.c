
long md_callback_ctrl(int param_1,int param_2,fp *param_3)

{
  long lVar1;
  
  if (*(BIO **)(param_1 + 0x24) != (BIO *)0x0) {
    lVar1 = BIO_callback_ctrl(*(BIO **)(param_1 + 0x24),param_2,param_3);
    return lVar1;
  }
  return 0;
}
