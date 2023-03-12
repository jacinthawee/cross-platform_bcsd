
undefined4 load_dh_param(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_BIO_new_file_006a7fac)(param_1,"r");
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (*(code *)PTR_PEM_read_bio_DHparams_006a8608)(iVar1,0,0,0);
    (*(code *)PTR_BIO_free_006a7f70)(iVar1);
  }
  return uVar2;
}

