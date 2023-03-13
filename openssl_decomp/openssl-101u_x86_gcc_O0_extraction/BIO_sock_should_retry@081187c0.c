
int BIO_sock_should_retry(int i)

{
  int iVar1;
  int *piVar2;
  
  if (1 < i + 1U) {
    return 0;
  }
  piVar2 = __errno_location();
  iVar1 = *piVar2;
  if (iVar1 == 0x47) {
    return 1;
  }
  if (iVar1 < 0x48) {
    if (iVar1 == 4) {
      return 1;
    }
    if (iVar1 == 0xb) {
      return 1;
    }
  }
  else {
    if (iVar1 == 0x6b) {
      return 1;
    }
    if ((0x6a < iVar1) && (iVar1 - 0x72U < 2)) {
      return 1;
    }
  }
  return 0;
}

