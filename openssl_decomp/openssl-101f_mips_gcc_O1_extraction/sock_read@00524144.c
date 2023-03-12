
int sock_read(BIO *param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 0) {
    return 0;
  }
  piVar1 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
  *piVar1 = 0;
  iVar2 = (*(code *)PTR_read_006aac18)(param_1->num,param_2,param_3);
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
      if ((iVar3 == 4) || (iVar3 == 0xb)) goto LAB_0052422c;
    }
    else if ((iVar3 == 0x86) || ((0x85 < iVar3 && (iVar3 - 0x95U < 2)))) goto LAB_0052422c;
    return iVar2;
  }
LAB_0052422c:
  BIO_set_flags(param_1,9);
  return iVar2;
}

