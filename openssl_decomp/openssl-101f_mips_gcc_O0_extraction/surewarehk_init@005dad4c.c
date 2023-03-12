
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
  undefined1 *puVar17;
  undefined1 *local_a0;
  undefined1 *local_9c;
  undefined1 *local_98;
  undefined1 *local_94;
  undefined1 *local_90;
  undefined1 *local_8c;
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
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
  local_6c = s_ENGINE_init_00674e90._0_4_;
  local_68 = s_ENGINE_init_00674e90._4_4_;
  local_64 = s_ENGINE_init_00674e90._8_4_;
  if (surewarehk_dso == 0) {
    surewarehk_dso = (*(code *)PTR_DSO_load_006a99a4)(0,"SureWareHook",0,0);
    if (surewarehk_dso == 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      uVar16 = 0x68;
      uVar2 = 0x1ce;
    }
    else {
      pcVar3 = (code *)(*(code *)PTR_DSO_bind_func_006a99ac)(surewarehk_dso,"SureWareHook_Init");
      if (pcVar3 != (code *)0x0) {
        iVar4 = (*(code *)PTR_DSO_bind_func_006a99ac)(surewarehk_dso,"SureWareHook_Finish");
        if (iVar4 != 0) {
          iVar5 = (*(code *)PTR_DSO_bind_func_006a99ac)(surewarehk_dso,"SureWareHook_Rand_Bytes");
          if (iVar5 != 0) {
            iVar6 = (*(code *)PTR_DSO_bind_func_006a99ac)(surewarehk_dso,"SureWareHook_Rand_Seed");
            if (iVar6 != 0) {
              iVar7 = (*(code *)PTR_DSO_bind_func_006a99ac)
                                (surewarehk_dso,"SureWareHook_Load_Privkey");
              if (iVar7 != 0) {
                iVar8 = (*(code *)PTR_DSO_bind_func_006a99ac)
                                  (surewarehk_dso,"SureWareHook_Load_Rsa_Pubkey");
                if (iVar8 != 0) {
                  iVar9 = (*(code *)PTR_DSO_bind_func_006a99ac)(surewarehk_dso,"SureWareHook_Free");
                  if (iVar9 != 0) {
                    iVar10 = (*(code *)PTR_DSO_bind_func_006a99ac)
                                       (surewarehk_dso,"SureWareHook_Rsa_Priv_Dec");
                    if (iVar10 != 0) {
                      iVar11 = (*(code *)PTR_DSO_bind_func_006a99ac)
                                         (surewarehk_dso,"SureWareHook_Rsa_Sign");
                      if (iVar11 != 0) {
                        iVar12 = (*(code *)PTR_DSO_bind_func_006a99ac)
                                           (surewarehk_dso,"SureWareHook_Dsa_Sign");
                        if (iVar12 != 0) {
                          iVar13 = (*(code *)PTR_DSO_bind_func_006a99ac)
                                             (surewarehk_dso,"SureWareHook_Info_Pubkey");
                          if (iVar13 != 0) {
                            iVar14 = (*(code *)PTR_DSO_bind_func_006a99ac)
                                               (surewarehk_dso,"SureWareHook_Load_Dsa_Pubkey");
                            if (iVar14 != 0) {
                              iVar15 = (*(code *)PTR_DSO_bind_func_006a99ac)
                                                 (surewarehk_dso,"SureWareHook_Mod_Exp");
                              if (iVar15 != 0) {
                                puVar17 = &_ITM_registerTMCloneTable;
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
                                local_98 = &_ITM_registerTMCloneTable;
                                local_94 = &_ITM_registerTMCloneTable;
                                local_9c = &_ITM_registerTMCloneTable;
                                local_90 = &_ITM_registerTMCloneTable;
                                local_a0 = &_ITM_registerTMCloneTable;
                                local_8c = &_ITM_registerTMCloneTable;
                                if (iVar4 == -3) goto LAB_005db2f4;
                                iVar4 = (*p_surewarehk_Init)(&local_6c,threadsafe);
                                local_a0 = &_ITM_registerTMCloneTable;
                                local_9c = &_ITM_registerTMCloneTable;
                                local_98 = &_ITM_registerTMCloneTable;
                                local_94 = &_ITM_registerTMCloneTable;
                                local_90 = &_ITM_registerTMCloneTable;
                                if (iVar4 != -3) {
                                  local_8c = (undefined1 *)0x0;
                                  surewarehk_load_privkey(param_1,0,0);
                                  if (rsaHndidx == -1) {
                                    local_8c = (undefined1 *)0x0;
                                    rsaHndidx = (*(code *)PTR_RSA_get_ex_new_index_006aa64c)
                                                          (0,"SureWareHook RSA key handle",0,0,
                                                           surewarehk_ex_free);
                                  }
                                  puVar17 = (undefined1 *)0x6a0000;
                                  if (dsaHndidx != -1) {
                                    uVar2 = 1;
                                    goto LAB_005daef4;
                                  }
                                  local_8c = (undefined1 *)0x0;
                                  dsaHndidx = (*(code *)PTR_DSA_get_ex_new_index_006aa690)
                                                        (0,"SureWareHook DSA key handle",0,0,
                                                         surewarehk_ex_free);
                                  uVar2 = 1;
                                  goto LAB_005daef4;
                                }
                                local_8c = &_ITM_registerTMCloneTable;
                                uVar2 = 0x1f8;
                                local_90 = &_ITM_registerTMCloneTable;
                                local_94 = &_ITM_registerTMCloneTable;
                                local_98 = &_ITM_registerTMCloneTable;
                                local_9c = &_ITM_registerTMCloneTable;
                                local_a0 = &_ITM_registerTMCloneTable;
                                goto LAB_005db310;
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
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      uVar16 = 0x68;
      uVar2 = 0x1df;
    }
  }
  else {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar16 = 100;
    uVar2 = 0x1c7;
  }
  puVar17 = &_ITM_registerTMCloneTable;
  (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x68,uVar16,"e_sureware.c",uVar2);
  local_8c = &_ITM_registerTMCloneTable;
  local_a0 = &_ITM_registerTMCloneTable;
  local_90 = &_ITM_registerTMCloneTable;
  local_9c = &_ITM_registerTMCloneTable;
  local_94 = &_ITM_registerTMCloneTable;
  local_98 = &_ITM_registerTMCloneTable;
  while( true ) {
    if (surewarehk_dso != 0) {
      (*(code *)PTR_DSO_free_006a9994)();
    }
    uVar2 = 0;
    surewarehk_dso = 0;
    *(undefined4 *)(local_8c + -0xaec) = 0;
    *(undefined4 *)(local_a0 + -0xaf0) = 0;
    *(undefined4 *)(local_90 + -0xaf4) = 0;
    *(undefined4 *)(local_9c + -0xaf8) = 0;
    *(undefined4 *)(local_94 + -0xafc) = 0;
    *(undefined4 *)(puVar17 + -0xb04) = 0;
    p_surewarehk_Free = 0;
    p_surewarehk_Rsa_Priv_Dec = 0;
    p_surewarehk_Rsa_Sign = 0;
    p_surewarehk_Dsa_Sign = 0;
    p_surewarehk_Info_Pubkey = 0;
    p_surewarehk_Load_Dsa_Pubkey = 0;
    *(undefined4 *)(local_98 + -0xb1c) = 0;
LAB_005daef4:
    if (local_2c == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005db2f4:
    uVar2 = 499;
LAB_005db310:
    ERR_SUREWARE_error_constprop_5(0x68,0x68,uVar2);
  }
  return uVar2;
}

