
int set_pbe_isra_0(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (*(code *)PTR_strcmp_006a9b18)(param_2,&DAT_006372d8);
    if (iVar1 == 0) {
      iVar1 = 1;
      *param_1 = -1;
    }
    else {
      iVar1 = (*(code *)PTR_OBJ_txt2nid_006a6f5c)(param_2);
      *param_1 = iVar1;
      if (iVar1 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)PTR_bio_err_006a6e3c,"Unknown PBE algorithm %s\n",param_2);
      }
      else {
        iVar1 = 1;
      }
    }
  }
  return iVar1;
}

