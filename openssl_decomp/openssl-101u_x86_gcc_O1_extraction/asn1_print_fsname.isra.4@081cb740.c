
bool __regparm3
asn1_print_fsname_isra_4(BIO *param_1_00,int param_2_00,char *param_3,char *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  
  if (0x14 < param_2_00) {
    do {
      iVar2 = BIO_write(param_1_00,spaces_13925,0x14);
      if (iVar2 != 0x14) goto LAB_081cb770;
      param_2_00 = param_2_00 + -0x14;
    } while (0x14 < param_2_00);
  }
  iVar2 = BIO_write(param_1_00,spaces_13925,param_2_00);
  if (iVar2 == param_2_00) {
    uVar1 = *param_2;
    if ((uVar1 & 0x100) == 0) {
      if ((uVar1 & 0x40) == 0) {
        bVar3 = param_1 == (char *)0x0;
        goto LAB_081cb7e7;
      }
      if (param_1 == (char *)0x0) {
        return true;
      }
LAB_081cb7b7:
      iVar2 = BIO_puts(param_1_00,param_1);
joined_r0x081cb830:
      if (iVar2 < 1) goto LAB_081cb770;
    }
    else {
      if ((uVar1 & 0x40) != 0) {
        return true;
      }
      bVar3 = true;
      param_1 = (char *)0x0;
LAB_081cb7e7:
      if ((param_3 == (char *)0x0) && (bVar3)) {
        return true;
      }
      if (param_3 != (char *)0x0) {
        iVar2 = BIO_puts(param_1_00,param_3);
        if (iVar2 < 1) goto LAB_081cb770;
        if (param_1 == (char *)0x0) goto LAB_081cb836;
        iVar2 = BIO_printf(param_1_00," (%s)",param_1);
        goto joined_r0x081cb830;
      }
      if (param_1 != (char *)0x0) goto LAB_081cb7b7;
    }
LAB_081cb836:
    iVar2 = BIO_write(param_1_00,": ",2);
    bVar3 = iVar2 == 2;
  }
  else {
LAB_081cb770:
    bVar3 = false;
  }
  return bVar3;
}

