
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
  if (pXVar2 != (X509_POLICY_CACHE *)0x0) goto LAB_0817526e;
  CRYPTO_lock(0,9,(char *)0x3,(int)"pcy_cache.c");
  p_Var3 = (_STACK *)CRYPTO_malloc(0x14,"pcy_cache.c",0x83);
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
      if (local_24 != (_STACK *)0xffffffff) goto LAB_081753e8;
LAB_08175351:
      p_Var6 = (_STACK *)X509_get_ext_d2i(param_1,0x59,(int *)&local_24,(int *)0x0);
      p_Var10 = local_24;
      if (p_Var6 == (_STACK *)0x0) {
        if (local_24 == (_STACK *)0xffffffff) goto LAB_081753c0;
        goto LAB_081753e8;
      }
      pp_Var1 = (_STACK **)param_1->policy_cache;
      data = (_STACK *)sk_num(p_Var6);
      if (data == (_STACK *)0x0) {
LAB_0817538d:
        sk_pop_free(p_Var6,POLICYINFO_free);
LAB_081753a1:
        sk_pop_free(pp_Var1[1],policy_data_free);
        pp_Var1[1] = (_STACK *)0x0;
        p_Var6 = data;
        goto LAB_081753c0;
      }
      data = sk_new(policy_data_cmp);
      pp_Var1[1] = data;
      if (data == (_STACK *)0x0) goto LAB_0817538d;
      for (iVar9 = 0; iVar7 = sk_num(p_Var6), iVar9 < iVar7; iVar9 = iVar9 + 1) {
        pvVar8 = sk_value(p_Var6,iVar9);
        data = (_STACK *)policy_data_new(pvVar8,0,p_Var10);
        if (data == (_STACK *)0x0) goto LAB_0817538d;
        iVar7 = OBJ_obj2nid((ASN1_OBJECT *)data->data);
        if (iVar7 != 0x2ea) {
          iVar7 = sk_find(pp_Var1[1],data);
          if (iVar7 != -1) goto LAB_08175524;
          iVar7 = sk_push(pp_Var1[1],data);
          if (iVar7 != 0) goto LAB_08175480;
LAB_08175503:
          policy_data_free();
          sk_pop_free(p_Var6,POLICYINFO_free);
          goto LAB_081753a1;
        }
        if (*pp_Var1 != (_STACK *)0x0) {
LAB_08175524:
          param_1->ex_flags = param_1->ex_flags | 0x800;
          goto LAB_08175503;
        }
        *pp_Var1 = data;
LAB_08175480:
      }
      sk_pop_free(p_Var6,POLICYINFO_free);
      local_24 = (_STACK *)0x1;
      p_Var6 = (_STACK *)X509_get_ext_d2i(param_1,0x2eb,(int *)&local_24,(int *)0x0);
      if (p_Var6 == (_STACK *)0x0) {
        if (local_24 == (_STACK *)0xffffffff) goto LAB_0817558f;
        goto LAB_081753e8;
      }
      local_24 = (_STACK *)policy_cache_set_mapping(param_1,p_Var6);
      p_Var6 = local_24;
      if ((int)local_24 < 1) goto LAB_081753e8;
LAB_0817558f:
      p_Var6 = (_STACK *)X509_get_ext_d2i(param_1,0x2ec,(int *)&local_24,(int *)0x0);
      p_Var10 = p_Var6;
      if (p_Var6 == (_STACK *)0x0) {
        if (local_24 == (_STACK *)0xffffffff) {
          if (a == (_STACK *)0x0) goto LAB_081753c0;
          goto LAB_081753f5;
        }
        goto LAB_081753e8;
      }
      if (p_Var6->data != (char **)0x102) {
        p_Var6 = (_STACK *)ASN1_INTEGER_get((ASN1_INTEGER *)p_Var6);
        p_Var3->sorted = (int)p_Var6;
        if (a == (_STACK *)0x0) goto LAB_08175405;
        goto LAB_081753f5;
      }
      param_1->ex_flags = param_1->ex_flags | 0x800;
      if (a != (_STACK *)0x0) goto LAB_081753f5;
LAB_08175405:
      ASN1_INTEGER_free((ASN1_INTEGER *)p_Var10);
    }
    else {
      p_Var6 = (_STACK *)a->num;
      if (p_Var6 == (_STACK *)0x0) {
        p_Var6 = (_STACK *)a->data;
        if (p_Var6 != (_STACK *)0x0) goto LAB_08175335;
      }
      else if (p_Var6->data != (char **)0x102) {
        lVar4 = ASN1_INTEGER_get((ASN1_INTEGER *)p_Var6);
        p_Var3->num_alloc = lVar4;
        p_Var6 = (_STACK *)a->data;
        if (p_Var6 == (_STACK *)0x0) goto LAB_08175351;
LAB_08175335:
        if (p_Var6->data != (char **)0x102) {
          p_Var5 = (_func_257 *)ASN1_INTEGER_get((ASN1_INTEGER *)p_Var6);
          p_Var3->comp = p_Var5;
          goto LAB_08175351;
        }
      }
LAB_081753e8:
      param_1->ex_flags = param_1->ex_flags | 0x800;
      if (a != (_STACK *)0x0) {
        p_Var10 = (_STACK *)0x0;
LAB_081753f5:
        POLICY_CONSTRAINTS_free((POLICY_CONSTRAINTS *)a);
        if (p_Var10 != (_STACK *)0x0) goto LAB_08175405;
      }
    }
  }
LAB_081753c0:
  CRYPTO_lock((int)p_Var6,10,(char *)0x3,(int)"pcy_cache.c");
  pXVar2 = param_1->policy_cache;
LAB_0817526e:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pXVar2;
}

