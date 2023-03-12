
int dlfcn_name_converter(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  
  iVar1 = (*(code *)PTR_strlen_006a9a24)(param_2);
  iVar2 = (*(code *)PTR_strchr_006a9a28)(param_2,0x2f);
  if (iVar2 == 0) {
    uVar3 = (*(code *)PTR_DSO_flags_006a9914)(param_1);
    if ((uVar3 & 2) == 0) {
      iVar1 = iVar1 + 7;
    }
    else {
      iVar1 = iVar1 + 4;
    }
    iVar1 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar1,"dso_dlfcn.c",0x170);
    if (iVar1 != 0) {
      uVar3 = (*(code *)PTR_DSO_flags_006a9914)(param_1);
      if ((uVar3 & 2) == 0) {
        pcVar4 = "lib%s.so";
      }
      else {
        pcVar4 = "%s.so";
      }
      (*(code *)PTR___sprintf_chk_006a9930)(iVar1,1,0xffffffff,pcVar4,param_2);
      return iVar1;
    }
  }
  else {
    iVar1 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar1 + 1,"dso_dlfcn.c",0x170);
    if (iVar1 != 0) {
      iVar1 = (*(code *)PTR_strcpy_006a9a6c)(iVar1,param_2);
      return iVar1;
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x7b,0x6d,"dso_dlfcn.c",0x172);
  return 0;
}

