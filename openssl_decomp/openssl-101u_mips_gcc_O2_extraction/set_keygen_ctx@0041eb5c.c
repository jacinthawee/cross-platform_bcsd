
int set_keygen_ctx(undefined4 param_1,char *param_2,int *param_3,int *param_4,undefined4 *param_5,
                  undefined4 param_6)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int local_34;
  int local_30;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puVar1 = PTR_strtol_006a9958;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (param_2 == (char *)0x0) {
    iVar8 = *param_4;
    *param_3 = 6;
    goto LAB_0041ef14;
  }
  if ((byte)(*param_2 - 0x30U) < 10) {
    *param_3 = 6;
    iVar8 = (*(code *)puVar1)(param_2,0,10);
    *param_4 = iVar8;
    goto LAB_0041ef14;
  }
  iVar8 = (*(code *)PTR_strncmp_006a9970)(param_2,"param:",6);
  if (iVar8 == 0) {
    param_2 = param_2 + 6;
LAB_0041ed4c:
    iVar8 = -1;
    if (param_2 == (char *)0x0) goto LAB_0041eeb4;
    iVar5 = (*(code *)PTR_BIO_new_file_006a6eac)(param_2,"r");
    if (iVar5 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Can\'t open parameter file %s\n",param_2);
      iVar5 = 0;
      goto LAB_0041eef0;
    }
    iVar7 = (*(code *)PTR_PEM_read_bio_Parameters_006a6fc8)(iVar5,0);
    if (iVar7 == 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar5,1,0,0);
      iVar4 = (*(code *)PTR_PEM_read_bio_X509_006a6fcc)(iVar5,0,0,0);
      if (iVar4 != 0) {
        iVar7 = (*(code *)PTR_X509_get_pubkey_006a6f08)(iVar4);
        (*(code *)PTR_X509_free_006a6e90)(iVar4);
      }
    }
    (*(code *)PTR_BIO_free_006a6e70)(iVar5);
    if (iVar7 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Error reading parameter file %s\n",param_2);
      iVar5 = iVar7;
      goto LAB_0041eef0;
    }
    iVar5 = *param_3;
    if (iVar5 == -1) {
      iVar5 = (*(code *)PTR_EVP_PKEY_id_006a6fd0)(iVar7);
      *param_3 = iVar5;
    }
    else {
      iVar4 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(iVar7);
      if (iVar5 != iVar4) {
        (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Key Type does not match parameters\n");
        iVar5 = 0;
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar7);
        goto LAB_0041eef0;
      }
    }
    if (param_5 == (undefined4 *)0x0) goto LAB_0041ef84;
  }
  else {
    iVar5 = (*(code *)PTR_strchr_006a9a28)(param_2,0x3a);
    if (iVar5 == 0) {
      iVar8 = (*(code *)PTR_strlen_006a9a24)(param_2);
    }
    else {
      iVar8 = iVar5 - (int)param_2;
    }
    iVar7 = (*(code *)PTR_EVP_PKEY_asn1_find_str_006a6fbc)(&local_30,param_2,iVar8);
    if (iVar7 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Unknown algorithm %.*s\n",iVar8,param_2);
      iVar5 = 0;
      goto LAB_0041eef0;
    }
    (*(code *)PTR_EVP_PKEY_asn1_get0_info_006a6fc0)(0,param_3,0,0,0,iVar7);
    if (local_30 != 0) {
      (*(code *)PTR_ENGINE_finish_006a6fc4)();
    }
    if (*param_3 == 6) {
      if (iVar5 == 0) {
        iVar8 = *param_4;
      }
      else {
        iVar8 = (*(code *)PTR_strtol_006a9958)(iVar5 + 1,0,10);
        *param_4 = iVar8;
      }
    }
    else {
      param_2 = (char *)(iVar5 + 1);
      if (iVar5 != 0) goto LAB_0041ed4c;
      iVar8 = -1;
    }
LAB_0041eeb4:
    iVar7 = 0;
    if (param_5 == (undefined4 *)0x0) goto LAB_0041efc0;
  }
  while (iVar5 = (*(code *)PTR_EVP_PKEY_asn1_find_006a6fd4)(&local_34,*param_3), iVar5 == 0) {
    (*(code *)PTR_BIO_puts_006a6f58)(param_1,"Internal error: can\'t find key algorithm\n");
    iVar5 = 0;
LAB_0041eef0:
    while( true ) {
      if (local_2c == *(int *)puVar2) {
        return iVar5;
      }
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0041ef14:
      iVar7 = 0;
      if (param_5 != (undefined4 *)0x0) break;
LAB_0041efc0:
      iVar5 = (*(code *)PTR_EVP_PKEY_CTX_new_id_006a6fd8)(*param_3,param_6);
LAB_0041efd4:
      if (iVar5 == 0) {
        pcVar6 = "Error allocating keygen context\n";
LAB_0041f010:
        (*(code *)PTR_BIO_puts_006a6f58)(param_1,pcVar6);
        (*(code *)PTR_ERR_print_errors_006a6e40)(param_1);
        iVar5 = 0;
      }
      else {
        iVar7 = (*(code *)PTR_EVP_PKEY_keygen_init_006a6fe8)(iVar5);
        if (iVar7 < 1) {
          pcVar6 = "Error initializing keygen context\n";
          goto LAB_0041f010;
        }
        if (((*param_3 == 6) && (iVar8 != -1)) &&
           (iVar7 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)(iVar5,6,4,0x1003,iVar8,0), iVar7 < 1))
        {
          (*(code *)PTR_BIO_puts_006a6f58)(param_1,"Error setting RSA keysize\n");
          (*(code *)PTR_ERR_print_errors_006a6e40)(param_1);
          (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar5);
          iVar5 = 0;
        }
      }
    }
  }
  (*(code *)PTR_EVP_PKEY_asn1_get0_info_006a6fc0)(0,0,0,0,&local_30,iVar5);
  uVar3 = (*(code *)PTR_BUF_strdup_006a6fdc)(local_30);
  *param_5 = uVar3;
  if (local_34 != 0) {
    (*(code *)PTR_ENGINE_finish_006a6fc4)();
  }
  if (iVar7 == 0) goto LAB_0041efc0;
LAB_0041ef84:
  iVar5 = (*(code *)PTR_EVP_PKEY_CTX_new_006a6fe0)(iVar7,param_6);
  iVar4 = (*(code *)PTR_EVP_PKEY_bits_006a6fe4)(iVar7);
  puVar1 = PTR_EVP_PKEY_free_006a6e78;
  *param_4 = iVar4;
  (*(code *)puVar1)(iVar7);
  goto LAB_0041efd4;
}

