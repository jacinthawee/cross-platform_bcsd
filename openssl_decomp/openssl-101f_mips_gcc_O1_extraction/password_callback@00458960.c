
int password_callback(undefined4 param_1,int param_2,int param_3,int *param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_4 == (int *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar4 = *param_4;
    iVar5 = param_4[1];
    if (iVar4 != 0) {
      iVar5 = (*(code *)PTR_strlen_006aab30)(iVar4);
      if (iVar5 <= param_2) {
        param_2 = iVar5;
      }
      (*(code *)PTR_memcpy_006aabf4)(param_1,iVar4,param_2);
      return param_2;
    }
  }
  iVar4 = (*(code *)PTR_UI_new_method_006a8c10)(ui_method);
  if (iVar4 == 0) {
    return 0;
  }
  uVar2 = (*(code *)PTR_UI_construct_prompt_006a8c14)(iVar4,"pass phrase",iVar5);
  (*(code *)PTR_UI_ctrl_006a8c18)(iVar4,1,1,0,0);
  iVar5 = (*(code *)PTR_UI_add_input_string_006a8c1c)(iVar4,uVar2,2,param_1,4,0x1fff);
  if (-1 < iVar5) {
    if (param_3 == 0) {
      iVar6 = 0;
LAB_00458ac0:
      do {
        iVar5 = (*(code *)PTR_UI_process_006a8c20)(iVar4);
        if (-1 < iVar5) {
          if (iVar6 != 0) {
            (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar6,param_2);
            (*(code *)PTR_CRYPTO_free_006a7f88)(iVar6);
          }
          iVar5 = (*(code *)PTR_strlen_006aab30)(param_1);
          goto LAB_00458b28;
        }
        iVar3 = (*(code *)PTR_UI_ctrl_006a8c18)(iVar4,2,0,0,0);
      } while (iVar3 != 0);
    }
    else {
      iVar6 = (*(code *)PTR_CRYPTO_malloc_006a8108)(param_2,"apps.c",0x250);
      iVar5 = (*(code *)PTR_UI_add_verify_string_006a8c28)(iVar4,uVar2,2,iVar6,4,0x1fff,param_1);
      if (-1 < iVar5) goto LAB_00458ac0;
    }
    if (iVar6 != 0) {
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar6,param_2);
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar6);
    }
  }
  puVar1 = PTR_bio_err_006a7f3c;
  if (iVar5 == -1) {
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,"User interface error\n")
    ;
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar1);
  }
  else {
    if (iVar5 != -2) {
      iVar5 = 0;
      goto LAB_00458b28;
    }
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,"aborted!\n");
  }
  iVar5 = 0;
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(param_1,param_2);
LAB_00458b28:
  (*(code *)PTR_UI_free_006a8c24)(iVar4);
  (*(code *)PTR_CRYPTO_free_006a7f88)(uVar2);
  return iVar5;
}

