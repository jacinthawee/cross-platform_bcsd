
int TS_CONF_load_cert(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_BIO_new_file_006a6eac)(param_1,"r");
  if (iVar1 != 0) {
    iVar2 = (*(code *)PTR_PEM_read_bio_X509_AUX_006a7b80)(iVar1,0,0,0);
    if (iVar2 != 0) goto LAB_005c53a4;
  }
  iVar2 = 0;
  (*(code *)PTR___fprintf_chk_006a9980)
            (*(undefined4 *)PTR_stderr_006a9af8,1,"unable to load certificate: %s\n",param_1);
LAB_005c53a4:
  (*(code *)PTR_BIO_free_006a6e70)(iVar1);
  return iVar2;
}

