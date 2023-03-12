
bool asn1_print_fsname_isra_4(undefined4 param_1,int param_2,int param_3,int param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  
  if (0x14 < param_2) {
    do {
      iVar1 = (*(code *)PTR_BIO_write_006a7f14)(param_1,spaces_13935,0x14);
      param_2 = param_2 + -0x14;
      if (iVar1 != 0x14) {
        return false;
      }
    } while (0x14 < param_2);
  }
  iVar1 = (*(code *)PTR_BIO_write_006a7f14)(param_1,spaces_13935,param_2);
  if (iVar1 != param_2) {
    return false;
  }
  uVar2 = *param_5 & 0x40;
  if ((*param_5 & 0x100) == 0) {
    if (uVar2 == 0) {
      if (param_4 == 0) goto LAB_0060a8fc;
      if (param_3 != 0) {
        iVar1 = (*(code *)PTR_BIO_puts_006a8058)(param_1,param_3);
        if (iVar1 < 1) {
          return false;
        }
        iVar1 = (*(code *)PTR_BIO_printf_006a7f38)(param_1," (%s)",param_4);
        if (iVar1 < 1) {
          return false;
        }
        iVar1 = (*(code *)PTR_BIO_write_006a7f14)(param_1,": ",2);
        goto LAB_0060a8d0;
      }
    }
    else if (param_4 == 0) {
      return true;
    }
    iVar1 = (*(code *)PTR_BIO_puts_006a8058)(param_1,param_4);
  }
  else {
    if (uVar2 != 0) {
      return true;
    }
LAB_0060a8fc:
    if (param_3 == 0) {
      return true;
    }
    iVar1 = (*(code *)PTR_BIO_puts_006a8058)(param_1,param_3);
  }
  if (iVar1 < 1) {
    return false;
  }
  iVar1 = (*(code *)PTR_BIO_write_006a7f14)(param_1,": ",2);
LAB_0060a8d0:
  return iVar1 == 2;
}

