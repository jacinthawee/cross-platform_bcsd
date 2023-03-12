
X509_POLICY_CACHE * policy_cache_set(X509 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  POLICY_CONSTRAINTS *a;
  ASN1_INTEGER *pAVar3;
  long lVar4;
  _STACK *st;
  int iVar5;
  void *pvVar6;
  _STACK *p_Var7;
  int iVar8;
  void **ppvVar9;
  int local_2c [2];
  
  if (param_1->policy_cache != (X509_POLICY_CACHE *)0x0) {
    return param_1->policy_cache;
  }
  CRYPTO_lock(9,3,"pcy_cache.c",0xfb);
  puVar2 = (undefined4 *)CRYPTO_malloc(0x14,"pcy_cache.c",0x89);
  if (puVar2 == (undefined4 *)0x0) goto LAB_000d8a3e;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0xffffffff;
  puVar2[3] = 0xffffffff;
  puVar2[4] = 0xffffffff;
  param_1->policy_cache = (X509_POLICY_CACHE *)puVar2;
  a = (POLICY_CONSTRAINTS *)X509_get_ext_d2i(param_1,0x191,local_2c,(int *)0x0);
  if (a == (POLICY_CONSTRAINTS *)0x0) {
    if (local_2c[0] != -1) goto LAB_000d8a60;
LAB_000d89b0:
    st = (_STACK *)X509_get_ext_d2i(param_1,0x59,local_2c,(int *)0x0);
    iVar1 = local_2c[0];
    if (st == (_STACK *)0x0) {
      if (local_2c[0] == -1) goto LAB_000d8a3e;
      goto LAB_000d8a60;
    }
    ppvVar9 = (void **)param_1->policy_cache;
    iVar5 = sk_num(st);
    if (iVar5 == 0) {
LAB_000d89d2:
      iVar8 = 0;
    }
    else {
      iVar5 = 0;
      p_Var7 = sk_new(policy_data_cmp + 1);
      ppvVar9[1] = p_Var7;
      if (p_Var7 == (_STACK *)0x0) goto LAB_000d89d2;
      for (; iVar8 = sk_num(st), iVar5 < iVar8; iVar5 = iVar5 + 1) {
        pvVar6 = sk_value(st,iVar5);
        pvVar6 = (void *)policy_data_new(pvVar6,0,iVar1);
        if (pvVar6 == (void *)0x0) goto LAB_000d89d2;
        iVar8 = OBJ_obj2nid(*(ASN1_OBJECT **)((int)pvVar6 + 4));
        if (iVar8 != 0x2ea) {
          iVar8 = sk_find((_STACK *)ppvVar9[1],pvVar6);
          if (iVar8 != -1) goto LAB_000d8b18;
          iVar8 = sk_push((_STACK *)ppvVar9[1],pvVar6);
          if (iVar8 != 0) goto LAB_000d8a9e;
LAB_000d8aec:
          policy_data_free(pvVar6);
          goto LAB_000d89d4;
        }
        if (*ppvVar9 != (void *)0x0) {
LAB_000d8b18:
          iVar8 = -1;
          param_1->ex_flags = param_1->ex_flags | 0x800;
          goto LAB_000d8aec;
        }
        *ppvVar9 = pvVar6;
LAB_000d8a9e:
      }
      iVar8 = 1;
    }
LAB_000d89d4:
    sk_pop_free(st,POLICYINFO_free + 1);
    if (iVar8 != 1) {
      sk_pop_free((_STACK *)ppvVar9[1],policy_data_free);
      ppvVar9[1] = (void *)0x0;
      goto LAB_000d8a3e;
    }
    local_2c[0] = iVar8;
    pvVar6 = X509_get_ext_d2i(param_1,0x2eb,local_2c,(int *)0x0);
    if (pvVar6 == (void *)0x0) {
      if (local_2c[0] == -1) goto LAB_000d8a0a;
      goto LAB_000d8a60;
    }
    local_2c[0] = policy_cache_set_mapping(param_1,pvVar6);
    if (local_2c[0] < 1) goto LAB_000d8a60;
LAB_000d8a0a:
    pAVar3 = (ASN1_INTEGER *)X509_get_ext_d2i(param_1,0x2ec,local_2c,(int *)0x0);
    if (pAVar3 != (ASN1_INTEGER *)0x0) {
      if (pAVar3->type != 0x102) {
        lVar4 = ASN1_INTEGER_get(pAVar3);
        puVar2[2] = lVar4;
        goto LAB_000d8a2e;
      }
      goto LAB_000d8a62;
    }
    if (local_2c[0] != -1) goto LAB_000d8a60;
  }
  else {
    pAVar3 = a->requireExplicitPolicy;
    if (pAVar3 == (ASN1_INTEGER *)0x0) {
      pAVar3 = a->inhibitPolicyMapping;
      if (pAVar3 != (ASN1_INTEGER *)0x0) goto LAB_000d89a0;
    }
    else if (pAVar3->type != 0x102) {
      lVar4 = ASN1_INTEGER_get(pAVar3);
      pAVar3 = a->inhibitPolicyMapping;
      puVar2[3] = lVar4;
      if (pAVar3 == (ASN1_INTEGER *)0x0) goto LAB_000d89b0;
LAB_000d89a0:
      if (pAVar3->type != 0x102) {
        lVar4 = ASN1_INTEGER_get(pAVar3);
        puVar2[4] = lVar4;
        goto LAB_000d89b0;
      }
    }
LAB_000d8a60:
    pAVar3 = (ASN1_INTEGER *)0x0;
LAB_000d8a62:
    param_1->ex_flags = param_1->ex_flags | 0x800;
  }
LAB_000d8a2e:
  if (a != (POLICY_CONSTRAINTS *)0x0) {
    POLICY_CONSTRAINTS_free(a);
  }
  if (pAVar3 != (ASN1_INTEGER *)0x0) {
    ASN1_INTEGER_free(pAVar3);
  }
LAB_000d8a3e:
  CRYPTO_lock(10,3,"pcy_cache.c",0xfd);
  return param_1->policy_cache;
}

