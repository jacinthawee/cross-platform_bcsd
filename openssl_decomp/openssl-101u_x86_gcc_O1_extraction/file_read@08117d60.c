
size_t file_read(int param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  int iVar2;
  int *piVar3;
  
  if ((*(int *)(param_1 + 0xc) != 0) && (param_2 != (void *)0x0)) {
    sVar1 = fread(param_2,1,param_3,*(FILE **)(param_1 + 0x20));
    iVar2 = ferror(*(FILE **)(param_1 + 0x20));
    if (iVar2 != 0) {
      piVar3 = __errno_location();
      sVar1 = 0xffffffff;
      ERR_put_error(2,0xb,*piVar3,"bss_file.c",0xfb);
      ERR_put_error(0x20,0x82,2,"bss_file.c",0xfc);
    }
    return sVar1;
  }
  return 0;
}

