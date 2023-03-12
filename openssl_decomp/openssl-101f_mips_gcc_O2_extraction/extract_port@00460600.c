
int extract_port(undefined4 param_1,undefined2 *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_strtol_006aaa68)(param_1,0,10);
  if (iVar1 == 0) {
    iVar2 = (*(code *)PTR_getservbyname_006aaafc)(param_1,&DAT_00641588);
    if (iVar2 != 0) {
      *param_2 = (short)*(undefined4 *)(iVar2 + 8);
      return 1;
    }
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,"getservbyname failure for %s\n",param_1);
  }
  else {
    *param_2 = (short)iVar1;
    iVar1 = 1;
  }
  return iVar1;
}

