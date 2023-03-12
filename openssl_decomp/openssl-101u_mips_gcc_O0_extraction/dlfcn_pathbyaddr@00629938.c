
uint dlfcn_pathbyaddr(code *param_1,int param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_2c [4];
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (param_1 == (code *)0x0) {
    param_1 = dlfcn_pathbyaddr;
  }
  iVar2 = (*(code *)PTR_dladdr_006a99a8)(param_1,local_2c);
  if (iVar2 == 0) {
    uVar4 = (*(code *)PTR_dlerror_006a9a9c)();
    (*(code *)PTR_ERR_add_error_data_006a813c)(2,"dlfcn_pathbyaddr(): ",uVar4);
    uVar3 = 0xffffffff;
  }
  else {
    iVar2 = (*(code *)PTR_strlen_006a9a24)(local_2c[0]);
    if (param_3 < 1) {
      uVar3 = iVar2 + 1;
    }
    else {
      if (param_3 <= iVar2) {
        iVar2 = param_3 + -1;
      }
      (*(code *)PTR_memcpy_006a9aec)(param_2,local_2c[0],iVar2);
      uVar3 = iVar2 + 1;
      *(undefined *)(param_2 + iVar2) = 0;
    }
  }
  if (local_1c == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x67,0x43,"dso_dlfcn.c",0xd3);
    return 0;
  }
  iVar5 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(iVar2 + 4));
  if (0 < iVar5) {
    iVar5 = (*(code *)PTR_sk_pop_006a8da4)(*(undefined4 *)(iVar2 + 4));
    if (iVar5 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x67,0x68,"dso_dlfcn.c",0xda);
      (*(code *)PTR_sk_push_006a6fa8)(*(undefined4 *)(iVar2 + 4),0);
    }
    else {
      (*(code *)PTR_dlclose_006a9aac)(iVar5);
    }
    return (uint)(iVar5 != 0);
  }
  return 1;
}

