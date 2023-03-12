
int ssl_replace_hash(int *param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  
  if (*param_1 != 0) {
    (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)();
  }
  puVar1 = PTR_EVP_MD_CTX_create_006a8084;
  *param_1 = 0;
  iVar2 = (*(code *)puVar1)();
  *param_1 = iVar2;
  if (iVar2 != 0) {
    if (param_2 == 0) {
      return iVar2;
    }
    iVar2 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(iVar2,param_2,0);
    if (0 < iVar2) {
      return *param_1;
    }
    iVar2 = *param_1;
  }
  (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(iVar2);
  *param_1 = 0;
  return 0;
}

