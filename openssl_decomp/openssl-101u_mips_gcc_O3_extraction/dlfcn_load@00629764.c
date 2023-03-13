
undefined4 dlfcn_load(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = (*(code *)PTR_DSO_convert_filename_006a88bc)(param_1,0);
  if (iVar1 == 0) {
    uVar4 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x66,0x6f,"dso_dlfcn.c",0xb2);
  }
  else {
    uVar4 = 2;
    if ((*(uint *)(param_1 + 0xc) & 0x20) != 0) {
      uVar4 = 6;
    }
    iVar2 = (*(code *)PTR_dlopen_006a9abc)(iVar1,uVar4);
    if (iVar2 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x66,0x67,"dso_dlfcn.c",0xbb);
      uVar4 = (*(code *)PTR_dlerror_006a9a9c)();
      (*(code *)PTR_ERR_add_error_data_006a813c)(4,"filename(",iVar1,"): ",uVar4);
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar1);
      return 0;
    }
    iVar3 = (*(code *)PTR_sk_push_006a6fa8)(*(undefined4 *)(param_1 + 4),iVar2);
    if (iVar3 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x66,0x69,"dso_dlfcn.c",0xc0);
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar1);
      (*(code *)PTR_dlclose_006a9aac)(iVar2);
      return 0;
    }
    uVar4 = 1;
    *(int *)(param_1 + 0x24) = iVar1;
  }
  return uVar4;
}

