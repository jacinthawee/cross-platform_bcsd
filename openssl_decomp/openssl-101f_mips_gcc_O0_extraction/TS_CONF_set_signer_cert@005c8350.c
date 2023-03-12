
bool TS_CONF_set_signer_cert(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  if (param_3 == 0) {
    param_3 = (*(code *)PTR_NCONF_get_string_006a7fa8)(param_1,param_2,"signer_cert");
    if (param_3 == 0) {
      iVar2 = 0;
      bVar3 = false;
      (*(code *)PTR___fprintf_chk_006aaa8c)
                (*(undefined4 *)PTR_stderr_006aac00,1,"variable lookup failed for %s::%s\n",param_2,
                 "signer_cert");
      goto LAB_005c83ec;
    }
  }
  iVar1 = (*(code *)PTR_BIO_new_file_006a7fac)(param_3,"r");
  if (iVar1 != 0) {
    iVar2 = (*(code *)PTR_PEM_read_bio_X509_AUX_006a8c6c)(iVar1,0,0,0);
    if (iVar2 != 0) {
      (*(code *)PTR_BIO_free_006a7f70)(iVar1);
      iVar1 = TS_RESP_CTX_set_signer_cert(param_4,iVar2);
      bVar3 = iVar1 != 0;
      goto LAB_005c83ec;
    }
  }
  iVar2 = 0;
  (*(code *)PTR___fprintf_chk_006aaa8c)
            (*(undefined4 *)PTR_stderr_006aac00,1,"unable to load certificate: %s\n",param_3);
  bVar3 = false;
  (*(code *)PTR_BIO_free_006a7f70)(iVar1);
LAB_005c83ec:
  (*(code *)PTR_X509_free_006a7f90)(iVar2);
  return bVar3;
}

