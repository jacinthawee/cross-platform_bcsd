
int X509V3_EXT_add_nconf(CONF *conf,X509V3_CTX *ctx,char *section,X509 *cert)

{
  stack_st_X509_EXTENSION **x;
  _STACK *p_Var1;
  void *pvVar2;
  X509_EXTENSION *pXVar3;
  int iVar4;
  int iVar5;
  
  if (cert == (X509 *)0x0) {
    p_Var1 = (_STACK *)NCONF_get_section(conf,section);
    if (p_Var1 == (_STACK *)0x0) {
      return 0;
    }
  }
  else {
    x = &cert->cert_info->extensions;
    p_Var1 = (_STACK *)NCONF_get_section(conf,section);
    if (p_Var1 == (_STACK *)0x0) {
      return 0;
    }
    iVar5 = 0;
    if (x != (stack_st_X509_EXTENSION **)0x0) {
      while( true ) {
        iVar4 = sk_num(p_Var1);
        if (iVar4 <= iVar5) {
          return 1;
        }
        pvVar2 = sk_value(p_Var1,iVar5);
        pXVar3 = X509V3_EXT_nconf(conf,ctx,*(char **)((int)pvVar2 + 4),*(char **)((int)pvVar2 + 8));
        if (pXVar3 == (X509_EXTENSION *)0x0) break;
        iVar5 = iVar5 + 1;
        X509v3_add_ext(x,pXVar3,-1);
        X509_EXTENSION_free(pXVar3);
      }
      return 0;
    }
  }
  iVar5 = 0;
  while( true ) {
    iVar4 = sk_num(p_Var1);
    if (iVar4 <= iVar5) {
      return 1;
    }
    pvVar2 = sk_value(p_Var1,iVar5);
    pXVar3 = X509V3_EXT_nconf(conf,ctx,*(char **)((int)pvVar2 + 4),*(char **)((int)pvVar2 + 8));
    if (pXVar3 == (X509_EXTENSION *)0x0) break;
    iVar5 = iVar5 + 1;
    X509_EXTENSION_free(pXVar3);
  }
  return 0;
}

