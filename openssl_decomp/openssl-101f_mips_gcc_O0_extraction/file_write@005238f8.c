
undefined4 file_write(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (((*(int *)(param_1 + 0xc) == 0) || (param_2 == 0)) ||
     (iVar1 = (*(code *)PTR_fwrite_006aab7c)(param_2,param_3,1,*(undefined4 *)(param_1 + 0x20),&_gp)
     , iVar1 == 0)) {
    param_3 = 0;
  }
  return param_3;
}

