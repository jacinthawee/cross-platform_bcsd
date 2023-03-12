
stack_st_CONF_VALUE *
i2v_AUTHORITY_INFO_ACCESS
          (X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,stack_st_CONF_VALUE *param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  stack_st_CONF_VALUE *psVar4;
  int *piVar5;
  int iVar6;
  GENERAL_NAME *pGVar7;
  int iVar8;
  undefined4 uVar9;
  X509V3_EXT_METHOD *method;
  X509V3_CTX *ctx;
  undefined4 uVar10;
  stack_st_CONF_VALUE *unaff_s0;
  int iVar11;
  int unaff_s2;
  code *pcVar12;
  CONF_VALUE CStack_e0;
  int iStack_d4;
  stack_st_CONF_VALUE *psStack_d0;
  int iStack_cc;
  int iStack_c8;
  stack_st_CONF_VALUE *psStack_c4;
  X509V3_CTX *pXStack_c0;
  char *pcStack_bc;
  char *pcStack_b8;
  X509V3_EXT_METHOD *pXStack_b4;
  undefined *puStack_b0;
  code *pcStack_ac;
  undefined4 local_98;
  undefined *local_90;
  undefined *local_88;
  X509V3_EXT_METHOD **local_84;
  undefined auStack_7c [80];
  X509V3_EXT_METHOD *local_2c;
  
  pcStack_b8 = "7 datafinal";
  puStack_b0 = auStack_7c;
  local_84 = (X509V3_EXT_METHOD **)PTR___stack_chk_guard_006aabf0;
  local_2c = *(X509V3_EXT_METHOD **)PTR___stack_chk_guard_006aabf0;
  local_90 = &_gp;
  local_88 = &DAT_006682f4;
  ctx = param_2;
  psVar4 = param_3;
  for (iStack_cc = 0; iVar3 = (**(code **)(local_90 + -0x7fb4))(param_2), iStack_cc < iVar3;
      iStack_cc = iStack_cc + 1) {
    unaff_s0 = (stack_st_CONF_VALUE *)(**(code **)(local_90 + -0x7fbc))(param_2,iStack_cc);
    ctx = (X509V3_CTX *)(unaff_s0->stack).data;
    psStack_c4 = i2v_GENERAL_NAME(param_1,(GENERAL_NAME *)ctx,psVar4);
    if (psStack_c4 == (stack_st_CONF_VALUE *)0x0) {
      pcVar12 = *(code **)(local_90 + -0x7e3c);
      param_3 = psVar4;
      goto LAB_00598880;
    }
    unaff_s2 = (**(code **)(local_90 + -0x7fbc))(psStack_c4,iStack_cc);
    (**(code **)(local_90 + -0x617c))(puStack_b0,0x50,(unaff_s0->stack).num);
    iVar3 = (**(code **)(local_90 + -0x53b0))(puStack_b0);
    iVar8 = (**(code **)(local_90 + -0x53b0))(*(undefined4 *)(unaff_s2 + 4));
    unaff_s0 = (stack_st_CONF_VALUE *)(iVar3 + iVar8 + 5);
    pcStack_b8 = (char *)(**(code **)(local_90 + -0x7dd8))(unaff_s0,"v3_info.c",0x76);
    if (pcStack_b8 == (char *)0x0) {
      param_3 = (stack_st_CONF_VALUE *)&DAT_00000041;
      ctx = (X509V3_CTX *)0x8a;
      local_98 = 0x79;
      (**(code **)(local_90 + -0x6eb0))(0x22,0x8a,0x41,"v3_info.c");
      psVar4 = (stack_st_CONF_VALUE *)0x0;
      goto LAB_0059883c;
    }
    (**(code **)(local_90 + -0x7e7c))(pcStack_b8,puStack_b0,unaff_s0);
    (**(code **)(local_90 + -0x7e78))(pcStack_b8,local_88,unaff_s0);
    ctx = *(X509V3_CTX **)(unaff_s2 + 4);
    param_3 = unaff_s0;
    (**(code **)(local_90 + -0x7e78))(pcStack_b8,ctx,unaff_s0);
    (**(code **)(local_90 + -0x7f58))(*(undefined4 *)(unaff_s2 + 4));
    *(char **)(unaff_s2 + 4) = pcStack_b8;
    psVar4 = psStack_c4;
  }
  pcVar12 = *(code **)(local_90 + -0x7e3c);
  psStack_c4 = psVar4;
  if (psVar4 == (stack_st_CONF_VALUE *)0x0) {
LAB_00598880:
    psVar4 = (stack_st_CONF_VALUE *)(*pcVar12)();
  }
LAB_0059883c:
  if (local_2c == *local_84) {
    return psVar4;
  }
  pcStack_ac = v2i_AUTHORITY_INFO_ACCESS;
  method = local_2c;
  (**(code **)(local_90 + -0x5328))();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  pcStack_bc = "v3_info.c";
  iStack_d4 = *(int *)PTR___stack_chk_guard_006aabf0;
  psStack_d0 = unaff_s0;
  iStack_c8 = unaff_s2;
  pXStack_c0 = param_2;
  pXStack_b4 = param_1;
  psVar4 = (stack_st_CONF_VALUE *)(*(code *)PTR_sk_new_null_006a80a4)();
  if (psVar4 == (stack_st_CONF_VALUE *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x8b,0x41,"v3_info.c",0x90);
    psVar4 = (stack_st_CONF_VALUE *)0x0;
  }
  else {
    for (iVar3 = 0; iVar8 = (*(code *)PTR_sk_num_006a7f2c)(param_3), iVar3 < iVar8;
        iVar3 = iVar3 + 1) {
      iVar8 = (*(code *)PTR_sk_value_006a7f24)(param_3,iVar3);
      piVar5 = (int *)(*(code *)PTR_ASN1_item_new_006a9778)(ACCESS_DESCRIPTION_it);
      if ((piVar5 == (int *)0x0) ||
         (iVar6 = (*(code *)PTR_sk_push_006a80a8)(psVar4,piVar5), iVar6 == 0)) {
        uVar10 = 0x41;
        uVar9 = 0x97;
LAB_00598a94:
        (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x8b,uVar10,"v3_info.c",uVar9);
LAB_00598aa8:
        (*(code *)PTR_sk_pop_free_006a8158)(psVar4,ACCESS_DESCRIPTION_free);
        psVar4 = (stack_st_CONF_VALUE *)0x0;
        break;
      }
      iVar11 = *(int *)(iVar8 + 4);
      iVar6 = (*(code *)PTR_strchr_006aab34)(iVar11,0x3b);
      if (iVar6 == 0) {
        uVar10 = 0x8f;
        uVar9 = 0x9c;
        goto LAB_00598a94;
      }
      CStack_e0.value = *(char **)(iVar8 + 8);
      CStack_e0.name = (char *)(iVar6 + 1);
      iVar6 = iVar6 - iVar11;
      pGVar7 = v2i_GENERAL_NAME_ex((GENERAL_NAME *)piVar5[1],method,ctx,&CStack_e0,0);
      if (pGVar7 == (GENERAL_NAME *)0x0) goto LAB_00598aa8;
      iVar11 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar6 + 1,"v3_info.c",0xa4);
      if (iVar11 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x8b,0x41,"v3_info.c",0xa5);
        goto LAB_00598aa8;
      }
      (*(code *)PTR_strncpy_006aaaec)(iVar11,*(undefined4 *)(iVar8 + 4),iVar6);
      puVar1 = PTR_OBJ_txt2obj_006a8100;
      *(undefined *)(iVar11 + iVar6) = 0;
      iVar8 = (*(code *)puVar1)(iVar11,0);
      *piVar5 = iVar8;
      if (iVar8 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x8b,0x77,"v3_info.c",0xac);
        (*(code *)PTR_ERR_add_error_data_006a9264)(2,"value=",iVar11);
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar11);
        goto LAB_00598aa8;
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar11);
    }
  }
  if (iStack_d4 != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x00598be4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    psVar4 = (stack_st_CONF_VALUE *)(*(code *)PTR_ASN1_item_free_006a977c)();
    return psVar4;
  }
  return psVar4;
}

