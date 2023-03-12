
int BIO_fd_should_retry(int i)

{
  int *piVar1;
  int iVar2;
  
  if (1 < i + 1U) {
    return 0;
  }
  piVar1 = (int *)(*(code *)PTR___errno_location_006a99e8)();
  iVar2 = *piVar1;
  if (iVar2 != 0x47) {
    if (iVar2 < 0x48) {
      if ((iVar2 != 4) && (iVar2 != 0xb)) {
        return 0;
      }
    }
    else if ((iVar2 != 0x86) && ((iVar2 < 0x86 || (1 < iVar2 - 0x95U)))) {
      return 0;
    }
  }
  return 1;
}

