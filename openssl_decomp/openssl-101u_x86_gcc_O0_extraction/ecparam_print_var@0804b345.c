
undefined4 __regparm3
ecparam_print_var(BIO *param_1_00,BIGNUM *param_2_00,undefined4 param_3,undefined4 param_1,
                 uchar *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 uVar3;
  undefined4 extraout_ECX_00;
  int extraout_EDX;
  int iVar4;
  
  iVar1 = BIO_printf(param_1_00,"static unsigned char %s_%d[] = {",param_3,param_1);
  if (param_2_00->top == 0) {
    iVar1 = BIO_printf(param_1_00,"\n\t0x00",iVar1,iVar1);
  }
  else {
    iVar1 = BN_bn2bin(param_2_00,param_2);
    uVar3 = extraout_ECX;
    for (iVar4 = 0; iVar4 < iVar1 + -1; iVar4 = iVar4 + 1) {
      iVar2 = iVar4 / 0xc;
      if (iVar4 % 0xc == 0) {
        iVar2 = BIO_printf(param_1_00,"\n\t",iVar2,iVar2);
      }
      BIO_printf(param_1_00,"0x%02X,",(uint)param_2[iVar4],iVar2);
      uVar3 = extraout_ECX_00;
    }
    iVar1 = iVar4 % 0xc;
    if (iVar1 == 0) {
      BIO_printf(param_1_00,"\n\t",uVar3,uVar3);
      iVar1 = extraout_EDX;
    }
    iVar1 = BIO_printf(param_1_00,"0x%02X",(uint)param_2[iVar4],iVar1);
  }
  BIO_printf(param_1_00,"\n\t};\n\n",iVar1,iVar1);
  return 1;
}

