
int X509V3_EXT_add_conf(lhash_st_CONF_VALUE *conf,X509V3_CTX *ctx,char *section,X509 *cert)

{
  stack_st_X509_EXTENSION **x;
  _STACK *p_Var1;
  void *pvVar2;
  X509_EXTENSION *pXVar3;
  int iVar4;
  int iVar5;
  int in_GS_OFFSET;
  CONF local_2c;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  CONF_set_nconf(&local_2c,conf);
  if (cert == (X509 *)0x0) {
    p_Var1 = (_STACK *)NCONF_get_section(&local_2c,section);
    if (p_Var1 != (_STACK *)0x0) goto LAB_08168500;
  }
  else {
    x = &cert->cert_info->extensions;
    p_Var1 = (_STACK *)NCONF_get_section(&local_2c,section);
    if (p_Var1 != (_STACK *)0x0) {
      iVar5 = 0;
      if (x != (stack_st_X509_EXTENSION **)0x0) {
        for (; iVar4 = sk_num(p_Var1), iVar5 < iVar4; iVar5 = iVar5 + 1) {
          pvVar2 = sk_value(p_Var1,iVar5);
          pXVar3 = X509V3_EXT_nconf(&local_2c,ctx,*(char **)((int)pvVar2 + 4),
                                    *(char **)((int)pvVar2 + 8));
          if (pXVar3 == (X509_EXTENSION *)0x0) goto LAB_081684e8;
          X509v3_add_ext(x,pXVar3,-1);
          X509_EXTENSION_free(pXVar3);
        }
        iVar5 = 1;
        goto LAB_081684ea;
      }
LAB_08168500:
      for (iVar5 = 0; iVar4 = sk_num(p_Var1), iVar5 < iVar4; iVar5 = iVar5 + 1) {
        pvVar2 = sk_value(p_Var1,iVar5);
        pXVar3 = X509V3_EXT_nconf(&local_2c,ctx,*(char **)((int)pvVar2 + 4),
                                  *(char **)((int)pvVar2 + 8));
        if (pXVar3 == (X509_EXTENSION *)0x0) goto LAB_081684e8;
        X509_EXTENSION_free(pXVar3);
      }
      iVar5 = 1;
      goto LAB_081684ea;
    }
  }
LAB_081684e8:
  iVar5 = 0;
LAB_081684ea:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}

