
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
    if (param_4 == (int *)0x0) goto LAB_005d50d4;
    pcVar7 = (code *)0x0;
    pcVar1 = (code *)param_4[1];
    pcVar8 = (code *)0x0;
    if (*param_4 == 0) goto LAB_005d5094;
LAB_005d4f3c:
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
      if (*param_4 != 0) goto LAB_005d4f3c;
LAB_005d5094:
      if (pcVar1 != (code *)0x0) {
        pcVar7 = pcVar1;
      }
    }
    if (pcVar8 == (code *)0x0) {
      param_1 = pcVar5;
      if (pcVar5 == (code *)0x0) {
LAB_005d50d4:
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)(param_1);
        }
        (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,0x66,0x6c,"e_chil.c",0x4bd);
        return -1;
      }
    }
    else if (pcVar5 == (code *)0x0) {
      iVar2 = (*pcVar8)(param_3,*param_2,0,pcVar7);
      *param_2 = iVar2;
      goto LAB_005d5000;
    }
  }
  iVar2 = (*(code *)PTR_UI_new_method_006a8c10)();
  if (iVar2 != 0) {
    uVar3 = (*(code *)PTR_UI_construct_prompt_006a8c14)(iVar2,"pass phrase",pcVar6);
    iVar4 = (*(code *)PTR_UI_add_input_string_006a8c1c)(iVar2,uVar3,2,param_3,0,*param_2 + -1);
    (*(code *)PTR_UI_add_user_data_006aa678)(iVar2,pcVar7);
    (*(code *)PTR_UI_ctrl_006a8c18)(iVar2,1,1,0,0);
    if (-1 < iVar4) {
      do {
        iVar4 = (*(code *)PTR_UI_process_006a8c20)(iVar2);
        if (-1 < iVar4) {
          iVar4 = (*(code *)PTR_strlen_006aab30)(param_3);
          *param_2 = iVar4;
          break;
        }
        iVar4 = (*(code *)PTR_UI_ctrl_006a8c18)(iVar2,2,0,0,0);
      } while (iVar4 != 0);
    }
    (*(code *)PTR_UI_free_006a8c24)(iVar2);
    (*(code *)PTR_CRYPTO_free_006a7f88)(uVar3);
  }
  iVar2 = *param_2;
LAB_005d5000:
  return -(uint)(iVar2 == 0);
}

