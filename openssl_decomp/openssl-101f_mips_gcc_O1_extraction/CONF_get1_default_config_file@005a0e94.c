
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * CONF_get1_default_config_file(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  iVar1 = (*(code *)PTR_getenv_006aab6c)("OPENSSL_CONF");
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x005a0edc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar2 = (char *)(*(code *)PTR_BUF_strdup_006a80dc)(iVar1);
    return pcVar2;
  }
  uVar3 = (*(code *)PTR_X509_get_default_cert_area_006a8164)();
  iVar1 = (*(code *)PTR_strlen_006aab30)(uVar3);
  iVar1 = iVar1 + 0xd;
  pcVar2 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar1,"conf_mod.c",0x231);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = (char *)0x0;
  }
  else {
    uVar3 = (*(code *)PTR_X509_get_default_cert_area_006a8164)();
    (*(code *)PTR_BUF_strlcpy_006a8064)(pcVar2,uVar3,iVar1);
    (*(code *)PTR_BUF_strlcat_006a8068)(pcVar2,&DAT_0063ba98,iVar1);
    (*(code *)PTR_BUF_strlcat_006a8068)(pcVar2,"openssl.cnf",iVar1);
  }
  return pcVar2;
}

