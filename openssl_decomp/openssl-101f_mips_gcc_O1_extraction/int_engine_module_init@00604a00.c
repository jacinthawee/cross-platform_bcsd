
/* WARNING: Type propagation algorithm not settling */

undefined4 int_engine_module_init(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int local_44;
  int local_30;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar3 = (*(code *)PTR_CONF_imodule_get_value_006aa8a8)();
  iVar4 = (*(code *)PTR_NCONF_get_section_006a7fd4)(param_2,uVar3);
  if (iVar4 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x26,0xbb,0x94,"eng_cnf.c",0xe6);
    uVar3 = 0;
  }
  else {
    local_44 = 0;
    iVar5 = (*(code *)PTR_sk_num_006a7f2c)(iVar4);
    if (0 < iVar5) {
      do {
        iVar6 = (*(code *)PTR_sk_value_006a7f24)(iVar4,local_44);
        iVar5 = *(int *)(iVar6 + 4);
        uVar3 = *(undefined4 *)(iVar6 + 8);
        local_30 = -1;
        iVar6 = (*(code *)PTR_strchr_006aab34)(iVar5,0x2e);
        if (iVar6 != 0) {
          iVar5 = iVar6 + 1;
        }
        iVar6 = (*(code *)PTR_NCONF_get_section_006a7fd4)(param_2,uVar3);
        if (iVar6 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x26,0xbc,0x95,"eng_cnf.c",0x70);
          uVar3 = 0;
          goto LAB_00604d54;
        }
        iVar10 = 0;
        bVar1 = false;
        iVar12 = 0;
        iVar7 = (*(code *)PTR_sk_num_006a7f2c)(iVar6);
        if (0 < iVar7) {
LAB_00604b50:
          puVar8 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(iVar6,iVar10);
          iVar7 = puVar8[1];
          iVar9 = (*(code *)PTR_strchr_006aab34)(iVar7,0x2e);
          iVar11 = puVar8[2];
          if (iVar9 != 0) {
            iVar7 = iVar9 + 1;
          }
          iVar9 = (*(code *)PTR_strcmp_006aac20)(iVar7,"engine_id");
          if (iVar9 != 0) {
            iVar9 = (*(code *)PTR_strcmp_006aac20)(iVar7,"soft_load");
            if (iVar9 != 0) {
              iVar9 = (*(code *)PTR_strcmp_006aac20)(iVar7,"dynamic_path");
              if (iVar9 == 0) {
                iVar12 = (*(code *)PTR_ENGINE_by_id_006a7f9c)("dynamic");
                if (iVar12 != 0) {
                  iVar7 = (*(code *)PTR_ENGINE_ctrl_cmd_string_006a8cc4)(iVar12,"SO_PATH",iVar11,0);
                  if ((iVar7 == 0) ||
                     (iVar7 = (*(code *)PTR_ENGINE_ctrl_cmd_string_006a8cc4)
                                        (iVar12,"LIST_ADD","2",0), iVar7 == 0)) goto LAB_00604ca8;
                  iVar7 = (*(code *)PTR_ENGINE_ctrl_cmd_string_006a8cc4)(iVar12,"LOAD",0,0);
joined_r0x00604e34:
                  iVar11 = iVar5;
                  if (iVar7 == 0) goto LAB_00604ca8;
                  goto LAB_00604c4c;
                }
LAB_00604ca0:
                iVar12 = 0;
              }
              else {
                if ((iVar12 == 0) &&
                   (iVar12 = (*(code *)PTR_ENGINE_by_id_006a7f9c)(iVar5), iVar12 == 0)) {
                  if (!bVar1) goto LAB_00604ca0;
                  (*(code *)PTR_ERR_clear_error_006a7fe0)();
                  goto LAB_00604d28;
                }
                iVar9 = (*(code *)PTR_strcmp_006aac20)(iVar11,"EMPTY");
                if (iVar9 == 0) {
                  iVar11 = 0;
                }
                iVar9 = (*(code *)PTR_strcmp_006aac20)(iVar7,"init");
                if (iVar9 != 0) {
                  iVar9 = (*(code *)PTR_strcmp_006aac20)(iVar7,"default_algorithms");
                  if (iVar9 == 0) {
                    iVar7 = (*(code *)PTR_ENGINE_set_default_string_006aa8ac)(iVar12,iVar11);
                  }
                  else {
                    iVar7 = (*(code *)PTR_ENGINE_ctrl_cmd_string_006a8cc4)(iVar12,iVar7,iVar11,0);
                  }
                  goto joined_r0x00604e34;
                }
                iVar7 = (*(code *)PTR_NCONF_get_number_e_006a803c)(param_2,uVar3,"init",&local_30);
                if (iVar7 != 0) {
                  if (local_30 != 1) {
                    iVar11 = iVar5;
                    if (local_30 != 0) {
                      (*(code *)PTR_ERR_put_error_006a9030)(0x26,0xbc,0x97,"eng_cnf.c",0xb2);
                      goto LAB_00604ca8;
                    }
                    goto LAB_00604c4c;
                  }
                  iVar7 = (*(code *)PTR_ENGINE_init_006a8e68)(iVar12);
                  if (iVar7 == 0) goto LAB_00604f20;
                  if (((initialized_engines == 0) &&
                      (initialized_engines = (*(code *)PTR_sk_new_null_006a80a4)(),
                      initialized_engines == 0)) ||
                     (iVar7 = (*(code *)PTR_sk_push_006a80a8)(initialized_engines,iVar12),
                     iVar11 = iVar5, iVar7 == 0)) {
                    (*(code *)PTR_ENGINE_finish_006a80c4)(iVar12);
                    goto LAB_00604f20;
                  }
                  goto LAB_00604c4c;
                }
              }
LAB_00604ca8:
              (*(code *)PTR_ERR_put_error_006a9030)(0x26,0xbc,0x66,"eng_cnf.c",0xcc);
              uVar3 = puVar8[2];
              goto LAB_00604cd0;
            }
            bVar1 = true;
            iVar11 = iVar5;
          }
LAB_00604c4c:
          iVar10 = iVar10 + 1;
          iVar7 = (*(code *)PTR_sk_num_006a7f2c)(iVar6);
          iVar5 = iVar11;
          if (iVar7 <= iVar10) goto LAB_00604c64;
          goto LAB_00604b50;
        }
LAB_00604c64:
        if (iVar12 != 0) {
          if (local_30 == -1) {
            iVar5 = (*(code *)PTR_ENGINE_init_006a8e68)(iVar12);
            if (iVar5 != 0) {
              if (((initialized_engines != 0) ||
                  (initialized_engines = (*(code *)PTR_sk_new_null_006a80a4)(),
                  initialized_engines != 0)) &&
                 (iVar5 = (*(code *)PTR_sk_push_006a80a8)(initialized_engines,iVar12), iVar5 != 0))
              goto LAB_00604c78;
              (*(code *)PTR_ENGINE_finish_006a80c4)(iVar12);
            }
            puVar8 = (undefined4 *)0x0;
LAB_00604f20:
            (*(code *)PTR_ERR_put_error_006a9030)(0x26,0xbc,0x66,"eng_cnf.c",0xcc);
            if (puVar8 == (undefined4 *)0x0) {
LAB_00604d10:
              bVar1 = false;
              goto LAB_00604d14;
            }
            uVar3 = puVar8[2];
LAB_00604cd0:
            (*(code *)PTR_ERR_add_error_data_006a9264)
                      (6,"section=",*puVar8,", name=",puVar8[1],", value=",uVar3);
            if (iVar12 != 0) goto LAB_00604d10;
          }
          else {
LAB_00604c78:
            bVar1 = true;
LAB_00604d14:
            (*(code *)PTR_ENGINE_free_006a7f84)(iVar12);
            if (bVar1) goto LAB_00604d28;
          }
          uVar3 = 0;
          goto LAB_00604d54;
        }
LAB_00604d28:
        local_44 = local_44 + 1;
        iVar5 = (*(code *)PTR_sk_num_006a7f2c)(iVar4);
      } while (local_44 < iVar5);
    }
    uVar3 = 1;
  }
LAB_00604d54:
  if (local_2c == *(int *)puVar2) {
    return uVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x00605078. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*(code *)PTR_CONF_module_add_006aa8b0)
                    ("engines",int_engine_module_init,int_engine_module_finish);
  return uVar3;
}

