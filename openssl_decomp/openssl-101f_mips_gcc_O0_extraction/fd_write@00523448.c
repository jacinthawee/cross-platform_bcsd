
int fd_write(BIO *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
  *piVar1 = 0;
  iVar2 = (*(code *)PTR_write_006aab28)(param_1->num,param_2,param_3);
  BIO_clear_flags(param_1,0xf);
  if (0 < iVar2) {
    return iVar2;
  }
  if (1 < iVar2 + 1U) {
    return iVar2;
  }
  iVar3 = *piVar1;
  if (iVar3 != 0x47) {
    if (iVar3 < 0x48) {
      if ((iVar3 == 4) || (iVar3 == 0xb)) goto LAB_00523524;
    }
    else if ((iVar3 == 0x86) || ((0x85 < iVar3 && (iVar3 - 0x95U < 2)))) goto LAB_00523524;
    return iVar2;
  }
LAB_00523524:
  BIO_set_flags(param_1,10);
  return iVar2;
}

