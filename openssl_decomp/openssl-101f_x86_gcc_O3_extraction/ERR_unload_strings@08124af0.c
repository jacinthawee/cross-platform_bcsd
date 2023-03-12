
void ERR_unload_strings(int lib,ERR_STRING_DATA *str)

{
  uint uVar1;
  ERR_STRING_DATA *pEVar2;
  
  uVar1 = str->error;
  if (uVar1 != 0) {
    if (lib == 0) {
      do {
        pEVar2 = str + 1;
        (**(code **)(err_fns + 0x10))(str);
        str = pEVar2;
      } while (pEVar2->error != 0);
    }
    else {
      do {
        str->error = uVar1 | lib << 0x18;
        (**(code **)(err_fns + 0x10))(str);
        uVar1 = str[1].error;
        str = str + 1;
      } while (uVar1 != 0);
    }
  }
  return;
}

