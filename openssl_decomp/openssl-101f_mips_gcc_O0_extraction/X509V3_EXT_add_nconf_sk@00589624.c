
int X509V3_EXT_add_nconf_sk(CONF *conf,X509V3_CTX *ctx,char *section,stack_st_X509_EXTENSION **sk)

{
  stack_st_CONF_VALUE *psVar1;
  X509_EXTENSION *pXVar2;
  int iVar3;
  int iVar4;
  
  psVar1 = NCONF_get_section(conf,section);
  if (psVar1 == (stack_st_CONF_VALUE *)0x0) {
    return 0;
  }
  iVar4 = 0;
  if (sk == (stack_st_X509_EXTENSION **)0x0) {
    while (iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psVar1), iVar4 < iVar3) {
      iVar3 = (*(code *)PTR_sk_value_006a7f24)(psVar1,iVar4);
      pXVar2 = X509V3_EXT_nconf(conf,ctx,*(char **)(iVar3 + 4),*(char **)(iVar3 + 8));
      if (pXVar2 == (X509_EXTENSION *)0x0) {
        return 0;
      }
      (*(code *)PTR_X509_EXTENSION_free_006a8268)(pXVar2);
      iVar4 = iVar4 + 1;
    }
  }
  else {
    while( true ) {
      iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psVar1);
      if (iVar3 <= iVar4) break;
      iVar3 = (*(code *)PTR_sk_value_006a7f24)(psVar1,iVar4);
      pXVar2 = X509V3_EXT_nconf(conf,ctx,*(char **)(iVar3 + 4),*(char **)(iVar3 + 8));
      if (pXVar2 == (X509_EXTENSION *)0x0) {
        return 0;
      }
      X509v3_add_ext(sk,pXVar2,-1);
      (*(code *)PTR_X509_EXTENSION_free_006a8268)(pXVar2);
      iVar4 = iVar4 + 1;
    }
  }
  return 1;
}

