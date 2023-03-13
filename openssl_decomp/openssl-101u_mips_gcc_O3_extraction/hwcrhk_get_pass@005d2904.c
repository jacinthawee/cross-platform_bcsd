
int hwcrhk_get_pass(code *param_1,int *param_2,undefined4 param_3,int *param_4,code **param_5)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  code *pcVar6;
  code *pcVar7;
  code *pcVar8;
  
  pcVar6 = param_1;
  if ((param_1 != (code *)0x0) && (*param_1 == (code)0x0)) {
    pcVar6 = (code *)0x0;
  }
  if (param_5 == (code **)0x0) {
    pcVar5 = (code *)0x0;
    if (param_4 == (int *)0x0) goto LAB_005d2b04;
    pcVar7 = (code *)0x0;
    pcVar1 = (code *)param_4[1];
    pcVar8 = (code *)0x0;
    if (*param_4 == 0) goto LAB_005d2ac4;
LAB_005d296c:
    if (pcVar1 != (code *)0x0) {
      pcVar7 = pcVar1;
    }
  }
  else {
    pcVar5 = param_5[1];
    pcVar8 = *param_5;
    pcVar7 = param_5[2];
    if (param_4 != (int *)0x0) {
      pcVar1 = (code *)param_4[1];
      if (*param_4 != 0) goto LAB_005d296c;
LAB_005d2ac4:
      if (pcVar1 != (code *)0x0) {
        pcVar7 = pcVar1;
      }
    }
    if (pcVar8 == (code *)0x0) {
      param_1 = pcVar5;
      if (pcVar5 == (code *)0x0) {
LAB_005d2b04:
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)(param_1);
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,0x66,0x6c,"e_chil.c",0x4b8);
        return -1;
      }
    }
    else if (pcVar5 == (code *)0x0) {
      iVar2 = (*pcVar8)(param_3,*param_2,0,pcVar7);
      *param_2 = iVar2;
      goto LAB_005d2a30;
    }
  }
  iVar2 = (*(code *)PTR_UI_new_method_006a7b24)();
  if (iVar2 != 0) {
    uVar3 = (*(code *)PTR_UI_construct_prompt_006a7b28)(iVar2,"pass phrase",pcVar6);
    iVar4 = (*(code *)PTR_UI_add_input_string_006a7b30)(iVar2,uVar3,2,param_3,0,*param_2 + -1);
    (*(code *)PTR_UI_add_user_data_006a956c)(iVar2,pcVar7);
    (*(code *)PTR_UI_ctrl_006a7b2c)(iVar2,1,1,0,0);
    if (-1 < iVar4) {
      do {
        iVar4 = (*(code *)PTR_UI_process_006a7b34)(iVar2);
        if (-1 < iVar4) {
          iVar4 = (*(code *)PTR_strlen_006a9a24)(param_3);
          *param_2 = iVar4;
          break;
        }
        iVar4 = (*(code *)PTR_UI_ctrl_006a7b2c)(iVar2,2,0,0,0);
      } while (iVar4 != 0);
    }
    (*(code *)PTR_UI_free_006a7b38)(iVar2);
    (*(code *)PTR_CRYPTO_free_006a6e88)(uVar3);
  }
  iVar2 = *param_2;
LAB_005d2a30:
  return -(uint)(iVar2 == 0);
}

