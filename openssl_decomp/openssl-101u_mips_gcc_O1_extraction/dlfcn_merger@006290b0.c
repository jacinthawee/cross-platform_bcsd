
int dlfcn_merger(undefined4 param_1,char *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 == (char *)0x0) {
    if (param_3 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x82,0x43,"dso_dlfcn.c",0x124);
      return 0;
    }
    iVar1 = (*(code *)PTR_strlen_006a9a24)(param_3);
    iVar1 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar1 + 1,"dso_dlfcn.c",0x137);
    if (iVar1 != 0) {
      (*(code *)PTR_strcpy_006a9a6c)(iVar1,param_3);
      return iVar1;
    }
    uVar3 = 0x139;
  }
  else if ((param_3 == 0) || (*param_2 == '/')) {
    iVar1 = (*(code *)PTR_strlen_006a9a24)(param_2);
    iVar1 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar1 + 1,"dso_dlfcn.c",300);
    if (iVar1 != 0) {
      (*(code *)PTR_strcpy_006a9a6c)(iVar1,param_2);
      return iVar1;
    }
    uVar3 = 0x12e;
  }
  else {
    iVar1 = (*(code *)PTR_strlen_006a9a24)(param_3);
    iVar2 = (*(code *)PTR_strlen_006a9a24)(param_2);
    iVar2 = iVar1 + iVar2;
    if ((iVar1 != 0) && (*(char *)(param_3 + iVar1 + -1) == '/')) {
      iVar1 = iVar1 + -1;
      iVar2 = iVar2 + -1;
    }
    iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2 + 2,"dso_dlfcn.c",0x14e);
    if (iVar2 != 0) {
      (*(code *)PTR_strcpy_006a9a6c)(iVar2,param_3);
      *(undefined *)(iVar2 + iVar1) = 0x2f;
      (*(code *)PTR_strcpy_006a9a6c)(iVar2 + iVar1 + 1,param_2);
      return iVar2;
    }
    uVar3 = 0x150;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x82,0x41,"dso_dlfcn.c",uVar3);
  return 0;
}

