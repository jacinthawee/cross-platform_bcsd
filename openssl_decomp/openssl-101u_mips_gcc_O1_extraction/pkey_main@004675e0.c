
int pkey_main(undefined4 param_1,int param_2)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  char *pcVar9;
  char *unaff_s4;
  undefined4 unaff_s5;
  int unaff_s7;
  code *pcVar10;
  int *unaff_s8;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  char *local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_34;
  int local_30;
  int local_2c;
  
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  puVar2 = PTR_bio_err_006a6e3c;
  local_34 = 0;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar6 = *(int *)PTR_bio_err_006a6e3c;
  if (iVar6 == 0) {
    iVar6 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *(int *)puVar2 = iVar6;
  }
  iVar6 = load_config(iVar6,0);
  if (iVar6 == 0) {
    iVar6 = 1;
    pcVar9 = (char *)0x0;
    piVar7 = (int *)0x0;
    goto LAB_00467878;
  }
  piVar7 = (int *)(param_2 + 4);
  (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
  (*(code *)PTR_OPENSSL_add_all_algorithms_noconf_006a73fc)();
  unaff_s8 = *(int **)(param_2 + 4);
  if (unaff_s8 != (int *)0x0) {
    local_64 = 0;
    local_50 = 0;
    local_4c = 0;
    local_44 = 0;
    local_40 = 0;
    local_54 = 0;
    if (*(char *)unaff_s8 == '-') {
      local_3c = 0;
      local_68 = 0;
      local_58 = 0;
      local_70 = 3;
      unaff_s5 = 3;
      local_5c = 0;
      unaff_s7 = 0;
      local_6c = 0x630000;
      iVar8 = 0x630000;
      pcVar9 = "-outform";
      unaff_s4 = "-passin";
      local_60 = "-engine";
      local_48 = 0x630000;
      goto LAB_00467734;
    }
  }
  local_40 = 0;
  local_44 = 0;
  local_4c = 0;
  local_50 = 0;
  local_54 = 0;
  local_64 = 0;
  local_3c = 0;
  unaff_s5 = 3;
  local_68 = 0;
  unaff_s7 = 0;
  local_58 = 0;
  local_70 = 3;
  local_5c = 0;
LAB_004679f0:
  puVar3 = PTR_bio_err_006a6e3c;
  uVar5 = setup_engine(*(undefined4 *)puVar2,local_64,0);
  iVar6 = app_passwd(*(undefined4 *)puVar2,unaff_s7,local_68,&local_34,&local_30);
  if (iVar6 == 0) {
    iVar6 = 1;
    pcVar9 = (char *)0x0;
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"Error getting passwords\n");
    piVar7 = (int *)0x0;
  }
  else {
    if (local_58 == 0) {
      piVar7 = (int *)(*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
    }
    else {
      piVar7 = (int *)(*(code *)PTR_BIO_new_file_006a6eac)(local_58,&DAT_00632420);
      if (piVar7 == (int *)0x0) {
        iVar6 = 1;
        pcVar9 = (char *)0x0;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar3,"Can\'t open output file %s\n",local_58);
        goto LAB_00467878;
      }
    }
    if (local_54 == 0) {
      pcVar9 = "key";
      pcVar10 = (code *)PTR_load_key_006a6ec8;
    }
    else {
      pcVar9 = "Public Key";
      pcVar10 = (code *)PTR_load_pubkey_006a74e8;
    }
    pcVar9 = (char *)(*pcVar10)(*(undefined4 *)puVar2,local_5c,unaff_s5,1,local_34,uVar5,pcVar9);
    if (pcVar9 == (char *)0x0) {
      iVar6 = 1;
    }
    else {
      if (local_50 == 0) {
        if (local_70 == 3) {
          if (local_40 == 0) {
            (*(code *)PTR_PEM_write_bio_PrivateKey_006a6f50)(piVar7,pcVar9,local_3c,0,0,0,local_30);
          }
          else {
            (*(code *)PTR_PEM_write_bio_PUBKEY_006a6f28)(piVar7,pcVar9);
          }
        }
        else {
          if (local_70 != 1) {
            iVar6 = 1;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar2,"Bad format specified for key\n");
            goto LAB_00467878;
          }
          if (local_40 == 0) {
            (*(code *)PTR_i2d_PrivateKey_bio_006a7758)(piVar7,pcVar9);
          }
          else {
            (*(code *)PTR_i2d_PUBKEY_bio_006a7cd8)(piVar7,pcVar9);
          }
        }
      }
      iVar6 = 0;
      if (local_4c != 0) {
        pcVar10 = (code *)PTR_EVP_PKEY_print_private_006a7750;
        if (local_44 != 0) {
          pcVar10 = (code *)PTR_EVP_PKEY_print_public_006a7cdc;
        }
        (*pcVar10)(piVar7,pcVar9,0,0);
        iVar6 = 0;
      }
    }
  }
LAB_00467878:
  (*(code *)PTR_EVP_PKEY_free_006a6e78)(pcVar9);
  (*(code *)PTR_BIO_free_all_006a6e74)(piVar7);
  (*(code *)PTR_BIO_free_006a6e70)(0);
  if (local_34 != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  iVar8 = iVar6;
  if (local_30 != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
LAB_004678dc:
  if (local_2c == *(int *)puVar4) {
    return iVar6;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00467de8:
  local_3c = (*(code *)PTR_EVP_get_cipherbyname_006a7394)((char *)((int)unaff_s8 + 1));
  unaff_s8 = piVar7;
  if (local_3c == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Unknown cipher %s\n",*piVar7 + 1);
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
LAB_00467714:
  do {
    piVar7 = unaff_s8 + 1;
    if (bVar1) {
LAB_0046778c:
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Usage pkey [options]\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"where options are\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"-in file        input file\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-inform X       input format (DER or PEM)\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-passin arg     input file pass phrase source\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-outform X      output format (DER or PEM)\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"-out file       output file\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-passout arg    output file pass phrase source\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-engine e       use engine e, possibly a hardware device.\n"
                );
      iVar6 = 1;
      goto LAB_004678dc;
    }
    while( true ) {
      unaff_s8 = (int *)unaff_s8[1];
      if ((unaff_s8 == (int *)0x0) || (*(char *)unaff_s8 != '-')) goto LAB_004679f0;
LAB_00467734:
      iVar6 = (*(code *)PTR_strcmp_006a9b18)(unaff_s8,iVar8 + 0x20bc);
      if (iVar6 == 0) {
        if (piVar7[1] != 0) {
          unaff_s8 = piVar7 + 1;
          unaff_s5 = str2fmt();
          bVar1 = false;
          goto LAB_00467714;
        }
        goto LAB_00467944;
      }
      iVar6 = (*(code *)PTR_strcmp_006a9b18)(unaff_s8,pcVar9);
      if (iVar6 != 0) break;
      if (piVar7[1] == 0) goto LAB_00467944;
      unaff_s8 = piVar7 + 1;
      piVar7 = piVar7 + 2;
      local_70 = str2fmt();
    }
    iVar6 = (*(code *)PTR_strcmp_006a9b18)(unaff_s8,unaff_s4);
    if (iVar6 == 0) {
      unaff_s7 = piVar7[1];
      bVar1 = false;
      if (unaff_s7 == 0) goto LAB_0046778c;
      unaff_s8 = piVar7 + 1;
      goto LAB_00467714;
    }
    iVar6 = (*(code *)PTR_strcmp_006a9b18)(unaff_s8,local_6c + 0x2728);
    if (iVar6 == 0) {
      local_68 = piVar7[1];
      if (local_68 == 0) goto LAB_0046778c;
      bVar1 = false;
      unaff_s8 = piVar7 + 1;
      goto LAB_00467714;
    }
    iVar6 = (*(code *)PTR_strcmp_006a9b18)(unaff_s8,local_60);
    if (iVar6 == 0) {
      local_64 = piVar7[1];
      if (local_64 == 0) goto LAB_0046778c;
      bVar1 = false;
      unaff_s8 = piVar7 + 1;
      goto LAB_00467714;
    }
    if (((*(char *)((int)unaff_s8 + 1) == 'i') && (*(char *)((int)unaff_s8 + 2) == 'n')) &&
       (*(char *)((int)unaff_s8 + 3) == '\0')) {
      if (piVar7[1] != 0) {
        unaff_s8 = piVar7 + 1;
        bVar1 = false;
        local_5c = piVar7[1];
        goto LAB_00467714;
      }
    }
    else {
      iVar6 = (*(code *)PTR_strcmp_006a9b18)(unaff_s8,local_48 + 0x2514);
      if (iVar6 != 0) {
        iVar6 = (*(code *)PTR_strcmp_006a9b18)(unaff_s8,"-pubin");
        if (iVar6 == 0) {
          bVar1 = false;
          local_44 = 1;
          local_40 = 1;
          local_54 = 1;
          unaff_s8 = piVar7;
          goto LAB_00467714;
        }
        iVar6 = (*(code *)PTR_strcmp_006a9b18)(unaff_s8,"-pubout");
        if (iVar6 == 0) {
          bVar1 = false;
          local_40 = 1;
          unaff_s8 = piVar7;
          goto LAB_00467714;
        }
        iVar6 = (*(code *)PTR_strcmp_006a9b18)(unaff_s8,"-text_pub");
        if (iVar6 == 0) {
          bVar1 = false;
          local_4c = 1;
          local_44 = 1;
          unaff_s8 = piVar7;
          goto LAB_00467714;
        }
        iVar6 = (*(code *)PTR_strcmp_006a9b18)(unaff_s8,"-text");
        if (iVar6 == 0) {
          bVar1 = false;
          local_4c = 1;
          unaff_s8 = piVar7;
        }
        else {
          iVar6 = (*(code *)PTR_strcmp_006a9b18)(unaff_s8,"-noout");
          if (iVar6 != 0) goto LAB_00467de8;
          bVar1 = false;
          local_50 = 1;
          unaff_s8 = piVar7;
        }
        goto LAB_00467714;
      }
      if (piVar7[1] != 0) {
        bVar1 = false;
        unaff_s8 = piVar7 + 1;
        local_58 = piVar7[1];
        goto LAB_00467714;
      }
    }
LAB_00467944:
    bVar1 = true;
    unaff_s8 = piVar7;
  } while( true );
}
