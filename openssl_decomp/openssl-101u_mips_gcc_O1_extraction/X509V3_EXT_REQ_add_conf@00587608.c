
int X509V3_EXT_REQ_add_conf(lhash_st_CONF_VALUE *conf,X509V3_CTX *ctx,char *section,X509_REQ *req)

{
  undefined *puVar1;
  stack_st_CONF_VALUE *psVar2;
  X509_EXTENSION *pXVar3;
  int iVar4;
  int iVar5;
  stack_st_X509_EXTENSION *local_3c;
  CONF CStack_38;
  int **local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int ***)PTR___stack_chk_guard_006a9ae8;
  CONF_set_nconf(&CStack_38,conf);
  local_3c = (stack_st_X509_EXTENSION *)0x0;
  if (req == (X509_REQ *)0x0) {
    psVar2 = NCONF_get_section(&CStack_38,section);
    if (psVar2 != (stack_st_CONF_VALUE *)0x0) {
      iVar5 = 0;
      while( true ) {
        iVar4 = (*(code *)PTR_sk_num_006a6e2c)(psVar2);
        if (iVar4 <= iVar5) break;
        iVar4 = (*(code *)PTR_sk_value_006a6e24)(psVar2,iVar5);
        section = (char *)ctx;
        pXVar3 = X509V3_EXT_nconf(&CStack_38,ctx,*(char **)(iVar4 + 4),*(char **)(iVar4 + 8));
        if (pXVar3 == (X509_EXTENSION *)0x0) goto LAB_00587748;
        iVar5 = iVar5 + 1;
        (*(code *)PTR_X509_EXTENSION_free_006a7168)(pXVar3);
      }
      iVar5 = 1;
      goto LAB_0058774c;
    }
  }
  else {
    psVar2 = NCONF_get_section(&CStack_38,section);
    if (psVar2 != (stack_st_CONF_VALUE *)0x0) {
      iVar5 = 0;
      while( true ) {
        iVar4 = (*(code *)PTR_sk_num_006a6e2c)(psVar2);
        if (iVar4 <= iVar5) break;
        iVar4 = (*(code *)PTR_sk_value_006a6e24)(psVar2,iVar5);
        section = (char *)ctx;
        pXVar3 = X509V3_EXT_nconf(&CStack_38,ctx,*(char **)(iVar4 + 4),*(char **)(iVar4 + 8));
        if (pXVar3 == (X509_EXTENSION *)0x0) goto LAB_00587748;
        X509v3_add_ext(&local_3c,pXVar3,-1);
        iVar5 = iVar5 + 1;
        (*(code *)PTR_X509_EXTENSION_free_006a7168)(pXVar3);
      }
      iVar5 = X509_REQ_add_extensions(req,local_3c);
      section = PTR_X509_EXTENSION_free_006a7168;
      (*(code *)PTR_sk_pop_free_006a7058)(local_3c);
      goto LAB_0058774c;
    }
  }
LAB_00587748:
  iVar5 = 0;
LAB_0058774c:
  if (local_2c == *(int ***)puVar1) {
    return iVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return **local_2c - *(int *)*(int *)section;
}

