
int X509V3_EXT_REQ_add_nconf(CONF *conf,X509V3_CTX *ctx,char *section,X509_REQ *req)

{
  undefined *puVar1;
  stack_st_CONF_VALUE *psVar2;
  X509_EXTENSION *pXVar3;
  int iVar4;
  int iVar5;
  code *UNRECOVERED_JUMPTABLE;
  stack_st_X509_EXTENSION *local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_30 = (stack_st_X509_EXTENSION *)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (req == (X509_REQ *)0x0) {
    psVar2 = NCONF_get_section(conf,section);
    if (psVar2 != (stack_st_CONF_VALUE *)0x0) {
      iVar5 = 0;
      while( true ) {
        iVar4 = (*(code *)PTR_sk_num_006a7f2c)(psVar2);
        if (iVar4 <= iVar5) break;
        iVar4 = (*(code *)PTR_sk_value_006a7f24)(psVar2,iVar5);
        pXVar3 = X509V3_EXT_nconf(conf,ctx,*(char **)(iVar4 + 4),*(char **)(iVar4 + 8));
        if (pXVar3 == (X509_EXTENSION *)0x0) goto LAB_00589c44;
        iVar5 = iVar5 + 1;
        (*(code *)PTR_X509_EXTENSION_free_006a8268)(pXVar3);
      }
      iVar5 = 1;
      goto LAB_00589c48;
    }
  }
  else {
    psVar2 = NCONF_get_section(conf,section);
    if (psVar2 != (stack_st_CONF_VALUE *)0x0) {
      iVar5 = 0;
      while( true ) {
        iVar4 = (*(code *)PTR_sk_num_006a7f2c)(psVar2);
        if (iVar4 <= iVar5) break;
        iVar4 = (*(code *)PTR_sk_value_006a7f24)(psVar2,iVar5);
        pXVar3 = X509V3_EXT_nconf(conf,ctx,*(char **)(iVar4 + 4),*(char **)(iVar4 + 8));
        if (pXVar3 == (X509_EXTENSION *)0x0) goto LAB_00589c44;
        X509v3_add_ext(&local_30,pXVar3,-1);
        iVar5 = iVar5 + 1;
        (*(code *)PTR_X509_EXTENSION_free_006a8268)(pXVar3);
      }
      iVar5 = X509_REQ_add_extensions(req,local_30);
      (*(code *)PTR_sk_pop_free_006a8158)(local_30,PTR_X509_EXTENSION_free_006a8268);
      goto LAB_00589c48;
    }
  }
LAB_00589c44:
  iVar5 = 0;
LAB_00589c48:
  if (local_2c == *(int *)puVar1) {
    return iVar5;
  }
  iVar5 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (((*(int *)(iVar5 + 0x18) != 0) && (*(code ***)(iVar5 + 0x14) != (code **)0x0)) &&
     (UNRECOVERED_JUMPTABLE = **(code ***)(iVar5 + 0x14), UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00589d40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar5 = (*UNRECOVERED_JUMPTABLE)(*(int *)(iVar5 + 0x18));
    return iVar5;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x8f,0x94,"v3_conf.c",0x185);
  return 0;
}

