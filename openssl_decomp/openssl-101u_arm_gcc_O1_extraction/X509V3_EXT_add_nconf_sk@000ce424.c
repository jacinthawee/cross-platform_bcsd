
int X509V3_EXT_add_nconf_sk(CONF *conf,X509V3_CTX *ctx,char *section,stack_st_X509_EXTENSION **sk)

{
  _STACK *p_Var1;
  int iVar2;
  void *pvVar3;
  X509_EXTENSION *pXVar4;
  int iVar5;
  
  p_Var1 = (_STACK *)NCONF_get_section(conf,section);
  if (p_Var1 == (_STACK *)0x0) {
    return 0;
  }
  iVar5 = 0;
  if (sk == (stack_st_X509_EXTENSION **)0x0) {
    while( true ) {
      iVar5 = sk_num(p_Var1);
      if (iVar5 <= (int)sk) break;
      pvVar3 = sk_value(p_Var1,(int)sk);
      pXVar4 = X509V3_EXT_nconf(conf,ctx,*(char **)((int)pvVar3 + 4),*(char **)((int)pvVar3 + 8));
      if (pXVar4 == (X509_EXTENSION *)0x0) {
        return 0;
      }
      X509_EXTENSION_free(pXVar4);
      sk = (stack_st_X509_EXTENSION **)((int)sk + 1);
    }
  }
  else {
    while( true ) {
      iVar2 = sk_num(p_Var1);
      if (iVar2 <= iVar5) break;
      pvVar3 = sk_value(p_Var1,iVar5);
      pXVar4 = X509V3_EXT_nconf(conf,ctx,*(char **)((int)pvVar3 + 4),*(char **)((int)pvVar3 + 8));
      if (pXVar4 == (X509_EXTENSION *)0x0) {
        return 0;
      }
      X509v3_add_ext(sk,pXVar4,-1);
      X509_EXTENSION_free(pXVar4);
      iVar5 = iVar5 + 1;
    }
  }
  return 1;
}

