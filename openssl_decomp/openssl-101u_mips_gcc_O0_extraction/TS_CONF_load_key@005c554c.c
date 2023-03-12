
int TS_CONF_load_key(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_BIO_new_file_006a6eac)(param_1,"r");
  if (iVar1 != 0) {
    iVar2 = (*(code *)PTR_PEM_read_bio_PrivateKey_006a7b8c)(iVar1,0,0,param_2);
    if (iVar2 != 0) goto LAB_005c55b4;
  }
  iVar2 = 0;
  (*(code *)PTR___fprintf_chk_006a9980)
            (*(undefined4 *)PTR_stderr_006a9af8,1,"unable to load private key: %s\n",param_1);
LAB_005c55b4:
  (*(code *)PTR_BIO_free_006a6e70)(iVar1);
  return iVar2;
}

