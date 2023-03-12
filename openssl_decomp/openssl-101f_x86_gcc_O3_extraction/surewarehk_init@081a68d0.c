
undefined4 surewarehk_init(undefined4 param_1)

{
  DSO_FUNC_TYPE pDVar1;
  DSO_FUNC_TYPE pDVar2;
  DSO_FUNC_TYPE pDVar3;
  DSO_FUNC_TYPE pDVar4;
  DSO_FUNC_TYPE pDVar5;
  DSO_FUNC_TYPE pDVar6;
  DSO_FUNC_TYPE pDVar7;
  DSO_FUNC_TYPE pDVar8;
  DSO_FUNC_TYPE pDVar9;
  DSO_FUNC_TYPE pDVar10;
  DSO_FUNC_TYPE pDVar11;
  DSO_FUNC_TYPE pDVar12;
  DSO_FUNC_TYPE pDVar13;
  int iVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  int in_GS_OFFSET;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54 [13];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_60 = 0x49474e45;
  local_5c = 0x695f454e;
  local_58 = 0x74696e;
  puVar16 = local_54;
  for (iVar14 = 0xd; iVar14 != 0; iVar14 = iVar14 + -1) {
    *puVar16 = 0;
    puVar16 = puVar16 + 1;
  }
  if (surewarehk_dso == (DSO *)0x0) {
    surewarehk_dso = DSO_load((DSO *)0x0,"SureWareHook",(DSO_METHOD *)0x0,0);
    if (surewarehk_dso == (DSO *)0x0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      iVar14 = 0x1ce;
    }
    else {
      pDVar1 = DSO_bind_func(surewarehk_dso,"SureWareHook_Init");
      if (pDVar1 != (DSO_FUNC_TYPE)0x0) {
        pDVar2 = DSO_bind_func(surewarehk_dso,"SureWareHook_Finish");
        if (pDVar2 != (DSO_FUNC_TYPE)0x0) {
          pDVar3 = DSO_bind_func(surewarehk_dso,"SureWareHook_Rand_Bytes");
          if (pDVar3 != (DSO_FUNC_TYPE)0x0) {
            pDVar4 = DSO_bind_func(surewarehk_dso,"SureWareHook_Rand_Seed");
            if (pDVar4 != (DSO_FUNC_TYPE)0x0) {
              pDVar5 = DSO_bind_func(surewarehk_dso,"SureWareHook_Load_Privkey");
              if (pDVar5 != (DSO_FUNC_TYPE)0x0) {
                pDVar6 = DSO_bind_func(surewarehk_dso,"SureWareHook_Load_Rsa_Pubkey");
                if (pDVar6 != (DSO_FUNC_TYPE)0x0) {
                  pDVar7 = DSO_bind_func(surewarehk_dso,"SureWareHook_Free");
                  if (pDVar7 != (DSO_FUNC_TYPE)0x0) {
                    pDVar8 = DSO_bind_func(surewarehk_dso,"SureWareHook_Rsa_Priv_Dec");
                    if (pDVar8 != (DSO_FUNC_TYPE)0x0) {
                      pDVar9 = DSO_bind_func(surewarehk_dso,"SureWareHook_Rsa_Sign");
                      if (pDVar9 != (DSO_FUNC_TYPE)0x0) {
                        pDVar10 = DSO_bind_func(surewarehk_dso,"SureWareHook_Dsa_Sign");
                        if (pDVar10 != (DSO_FUNC_TYPE)0x0) {
                          pDVar11 = DSO_bind_func(surewarehk_dso,"SureWareHook_Info_Pubkey");
                          if (pDVar11 != (DSO_FUNC_TYPE)0x0) {
                            pDVar12 = DSO_bind_func(surewarehk_dso,"SureWareHook_Load_Dsa_Pubkey");
                            if (pDVar12 != (DSO_FUNC_TYPE)0x0) {
                              pDVar13 = DSO_bind_func(surewarehk_dso,"SureWareHook_Mod_Exp");
                              if (pDVar13 != (DSO_FUNC_TYPE)0x0) {
                                p_surewarehk_Mod_Exp = pDVar13;
                                p_surewarehk_Dsa_Sign = pDVar10;
                                p_surewarehk_Rsa_Sign = pDVar9;
                                p_surewarehk_Rsa_Priv_Dec = pDVar8;
                                p_surewarehk_Free = pDVar7;
                                p_surewarehk_Load_Dsa_Pubkey = pDVar12;
                                p_surewarehk_Load_Rsa_Pubkey = pDVar6;
                                p_surewarehk_Info_Pubkey = pDVar11;
                                p_surewarehk_Load_Privkey = pDVar5;
                                p_surewarehk_Rand_Seed = pDVar4;
                                p_surewarehk_Rand_Bytes = pDVar3;
                                p_surewarehk_Finish = pDVar2;
                                p_surewarehk_Init = pDVar1;
                                iVar14 = (*pDVar1)(&local_60,threadsafe);
                                if (iVar14 == -3) {
                                  ERR_SUREWARE_error_constprop_5();
                                }
                                else {
                                  iVar14 = (*p_surewarehk_Init)(&local_60,threadsafe);
                                  if (iVar14 != -3) {
                                    surewarehk_load_privkey(param_1,0,0,0);
                                    if (rsaHndidx == -1) {
                                      rsaHndidx = RSA_get_ex_new_index
                                                            (0,"SureWareHook RSA key handle",
                                                             (undefined1 *)0x0,(undefined1 *)0x0,
                                                             surewarehk_ex_free);
                                    }
                                    uVar15 = 1;
                                    if (dsaHndidx == -1) {
                                      dsaHndidx = DSA_get_ex_new_index
                                                            (0,"SureWareHook DSA key handle",
                                                             (undefined1 *)0x0,(undefined1 *)0x0,
                                                             surewarehk_ex_free);
                                    }
                                    goto LAB_081a69ed;
                                  }
                                  ERR_SUREWARE_error_constprop_5();
                                }
                                goto LAB_081a694a;
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
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      iVar14 = 0x1df;
    }
    ERR_put_error(SUREWARE_lib_error_code,0x68,0x68,"e_sureware.c",iVar14);
  }
  else {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x68,100,"e_sureware.c",0x1c7);
  }
LAB_081a694a:
  if (surewarehk_dso != (DSO *)0x0) {
    DSO_free(surewarehk_dso);
  }
  surewarehk_dso = (DSO *)0x0;
  p_surewarehk_Init = (DSO_FUNC_TYPE)0x0;
  uVar15 = 0;
  p_surewarehk_Finish = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Rand_Bytes = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Rand_Seed = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Load_Privkey = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Load_Rsa_Pubkey = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Free = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Rsa_Priv_Dec = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Rsa_Sign = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Dsa_Sign = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Info_Pubkey = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Load_Dsa_Pubkey = (DSO_FUNC_TYPE)0x0;
  p_surewarehk_Mod_Exp = (DSO_FUNC_TYPE)0x0;
LAB_081a69ed:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar15;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

