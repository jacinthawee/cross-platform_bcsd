
ssize_t fd_write(BIO *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  int *piVar2;
  ssize_t sVar3;
  
  piVar2 = __errno_location();
  *piVar2 = 0;
  sVar3 = write(param_1->num,param_2,param_3);
  BIO_clear_flags(param_1,0xf);
  if (0 < sVar3) {
    return sVar3;
  }
  if (1 < sVar3 + 1U) {
    return sVar3;
  }
  iVar1 = *piVar2;
  if (iVar1 != 0x47) {
    if (iVar1 < 0x48) {
      if ((iVar1 == 4) || (iVar1 == 0xb)) goto LAB_08119250;
    }
    else if ((iVar1 == 0x6b) || ((0x6a < iVar1 && (iVar1 - 0x72U < 2)))) goto LAB_08119250;
    return sVar3;
  }
LAB_08119250:
  BIO_set_flags(param_1,10);
  return sVar3;
}

