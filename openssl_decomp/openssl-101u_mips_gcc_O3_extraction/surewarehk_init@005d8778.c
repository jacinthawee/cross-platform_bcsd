
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 surewarehk_init(undefined4 param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  undefined *puVar17;
  undefined *local_a0;
  undefined *local_9c;
  undefined *local_98;
  undefined *local_94;
  undefined *local_90;
  undefined *local_8c;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_6c = s_ENGINE_init_006745a0._0_4_;
  local_68 = s_ENGINE_init_006745a0._4_4_;
  local_64 = s_ENGINE_init_006745a0._8_4_;
  if (surewarehk_dso == 0) {
    surewarehk_dso = (*(code *)PTR_DSO_load_006a8884)(0,"SureWareHook",0,0);
    if (surewarehk_dso == 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      uVar16 = 0x68;
      uVar2 = 0x1df;
    }
    else {
      pcVar3 = (code *)(*(code *)PTR_DSO_bind_func_006a888c)(surewarehk_dso,"SureWareHook_Init");
      if (pcVar3 != (code *)0x0) {
        iVar4 = (*(code *)PTR_DSO_bind_func_006a888c)(surewarehk_dso,"SureWareHook_Finish");
        if (iVar4 != 0) {
          iVar5 = (*(code *)PTR_DSO_bind_func_006a888c)(surewarehk_dso,"SureWareHook_Rand_Bytes");
          if (iVar5 != 0) {
            iVar6 = (*(code *)PTR_DSO_bind_func_006a888c)(surewarehk_dso,"SureWareHook_Rand_Seed");
            if (iVar6 != 0) {
              iVar7 = (*(code *)PTR_DSO_bind_func_006a888c)
                                (surewarehk_dso,"SureWareHook_Load_Privkey");
              if (iVar7 != 0) {
                iVar8 = (*(code *)PTR_DSO_bind_func_006a888c)
                                  (surewarehk_dso,"SureWareHook_Load_Rsa_Pubkey");
                if (iVar8 != 0) {
                  iVar9 = (*(code *)PTR_DSO_bind_func_006a888c)(surewarehk_dso,"SureWareHook_Free");
                  if (iVar9 != 0) {
                    iVar10 = (*(code *)PTR_DSO_bind_func_006a888c)
                                       (surewarehk_dso,"SureWareHook_Rsa_Priv_Dec");
                    if (iVar10 != 0) {
                      iVar11 = (*(code *)PTR_DSO_bind_func_006a888c)
                                         (surewarehk_dso,"SureWareHook_Rsa_Sign");
                      if (iVar11 != 0) {
                        iVar12 = (*(code *)PTR_DSO_bind_func_006a888c)
                                           (surewarehk_dso,"SureWareHook_Dsa_Sign");
                        if (iVar12 != 0) {
                          iVar13 = (*(code *)PTR_DSO_bind_func_006a888c)
                                             (surewarehk_dso,"SureWareHook_Info_Pubkey");
                          if (iVar13 != 0) {
                            iVar14 = (*(code *)PTR_DSO_bind_func_006a888c)
                                               (surewarehk_dso,"SureWareHook_Load_Dsa_Pubkey");
                            if (iVar14 != 0) {
                              iVar15 = (*(code *)PTR_DSO_bind_func_006a888c)
                                                 (surewarehk_dso,"SureWareHook_Mod_Exp");
                              if (iVar15 != 0) {
                                puVar17 = &_gp_1;
                                p_surewarehk_Mod_Exp = iVar15;
                                p_surewarehk_Dsa_Sign = iVar12;
                                p_surewarehk_Rsa_Sign = iVar11;
                                p_surewarehk_Rsa_Priv_Dec = iVar10;
                                p_surewarehk_Free = iVar9;
                                p_surewarehk_Load_Dsa_Pubkey = iVar14;
                                p_surewarehk_Load_Rsa_Pubkey = iVar8;
                                p_surewarehk_Info_Pubkey = iVar13;
                                p_surewarehk_Load_Privkey = iVar7;
                                p_surewarehk_Rand_Seed = iVar6;
                                p_surewarehk_Rand_Bytes = iVar5;
                                p_surewarehk_Finish = iVar4;
                                p_surewarehk_Init = pcVar3;
                                iVar4 = (*pcVar3)(&local_6c,threadsafe);
                                local_98 = &_gp_1;
                                local_94 = &_gp_1;
                                local_9c = &_gp_1;
                                local_90 = &_gp_1;
                                local_a0 = &_gp_1;
                                local_8c = &_gp_1;
                                if (iVar4 == -3) goto LAB_005d8d20;
                                iVar4 = (*p_surewarehk_Init)(&local_6c,threadsafe);
                                local_a0 = &_gp_1;
                                local_9c = &_gp_1;
                                local_98 = &_gp_1;
                                local_94 = &_gp_1;
                                local_90 = &_gp_1;
                                if (iVar4 != -3) {
                                  local_8c = (undefined *)0x0;
                                  surewarehk_load_privkey(param_1,0,0);
                                  if (rsaHndidx == -1) {
                                    local_8c = (undefined *)0x0;
                                    rsaHndidx = (*(code *)PTR_RSA_get_ex_new_index_006a9540)
                                                          (0,"SureWareHook RSA key handle",0,0,
                                                           surewarehk_ex_free);
                                  }
                                  puVar17 = (undefined *)0x6a0000;
                                  if (dsaHndidx != -1) {
                                    uVar2 = 1;
                                    goto LAB_005d8920;
                                  }
                                  local_8c = (undefined *)0x0;
                                  dsaHndidx = (*(code *)PTR_DSA_get_ex_new_index_006a9584)
                                                        (0,"SureWareHook DSA key handle",0,0,
                                                         surewarehk_ex_free);
                                  uVar2 = 1;
                                  goto LAB_005d8920;
                                }
                                local_8c = &_gp_1;
                                uVar2 = 0x220;
                                local_90 = &_gp_1;
                                local_94 = &_gp_1;
                                local_98 = &_gp_1;
                                local_9c = &_gp_1;
                                local_a0 = &_gp_1;
                                goto LAB_005d8d3c;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      uVar16 = 0x68;
      uVar2 = 0x209;
    }
  }
  else {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar16 = 100;
    uVar2 = 0x1d9;
  }
  puVar17 = &_gp_1;
  (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x68,uVar16,"e_sureware.c",uVar2);
  local_8c = &_gp_1;
  local_a0 = &_gp_1;
  local_90 = &_gp_1;
  local_9c = &_gp_1;
  local_94 = &_gp_1;
  local_98 = &_gp_1;
  while( true ) {
    if (surewarehk_dso != 0) {
      (*(code *)PTR_DSO_free_006a8874)();
    }
    uVar2 = 0;
    surewarehk_dso = 0;
    *(undefined4 *)(local_8c + -0x1cac) = 0;
    *(undefined4 *)(local_a0 + -0x1cb0) = 0;
    *(undefined4 *)(local_90 + -0x1cb4) = 0;
    *(undefined4 *)(local_9c + -0x1cb8) = 0;
    *(undefined4 *)(local_94 + -0x1cbc) = 0;
    *(undefined4 *)(puVar17 + -0x1cc4) = 0;
    p_surewarehk_Free = 0;
    p_surewarehk_Rsa_Priv_Dec = 0;
    p_surewarehk_Rsa_Sign = 0;
    p_surewarehk_Dsa_Sign = 0;
    p_surewarehk_Info_Pubkey = 0;
    p_surewarehk_Load_Dsa_Pubkey = 0;
    *(undefined4 *)(local_98 + -0x1cdc) = 0;
LAB_005d8920:
    if (local_2c == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005d8d20:
    uVar2 = 0x21c;
LAB_005d8d3c:
    ERR_SUREWARE_error_constprop_5(0x68,0x68,uVar2);
  }
  return uVar2;
}

