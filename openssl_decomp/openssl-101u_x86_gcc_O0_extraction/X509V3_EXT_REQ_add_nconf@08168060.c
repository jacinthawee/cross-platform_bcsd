
int X509V3_EXT_REQ_add_nconf(CONF *conf,X509V3_CTX *ctx,char *section,X509_REQ *req)

{
  _STACK *p_Var1;
  void *pvVar2;
  X509_EXTENSION *pXVar3;
  int iVar4;
  int iVar5;
  int in_GS_OFFSET;
  _STACK *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (_STACK *)0x0;
  if (req == (X509_REQ *)0x0) {
    p_Var1 = (_STACK *)NCONF_get_section(conf,section);
    if (p_Var1 != (_STACK *)0x0) {
      for (iVar5 = 0; iVar4 = sk_num(p_Var1), iVar5 < iVar4; iVar5 = iVar5 + 1) {
        pvVar2 = sk_value(p_Var1,iVar5);
        pXVar3 = X509V3_EXT_nconf(conf,ctx,*(char **)((int)pvVar2 + 4),*(char **)((int)pvVar2 + 8));
        if (pXVar3 == (X509_EXTENSION *)0x0) goto LAB_08168140;
        X509_EXTENSION_free(pXVar3);
      }
      iVar5 = 1;
      goto LAB_08168142;
    }
  }
  else {
    iVar5 = 0;
    p_Var1 = (_STACK *)NCONF_get_section(conf,section);
    if (p_Var1 != (_STACK *)0x0) {
      for (; iVar4 = sk_num(p_Var1), iVar5 < iVar4; iVar5 = iVar5 + 1) {
        pvVar2 = sk_value(p_Var1,iVar5);
        pXVar3 = X509V3_EXT_nconf(conf,ctx,*(char **)((int)pvVar2 + 4),*(char **)((int)pvVar2 + 8));
        if (pXVar3 == (X509_EXTENSION *)0x0) goto LAB_08168140;
        X509v3_add_ext((stack_st_X509_EXTENSION **)&local_24,pXVar3,-1);
        X509_EXTENSION_free(pXVar3);
      }
      iVar5 = X509_REQ_add_extensions(req,(stack_st_X509_EXTENSION *)local_24);
      sk_pop_free(local_24,X509_EXTENSION_free);
      goto LAB_08168142;
    }
  }
LAB_08168140:
  iVar5 = 0;
LAB_08168142:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}

