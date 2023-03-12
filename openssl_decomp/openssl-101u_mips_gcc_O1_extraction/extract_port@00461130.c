
int extract_port(undefined4 param_1,undefined2 *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_strtol_006a9958)(param_1,0,10);
  if (iVar1 == 0) {
    iVar2 = (*(code *)PTR_getservbyname_006a99f0)(param_1,&DAT_00641018);
    if (iVar2 != 0) {
      *param_2 = (short)*(undefined4 *)(iVar2 + 8);
      return 1;
    }
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,"getservbyname failure for %s\n",param_1);
  }
  else {
    *param_2 = (short)iVar1;
    iVar1 = 1;
  }
  return iVar1;
}

