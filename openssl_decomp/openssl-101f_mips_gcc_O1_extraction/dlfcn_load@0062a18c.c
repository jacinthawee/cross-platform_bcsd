
undefined4 dlfcn_load(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = (*(code *)PTR_DSO_convert_filename_006a99dc)(param_1,0);
  if (iVar1 == 0) {
    uVar4 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x25,0x66,0x6f,"dso_dlfcn.c",0xb0);
  }
  else {
    uVar4 = 2;
    if ((*(uint *)(param_1 + 0xc) & 0x20) != 0) {
      uVar4 = 6;
    }
    iVar2 = (*(code *)PTR_dlopen_006aabc4)(iVar1,uVar4);
    if (iVar2 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x25,0x66,0x67,"dso_dlfcn.c",0xbb);
      uVar4 = (*(code *)PTR_dlerror_006aaba4)();
      (*(code *)PTR_ERR_add_error_data_006a9264)(4,"filename(",iVar1,"): ",uVar4);
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar1);
      return 0;
    }
    iVar3 = (*(code *)PTR_sk_push_006a80a8)(*(undefined4 *)(param_1 + 4),iVar2);
    if (iVar3 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x25,0x66,0x69,"dso_dlfcn.c",0xc1);
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar1);
      (*(code *)PTR_dlclose_006aabb4)(iVar2);
      return 0;
    }
    uVar4 = 1;
    *(int *)(param_1 + 0x24) = iVar1;
  }
  return uVar4;
}

