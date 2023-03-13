
bool dlfcn_unload(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x67,0x43,"dso_dlfcn.c",0xd3);
    return false;
  }
  iVar1 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(param_1 + 4));
  if (0 < iVar1) {
    iVar1 = (*(code *)PTR_sk_pop_006a8da4)(*(undefined4 *)(param_1 + 4));
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x67,0x68,"dso_dlfcn.c",0xda);
      (*(code *)PTR_sk_push_006a6fa8)(*(undefined4 *)(param_1 + 4),0);
    }
    else {
      (*(code *)PTR_dlclose_006a9aac)(iVar1);
    }
    return iVar1 != 0;
  }
  return true;
}

