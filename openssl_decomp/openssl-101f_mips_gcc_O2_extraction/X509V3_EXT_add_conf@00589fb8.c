
int X509V3_EXT_add_conf(lhash_st_CONF_VALUE *conf,X509V3_CTX *ctx,char *section,X509 *cert)

{
  undefined *puVar1;
  int iVar2;
  stack_st_CONF_VALUE *psVar3;
  X509_EXTENSION *pXVar4;
  int iVar5;
  lhash_st_CONF_VALUE *plVar6;
  X509V3_CTX *pXVar7;
  X509V3_CTX *name;
  X509 *req;
  X509_PUBKEY **unaff_s5;
  X509_CINF *pXVar8;
  stack_st_X509_EXTENSION *psStack_cc;
  CONF CStack_c8;
  int **ppiStack_bc;
  X509 *pXStack_b4;
  X509V3_CTX *pXStack_b0;
  stack_st_CONF_VALUE *psStack_ac;
  CONF *pCStack_a8;
  X509V3_CTX *pXStack_a4;
  X509_PUBKEY **ppXStack_a0;
  undefined *puStack_9c;
  CONF CStack_78;
  lhash_st_CONF_VALUE *plStack_6c;
  X509 *pXStack_68;
  X509V3_CTX *pXStack_64;
  stack_st_CONF_VALUE *psStack_60;
  CONF *pCStack_5c;
  X509V3_CTX *pXStack_58;
  X509_PUBKEY **ppXStack_54;
  undefined *puStack_50;
  code *pcStack_4c;
  undefined *local_38;
  CONF CStack_30;
  lhash_st_CONF_VALUE *local_24;
  
  puStack_50 = PTR___stack_chk_guard_006aabf0;
  pCStack_5c = &CStack_30;
  local_38 = &_gp;
  local_24 = *(lhash_st_CONF_VALUE **)PTR___stack_chk_guard_006aabf0;
  pXStack_b0 = (X509V3_CTX *)section;
  pXStack_b4 = cert;
  CONF_set_nconf(pCStack_5c,conf);
  pXStack_a4 = (X509V3_CTX *)section;
  if (cert == (X509 *)0x0) {
    psStack_60 = NCONF_get_section(pCStack_5c,section);
    if (psStack_60 == (stack_st_CONF_VALUE *)0x0) goto LAB_0058a0ec;
LAB_0058a124:
    cert = (X509 *)0x0;
    while( true ) {
      iVar2 = (**(code **)(local_38 + -0x7fb4))(psStack_60);
      if (iVar2 <= (int)cert) break;
      iVar2 = (**(code **)(local_38 + -0x7fbc))(psStack_60,cert);
      pXStack_b4 = *(X509 **)(iVar2 + 8);
      pXStack_b0 = *(X509V3_CTX **)(iVar2 + 4);
      pXStack_a4 = ctx;
      pXVar4 = X509V3_EXT_nconf(pCStack_5c,ctx,(char *)pXStack_b0,(char *)pXStack_b4);
      if (pXVar4 == (X509_EXTENSION *)0x0) goto LAB_0058a0ec;
      cert = (X509 *)((int)&cert->cert_info + 1);
      (**(code **)(local_38 + -0x7c78))(pXVar4);
    }
    iVar2 = 1;
  }
  else {
    pXVar8 = cert->cert_info;
    psStack_60 = NCONF_get_section(pCStack_5c,section);
    unaff_s5 = (X509_PUBKEY **)&pXVar8->extensions;
    if (psStack_60 == (stack_st_CONF_VALUE *)0x0) {
LAB_0058a0ec:
      iVar2 = 0;
    }
    else {
      if (unaff_s5 == (X509_PUBKEY **)0x0) goto LAB_0058a124;
      cert = (X509 *)0x0;
      while( true ) {
        iVar2 = (**(code **)(local_38 + -0x7fb4))(psStack_60);
        if (iVar2 <= (int)cert) break;
        iVar2 = (**(code **)(local_38 + -0x7fbc))(psStack_60,cert);
        pXStack_b4 = *(X509 **)(iVar2 + 8);
        pXStack_b0 = *(X509V3_CTX **)(iVar2 + 4);
        pXStack_a4 = ctx;
        section = (char *)X509V3_EXT_nconf(pCStack_5c,ctx,(char *)pXStack_b0,(char *)pXStack_b4);
        if ((X509V3_CTX *)section == (X509V3_CTX *)0x0) goto LAB_0058a0ec;
        pXStack_b0 = (X509V3_CTX *)0xffffffff;
        pXStack_a4 = (X509V3_CTX *)section;
        X509v3_add_ext((stack_st_X509_EXTENSION **)unaff_s5,(X509_EXTENSION *)section,-1);
        cert = (X509 *)((int)&cert->cert_info + 1);
        (**(code **)(local_38 + -0x7c78))(section);
      }
      iVar2 = 1;
    }
  }
  if (local_24 == *(lhash_st_CONF_VALUE **)puStack_50) {
    return iVar2;
  }
  pcStack_4c = X509V3_EXT_CRL_add_conf;
  plVar6 = local_24;
  (**(code **)(local_38 + -0x5328))();
  puStack_9c = PTR___stack_chk_guard_006aabf0;
  pCStack_a8 = &CStack_78;
  plStack_6c = *(lhash_st_CONF_VALUE **)PTR___stack_chk_guard_006aabf0;
  name = pXStack_b0;
  req = pXStack_b4;
  pXStack_68 = cert;
  pXStack_64 = (X509V3_CTX *)section;
  pXStack_58 = ctx;
  ppXStack_54 = unaff_s5;
  CONF_set_nconf(pCStack_a8,plVar6);
  pXVar7 = pXStack_b0;
  if (pXStack_b4 == (X509 *)0x0) {
    psStack_ac = NCONF_get_section(pCStack_a8,(char *)pXStack_b0);
    if (psStack_ac == (stack_st_CONF_VALUE *)0x0) goto LAB_0058a2cc;
LAB_0058a304:
    pXStack_b4 = (X509 *)0x0;
    while( true ) {
      iVar2 = (*(code *)PTR_sk_num_006a7f2c)(psStack_ac);
      if (iVar2 <= (int)pXStack_b4) break;
      iVar2 = (*(code *)PTR_sk_value_006a7f24)(psStack_ac,pXStack_b4);
      req = *(X509 **)(iVar2 + 8);
      name = *(X509V3_CTX **)(iVar2 + 4);
      pXVar7 = pXStack_a4;
      pXVar4 = X509V3_EXT_nconf(pCStack_a8,pXStack_a4,(char *)name,(char *)req);
      if (pXVar4 == (X509_EXTENSION *)0x0) goto LAB_0058a2cc;
      pXStack_b4 = (X509 *)((int)&pXStack_b4->cert_info + 1);
      (*(code *)PTR_X509_EXTENSION_free_006a8268)(pXVar4);
    }
    iVar2 = 1;
  }
  else {
    pXVar8 = pXStack_b4->cert_info;
    psStack_ac = NCONF_get_section(pCStack_a8,(char *)pXStack_b0);
    unaff_s5 = &pXVar8->key;
    if (psStack_ac == (stack_st_CONF_VALUE *)0x0) {
LAB_0058a2cc:
      iVar2 = 0;
    }
    else {
      if (unaff_s5 == (X509_PUBKEY **)0x0) goto LAB_0058a304;
      pXStack_b4 = (X509 *)0x0;
      while( true ) {
        iVar2 = (*(code *)PTR_sk_num_006a7f2c)(psStack_ac);
        if (iVar2 <= (int)pXStack_b4) break;
        iVar2 = (*(code *)PTR_sk_value_006a7f24)(psStack_ac,pXStack_b4);
        req = *(X509 **)(iVar2 + 8);
        name = *(X509V3_CTX **)(iVar2 + 4);
        pXVar7 = pXStack_a4;
        pXStack_b0 = (X509V3_CTX *)X509V3_EXT_nconf(pCStack_a8,pXStack_a4,(char *)name,(char *)req);
        if (pXStack_b0 == (X509V3_CTX *)0x0) goto LAB_0058a2cc;
        name = (X509V3_CTX *)0xffffffff;
        pXVar7 = pXStack_b0;
        X509v3_add_ext((stack_st_X509_EXTENSION **)unaff_s5,(X509_EXTENSION *)pXStack_b0,-1);
        pXStack_b4 = (X509 *)((int)&pXStack_b4->cert_info + 1);
        (*(code *)PTR_X509_EXTENSION_free_006a8268)(pXStack_b0);
      }
      iVar2 = 1;
    }
  }
  if (plStack_6c == *(lhash_st_CONF_VALUE **)puStack_9c) {
    return iVar2;
  }
  plVar6 = plStack_6c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  ppiStack_bc = *(int ***)PTR___stack_chk_guard_006aabf0;
  ppXStack_a0 = unaff_s5;
  CONF_set_nconf(&CStack_c8,plVar6);
  psStack_cc = (stack_st_X509_EXTENSION *)0x0;
  if (req == (X509 *)0x0) {
    psVar3 = NCONF_get_section(&CStack_c8,(char *)name);
    if (psVar3 != (stack_st_CONF_VALUE *)0x0) {
      iVar2 = 0;
      while( true ) {
        iVar5 = (*(code *)PTR_sk_num_006a7f2c)(psVar3);
        if (iVar5 <= iVar2) break;
        iVar5 = (*(code *)PTR_sk_value_006a7f24)(psVar3,iVar2);
        name = pXVar7;
        pXVar4 = X509V3_EXT_nconf(&CStack_c8,pXVar7,*(char **)(iVar5 + 4),*(char **)(iVar5 + 8));
        if (pXVar4 == (X509_EXTENSION *)0x0) goto LAB_0058a4b8;
        iVar2 = iVar2 + 1;
        (*(code *)PTR_X509_EXTENSION_free_006a8268)(pXVar4);
      }
      iVar2 = 1;
      goto LAB_0058a4bc;
    }
  }
  else {
    psVar3 = NCONF_get_section(&CStack_c8,(char *)name);
    if (psVar3 != (stack_st_CONF_VALUE *)0x0) {
      iVar2 = 0;
      while( true ) {
        iVar5 = (*(code *)PTR_sk_num_006a7f2c)(psVar3);
        if (iVar5 <= iVar2) break;
        iVar5 = (*(code *)PTR_sk_value_006a7f24)(psVar3,iVar2);
        name = pXVar7;
        pXVar4 = X509V3_EXT_nconf(&CStack_c8,pXVar7,*(char **)(iVar5 + 4),*(char **)(iVar5 + 8));
        if (pXVar4 == (X509_EXTENSION *)0x0) goto LAB_0058a4b8;
        X509v3_add_ext(&psStack_cc,pXVar4,-1);
        iVar2 = iVar2 + 1;
        (*(code *)PTR_X509_EXTENSION_free_006a8268)(pXVar4);
      }
      iVar2 = X509_REQ_add_extensions((X509_REQ *)req,psStack_cc);
      name = (X509V3_CTX *)PTR_X509_EXTENSION_free_006a8268;
      (*(code *)PTR_sk_pop_free_006a8158)(psStack_cc);
      goto LAB_0058a4bc;
    }
  }
LAB_0058a4b8:
  iVar2 = 0;
LAB_0058a4bc:
  if (ppiStack_bc == *(int ***)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return **ppiStack_bc - (int)((ASN1_OBJECT *)name->flags)->sn;
}

