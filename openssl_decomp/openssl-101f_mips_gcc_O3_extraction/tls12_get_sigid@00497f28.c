
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 tls12_get_sigid(int *param_1)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = *param_1;
  pcVar1 = "";
  if (iVar2 != ram0x0069fd60) {
    if (iVar2 != _DAT_0069fd68) {
      if (iVar2 != _DAT_0069fd70) {
        return 0xffffffff;
      }
      return _DAT_0069fd74;
    }
    pcVar1 = "";
  }
  return *(undefined4 *)(pcVar1 + 4);
}

