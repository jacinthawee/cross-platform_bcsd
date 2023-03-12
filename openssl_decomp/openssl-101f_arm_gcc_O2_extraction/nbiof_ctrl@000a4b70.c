
long nbiof_ctrl(BIO *param_1,int param_2,long param_3,void *param_4)

{
  long lVar1;
  
  if (param_1->next_bio == (BIO *)0x0) {
    return 0;
  }
  if (param_2 != 0xc) {
    if (param_2 == 0x65) {
      BIO_clear_flags(param_1,0xf);
      lVar1 = BIO_ctrl(param_1->next_bio,0x65,param_3,param_4);
      BIO_copy_next_retry(param_1);
      return lVar1;
    }
    lVar1 = BIO_ctrl(param_1->next_bio,param_2,param_3,param_4);
    return lVar1;
  }
  return 0;
}

