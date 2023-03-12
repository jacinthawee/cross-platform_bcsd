
X509_POLICY_CACHE * policy_cache_set(X509 *param_1,undefined4 param_2)

{
  undefined *puVar1;
  X509_POLICY_CACHE *pXVar2;
  POLICY_CONSTRAINTS *a;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  ASN1_INTEGER *pAVar9;
  uint *puVar10;
  undefined4 *unaff_s0;
  int *piVar11;
  code *pcVar12;
  undefined auStack_74 [4];
  undefined4 uStack_70;
  uint *puStack_64;
  undefined4 *puStack_5c;
  char *pcStack_58;
  code *pcStack_54;
  undefined *local_40;
  int *local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pXVar2 = param_1->policy_cache;
  local_40 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (pXVar2 != (X509_POLICY_CACHE *)0x0) goto LAB_0059894c;
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,3,"pcy_cache.c",0xea);
  unaff_s0 = (undefined4 *)(**(code **)(local_40 + -0x7dd8))(0x14,"pcy_cache.c",0x83);
  if (unaff_s0 == (undefined4 *)0x0) {
LAB_00598ad0:
    pcVar12 = *(code **)(local_40 + -0x6c9c);
  }
  else {
    local_38 = &local_30;
    *unaff_s0 = 0;
    unaff_s0[1] = 0;
    unaff_s0[2] = 0xffffffff;
    unaff_s0[3] = 0xffffffff;
    unaff_s0[4] = 0xffffffff;
    param_1->policy_cache = (X509_POLICY_CACHE *)unaff_s0;
    a = (POLICY_CONSTRAINTS *)X509_get_ext_d2i(param_1,0x191,local_38,(int *)0x0);
    if (a != (POLICY_CONSTRAINTS *)0x0) {
      if (a->requireExplicitPolicy != (ASN1_INTEGER *)0x0) {
        if (a->requireExplicitPolicy->type == 0x102) goto LAB_00598b04;
        uVar3 = (**(code **)(local_40 + -0x7bd8))();
        pAVar9 = a->inhibitPolicyMapping;
        unaff_s0[3] = uVar3;
        if (pAVar9 == (ASN1_INTEGER *)0x0) goto LAB_00598a68;
LAB_00598a40:
        if (pAVar9->type != 0x102) {
          uVar3 = (**(code **)(local_40 + -0x7bd8))();
          unaff_s0[4] = uVar3;
          goto LAB_00598a68;
        }
        goto LAB_00598b04;
      }
      pAVar9 = a->inhibitPolicyMapping;
      if (pAVar9 != (ASN1_INTEGER *)0x0) goto LAB_00598a40;
      uVar6 = param_1->ex_flags;
LAB_00598b08:
      param_1->ex_flags = uVar6 | 0x800;
      if (a != (POLICY_CONSTRAINTS *)0x0) {
        pvVar4 = (void *)0x0;
LAB_00598b1c:
        POLICY_CONSTRAINTS_free(a);
        if (pvVar4 != (void *)0x0) {
LAB_00598b2c:
          pcVar12 = *(code **)(local_40 + -0x7f4c);
LAB_00598b30:
          (*pcVar12)(pvVar4);
        }
      }
      goto LAB_00598ad0;
    }
    if (local_30 != -1) goto LAB_00598b04;
LAB_00598a68:
    pvVar4 = X509_get_ext_d2i(param_1,0x59,local_38,(int *)0x0);
    if (pvVar4 != (void *)0x0) {
      piVar11 = (int *)param_1->policy_cache;
      local_34 = local_30;
      iVar5 = (**(code **)(local_40 + -0x7fb4))(pvVar4);
      if (iVar5 != 0) {
        iVar5 = (**(code **)(local_40 + -0x6d74))(policy_data_cmp);
        piVar11[1] = iVar5;
        if (iVar5 != 0) {
          for (iVar5 = 0; iVar8 = (**(code **)(local_40 + -0x7fb4))(pvVar4), iVar5 < iVar8;
              iVar5 = iVar5 + 1) {
            uVar3 = (**(code **)(local_40 + -0x7fbc))(pvVar4,iVar5);
            iVar8 = policy_data_new(uVar3,0,local_34);
            if (iVar8 == 0) goto LAB_00598aa4;
            iVar7 = (**(code **)(local_40 + -0x7cb4))(*(undefined4 *)(iVar8 + 4));
            if (iVar7 != 0x2ea) {
              iVar7 = (**(code **)(local_40 + -0x6d9c))(piVar11[1],iVar8);
              if (iVar7 != -1) goto LAB_00598d04;
              iVar7 = (**(code **)(local_40 + -0x7e38))(piVar11[1],iVar8);
              if (iVar7 != 0) goto LAB_00598bfc;
LAB_00598c38:
              policy_data_free(iVar8);
              (**(code **)(local_40 + -0x7d88))(pvVar4,*(undefined4 *)(local_40 + -0x5d44));
              goto LAB_00598ab8;
            }
            if (*piVar11 != 0) {
LAB_00598d04:
              param_1->ex_flags = param_1->ex_flags | 0x800;
              goto LAB_00598c38;
            }
            *piVar11 = iVar8;
LAB_00598bfc:
          }
          (**(code **)(local_40 + -0x7d88))(pvVar4,*(undefined4 *)(local_40 + -0x5d44));
          local_30 = 1;
          pvVar4 = X509_get_ext_d2i(param_1,0x2eb,local_38,(int *)0x0);
          if (pvVar4 == (void *)0x0) {
            if (local_30 == -1) goto LAB_00598cc0;
LAB_00598b04:
            uVar6 = param_1->ex_flags;
            goto LAB_00598b08;
          }
          local_30 = policy_cache_set_mapping(param_1,pvVar4);
          if (local_30 < 1) goto LAB_00598b04;
LAB_00598cc0:
          pvVar4 = X509_get_ext_d2i(param_1,0x2ec,local_38,(int *)0x0);
          if (pvVar4 == (void *)0x0) {
            if (local_30 == -1) {
              pcVar12 = *(code **)(local_40 + -0x6c9c);
              if (a == (POLICY_CONSTRAINTS *)0x0) goto LAB_00598ad8;
              goto LAB_00598b1c;
            }
            goto LAB_00598b04;
          }
          if (*(int *)((int)pvVar4 + 4) == 0x102) {
            param_1->ex_flags = param_1->ex_flags | 0x800;
            if (a != (POLICY_CONSTRAINTS *)0x0) goto LAB_00598b1c;
            goto LAB_00598b2c;
          }
          uVar3 = (**(code **)(local_40 + -0x7bd8))(pvVar4);
          unaff_s0[2] = uVar3;
          if (a != (POLICY_CONSTRAINTS *)0x0) goto LAB_00598b1c;
          pcVar12 = *(code **)(local_40 + -0x7f4c);
          goto LAB_00598b30;
        }
      }
LAB_00598aa4:
      (**(code **)(local_40 + -0x7d88))(pvVar4,*(undefined4 *)(local_40 + -0x5d44));
LAB_00598ab8:
      (**(code **)(local_40 + -0x7d88))(piVar11[1],*(undefined4 *)(local_40 + -0x5d48));
      piVar11[1] = 0;
      goto LAB_00598ad0;
    }
    pcVar12 = *(code **)(local_40 + -0x6c9c);
    if (local_30 != -1) goto LAB_00598b04;
  }
LAB_00598ad8:
  param_2 = 3;
  (*pcVar12)(10,3,"pcy_cache.c",0xec);
  pXVar2 = param_1->policy_cache;
LAB_0059894c:
  if (local_2c == *(int *)puVar1) {
    return pXVar2;
  }
  pcStack_54 = policy_cache_find_data;
  iVar5 = local_2c;
  (**(code **)(local_40 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pcStack_58 = "encrypt";
  puStack_64 = *(uint **)PTR___stack_chk_guard_006a9ae8;
  uStack_70 = param_2;
  puStack_5c = unaff_s0;
  iVar8 = (*(code *)PTR_sk_find_006a8044)(*(undefined4 *)(iVar5 + 4),auStack_74);
  if (iVar8 == -1) {
    pXVar2 = (X509_POLICY_CACHE *)0x0;
  }
  else {
    pXVar2 = (X509_POLICY_CACHE *)(*(code *)PTR_sk_value_006a6e24)(*(undefined4 *)(iVar5 + 4),iVar8)
    ;
  }
  if (puStack_64 != *(uint **)puVar1) {
    puVar10 = puStack_64;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(puVar10[1]);
    if ((*puVar10 & 4) == 0) {
      (*(code *)PTR_sk_pop_free_006a7058)(puVar10[2],PTR_POLICYQUALINFO_free_006a90ac);
    }
    (*(code *)PTR_sk_pop_free_006a7058)(puVar10[3],PTR_ASN1_OBJECT_free_006a7004);
                    /* WARNING: Could not recover jumptable at 0x00598e80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pXVar2 = (X509_POLICY_CACHE *)(*(code *)PTR_CRYPTO_free_006a6e88)(puVar10);
    return pXVar2;
  }
  return pXVar2;
}

