
/* WARNING: Removing unreachable block (ram,0x005d2aa8) */
/* WARNING: Removing unreachable block (ram,0x005d2ab0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint get_context_constprop_2(void)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  undefined *puVar8;
  undefined1 *puVar9;
  undefined *local_414;
  undefined4 local_410;
  undefined auStack_40c [1024];
  int *local_c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_410 = 0x400;
  local_414 = auStack_40c;
  local_c = *(int **)PTR___stack_chk_guard_006a9ae8;
  puVar9 = password_context;
  hwcrhk_context = (*p_hwcrhk_Init)(hwcrhk_globals,0x54,&local_414);
  puVar8 = &_gp_1;
  piVar5 = *(int **)puVar1;
  if (local_c == piVar5) {
    return (uint)(hwcrhk_context != 0);
  }
  piVar7 = local_c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((piVar5 != (int *)0x0) && (*(char *)piVar5 == '\0')) {
    piVar5 = (int *)0x0;
  }
  iVar4 = _DAT_006aede8;
  if ((int *)puVar9 == (int *)0x0) {
LAB_005d2acc:
    iVar6 = _DAT_006aede4;
    if (__gp == (code *)0x0) {
      if (_DAT_006aede4 == 0) {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,0x66,0x6c,"e_chil.c",0x4b8);
        return 0xffffffff;
      }
    }
    else if (_DAT_006aede4 == 0) {
      iVar4 = (*__gp)(puVar8,*piVar7,0,iVar4);
      *piVar7 = iVar4;
      goto LAB_005d2a30;
    }
  }
  else {
    iVar6 = *(int *)puVar9;
    iVar2 = *(int *)((int)puVar9 + 4);
    if (iVar6 == 0) {
      if (iVar2 != 0) {
        iVar4 = iVar2;
      }
      goto LAB_005d2acc;
    }
    if (iVar2 != 0) {
      iVar4 = iVar2;
    }
  }
  iVar6 = (*(code *)PTR_UI_new_method_006a7b24)(iVar6);
  if (iVar6 != 0) {
    uVar3 = (*(code *)PTR_UI_construct_prompt_006a7b28)(iVar6,"pass phrase",piVar5);
    iVar2 = (*(code *)PTR_UI_add_input_string_006a7b30)(iVar6,uVar3,2,puVar8,0,*piVar7 + -1);
    (*(code *)PTR_UI_add_user_data_006a956c)(iVar6,iVar4);
    (*(code *)PTR_UI_ctrl_006a7b2c)(iVar6,1,1,0,0);
    if (-1 < iVar2) {
      do {
        iVar4 = (*(code *)PTR_UI_process_006a7b34)(iVar6);
        if (-1 < iVar4) {
          iVar4 = (*(code *)PTR_strlen_006a9a24)(puVar8);
          *piVar7 = iVar4;
          break;
        }
        iVar4 = (*(code *)PTR_UI_ctrl_006a7b2c)(iVar6,2,0,0,0);
      } while (iVar4 != 0);
    }
    (*(code *)PTR_UI_free_006a7b38)(iVar6);
    (*(code *)PTR_CRYPTO_free_006a6e88)(uVar3);
  }
  iVar4 = *piVar7;
LAB_005d2a30:
  return -(uint)(iVar4 == 0);
}

