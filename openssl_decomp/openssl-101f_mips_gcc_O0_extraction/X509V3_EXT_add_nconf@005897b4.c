
int X509V3_EXT_add_nconf(CONF *conf,X509V3_CTX *ctx,char *section,X509 *cert)

{
  stack_st_CONF_VALUE *psVar1;
  X509_EXTENSION *pXVar2;
  int iVar3;
  int iVar4;
  X509_CINF *pXVar5;
  stack_st_X509_EXTENSION **x;
  
  if (cert == (X509 *)0x0) {
    psVar1 = NCONF_get_section(conf,section);
    if (psVar1 == (stack_st_CONF_VALUE *)0x0) {
      return 0;
    }
  }
  else {
    pXVar5 = cert->cert_info;
    psVar1 = NCONF_get_section(conf,section);
    x = &pXVar5->extensions;
    if (psVar1 == (stack_st_CONF_VALUE *)0x0) {
      return 0;
    }
    if (x != (stack_st_X509_EXTENSION **)0x0) {
      iVar4 = 0;
      while( true ) {
        iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psVar1);
        if (iVar3 <= iVar4) {
          return 1;
        }
        iVar3 = (*(code *)PTR_sk_value_006a7f24)(psVar1,iVar4);
        pXVar2 = X509V3_EXT_nconf(conf,ctx,*(char **)(iVar3 + 4),*(char **)(iVar3 + 8));
        if (pXVar2 == (X509_EXTENSION *)0x0) break;
        X509v3_add_ext(x,pXVar2,-1);
        (*(code *)PTR_X509_EXTENSION_free_006a8268)(pXVar2);
        iVar4 = iVar4 + 1;
      }
      return 0;
    }
  }
  iVar4 = 0;
  while( true ) {
    iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psVar1);
    if (iVar3 <= iVar4) {
      return 1;
    }
    iVar3 = (*(code *)PTR_sk_value_006a7f24)(psVar1,iVar4);
    pXVar2 = X509V3_EXT_nconf(conf,ctx,*(char **)(iVar3 + 4),*(char **)(iVar3 + 8));
    if (pXVar2 == (X509_EXTENSION *)0x0) break;
    (*(code *)PTR_X509_EXTENSION_free_006a8268)(pXVar2);
    iVar4 = iVar4 + 1;
  }
  return 0;
}

