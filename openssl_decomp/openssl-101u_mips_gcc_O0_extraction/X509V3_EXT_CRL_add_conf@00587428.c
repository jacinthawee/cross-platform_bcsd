
int X509V3_EXT_CRL_add_conf(lhash_st_CONF_VALUE *conf,X509V3_CTX *ctx,char *section,X509_CRL *crl)

{
  undefined *puVar1;
  int iVar2;
  stack_st_CONF_VALUE *psVar3;
  X509_EXTENSION *pXVar4;
  int iVar5;
  lhash_st_CONF_VALUE *hash;
  X509V3_CTX *pXVar6;
  X509V3_CTX *name;
  X509_CRL *req;
  stack_st_X509_EXTENSION **unaff_s5;
  X509_CRL_INFO *pXVar7;
  stack_st_X509_EXTENSION *psStack_84;
  CONF CStack_80;
  int **ppiStack_74;
  X509_CRL *pXStack_6c;
  X509V3_CTX *pXStack_68;
  stack_st_CONF_VALUE *psStack_64;
  CONF *pCStack_60;
  X509V3_CTX *pXStack_5c;
  stack_st_X509_EXTENSION **ppsStack_58;
  undefined *puStack_54;
  CONF CStack_30;
  lhash_st_CONF_VALUE *local_24;
  
  puStack_54 = PTR___stack_chk_guard_006a9ae8;
  pCStack_60 = &CStack_30;
  local_24 = *(lhash_st_CONF_VALUE **)PTR___stack_chk_guard_006a9ae8;
  name = (X509V3_CTX *)section;
  req = crl;
  CONF_set_nconf(pCStack_60,conf);
  pXVar6 = (X509V3_CTX *)section;
  if (crl == (X509_CRL *)0x0) {
    psStack_64 = NCONF_get_section(pCStack_60,section);
    if (psStack_64 == (stack_st_CONF_VALUE *)0x0) goto LAB_0058755c;
LAB_00587594:
    crl = (X509_CRL *)0x0;
    while( true ) {
      iVar2 = (*(code *)PTR_sk_num_006a6e2c)(psStack_64);
      if (iVar2 <= (int)crl) break;
      iVar2 = (*(code *)PTR_sk_value_006a6e24)(psStack_64,crl);
      req = *(X509_CRL **)(iVar2 + 8);
      name = *(X509V3_CTX **)(iVar2 + 4);
      pXVar6 = ctx;
      pXVar4 = X509V3_EXT_nconf(pCStack_60,ctx,(char *)name,(char *)req);
      if (pXVar4 == (X509_EXTENSION *)0x0) goto LAB_0058755c;
      crl = (X509_CRL *)((int)&crl->crl + 1);
      (*(code *)PTR_X509_EXTENSION_free_006a7168)(pXVar4);
    }
    iVar2 = 1;
  }
  else {
    pXVar7 = crl->crl;
    psStack_64 = NCONF_get_section(pCStack_60,section);
    unaff_s5 = &pXVar7->extensions;
    if (psStack_64 == (stack_st_CONF_VALUE *)0x0) {
LAB_0058755c:
      iVar2 = 0;
    }
    else {
      if (unaff_s5 == (stack_st_X509_EXTENSION **)0x0) goto LAB_00587594;
      crl = (X509_CRL *)0x0;
      while( true ) {
        iVar2 = (*(code *)PTR_sk_num_006a6e2c)(psStack_64);
        if (iVar2 <= (int)crl) break;
        iVar2 = (*(code *)PTR_sk_value_006a6e24)(psStack_64,crl);
        req = *(X509_CRL **)(iVar2 + 8);
        name = *(X509V3_CTX **)(iVar2 + 4);
        pXVar6 = ctx;
        section = (char *)X509V3_EXT_nconf(pCStack_60,ctx,(char *)name,(char *)req);
        if ((X509V3_CTX *)section == (X509V3_CTX *)0x0) goto LAB_0058755c;
        name = (X509V3_CTX *)0xffffffff;
        pXVar6 = (X509V3_CTX *)section;
        X509v3_add_ext(unaff_s5,(X509_EXTENSION *)section,-1);
        crl = (X509_CRL *)((int)&crl->crl + 1);
        (*(code *)PTR_X509_EXTENSION_free_006a7168)(section);
      }
      iVar2 = 1;
    }
  }
  if (local_24 == *(lhash_st_CONF_VALUE **)puStack_54) {
    return iVar2;
  }
  hash = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  ppiStack_74 = *(int ***)PTR___stack_chk_guard_006a9ae8;
  pXStack_6c = crl;
  pXStack_68 = (X509V3_CTX *)section;
  pXStack_5c = ctx;
  ppsStack_58 = unaff_s5;
  CONF_set_nconf(&CStack_80,hash);
  psStack_84 = (stack_st_X509_EXTENSION *)0x0;
  if (req == (X509_CRL *)0x0) {
    psVar3 = NCONF_get_section(&CStack_80,(char *)name);
    if (psVar3 != (stack_st_CONF_VALUE *)0x0) {
      iVar2 = 0;
      while( true ) {
        iVar5 = (*(code *)PTR_sk_num_006a6e2c)(psVar3);
        if (iVar5 <= iVar2) break;
        iVar5 = (*(code *)PTR_sk_value_006a6e24)(psVar3,iVar2);
        name = pXVar6;
        pXVar4 = X509V3_EXT_nconf(&CStack_80,pXVar6,*(char **)(iVar5 + 4),*(char **)(iVar5 + 8));
        if (pXVar4 == (X509_EXTENSION *)0x0) goto LAB_00587748;
        iVar2 = iVar2 + 1;
        (*(code *)PTR_X509_EXTENSION_free_006a7168)(pXVar4);
      }
      iVar2 = 1;
      goto LAB_0058774c;
    }
  }
  else {
    psVar3 = NCONF_get_section(&CStack_80,(char *)name);
    if (psVar3 != (stack_st_CONF_VALUE *)0x0) {
      iVar2 = 0;
      while( true ) {
        iVar5 = (*(code *)PTR_sk_num_006a6e2c)(psVar3);
        if (iVar5 <= iVar2) break;
        iVar5 = (*(code *)PTR_sk_value_006a6e24)(psVar3,iVar2);
        name = pXVar6;
        pXVar4 = X509V3_EXT_nconf(&CStack_80,pXVar6,*(char **)(iVar5 + 4),*(char **)(iVar5 + 8));
        if (pXVar4 == (X509_EXTENSION *)0x0) goto LAB_00587748;
        X509v3_add_ext(&psStack_84,pXVar4,-1);
        iVar2 = iVar2 + 1;
        (*(code *)PTR_X509_EXTENSION_free_006a7168)(pXVar4);
      }
      iVar2 = X509_REQ_add_extensions((X509_REQ *)req,psStack_84);
      name = (X509V3_CTX *)PTR_X509_EXTENSION_free_006a7168;
      (*(code *)PTR_sk_pop_free_006a7058)(psStack_84);
      goto LAB_0058774c;
    }
  }
LAB_00587748:
  iVar2 = 0;
LAB_0058774c:
  if (ppiStack_74 == *(int ***)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return **ppiStack_74 - *(int *)name->flags;
}

