
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
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puVar1 = PTR_strtol_006aaa68;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_2 == (char *)0x0) {
    iVar8 = *param_4;
    *param_3 = 6;
    goto LAB_0041ef3c;
  }
  if ((byte)(*param_2 - 0x30U) < 10) {
    *param_3 = 6;
    iVar8 = (*(code *)puVar1)(param_2,0,10);
    *param_4 = iVar8;
    goto LAB_0041ef3c;
  }
  iVar8 = (*(code *)PTR_strncmp_006aaa7c)(param_2,"param:",6);
  if (iVar8 == 0) {
    param_2 = param_2 + 6;
LAB_0041ed74:
    iVar8 = -1;
    if (param_2 == (char *)0x0) goto LAB_0041eedc;
    iVar5 = (*(code *)PTR_BIO_new_file_006a7fac)(param_2,"r");
    if (iVar5 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Can\'t open parameter file %s\n",param_2);
      iVar5 = 0;
      goto LAB_0041ef18;
    }
    iVar7 = (*(code *)PTR_PEM_read_bio_Parameters_006a80c8)(iVar5,0);
    if (iVar7 == 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar5,1,0,0);
      iVar4 = (*(code *)PTR_PEM_read_bio_X509_006a80cc)(iVar5,0,0,0);
      if (iVar4 != 0) {
        iVar7 = (*(code *)PTR_X509_get_pubkey_006a8008)(iVar4);
        (*(code *)PTR_X509_free_006a7f90)(iVar4);
      }
    }
    (*(code *)PTR_BIO_free_006a7f70)(iVar5);
    if (iVar7 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Error reading parameter file %s\n",param_2);
      iVar5 = iVar7;
      goto LAB_0041ef18;
    }
    iVar5 = *param_3;
    if (iVar5 == -1) {
      iVar5 = (*(code *)PTR_EVP_PKEY_id_006a80d0)(iVar7);
      *param_3 = iVar5;
    }
    else {
      iVar4 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(iVar7);
      if (iVar5 != iVar4) {
        (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Key Type does not match parameters\n");
        iVar5 = 0;
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar7);
        goto LAB_0041ef18;
      }
    }
    if (param_5 == (undefined4 *)0x0) goto LAB_0041efac;
  }
  else {
    iVar5 = (*(code *)PTR_strchr_006aab34)(param_2,0x3a);
    if (iVar5 == 0) {
      iVar8 = (*(code *)PTR_strlen_006aab30)(param_2);
    }
    else {
      iVar8 = iVar5 - (int)param_2;
    }
    iVar7 = (*(code *)PTR_EVP_PKEY_asn1_find_str_006a80bc)(&local_30,param_2,iVar8);
    if (iVar7 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Unknown algorithm %.*s\n",iVar8,param_2);
      iVar5 = 0;
      goto LAB_0041ef18;
    }
    (*(code *)PTR_EVP_PKEY_asn1_get0_info_006a80c0)(0,param_3,0,0,0,iVar7);
    if (local_30 != 0) {
      (*(code *)PTR_ENGINE_finish_006a80c4)();
    }
    if (*param_3 != 6) {
      param_2 = (char *)(iVar5 + 1);
      if (iVar5 == 0) goto LAB_0041ed6c;
      goto LAB_0041ed74;
    }
    if (iVar5 == 0) {
LAB_0041ed6c:
      iVar8 = -1;
    }
    else {
      iVar8 = (*(code *)PTR_strtol_006aaa68)(iVar5 + 1,0,10);
      *param_4 = iVar8;
    }
LAB_0041eedc:
    iVar7 = 0;
    if (param_5 == (undefined4 *)0x0) goto LAB_0041efe8;
  }
  while (iVar5 = (*(code *)PTR_EVP_PKEY_asn1_find_006a80d4)(&local_34,*param_3), iVar5 == 0) {
    (*(code *)PTR_BIO_puts_006a8058)(param_1,"Internal error: can\'t find key algorithm\n");
    iVar5 = 0;
LAB_0041ef18:
    while( true ) {
      if (local_2c == *(int *)puVar2) {
        return iVar5;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0041ef3c:
      iVar7 = 0;
      if (param_5 != (undefined4 *)0x0) break;
LAB_0041efe8:
      iVar5 = (*(code *)PTR_EVP_PKEY_CTX_new_id_006a80d8)(*param_3,param_6);
LAB_0041effc:
      if (iVar5 == 0) {
        pcVar6 = "Error allocating keygen context\n";
LAB_0041f038:
        (*(code *)PTR_BIO_puts_006a8058)(param_1,pcVar6);
        (*(code *)PTR_ERR_print_errors_006a7f40)(param_1);
        iVar5 = 0;
      }
      else {
        iVar7 = (*(code *)PTR_EVP_PKEY_keygen_init_006a80e8)(iVar5);
        if (iVar7 < 1) {
          pcVar6 = "Error initializing keygen context\n";
          goto LAB_0041f038;
        }
        if (((*param_3 == 6) && (iVar8 != -1)) &&
           (iVar7 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(iVar5,6,4,0x1003,iVar8,0), iVar7 < 1))
        {
          (*(code *)PTR_BIO_puts_006a8058)(param_1,"Error setting RSA keysize\n");
          (*(code *)PTR_ERR_print_errors_006a7f40)(param_1);
          (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(iVar5);
          iVar5 = 0;
        }
      }
    }
  }
  (*(code *)PTR_EVP_PKEY_asn1_get0_info_006a80c0)(0,0,0,0,&local_30,iVar5);
  uVar3 = (*(code *)PTR_BUF_strdup_006a80dc)(local_30);
  *param_5 = uVar3;
  if (local_34 != 0) {
    (*(code *)PTR_ENGINE_finish_006a80c4)();
  }
  if (iVar7 == 0) goto LAB_0041efe8;
LAB_0041efac:
  iVar5 = (*(code *)PTR_EVP_PKEY_CTX_new_006a80e0)(iVar7,param_6);
  iVar4 = (*(code *)PTR_EVP_PKEY_bits_006a80e4)(iVar7);
  puVar1 = PTR_EVP_PKEY_free_006a7f78;
  *param_4 = iVar4;
  (*(code *)puVar1)(iVar7);
  goto LAB_0041effc;
}

