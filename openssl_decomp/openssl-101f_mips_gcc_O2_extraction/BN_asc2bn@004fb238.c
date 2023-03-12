
int BN_asc2bn(BIGNUM **a,char *str)

{
  char cVar2;
  int iVar1;
  char *str_00;
  
  cVar2 = *str;
  str_00 = str;
  if (cVar2 == '-') {
    str_00 = str + 1;
    cVar2 = str[1];
  }
  if ((cVar2 == '0') && ((str_00[1] & 0xdfU) == 0x58)) {
    iVar1 = BN_hex2bn(a,str_00 + 2);
  }
  else {
    iVar1 = BN_dec2bn(a,str_00);
  }
  if (iVar1 != 0) {
    if (*str == '-') {
      (*a)->neg = 1;
      return 1;
    }
    return 1;
  }
  return 0;
}

