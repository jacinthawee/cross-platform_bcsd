
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 tls12_get_sigandhash(undefined *param_1,int *param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  undefined1 *puVar3;
  
  if (param_3 == 0) {
    return 0;
  }
  iVar1 = (*(code *)PTR_EVP_MD_type_006a73cc)(param_3);
  puVar3 = tls12_md;
  if (iVar1 != tls12_md._0_4_) {
    if (iVar1 == tls12_md._8_4_) {
      puVar3 = (undefined1 *)0x69eb70;
    }
    else if (iVar1 == tls12_md._16_4_) {
      puVar3 = (undefined1 *)0x69eb78;
    }
    else if (iVar1 == tls12_md._24_4_) {
      puVar3 = (undefined1 *)0x69eb80;
    }
    else if (iVar1 == tls12_md._32_4_) {
      puVar3 = (undefined1 *)0x69eb88;
    }
    else {
      if (iVar1 != tls12_md._40_4_) {
        return 0;
      }
      puVar3 = (undefined1 *)0x69eb90;
    }
  }
  if (*(int *)(puVar3 + 4) != -1) {
    iVar1 = *param_2;
    pcVar2 = "";
    if (iVar1 != ram0x0069eb50) {
      if (iVar1 == _DAT_0069eb58) {
        pcVar2 = "";
      }
      else {
        if (iVar1 != _DAT_0069eb60) {
          return 0;
        }
        pcVar2 = "";
      }
    }
    iVar1 = *(int *)(pcVar2 + 4);
    if (iVar1 != -1) {
      *param_1 = (char)*(int *)(puVar3 + 4);
      param_1[1] = (char)iVar1;
      return 1;
    }
  }
  return 0;
}
