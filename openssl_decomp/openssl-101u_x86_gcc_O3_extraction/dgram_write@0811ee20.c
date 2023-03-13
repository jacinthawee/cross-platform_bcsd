
int dgram_write(BIO *param_1,void *param_2,size_t param_3)

{
  sockaddr *__addr;
  int iVar1;
  int *piVar2;
  socklen_t __addr_len;
  ssize_t sVar3;
  
  piVar2 = __errno_location();
  __addr = (sockaddr *)param_1->ptr;
  *piVar2 = 0;
  if (*(int *)(__addr[1].sa_data + 10) == 0) {
    __addr_len = 0x1c;
    if (__addr->sa_family == 2) {
      __addr_len = 0x10;
    }
    sVar3 = sendto(param_1->num,param_2,param_3,0,__addr,__addr_len);
  }
  else {
    sVar3 = write(param_1->num,param_2,param_3);
  }
  BIO_clear_flags(param_1,0xf);
  if (sVar3 < 1) {
    if (1 < sVar3 + 1U) {
      return sVar3;
    }
    iVar1 = *piVar2;
    if (iVar1 != 0x47) {
      if (iVar1 < 0x48) {
        if ((iVar1 != 4) && (iVar1 != 0xb)) {
          return sVar3;
        }
      }
      else if (1 < iVar1 - 0x72U) {
        return sVar3;
      }
    }
    BIO_set_flags(param_1,10);
    *(int *)(__addr + 2) = *piVar2;
    return sVar3;
  }
  return sVar3;
}

