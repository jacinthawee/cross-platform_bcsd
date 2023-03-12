
size_t null_puts(undefined4 param_1,char *param_2)

{
  size_t sVar1;
  
  if (param_2 != (char *)0x0) {
    sVar1 = strlen(param_2);
    return sVar1;
  }
  return 0;
}

