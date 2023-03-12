
uint send_fp_chars(FILE *param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  uint uVar2;
  
  if (param_1 != (FILE *)0x0) {
    sVar1 = fwrite(param_2,1,param_3,param_1);
    uVar2 = count_leading_zeroes(param_3 - sVar1);
    return uVar2 >> 5;
  }
  return 1;
}

