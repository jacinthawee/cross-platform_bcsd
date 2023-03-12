
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * CONF_get1_default_config_file(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  iVar1 = (*(code *)PTR_getenv_006a9a60)("OPENSSL_CONF");
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0059e16c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar2 = (char *)(*(code *)PTR_BUF_strdup_006a6fdc)(iVar1);
    return pcVar2;
  }
  uVar3 = (*(code *)PTR_X509_get_default_cert_area_006a7064)();
  iVar1 = (*(code *)PTR_strlen_006a9a24)(uVar3);
  iVar1 = iVar1 + 0xd;
  pcVar2 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar1,"conf_mod.c",0x21b);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = (char *)0x0;
  }
  else {
    uVar3 = (*(code *)PTR_X509_get_default_cert_area_006a7064)();
    (*(code *)PTR_BUF_strlcpy_006a6f64)(pcVar2,uVar3,iVar1);
    (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar2,&DAT_0063b2b4,iVar1);
    (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar2,"openssl.cnf",iVar1);
  }
  return pcVar2;
}

