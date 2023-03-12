
int X509V3_EXT_add_conf(lhash_st_CONF_VALUE *conf,X509V3_CTX *ctx,char *section,X509 *cert)

{
  _STACK *p_Var1;
  int iVar2;
  void *pvVar3;
  X509_EXTENSION *pXVar4;
  int iVar5;
  stack_st_X509_EXTENSION **x;
  CONF CStack_24;
  
  CONF_set_nconf(&CStack_24,conf);
  if (cert == (X509 *)0x0) {
    p_Var1 = (_STACK *)NCONF_get_section(&CStack_24,section);
    if (p_Var1 == (_STACK *)0x0) {
      return 0;
    }
  }
  else {
    x = &cert->cert_info->extensions;
    p_Var1 = (_STACK *)NCONF_get_section(&CStack_24,section);
    if (p_Var1 == (_STACK *)0x0) {
      return 0;
    }
    iVar5 = 0;
    if (x != (stack_st_X509_EXTENSION **)0x0) {
      while( true ) {
        iVar2 = sk_num(p_Var1);
        if (iVar2 <= iVar5) {
          return 1;
        }
        pvVar3 = sk_value(p_Var1,iVar5);
        pXVar4 = X509V3_EXT_nconf(&CStack_24,ctx,*(char **)((int)pvVar3 + 4),
                                  *(char **)((int)pvVar3 + 8));
        if (pXVar4 == (X509_EXTENSION *)0x0) break;
        X509v3_add_ext(x,pXVar4,-1);
        X509_EXTENSION_free(pXVar4);
        iVar5 = iVar5 + 1;
      }
      return 0;
    }
  }
  iVar5 = 0;
  while( true ) {
    iVar2 = sk_num(p_Var1);
    if (iVar2 <= iVar5) {
      return 1;
    }
    pvVar3 = sk_value(p_Var1,iVar5);
    pXVar4 = X509V3_EXT_nconf(&CStack_24,ctx,*(char **)((int)pvVar3 + 4),*(char **)((int)pvVar3 + 8)
                             );
    if (pXVar4 == (X509_EXTENSION *)0x0) break;
    X509_EXTENSION_free(pXVar4);
    iVar5 = iVar5 + 1;
  }
  return 0;
}
