
uint asn1_print_fsname_isra_4(BIO *param_1,int param_2,char *param_3,char *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  
  while (0x14 < param_2) {
    param_2 = param_2 + -0x14;
    iVar1 = BIO_write(param_1,"                    ",0x14);
    if (iVar1 != 0x14) {
      return 0;
    }
  }
  iVar1 = BIO_write(param_1,"                    ",param_2);
  if (param_2 != iVar1) {
    return 0;
  }
  uVar2 = *param_5;
  if ((int)(uVar2 << 0x17) < 0) {
    param_4 = (char *)(uVar2 & 0x40);
    if (param_4 != (char *)0x0) {
      return 1;
    }
LAB_0010cf56:
    if (param_4 == (char *)0x0 && param_3 == (char *)0x0) {
      return 1;
    }
    if (param_3 == (char *)0x0) {
      if (param_4 == (char *)0x0) goto LAB_0010cf82;
      goto LAB_0010cfa4;
    }
    iVar1 = BIO_puts(param_1,param_3);
    if (iVar1 < 1) {
      return 0;
    }
    if (param_4 == (char *)0x0) goto LAB_0010cf82;
    iVar1 = BIO_printf(param_1," (%s)",param_4);
  }
  else {
    if (-1 < (int)(uVar2 << 0x19)) goto LAB_0010cf56;
    if (param_4 == (char *)0x0) {
      return 1;
    }
LAB_0010cfa4:
    iVar1 = BIO_puts(param_1,param_4);
  }
  if (iVar1 < 1) {
    return 0;
  }
LAB_0010cf82:
  iVar1 = BIO_write(param_1,": ",2);
  uVar2 = count_leading_zeroes(iVar1 + -2);
  return uVar2 >> 5;
}

