
int set_name_ex(uint *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = set_multi_opts(param_1,param_2,PTR_ex_tbl_19523_00033d38);
  if (iVar1 != 0) {
    if ((*param_1 & 0xf0000) == 0) {
      *param_1 = *param_1 | 0x20000;
      return 1;
    }
    iVar1 = 1;
  }
  return iVar1;
}

