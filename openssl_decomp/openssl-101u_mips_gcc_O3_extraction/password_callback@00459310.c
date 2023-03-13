
int password_callback(undefined4 param_1,int param_2,int param_3,int *param_4)

{
  undefined *puVar1;
  int iVar2;
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
      iVar5 = (*(code *)PTR_strlen_006a9a24)(iVar4);
      if (iVar5 <= param_2) {
        param_2 = iVar5;
      }
      (*(code *)PTR_memcpy_006a9aec)(param_1,iVar4,param_2);
      return param_2;
    }
  }
  iVar4 = (*(code *)PTR_UI_new_method_006a7b24)(ui_method);
  if (iVar4 == 0) {
    return 0;
  }
  iVar5 = (*(code *)PTR_UI_construct_prompt_006a7b28)(iVar4,"pass phrase",iVar5);
  if (iVar5 == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,"Out of memory\n");
    (*(code *)PTR_UI_free_006a7b38)(iVar4);
    return 0;
  }
  (*(code *)PTR_UI_ctrl_006a7b2c)(iVar4,1,1,0,0);
  iVar2 = (*(code *)PTR_UI_add_input_string_006a7b30)(iVar4,iVar5,2,param_1,4,param_2 + -1);
  if (-1 < iVar2) {
    if (param_3 == 0) {
      iVar6 = 0;
LAB_00459474:
      do {
        iVar2 = (*(code *)PTR_UI_process_006a7b34)(iVar4);
        if (-1 < iVar2) {
          if (iVar6 != 0) {
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar6,param_2);
            (*(code *)PTR_CRYPTO_free_006a6e88)(iVar6);
          }
          iVar2 = (*(code *)PTR_strlen_006a9a24)(param_1);
          goto LAB_004594bc;
        }
        iVar3 = (*(code *)PTR_UI_ctrl_006a7b2c)(iVar4,2,0,0,0);
      } while (iVar3 != 0);
      if (iVar6 == 0) goto LAB_00459538;
    }
    else {
      iVar6 = (*(code *)PTR_CRYPTO_malloc_006a7008)(param_2,"apps.c",0x249);
      if (iVar6 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,"Out of memory\n");
        (*(code *)PTR_UI_free_006a7b38)(iVar4);
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar5);
        return 0;
      }
      iVar2 = (*(code *)PTR_UI_add_verify_string_006a7b3c)
                        (iVar4,iVar5,2,iVar6,4,param_2 + -1,param_1);
      if (-1 < iVar2) goto LAB_00459474;
    }
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar6,param_2);
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar6);
  }
LAB_00459538:
  puVar1 = PTR_bio_err_006a6e3c;
  if (iVar2 == -1) {
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,"User interface error\n")
    ;
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar1);
  }
  else {
    if (iVar2 != -2) {
      iVar2 = 0;
      goto LAB_004594bc;
    }
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,"aborted!\n");
  }
  iVar2 = 0;
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(param_1,param_2);
LAB_004594bc:
  (*(code *)PTR_UI_free_006a7b38)(iVar4);
  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar5);
  return iVar2;
}

