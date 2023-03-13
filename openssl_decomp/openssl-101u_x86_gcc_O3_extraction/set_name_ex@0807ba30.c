
int set_name_ex(uint *param_1)

{
  int iVar1;
  
  iVar1 = set_multi_opts();
  if (iVar1 != 0) {
    iVar1 = 1;
    if ((*param_1 & 0xf0000) == 0) {
      *param_1 = *param_1 | 0x20000;
    }
  }
  return iVar1;
}

