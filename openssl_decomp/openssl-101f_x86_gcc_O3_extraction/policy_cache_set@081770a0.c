
X509_POLICY_CACHE * policy_cache_set(X509 *param_1)

{
  _STACK **pp_Var1;
  X509_POLICY_CACHE *pXVar2;
  _STACK *p_Var3;
  _STACK *a;
  long lVar4;
  _func_257 *p_Var5;
  _STACK *p_Var6;
  _STACK *data;
  int iVar7;
  void *pvVar8;
  int iVar9;
  _STACK *p_Var10;
  int in_GS_OFFSET;
  _STACK *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pXVar2 = param_1->policy_cache;
  if (pXVar2 != (X509_POLICY_CACHE *)0x0) goto LAB_081770be;
  CRYPTO_lock(0,9,(char *)0x3,(int)"pcy_cache.c");
  p_Var3 = (_STACK *)CRYPTO_malloc(0x14,"pcy_cache.c",0x89);
  p_Var6 = p_Var3;
  if (p_Var3 != (_STACK *)0x0) {
    p_Var3->num = 0;
    p_Var3->data = (char **)0x0;
    p_Var3->sorted = -1;
    p_Var3->num_alloc = -1;
    p_Var3->comp = (_func_257 *)0xffffffff;
    param_1->policy_cache = (X509_POLICY_CACHE *)p_Var3;
    a = (_STACK *)X509_get_ext_d2i(param_1,0x191,(int *)&local_24,(int *)0x0);
    if (a == (_STACK *)0x0) {
      p_Var6 = a;
      if (local_24 != (_STACK *)0xffffffff) goto LAB_08177238;
LAB_081771a1:
      p_Var6 = (_STACK *)X509_get_ext_d2i(param_1,0x59,(int *)&local_24,(int *)0x0);
      p_Var10 = local_24;
      if (p_Var6 == (_STACK *)0x0) {
        if (local_24 == (_STACK *)0xffffffff) goto LAB_08177210;
        goto LAB_08177238;
      }
      pp_Var1 = (_STACK **)param_1->policy_cache;
      data = (_STACK *)sk_num(p_Var6);
      if (data == (_STACK *)0x0) {
LAB_081771dd:
        sk_pop_free(p_Var6,POLICYINFO_free);
LAB_081771f1:
        sk_pop_free(pp_Var1[1],policy_data_free);
        pp_Var1[1] = (_STACK *)0x0;
        p_Var6 = data;
        goto LAB_08177210;
      }
      data = sk_new(policy_data_cmp);
      pp_Var1[1] = data;
      if (data == (_STACK *)0x0) goto LAB_081771dd;
      for (iVar9 = 0; iVar7 = sk_num(p_Var6), iVar9 < iVar7; iVar9 = iVar9 + 1) {
        pvVar8 = sk_value(p_Var6,iVar9);
        data = (_STACK *)policy_data_new(pvVar8,0,p_Var10);
        if (data == (_STACK *)0x0) goto LAB_081771dd;
        iVar7 = OBJ_obj2nid((ASN1_OBJECT *)data->data);
        if (iVar7 != 0x2ea) {
          iVar7 = sk_find(pp_Var1[1],data);
          if (iVar7 != -1) goto LAB_08177374;
          iVar7 = sk_push(pp_Var1[1],data);
          if (iVar7 != 0) goto LAB_081772d0;
LAB_08177353:
          policy_data_free();
          sk_pop_free(p_Var6,POLICYINFO_free);
          goto LAB_081771f1;
        }
        if (*pp_Var1 != (_STACK *)0x0) {
LAB_08177374:
          param_1->ex_flags = param_1->ex_flags | 0x800;
          goto LAB_08177353;
        }
        *pp_Var1 = data;
LAB_081772d0:
      }
      sk_pop_free(p_Var6,POLICYINFO_free);
      local_24 = (_STACK *)0x1;
      p_Var6 = (_STACK *)X509_get_ext_d2i(param_1,0x2eb,(int *)&local_24,(int *)0x0);
      if (p_Var6 == (_STACK *)0x0) {
        if (local_24 == (_STACK *)0xffffffff) goto LAB_081773df;
        goto LAB_08177238;
      }
      local_24 = (_STACK *)policy_cache_set_mapping(param_1,p_Var6);
      p_Var6 = local_24;
      if ((int)local_24 < 1) goto LAB_08177238;
LAB_081773df:
      p_Var6 = (_STACK *)X509_get_ext_d2i(param_1,0x2ec,(int *)&local_24,(int *)0x0);
      p_Var10 = p_Var6;
      if (p_Var6 == (_STACK *)0x0) {
        if (local_24 == (_STACK *)0xffffffff) {
          if (a == (_STACK *)0x0) goto LAB_08177210;
          goto LAB_08177245;
        }
        goto LAB_08177238;
      }
      if (p_Var6->data != (char **)0x102) {
        p_Var6 = (_STACK *)ASN1_INTEGER_get((ASN1_INTEGER *)p_Var6);
        p_Var3->sorted = (int)p_Var6;
        if (a == (_STACK *)0x0) goto LAB_08177255;
        goto LAB_08177245;
      }
      param_1->ex_flags = param_1->ex_flags | 0x800;
      if (a != (_STACK *)0x0) goto LAB_08177245;
LAB_08177255:
      ASN1_INTEGER_free((ASN1_INTEGER *)p_Var10);
    }
    else {
      p_Var6 = (_STACK *)a->num;
      if (p_Var6 == (_STACK *)0x0) {
        p_Var6 = (_STACK *)a->data;
        if (p_Var6 != (_STACK *)0x0) goto LAB_08177185;
      }
      else if (p_Var6->data != (char **)0x102) {
        lVar4 = ASN1_INTEGER_get((ASN1_INTEGER *)p_Var6);
        p_Var3->num_alloc = lVar4;
        p_Var6 = (_STACK *)a->data;
        if (p_Var6 == (_STACK *)0x0) goto LAB_081771a1;
LAB_08177185:
        if (p_Var6->data != (char **)0x102) {
          p_Var5 = (_func_257 *)ASN1_INTEGER_get((ASN1_INTEGER *)p_Var6);
          p_Var3->comp = p_Var5;
          goto LAB_081771a1;
        }
      }
LAB_08177238:
      param_1->ex_flags = param_1->ex_flags | 0x800;
      if (a != (_STACK *)0x0) {
        p_Var10 = (_STACK *)0x0;
LAB_08177245:
        POLICY_CONSTRAINTS_free((POLICY_CONSTRAINTS *)a);
        if (p_Var10 != (_STACK *)0x0) goto LAB_08177255;
      }
    }
  }
LAB_08177210:
  CRYPTO_lock((int)p_Var6,10,(char *)0x3,(int)"pcy_cache.c");
  pXVar2 = param_1->policy_cache;
LAB_081770be:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pXVar2;
}

