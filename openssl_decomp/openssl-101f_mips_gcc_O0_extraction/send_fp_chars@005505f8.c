
bool send_fp_chars(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = (*(code *)PTR_fwrite_006aab7c)(param_2,1,param_3,param_1,&_gp);
    return param_3 == iVar1;
  }
  return true;
}

