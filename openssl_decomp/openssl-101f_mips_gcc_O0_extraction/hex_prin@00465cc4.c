
void hex_prin(undefined4 param_1,undefined *param_2,int param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  
  if (0 < param_3) {
    puVar1 = param_2;
    do {
      puVar2 = puVar1 + 1;
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%02X ",*puVar1);
      puVar1 = puVar2;
    } while (puVar2 != param_2 + param_3);
  }
  return;
}

