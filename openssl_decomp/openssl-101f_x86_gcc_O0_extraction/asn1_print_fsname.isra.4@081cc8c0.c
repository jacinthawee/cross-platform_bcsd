
bool __regparm3
asn1_print_fsname_isra_4(BIO *param_1_00,int param_2_00,char *param_3,char *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  
  if (0x14 < param_2_00) {
    do {
      iVar2 = BIO_write(param_1_00,spaces_13915,0x14);
      if (iVar2 != 0x14) goto LAB_081cc8f0;
      param_2_00 = param_2_00 + -0x14;
    } while (0x14 < param_2_00);
  }
  iVar2 = BIO_write(param_1_00,spaces_13915,param_2_00);
  if (iVar2 == param_2_00) {
    uVar1 = *param_2;
    if ((uVar1 & 0x100) == 0) {
      if ((uVar1 & 0x40) == 0) {
        bVar3 = param_1 == (char *)0x0;
        goto LAB_081cc967;
      }
      if (param_1 == (char *)0x0) {
        return true;
      }
LAB_081cc937:
      iVar2 = BIO_puts(param_1_00,param_1);
joined_r0x081cc9b0:
      if (iVar2 < 1) goto LAB_081cc8f0;
    }
    else {
      if ((uVar1 & 0x40) != 0) {
        return true;
      }
      bVar3 = true;
      param_1 = (char *)0x0;
LAB_081cc967:
      if ((param_3 == (char *)0x0) && (bVar3)) {
        return true;
      }
      if (param_3 != (char *)0x0) {
        iVar2 = BIO_puts(param_1_00,param_3);
        if (iVar2 < 1) goto LAB_081cc8f0;
        if (param_1 == (char *)0x0) goto LAB_081cc9b6;
        iVar2 = BIO_printf(param_1_00," (%s)",param_1);
        goto joined_r0x081cc9b0;
      }
      if (param_1 != (char *)0x0) goto LAB_081cc937;
    }
LAB_081cc9b6:
    iVar2 = BIO_write(param_1_00,": ",2);
    bVar3 = iVar2 == 2;
  }
  else {
LAB_081cc8f0:
    bVar3 = false;
  }
  return bVar3;
}

