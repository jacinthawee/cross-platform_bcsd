
int setup_verify(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = (*(code *)PTR_X509_STORE_new_006a8364)();
  if (iVar1 != 0) {
    uVar2 = (*(code *)PTR_X509_LOOKUP_file_006a8580)();
    iVar3 = (*(code *)PTR_X509_STORE_add_lookup_006a8584)(iVar1,uVar2);
    if (iVar3 != 0) {
      if (param_2 == 0) {
        (*(code *)PTR_X509_LOOKUP_ctrl_006a8588)(iVar3,1,0,3,0);
      }
      else {
        iVar3 = (*(code *)PTR_X509_LOOKUP_ctrl_006a8588)(iVar3,1,param_2,1,0);
        if (iVar3 == 0) {
          (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Error loading file %s\n",param_2);
          goto LAB_0045b4c0;
        }
      }
      uVar2 = (*(code *)PTR_X509_LOOKUP_hash_dir_006a858c)();
      iVar3 = (*(code *)PTR_X509_STORE_add_lookup_006a8584)(iVar1,uVar2);
      if (iVar3 != 0) {
        if (param_3 == 0) {
          (*(code *)PTR_X509_LOOKUP_ctrl_006a8588)(iVar3,2,0,3,0);
        }
        else {
          iVar3 = (*(code *)PTR_X509_LOOKUP_ctrl_006a8588)(iVar3,2,param_3,1,0);
          if (iVar3 == 0) {
            (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Error loading directory %s\n",param_3);
            goto LAB_0045b4c0;
          }
        }
        (*(code *)PTR_ERR_clear_error_006a7fe0)();
        return iVar1;
      }
    }
  }
LAB_0045b4c0:
  (*(code *)PTR_X509_STORE_free_006a8384)(iVar1);
  return 0;
}

