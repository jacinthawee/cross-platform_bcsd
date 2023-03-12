
uint check_purpose_timestamp_sign(undefined4 param_1,X509 *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  X509_EXTENSION *ex;
  uint uVar3;
  
  uVar1 = param_2->ex_flags;
  uVar3 = uVar1 & 2;
  if (param_3 == 0) {
    if ((((uVar3 == 0) ||
         (((param_2->ex_kusage & 0xffffff3f) == 0 && ((param_2->ex_kusage & 0xc0) != 0)))) &&
        ((uVar1 & 4) != 0)) && (param_2->ex_xkusage == 0x40)) {
      iVar2 = X509_get_ext_by_NID(param_2,0x7e,-1);
      if (iVar2 < 0) {
        uVar1 = 1;
      }
      else {
        ex = X509_get_ext(param_2,iVar2);
        iVar2 = X509_EXTENSION_get_critical(ex);
        uVar1 = (uint)(iVar2 != 0);
      }
      return uVar1;
    }
  }
  else if ((uVar3 == 0) || ((param_2->ex_kusage & 4) != 0)) {
    if ((uVar1 & 1) != 0) {
      return (uVar1 << 0x1b) >> 0x1f;
    }
    if ((uVar1 & 0x60) == 0x60) {
      return 3;
    }
    if (uVar3 != 0) {
      return 4;
    }
    if ((uVar1 & 8) != 0) {
      uVar1 = 5;
      if ((param_2->ex_nscert & 7) == 0) {
        uVar1 = 0;
      }
      return uVar1;
    }
  }
  return 0;
}

