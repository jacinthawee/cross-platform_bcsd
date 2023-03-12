
/* WARNING: Could not reconcile some variable overlaps */

int TS_RESP_verify_response(undefined1 *param_1,undefined4 param_2)

{
  bool bVar1;
  undefined *puVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  char *pcVar10;
  undefined4 uVar11;
  undefined4 unaff_s4;
  undefined4 *puVar12;
  code *pcVar13;
  undefined4 uStack_1a4;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  int iStack_194;
  undefined1 *puStack_190;
  uint *puStack_18c;
  undefined4 *puStack_188;
  undefined4 *puStack_184;
  undefined4 uStack_180;
  code *pcStack_17c;
  undefined4 *local_168;
  char *local_164;
  undefined4 *local_160;
  undefined *local_158;
  uint **local_14c;
  char *local_148;
  char *local_144;
  char *local_13c;
  undefined4 local_138;
  char *local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  uint *local_2c;
  
  local_14c = (uint **)PTR___stack_chk_guard_006aabf0;
  local_158 = &_gp;
  local_2c = *(uint **)PTR___stack_chk_guard_006aabf0;
  puStack_184 = (undefined4 *)TS_RESP_get_token(param_2);
  pcVar3 = (char *)TS_RESP_get_tst_info(param_2);
  puStack_188 = (undefined4 *)TS_RESP_get_status_info(param_2);
  puStack_190 = (undefined1 *)(**(code **)(local_158 + -0x7bc4))(*puStack_188);
  local_12c = 0;
  (**(code **)(local_158 + -0x53e0))(&local_128,0,0xfc);
  if (puStack_190 < &SUB_00000002) {
    local_13c = (char *)0x0;
    puStack_190 = (undefined1 *)TS_TST_INFO_get_tsa(pcVar3);
    uVar8 = *(uint *)param_1;
    local_138 = 0;
    local_134 = (char *)0x0;
    local_130 = 0;
    if ((uVar8 & 1) == 0) {
LAB_005c6884:
      if ((uVar8 & 2) != 0) {
        iVar4 = TS_TST_INFO_get_version(pcVar3);
        if (iVar4 == 1) {
          uVar8 = *(uint *)param_1;
          goto LAB_005c6890;
        }
        pcVar13 = *(code **)(local_158 + -0x6eb0);
        uVar6 = 0x71;
        local_168 = (undefined4 *)0x1ac;
LAB_005c6a64:
        pcVar10 = (char *)0x95;
        (*pcVar13)(0x2f,0x95,uVar6,"ts_rsp_verify.c");
        goto LAB_005c698c;
      }
LAB_005c6890:
      if ((uVar8 & 4) == 0) {
LAB_005c689c:
        if ((uVar8 & 8) != 0) {
          pcVar10 = *(char **)((int)param_1 + 0x14);
          iVar4 = TS_check_imprints(*(uint *)((int)param_1 + 0x10),pcVar10,
                                    *(uint *)((int)param_1 + 0x18),pcVar3);
          if (iVar4 == 0) goto LAB_005c698c;
          uVar8 = *(uint *)param_1;
        }
        if ((uVar8 & 0x10) != 0) {
          pcVar10 = pcVar3;
          local_168 = &local_130;
          iVar4 = TS_compute_imprint(*(uint *)((int)param_1 + 0x1c),pcVar3,&local_138,&local_134);
          if ((iVar4 == 0) ||
             (pcVar10 = local_134, iVar4 = TS_check_imprints(local_138,local_134,local_130,pcVar3),
             iVar4 == 0)) goto LAB_005c698c;
          uVar8 = *(uint *)param_1;
        }
        if ((uVar8 & 0x20) == 0) {
LAB_005c68c0:
          if (((uVar8 & 0x40) != 0) && ((char **)puStack_190 != (char **)0x0)) {
            iVar4 = TS_check_signer_name(puStack_190,local_13c);
            if (iVar4 == 0) {
              pcVar13 = *(code **)(local_158 + -0x6eb0);
              uVar6 = 0x6f;
              local_168 = (undefined4 *)0x1cb;
              goto LAB_005c6a64;
            }
            uVar8 = *(uint *)param_1;
          }
          pcVar10 = local_13c;
          if (((uVar8 & 0x80) == 0) ||
             (iVar4 = TS_check_signer_name(*(uint *)((int)param_1 + 0x24),local_13c), iVar4 != 0)) {
            (**(code **)(local_158 + -0x7f50))(local_13c);
            (**(code **)(local_158 + -0x6f4c))(local_138);
            (**(code **)(local_158 + -0x7f58))(local_134);
            iVar4 = 1;
            goto LAB_005c6798;
          }
          pcVar13 = *(code **)(local_158 + -0x6eb0);
          uVar6 = 0x70;
          local_168 = (undefined4 *)0x1d3;
          goto LAB_005c6a64;
        }
        puStack_188 = *(undefined4 **)((int)param_1 + 0x20);
        iVar4 = TS_TST_INFO_get_nonce(pcVar3);
        if (iVar4 == 0) {
          pcVar13 = *(code **)(local_158 + -0x6eb0);
          uVar6 = 0x69;
          local_168 = (undefined4 *)0x2a1;
        }
        else {
          iVar4 = (**(code **)(local_158 + -0x6088))(puStack_188,iVar4);
          if (iVar4 == 0) {
            uVar8 = *(uint *)param_1;
            goto LAB_005c68c0;
          }
          pcVar13 = *(code **)(local_158 + -0x6eb0);
          uVar6 = 0x68;
          local_168 = (undefined4 *)0x2a8;
        }
        pcVar10 = (char *)0x65;
        (*pcVar13)(0x2f,0x65,uVar6,"ts_rsp_verify.c");
      }
      else {
        puStack_188 = *(undefined4 **)((int)param_1 + 0xc);
        uVar6 = TS_TST_INFO_get_policy_id(pcVar3);
        iVar4 = (**(code **)(local_158 + -0x60fc))(puStack_188,uVar6);
        if (iVar4 == 0) {
          uVar8 = *(uint *)param_1;
          goto LAB_005c689c;
        }
        local_168 = (undefined4 *)0x23f;
        pcVar10 = (char *)0x66;
        (**(code **)(local_158 + -0x6eb0))(0x2f,0x66,0x6c,"ts_rsp_verify.c");
      }
      (**(code **)(local_158 + -0x7f50))(local_13c);
      (**(code **)(local_158 + -0x6f4c))(local_138);
      (**(code **)(local_158 + -0x7f58))(local_134);
      iVar4 = 0;
    }
    else {
      pcVar10 = *(char **)((int)param_1 + 8);
      iVar4 = TS_RESP_verify_signature(puStack_184,pcVar10,*(uint *)((int)param_1 + 4),&local_13c);
      if (iVar4 != 0) {
        uVar8 = *(uint *)param_1;
        goto LAB_005c6884;
      }
LAB_005c698c:
      (**(code **)(local_158 + -0x7f50))(local_13c);
      (**(code **)(local_158 + -0x6f4c))(local_138);
      (**(code **)(local_158 + -0x7f58))(local_134);
      iVar4 = 0;
    }
  }
  else {
    if (puStack_190 < &DAT_00000006) {
      puStack_190 = TS_status_text + (int)puStack_190 * 4;
      local_144 = *(char **)puStack_190;
      iVar4 = (**(code **)(local_158 + -0x7fb4))(puStack_188[1]);
      if (0 < iVar4) goto LAB_005c65b8;
LAB_005c66f8:
      iVar4 = puStack_188[2];
      puStack_184 = (undefined4 *)0x0;
      local_148 = "7 datafinal";
      if (iVar4 != 0) goto LAB_005c67e8;
LAB_005c670c:
    }
    else {
      local_144 = "unknown code";
      iVar4 = (**(code **)(local_158 + -0x7fb4))(puStack_188[1]);
      if (iVar4 < 1) goto LAB_005c66f8;
LAB_005c65b8:
      param_1 = (undefined1 *)puStack_188[1];
      iVar4 = 0;
      for (puStack_190 = (undefined1 *)0x0; iVar5 = (**(code **)(local_158 + -0x7fb4))(param_1),
          (int)puStack_190 < iVar5; puStack_190 = (undefined1 *)((int)puStack_190 + 1)) {
        uVar6 = (**(code **)(local_158 + -0x7fbc))(param_1,puStack_190);
        iVar5 = (**(code **)(local_158 + -0x7ab4))(uVar6);
        iVar4 = iVar4 + iVar5 + 1;
      }
      local_148 = "7 datafinal";
      puStack_184 = (undefined4 *)(**(code **)(local_158 + -0x7dd8))(iVar4,"ts_rsp_verify.c",0x225);
      if (puStack_184 == (undefined4 *)0x0) {
        pcVar10 = (char *)0x69;
        local_168 = (undefined4 *)0x227;
        (**(code **)(local_158 + -0x6eb0))(0x2f,0x69,0x41,local_148 + 0x36f8);
        iVar4 = 0;
        goto LAB_005c6798;
      }
      puVar12 = puStack_184;
      for (puStack_190 = (undefined1 *)0x0; iVar4 = (**(code **)(local_158 + -0x7fb4))(param_1),
          (int)puStack_190 < iVar4; puStack_190 = (undefined1 *)((int)puStack_190 + 1)) {
        unaff_s4 = (**(code **)(local_158 + -0x7fbc))(param_1,puStack_190);
        iVar4 = (**(code **)(local_158 + -0x7ab4))(unaff_s4);
        if (0 < (int)puStack_190) {
          *(char *)puVar12 = '/';
          puVar12 = (undefined4 *)((int)puVar12 + 1);
        }
        uVar6 = (**(code **)(local_158 + -0x7ab0))(unaff_s4);
        (**(code **)(local_158 + -0x53f4))(puVar12,uVar6,iVar4);
        puVar12 = (undefined4 *)((int)puVar12 + iVar4);
      }
      *(char *)puVar12 = '\0';
      iVar4 = puStack_188[2];
      if (iVar4 == 0) goto LAB_005c670c;
LAB_005c67e8:
      puStack_190 = TS_failure_info;
      param_1 = TS_status_text;
      bVar1 = true;
      unaff_s4 = 0x2c00;
      while( true ) {
        iVar4 = (**(code **)(local_158 + -0x5d5c))(iVar4,*(char **)puStack_190);
        if (iVar4 != 0) {
          if (!bVar1) {
            local_12c = CONCAT22(0x2c00,local_12c._2_2_);
          }
          bVar1 = false;
          (**(code **)(local_158 + -0x52b4))(&local_12c,*(char **)((int)puStack_190 + 4),0x100);
        }
        puStack_190 = (undefined1 *)((int)puStack_190 + 8);
        if (puStack_190 == TS_status_text) break;
        iVar4 = puStack_188[2];
      }
    }
    local_160 = &local_12c;
    if (local_12c._0_1_ == '\0') {
      local_12c = s_unspecified_00635a2c._0_4_;
      local_128 = s_unspecified_00635a2c._4_4_;
      local_124 = s_unspecified_00635a2c._8_4_;
    }
    local_168 = (undefined4 *)0x20b;
    (**(code **)(local_158 + -0x6eb0))(0x2f,0x68,0x6b,local_148 + 0x36f8);
    local_168 = puStack_184;
    if (puStack_184 == (undefined4 *)0x0) {
      local_168 = (undefined4 *)"unspecified";
    }
    pcVar10 = "status code: ";
    local_164 = ", failure codes: ";
    (**(code **)(local_158 + -0x6c7c))(6,"status code: ",local_144,", status text: ");
    (**(code **)(local_158 + -0x7f58))(puStack_184);
    iVar4 = 0;
  }
LAB_005c6798:
  if (local_2c == *local_14c) {
    return iVar4;
  }
  pcStack_17c = TS_RESP_verify_token;
  puVar9 = local_2c;
  (**(code **)(local_158 + -0x5328))();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iStack_194 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_18c = (uint *)param_1;
  uStack_180 = unaff_s4;
  iVar4 = PKCS7_to_TS_TST_INFO(pcVar10);
  if (iVar4 == 0) {
    iVar5 = 0;
    goto LAB_005c6d1c;
  }
  uStack_1a4 = 0;
  iVar5 = TS_TST_INFO_get_tsa(iVar4);
  uVar8 = *puVar9;
  uStack_1a0 = 0;
  uStack_19c = 0;
  uStack_198 = 0;
  if ((uVar8 & 1) == 0) {
LAB_005c6c6c:
    if ((uVar8 & 2) != 0) {
      iVar7 = TS_TST_INFO_get_version(iVar4);
      if (iVar7 == 1) {
        uVar8 = *puVar9;
        goto joined_r0x005c6d6c;
      }
      uVar11 = 0x71;
      uVar6 = 0x1ac;
LAB_005c6db4:
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x95,uVar11,"ts_rsp_verify.c",uVar6);
      goto LAB_005c6dc8;
    }
joined_r0x005c6d6c:
    if ((uVar8 & 4) == 0) {
joined_r0x005c6e08:
      if ((uVar8 & 8) != 0) {
        iVar7 = TS_check_imprints(puVar9[4],puVar9[5],puVar9[6],iVar4);
        if (iVar7 == 0) goto LAB_005c6dc8;
        uVar8 = *puVar9;
      }
      if ((uVar8 & 0x10) != 0) {
        iVar7 = TS_compute_imprint(puVar9[7],iVar4,&uStack_1a0,&uStack_19c,&uStack_198);
        if ((iVar7 == 0) ||
           (iVar7 = TS_check_imprints(uStack_1a0,uStack_19c,uStack_198,iVar4), iVar7 == 0))
        goto LAB_005c6dc8;
        uVar8 = *puVar9;
      }
      if ((uVar8 & 0x20) == 0) {
LAB_005c6ca4:
        if (((uVar8 & 0x40) != 0) && (iVar5 != 0)) {
          iVar5 = TS_check_signer_name(iVar5,uStack_1a4);
          if (iVar5 == 0) {
            uVar11 = 0x6f;
            uVar6 = 0x1cb;
            goto LAB_005c6db4;
          }
          uVar8 = *puVar9;
        }
        if (((uVar8 & 0x80) == 0) ||
           (iVar5 = TS_check_signer_name(puVar9[9],uStack_1a4), iVar5 != 0)) {
          iVar5 = 1;
        }
        else {
          iVar5 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x95,0x70,"ts_rsp_verify.c",0x1d3);
        }
      }
      else {
        uVar8 = puVar9[8];
        iVar7 = TS_TST_INFO_get_nonce(iVar4);
        if (iVar7 == 0) {
          uVar11 = 0x69;
          uVar6 = 0x2a1;
        }
        else {
          iVar7 = (*(code *)PTR_ASN1_INTEGER_cmp_006a9e58)(uVar8,iVar7);
          if (iVar7 == 0) {
            uVar8 = *puVar9;
            goto LAB_005c6ca4;
          }
          uVar11 = 0x68;
          uVar6 = 0x2a8;
        }
        iVar5 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x65,uVar11,"ts_rsp_verify.c",uVar6);
      }
    }
    else {
      uVar8 = puVar9[3];
      uVar6 = TS_TST_INFO_get_policy_id(iVar4);
      iVar7 = (*(code *)PTR_OBJ_cmp_006a9de4)(uVar8,uVar6);
      if (iVar7 == 0) {
        uVar8 = *puVar9;
        goto joined_r0x005c6e08;
      }
      iVar5 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x66,0x6c,"ts_rsp_verify.c",0x23f);
    }
  }
  else {
    iVar7 = TS_RESP_verify_signature(pcVar10,puVar9[2],puVar9[1],&uStack_1a4);
    if (iVar7 != 0) {
      uVar8 = *puVar9;
      goto LAB_005c6c6c;
    }
LAB_005c6dc8:
    iVar5 = 0;
  }
  (*(code *)PTR_X509_free_006a7f90)(uStack_1a4);
  (*(code *)PTR_X509_ALGOR_free_006a8f94)(uStack_1a0);
  (*(code *)PTR_CRYPTO_free_006a7f88)(uStack_19c);
  TS_TST_INFO_free(iVar4);
LAB_005c6d1c:
  if (iStack_194 == *(int *)puVar2) {
    return iVar5;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar4 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x28,"ts_verify_ctx.c",0x42);
  if (iVar4 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x90,0x41,"ts_verify_ctx.c",0x46);
    return 0;
  }
  (*(code *)PTR_memset_006aab00)(iVar4,0,0x28);
  return iVar4;
}

