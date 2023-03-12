
undefined4 def_init_WIN32(undefined4 *param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_WIN32_method_000d7f70;
  if (param_1 != (undefined4 *)0x0) {
    param_1[2] = 0;
    param_1[1] = puVar1 + 0x28;
    *param_1 = puVar1;
    return 1;
  }
  return 0;
}

