
uint dlfcn_pathbyaddr(code *param_1,int param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_2c [4];
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_1 == (code *)0x0) {
    param_1 = dlfcn_pathbyaddr;
  }
  iVar2 = (*(code *)PTR_dladdr_006aaab4)(param_1,local_2c);
  if (iVar2 == 0) {
    uVar4 = (*(code *)PTR_dlerror_006aaba4)();
    (*(code *)PTR_ERR_add_error_data_006a9264)(4,"dlfcn_pathbyaddr(): ",uVar4);
    uVar3 = 0xffffffff;
  }
  else {
    iVar2 = (*(code *)PTR_strlen_006aab30)(local_2c[0]);
    if (param_3 < 1) {
      uVar3 = iVar2 + 1;
    }
    else {
      if (param_3 <= iVar2) {
        iVar2 = param_3 + -1;
      }
      (*(code *)PTR_memcpy_006aabf4)(param_2,local_2c[0],iVar2);
      uVar3 = iVar2 + 1;
      *(undefined *)(param_2 + iVar2) = 0;
    }
  }
  if (local_1c == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x25,0x67,0x43,"dso_dlfcn.c",0xd5);
    return 0;
  }
  iVar5 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(iVar2 + 4));
  if (0 < iVar5) {
    iVar5 = (*(code *)PTR_sk_pop_006a9ec4)(*(undefined4 *)(iVar2 + 4));
    if (iVar5 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x25,0x67,0x68,"dso_dlfcn.c",0xdd);
      (*(code *)PTR_sk_push_006a80a8)(*(undefined4 *)(iVar2 + 4),0);
    }
    else {
      (*(code *)PTR_dlclose_006aabb4)(iVar5);
    }
    return (uint)(iVar5 != 0);
  }
  return 1;
}

