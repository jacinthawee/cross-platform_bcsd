
void long_print(BIO *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = *param_2;
  uStack_4 = param_4;
  BIO_vprintf(param_1,"%ld\n",&uStack_8);
  return;
}

