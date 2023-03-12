
uint check_purpose_timestamp_sign(undefined4 param_1,X509 *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  X509_EXTENSION *ex;
  
  uVar1 = param_2->ex_flags;
  if (param_3 == 0) {
    if ((uVar1 & 2) != 0) {
      if ((param_2->ex_kusage & 0xffffff3f) != 0) {
        return 0;
      }
      if ((param_2->ex_kusage & 0xc0) == 0) {
        return 0;
      }
    }
    uVar2 = 0;
    if (((uVar1 & 4) != 0) && (param_2->ex_xkusage == 0x40)) {
      iVar3 = X509_get_ext_by_NID(param_2,0x7e,0);
      uVar2 = 1;
      if (-1 < iVar3) {
        ex = X509_get_ext(param_2,iVar3);
        iVar3 = X509_EXTENSION_get_critical(ex);
        uVar2 = (uint)(iVar3 != 0);
      }
    }
  }
  else if (((uVar1 & 2) == 0) || (uVar2 = 0, (*(byte *)&param_2->ex_kusage & 4) != 0)) {
    if ((uVar1 & 1) != 0) {
      return uVar1 >> 4 & 1;
    }
    uVar2 = 3;
    if ((((uVar1 & 0x60) != 0x60) && (uVar2 = 4, (uVar1 & 2) == 0)) && (uVar2 = 0, (uVar1 & 8) != 0)
       ) {
      uVar2 = ~-(uint)((param_2->ex_nscert & 7) == 0) & 5;
    }
  }
  return uVar2;
}

