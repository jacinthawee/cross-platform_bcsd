
undefined4 make_config_name(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = (*(code *)PTR_X509_get_default_cert_area_006a8164)();
  iVar2 = (*(code *)PTR_strlen_006aab30)(uVar1);
  iVar2 = iVar2 + 0xd;
  uVar3 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2,"apps.c",0x608);
  (*(code *)PTR_BUF_strlcpy_006a8064)(uVar3,uVar1,iVar2);
  (*(code *)PTR_BUF_strlcat_006a8068)(uVar3,&DAT_0063ba98,iVar2);
  (*(code *)PTR_BUF_strlcat_006a8068)(uVar3,"openssl.cnf",iVar2);
  return uVar3;
}

