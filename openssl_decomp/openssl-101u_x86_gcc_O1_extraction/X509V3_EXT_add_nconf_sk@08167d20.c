
int X509V3_EXT_add_nconf_sk(CONF *conf,X509V3_CTX *ctx,char *section,stack_st_X509_EXTENSION **sk)

{
  _STACK *p_Var1;
  void *pvVar2;
  X509_EXTENSION *pXVar3;
  int iVar4;
  int iVar5;
  
  p_Var1 = (_STACK *)NCONF_get_section(conf,section);
  if (p_Var1 == (_STACK *)0x0) {
    return 0;
  }
  iVar5 = 0;
  if (sk == (stack_st_X509_EXTENSION **)0x0) {
    for (; iVar4 = sk_num(p_Var1), iVar5 < iVar4; iVar5 = iVar5 + 1) {
      pvVar2 = sk_value(p_Var1,iVar5);
      pXVar3 = X509V3_EXT_nconf(conf,ctx,*(char **)((int)pvVar2 + 4),*(char **)((int)pvVar2 + 8));
      if (pXVar3 == (X509_EXTENSION *)0x0) {
        return 0;
      }
      X509_EXTENSION_free(pXVar3);
    }
  }
  else {
    for (; iVar4 = sk_num(p_Var1), iVar5 < iVar4; iVar5 = iVar5 + 1) {
      pvVar2 = sk_value(p_Var1,iVar5);
      pXVar3 = X509V3_EXT_nconf(conf,ctx,*(char **)((int)pvVar2 + 4),*(char **)((int)pvVar2 + 8));
      if (pXVar3 == (X509_EXTENSION *)0x0) {
        return 0;
      }
      X509v3_add_ext(sk,pXVar3,-1);
      X509_EXTENSION_free(pXVar3);
    }
  }
  return 1;
}

