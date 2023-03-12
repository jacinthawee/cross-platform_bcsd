
undefined4
bio_dump_callback(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = (*(code *)PTR_BIO_get_callback_arg_006a8d34)();
  if (iVar1 == 0) {
    return param_6;
  }
  if (param_2 == 0x82) {
    pcVar2 = "read from %p [%p] (%lu bytes => %ld (0x%lX))\n";
  }
  else {
    if (param_2 != 0x83) {
      return param_6;
    }
    pcVar2 = "write to %p [%p] (%lu bytes => %ld (0x%lX))\n";
  }
  (*(code *)PTR_BIO_printf_006a7f38)(iVar1,pcVar2,param_1,param_3,param_4,param_6,param_6);
  (*(code *)PTR_BIO_dump_006a8738)(iVar1,param_3,param_6);
  return param_6;
}

