
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 tls12_get_sigid(int *param_1)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = *param_1;
  pcVar1 = "";
  if (iVar2 != ram0x0069eb50) {
    if (iVar2 != _DAT_0069eb58) {
      if (iVar2 != _DAT_0069eb60) {
        return 0xffffffff;
      }
      return _DAT_0069eb64;
    }
    pcVar1 = "";
  }
  return *(undefined4 *)(pcVar1 + 4);
}

