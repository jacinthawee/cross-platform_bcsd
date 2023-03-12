
int dgram_puts(BIO *param_1,char *param_2)

{
  size_t __n;
  int *piVar1;
  ssize_t sVar2;
  int iVar3;
  sockaddr *__addr;
  socklen_t __addr_len;
  
  __n = strlen(param_2);
  __addr = (sockaddr *)param_1->ptr;
  piVar1 = __errno_location();
  *piVar1 = 0;
  if (*(int *)(__addr[1].sa_data + 10) == 0) {
    if (__addr->sa_family == 2) {
      __addr_len = 0x10;
    }
    else {
      __addr_len = 0x1c;
    }
    sVar2 = sendto(param_1->num,param_2,__n,0,__addr,__addr_len);
  }
  else {
    sVar2 = write(param_1->num,param_2,__n);
  }
  BIO_clear_flags(param_1,0xf);
  if (sVar2 < 1) {
    if (1 < sVar2 + 1U) {
      return sVar2;
    }
    iVar3 = *piVar1;
    if (iVar3 != 0x47) {
      if (iVar3 < 0x48) {
        if ((iVar3 != 4) && (iVar3 != 0xb)) {
          return sVar2;
        }
      }
      else if (1 < iVar3 - 0x72U) {
        return sVar2;
      }
    }
    BIO_set_flags(param_1,10);
    *(int *)(__addr + 2) = *piVar1;
    return sVar2;
  }
  return sVar2;
}

