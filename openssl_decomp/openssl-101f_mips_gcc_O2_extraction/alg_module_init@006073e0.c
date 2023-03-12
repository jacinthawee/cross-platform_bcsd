
int alg_module_init(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar2 = (*(code *)PTR_CONF_imodule_get_value_006aa8a8)();
  iVar3 = (*(code *)PTR_NCONF_get_section_006a7fd4)(param_2,uVar2);
  if (iVar3 == 0) {
    iVar4 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(6,0xb1,0xa5,"evp_cnf.c",0x53);
  }
  else {
    iVar7 = 0;
    iVar4 = (*(code *)PTR_sk_num_006a7f2c)(iVar3);
    if (0 < iVar4) {
      do {
        iVar5 = (*(code *)PTR_sk_value_006a7f24)(iVar3,iVar7);
        iVar4 = (*(code *)PTR_strcmp_006aac20)(*(undefined4 *)(iVar5 + 4),"fips_mode");
        if (iVar4 == 0) {
          iVar5 = (*(code *)PTR_X509V3_get_value_bool_006a9efc)(iVar5,&local_30);
          if (iVar5 == 0) {
            uVar6 = 0xa8;
            uVar2 = 0x5e;
          }
          else {
            if (local_30 < 1) goto LAB_006074ec;
            uVar6 = 0xa7;
            uVar2 = 0x6a;
          }
          (*(code *)PTR_ERR_put_error_006a9030)(6,0xb1,uVar6,"evp_cnf.c",uVar2);
          goto LAB_00607584;
        }
        (*(code *)PTR_ERR_put_error_006a9030)(6,0xb1,0xa9,"evp_cnf.c",0x71);
        (*(code *)PTR_ERR_add_error_data_006a9264)
                  (4,"name=",*(undefined4 *)(iVar5 + 4),", value=",*(undefined4 *)(iVar5 + 8));
LAB_006074ec:
        iVar7 = iVar7 + 1;
        iVar4 = (*(code *)PTR_sk_num_006a7f2c)(iVar3);
      } while (iVar7 < iVar4);
    }
    iVar4 = 1;
  }
LAB_00607584:
  if (local_2c == *(int *)puVar1) {
    return iVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x00607638. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar3 = (*(code *)PTR_CONF_module_add_006aa8b0)("alg_section",alg_module_init,0);
  return iVar3;
}

