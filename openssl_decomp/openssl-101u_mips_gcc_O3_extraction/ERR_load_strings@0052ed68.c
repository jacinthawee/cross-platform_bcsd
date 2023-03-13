
void ERR_load_strings(int lib,ERR_STRING_DATA *str)

{
  int iVar1;
  uint uVar2;
  ERR_STRING_DATA *pEVar3;
  
  ERR_load_ERR_strings();
  uVar2 = str->error;
  if (uVar2 != 0) {
    if (lib != 0) {
      do {
        iVar1 = err_fns;
        str->error = lib << 0x18 | uVar2;
        (**(code **)(iVar1 + 0xc))(str);
        uVar2 = str[1].error;
        str = str + 1;
      } while (uVar2 != 0);
      return;
    }
    do {
      pEVar3 = str + 1;
      (**(code **)(err_fns + 0xc))(str);
      str = pEVar3;
    } while (pEVar3->error != 0);
  }
  return;
}

