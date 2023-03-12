
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
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar3 = (*(code *)PTR_CONF_imodule_get_value_006a9798)();
  iVar4 = (*(code *)PTR_NCONF_get_section_006a6ed4)(param_2,uVar3);
  if (iVar4 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x26,0xbb,0x94,"eng_cnf.c",0xd8);
    uVar3 = 0;
  }
  else {
    local_44 = 0;
    iVar5 = (*(code *)PTR_sk_num_006a6e2c)(iVar4);
    if (0 < iVar5) {
      do {
        iVar6 = (*(code *)PTR_sk_value_006a6e24)(iVar4,local_44);
        iVar5 = *(int *)(iVar6 + 4);
        uVar3 = *(undefined4 *)(iVar6 + 8);
        local_30 = -1;
        iVar6 = (*(code *)PTR_strchr_006a9a28)(iVar5,0x2e);
        if (iVar6 != 0) {
          iVar5 = iVar6 + 1;
        }
        iVar6 = (*(code *)PTR_NCONF_get_section_006a6ed4)(param_2,uVar3);
        if (iVar6 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x26,0xbc,0x95,"eng_cnf.c",0x6f);
          uVar3 = 0;
          goto LAB_00602ee4;
        }
        iVar10 = 0;
        bVar1 = false;
        iVar12 = 0;
        iVar7 = (*(code *)PTR_sk_num_006a6e2c)(iVar6);
        if (0 < iVar7) {
LAB_00602ce0:
          puVar8 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(iVar6,iVar10);
          iVar7 = puVar8[1];
          iVar9 = (*(code *)PTR_strchr_006a9a28)(iVar7,0x2e);
          iVar11 = puVar8[2];
          if (iVar9 != 0) {
            iVar7 = iVar9 + 1;
          }
          iVar9 = (*(code *)PTR_strcmp_006a9b18)(iVar7,"engine_id");
          if (iVar9 != 0) {
            iVar9 = (*(code *)PTR_strcmp_006a9b18)(iVar7,"soft_load");
            if (iVar9 != 0) {
              iVar9 = (*(code *)PTR_strcmp_006a9b18)(iVar7,"dynamic_path");
              if (iVar9 == 0) {
                iVar12 = (*(code *)PTR_ENGINE_by_id_006a6e9c)("dynamic");
                if (iVar12 != 0) {
                  iVar7 = (*(code *)PTR_ENGINE_ctrl_cmd_string_006a7bd8)(iVar12,"SO_PATH",iVar11,0);
                  if ((iVar7 == 0) ||
                     (iVar7 = (*(code *)PTR_ENGINE_ctrl_cmd_string_006a7bd8)
                                        (iVar12,"LIST_ADD","2",0), iVar7 == 0)) goto LAB_00602e38;
                  iVar7 = (*(code *)PTR_ENGINE_ctrl_cmd_string_006a7bd8)(iVar12,"LOAD",0,0);
joined_r0x00602fc4:
                  iVar11 = iVar5;
                  if (iVar7 == 0) goto LAB_00602e38;
                  goto LAB_00602ddc;
                }
LAB_00602e30:
                iVar12 = 0;
              }
              else {
                if ((iVar12 == 0) &&
                   (iVar12 = (*(code *)PTR_ENGINE_by_id_006a6e9c)(iVar5), iVar12 == 0)) {
                  if (!bVar1) goto LAB_00602e30;
                  (*(code *)PTR_ERR_clear_error_006a6ee0)();
                  goto LAB_00602eb8;
                }
                iVar9 = (*(code *)PTR_strcmp_006a9b18)(iVar11,"EMPTY");
                if (iVar9 == 0) {
                  iVar11 = 0;
                }
                iVar9 = (*(code *)PTR_strcmp_006a9b18)(iVar7,"init");
                if (iVar9 != 0) {
                  iVar9 = (*(code *)PTR_strcmp_006a9b18)(iVar7,"default_algorithms");
                  if (iVar9 == 0) {
                    iVar7 = (*(code *)PTR_ENGINE_set_default_string_006a979c)(iVar12,iVar11);
                  }
                  else {
                    iVar7 = (*(code *)PTR_ENGINE_ctrl_cmd_string_006a7bd8)(iVar12,iVar7,iVar11,0);
                  }
                  goto joined_r0x00602fc4;
                }
                iVar7 = (*(code *)PTR_NCONF_get_number_e_006a6f3c)(param_2,uVar3,"init",&local_30);
                if (iVar7 != 0) {
                  if (local_30 != 1) {
                    iVar11 = iVar5;
                    if (local_30 != 0) {
                      (*(code *)PTR_ERR_put_error_006a7f34)(0x26,0xbc,0x97,"eng_cnf.c",0xac);
                      goto LAB_00602e38;
                    }
                    goto LAB_00602ddc;
                  }
                  iVar7 = (*(code *)PTR_ENGINE_init_006a7d78)(iVar12);
                  if (iVar7 == 0) goto LAB_006030b0;
                  if (((initialized_engines == 0) &&
                      (initialized_engines = (*(code *)PTR_sk_new_null_006a6fa4)(),
                      initialized_engines == 0)) ||
                     (iVar7 = (*(code *)PTR_sk_push_006a6fa8)(initialized_engines,iVar12),
                     iVar11 = iVar5, iVar7 == 0)) {
                    (*(code *)PTR_ENGINE_finish_006a6fc4)(iVar12);
                    goto LAB_006030b0;
                  }
                  goto LAB_00602ddc;
                }
              }
LAB_00602e38:
              (*(code *)PTR_ERR_put_error_006a7f34)(0x26,0xbc,0x66,"eng_cnf.c",0xbf);
              uVar3 = puVar8[2];
              goto LAB_00602e60;
            }
            bVar1 = true;
            iVar11 = iVar5;
          }
LAB_00602ddc:
          iVar10 = iVar10 + 1;
          iVar7 = (*(code *)PTR_sk_num_006a6e2c)(iVar6);
          iVar5 = iVar11;
          if (iVar7 <= iVar10) goto LAB_00602df4;
          goto LAB_00602ce0;
        }
LAB_00602df4:
        if (iVar12 != 0) {
          if (local_30 == -1) {
            iVar5 = (*(code *)PTR_ENGINE_init_006a7d78)(iVar12);
            if (iVar5 != 0) {
              if (((initialized_engines != 0) ||
                  (initialized_engines = (*(code *)PTR_sk_new_null_006a6fa4)(),
                  initialized_engines != 0)) &&
                 (iVar5 = (*(code *)PTR_sk_push_006a6fa8)(initialized_engines,iVar12), iVar5 != 0))
              goto LAB_00602e08;
              (*(code *)PTR_ENGINE_finish_006a6fc4)(iVar12);
            }
            puVar8 = (undefined4 *)0x0;
LAB_006030b0:
            (*(code *)PTR_ERR_put_error_006a7f34)(0x26,0xbc,0x66,"eng_cnf.c",0xbf);
            if (puVar8 == (undefined4 *)0x0) {
LAB_00602ea0:
              bVar1 = false;
              goto LAB_00602ea4;
            }
            uVar3 = puVar8[2];
LAB_00602e60:
            (*(code *)PTR_ERR_add_error_data_006a813c)
                      (6,"section=",*puVar8,", name=",puVar8[1],", value=",uVar3);
            if (iVar12 != 0) goto LAB_00602ea0;
          }
          else {
LAB_00602e08:
            bVar1 = true;
LAB_00602ea4:
            (*(code *)PTR_ENGINE_free_006a6e84)(iVar12);
            if (bVar1) goto LAB_00602eb8;
          }
          uVar3 = 0;
          goto LAB_00602ee4;
        }
LAB_00602eb8:
        local_44 = local_44 + 1;
        iVar5 = (*(code *)PTR_sk_num_006a6e2c)(iVar4);
      } while (local_44 < iVar5);
    }
    uVar3 = 1;
  }
LAB_00602ee4:
  if (local_2c == *(int *)puVar2) {
    return uVar3;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
                    /* WARNING: Could not recover jumptable at 0x00603208. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*(code *)PTR_CONF_module_add_006a97a0)
                    ("engines",int_engine_module_init,int_engine_module_finish);
  return uVar3;
}

