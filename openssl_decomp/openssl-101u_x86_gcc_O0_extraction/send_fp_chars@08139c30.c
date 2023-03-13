
bool send_fp_chars(FILE *param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  bool bVar2;
  
  bVar2 = true;
  if (param_1 != (FILE *)0x0) {
    sVar1 = fwrite(param_2,1,param_3,param_1);
    bVar2 = param_3 == sVar1;
  }
  return bVar2;
}

