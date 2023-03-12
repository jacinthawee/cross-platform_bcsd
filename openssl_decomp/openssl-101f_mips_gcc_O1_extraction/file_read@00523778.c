
undefined4 file_read(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  if ((*(int *)(param_1 + 0xc) != 0) && (param_2 != 0)) {
    uVar1 = (*(code *)PTR_fread_006aab78)(param_2,1,param_3,*(undefined4 *)(param_1 + 0x20));
    iVar2 = (*(code *)PTR_ferror_006aabec)(*(undefined4 *)(param_1 + 0x20));
    if (iVar2 != 0) {
      piVar3 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
      ERR_put_error(2,0xb,*piVar3,"bss_file.c",0xf5);
      uVar1 = 0xffffffff;
      ERR_put_error(0x20,0x82,2,"bss_file.c",0xf6);
    }
    return uVar1;
  }
  return 0;
}

