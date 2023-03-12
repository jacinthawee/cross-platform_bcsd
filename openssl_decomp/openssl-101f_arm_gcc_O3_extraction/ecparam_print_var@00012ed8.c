
undefined4
ecparam_print_var(BIO *param_1,BIGNUM *param_2,undefined4 param_3,undefined4 param_4,uchar *param_5)

{
  int iVar1;
  int extraout_r1;
  int extraout_r1_00;
  int iVar2;
  
  BIO_printf(param_1,"static unsigned char %s_%d[] = {",param_3,param_4,param_4);
  if (param_2->top == 0) {
    BIO_printf(param_1,"\n\t0x00");
  }
  else {
    iVar1 = BN_bn2bin(param_2,param_5);
    for (iVar2 = 0; iVar2 < iVar1 + -1; iVar2 = iVar2 + 1) {
      __aeabi_idivmod(iVar2,0xc);
      if (extraout_r1 == 0) {
        BIO_printf(param_1,"\n\t");
      }
      BIO_printf(param_1,"0x%02X,",(uint)param_5[iVar2]);
    }
    __aeabi_idivmod(iVar2,0xc);
    if (extraout_r1_00 == 0) {
      BIO_printf(param_1,"\n\t");
    }
    BIO_printf(param_1,"0x%02X",(uint)param_5[iVar2]);
  }
  BIO_printf(param_1,"\n\t};\n\n");
  return 1;
}

