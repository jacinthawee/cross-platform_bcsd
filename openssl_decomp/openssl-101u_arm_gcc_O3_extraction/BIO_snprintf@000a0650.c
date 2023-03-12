
int BIO_snprintf(char *buf,size_t n,char *format,...)

{
  int iVar1;
  undefined4 in_r3;
  char *local_20;
  size_t local_1c;
  uint local_18;
  int local_14;
  undefined4 uStack_4;
  
  local_20 = buf;
  local_1c = n;
  uStack_4 = in_r3;
  iVar1 = _dopr(&local_20,0,&local_1c,&local_18,&local_14,format,&uStack_4);
  if ((iVar1 == 0) || (local_14 != 0)) {
    local_18 = 0xffffffff;
  }
  else {
    local_18 = local_18 | (int)local_18 >> 0x1f;
  }
  return local_18;
}

