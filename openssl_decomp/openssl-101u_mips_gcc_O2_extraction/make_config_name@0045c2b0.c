
int make_config_name(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = (*(code *)PTR_X509_get_default_cert_area_006a7064)();
  iVar2 = (*(code *)PTR_strlen_006a9a24)(uVar1);
  iVar2 = iVar2 + 0xd;
  iVar3 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2,"apps.c",0x5d6);
  if (iVar3 != 0) {
    (*(code *)PTR_BUF_strlcpy_006a6f64)(iVar3,uVar1,iVar2);
    (*(code *)PTR_BUF_strlcat_006a6f68)(iVar3,&DAT_0063b2b4,iVar2);
    (*(code *)PTR_BUF_strlcat_006a6f68)(iVar3,"openssl.cnf",iVar2);
  }
  return iVar3;
}

