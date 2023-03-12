
bool dlfcn_unload(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x25,0x67,0x43,"dso_dlfcn.c",0xd5);
    return false;
  }
  iVar1 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(param_1 + 4));
  if (0 < iVar1) {
    iVar1 = (*(code *)PTR_sk_pop_006a9ec4)(*(undefined4 *)(param_1 + 4));
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x25,0x67,0x68,"dso_dlfcn.c",0xdd);
      (*(code *)PTR_sk_push_006a80a8)(*(undefined4 *)(param_1 + 4),0);
    }
    else {
      (*(code *)PTR_dlclose_006aabb4)(iVar1);
    }
    return iVar1 != 0;
  }
  return true;
}

