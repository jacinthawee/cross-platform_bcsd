
int fd_puts(BIO *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = (*(code *)PTR_strlen_006aab30)(param_2);
  piVar2 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
  *piVar2 = 0;
  iVar3 = (*(code *)PTR_write_006aab28)(param_1->num,param_2,uVar1);
  BIO_clear_flags(param_1,0xf);
  if (0 < iVar3) {
    return iVar3;
  }
  if (1 < iVar3 + 1U) {
    return iVar3;
  }
  iVar4 = *piVar2;
  if (iVar4 != 0x47) {
    if (iVar4 < 0x48) {
      if ((iVar4 == 4) || (iVar4 == 0xb)) goto LAB_00523408;
    }
    else if ((iVar4 == 0x86) || ((0x85 < iVar4 && (iVar4 - 0x95U < 2)))) goto LAB_00523408;
    return iVar3;
  }
LAB_00523408:
  BIO_set_flags(param_1,10);
  return iVar3;
}

