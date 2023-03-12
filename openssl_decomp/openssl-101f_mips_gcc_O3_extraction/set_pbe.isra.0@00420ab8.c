
int set_pbe_isra_0(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (*(code *)PTR_strcmp_006aac20)(param_2,&DAT_00637b4c);
    if (iVar1 == 0) {
      iVar1 = 1;
      *param_1 = -1;
    }
    else {
      iVar1 = (*(code *)PTR_OBJ_txt2nid_006a805c)(param_2);
      *param_1 = iVar1;
      if (iVar1 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)PTR_bio_err_006a7f3c,"Unknown PBE algorithm %s\n",param_2);
      }
      else {
        iVar1 = 1;
      }
    }
  }
  return iVar1;
}

