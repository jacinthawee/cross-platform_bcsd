
int X509V3_EXT_REQ_add_conf(lhash_st_CONF_VALUE *conf,X509V3_CTX *ctx,char *section,X509_REQ *req)

{
  _STACK *p_Var1;
  int iVar2;
  void *pvVar3;
  X509_EXTENSION *pXVar4;
  int iVar5;
  _STACK *local_28;
  CONF CStack_24;
  
  CONF_set_nconf(&CStack_24,conf);
  local_28 = (_STACK *)0x0;
  if (req == (X509_REQ *)0x0) {
    p_Var1 = (_STACK *)NCONF_get_section(&CStack_24,section);
    if (p_Var1 != (_STACK *)0x0) {
      while( true ) {
        iVar5 = sk_num(p_Var1);
        if (iVar5 <= (int)req) {
          return 1;
        }
        pvVar3 = sk_value(p_Var1,(int)req);
        pXVar4 = X509V3_EXT_nconf(&CStack_24,ctx,*(char **)((int)pvVar3 + 4),
                                  *(char **)((int)pvVar3 + 8));
        if (pXVar4 == (X509_EXTENSION *)0x0) break;
        X509_EXTENSION_free(pXVar4);
        req = (X509_REQ *)((int)&req->req_info + 1);
      }
    }
  }
  else {
    p_Var1 = (_STACK *)NCONF_get_section(&CStack_24,section);
    iVar5 = 0;
    if (p_Var1 != (_STACK *)0x0) {
      while( true ) {
        iVar2 = sk_num(p_Var1);
        if (iVar2 <= iVar5) {
          iVar5 = X509_REQ_add_extensions(req,(stack_st_X509_EXTENSION *)local_28);
          sk_pop_free(local_28,X509_EXTENSION_free);
          return iVar5;
        }
        pvVar3 = sk_value(p_Var1,iVar5);
        pXVar4 = X509V3_EXT_nconf(&CStack_24,ctx,*(char **)((int)pvVar3 + 4),
                                  *(char **)((int)pvVar3 + 8));
        if (pXVar4 == (X509_EXTENSION *)0x0) break;
        X509v3_add_ext((stack_st_X509_EXTENSION **)&local_28,pXVar4,-1);
        X509_EXTENSION_free(pXVar4);
        iVar5 = iVar5 + 1;
      }
    }
  }
  return 0;
}
