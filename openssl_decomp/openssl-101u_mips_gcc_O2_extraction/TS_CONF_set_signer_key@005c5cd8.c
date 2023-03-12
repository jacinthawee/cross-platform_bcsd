
bool TS_CONF_set_signer_key
               (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  if (param_3 == 0) {
    param_3 = (*(code *)PTR_NCONF_get_string_006a6ea8)(param_1,param_2,"signer_key");
    if (param_3 == 0) {
      iVar2 = 0;
      bVar3 = false;
      (*(code *)PTR___fprintf_chk_006a9980)
                (*(undefined4 *)PTR_stderr_006a9af8,1,"variable lookup failed for %s::%s\n",param_2,
                 "signer_key");
      goto LAB_005c5d74;
    }
  }
  iVar1 = (*(code *)PTR_BIO_new_file_006a6eac)(param_3,"r");
  if (iVar1 != 0) {
    iVar2 = (*(code *)PTR_PEM_read_bio_PrivateKey_006a7b8c)(iVar1,0,0,param_4);
    if (iVar2 != 0) {
      (*(code *)PTR_BIO_free_006a6e70)(iVar1);
      iVar1 = TS_RESP_CTX_set_signer_key(param_5,iVar2);
      bVar3 = iVar1 != 0;
      goto LAB_005c5d74;
    }
  }
  iVar2 = 0;
  (*(code *)PTR___fprintf_chk_006a9980)
            (*(undefined4 *)PTR_stderr_006a9af8,1,"unable to load private key: %s\n",param_3);
  bVar3 = false;
  (*(code *)PTR_BIO_free_006a6e70)(iVar1);
LAB_005c5d74:
  (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar2);
  return bVar3;
}

