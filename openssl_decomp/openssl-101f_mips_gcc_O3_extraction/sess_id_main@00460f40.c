
undefined4 sess_id_main(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char **ppcVar7;
  char *pcVar8;
  undefined1 *puVar9;
  int iVar10;
  int iVar11;
  char **ppcVar12;
  char *local_50;
  int local_4c;
  char *local_48;
  int local_40;
  int local_38;
  char *local_34;
  int local_2c;
  
  puVar1 = PTR_bio_err_006a7f3c;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  if (*(int *)puVar1 == 0) {
    uVar3 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar2 = (*(code *)PTR_BIO_new_006a7fa4)(uVar3);
    *(int *)puVar1 = iVar2;
    if (iVar2 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar2,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
    }
  }
  param_1 = param_1 + -1;
  ppcVar12 = (char **)(param_2 + 4);
  if (param_1 < 1) {
    (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
    uVar3 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar2 = (*(code *)PTR_BIO_new_006a7fa4)(uVar3);
    if (iVar2 == 0) goto LAB_004616c4;
    iVar11 = 3;
    local_34 = (char *)0x0;
    iVar10 = 3;
    local_38 = 0;
    local_40 = 0;
    local_2c = 0;
    local_48 = (char *)0x0;
LAB_0046154c:
    (*(code *)PTR_BIO_ctrl_006a7f18)(iVar2,0x6a,0,*(undefined4 *)PTR_stdin_006aab20);
  }
  else {
    local_40 = 0;
    local_2c = 0;
    local_38 = 0;
    local_34 = (char *)0x0;
    iVar11 = 3;
    local_48 = (char *)0x0;
    local_50 = (char *)0x0;
    iVar10 = 3;
    local_4c = 0;
LAB_00461030:
    do {
      pcVar8 = *ppcVar12;
      iVar2 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-inform");
      if (iVar2 == 0) {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_004612b0;
        ppcVar7 = ppcVar12 + 1;
        iVar10 = str2fmt(ppcVar12[1]);
      }
      else {
        iVar2 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-outform");
        if (iVar2 == 0) {
          if (param_1 == 1) goto LAB_004612b0;
          ppcVar7 = ppcVar12 + 1;
          param_1 = param_1 + -2;
          ppcVar12 = ppcVar12 + 2;
          iVar11 = str2fmt(*ppcVar7);
          if (param_1 == 0) break;
          goto LAB_00461030;
        }
        if ((((*pcVar8 == '-') && (pcVar8[1] == 'i')) && (pcVar8[2] == 'n')) && (pcVar8[3] == '\0'))
        {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_004612b0;
          local_50 = ppcVar12[1];
          ppcVar7 = ppcVar12 + 1;
        }
        else {
          iVar2 = (*(code *)PTR_strcmp_006aac20)(pcVar8,&DAT_00632edc);
          if (iVar2 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_004612b0;
            local_48 = ppcVar12[1];
            ppcVar7 = ppcVar12 + 1;
          }
          else {
            iVar2 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-text");
            ppcVar7 = ppcVar12;
            if (iVar2 == 0) {
              local_4c = local_4c + 1;
              local_40 = local_4c;
            }
            else {
              iVar2 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-cert");
              if (iVar2 == 0) {
                local_4c = local_4c + 1;
                local_38 = local_4c;
              }
              else {
                iVar2 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-noout");
                if (iVar2 == 0) {
                  local_4c = local_4c + 1;
                  local_2c = local_4c;
                }
                else {
                  iVar2 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-context");
                  if (iVar2 != 0) {
                    (*(code *)PTR_BIO_printf_006a7f38)
                              (*(undefined4 *)puVar1,"unknown option %s\n",pcVar8);
LAB_004612b0:
                    if (sess_id_usage._0_4_ == 0) {
                      return 1;
                    }
                    puVar9 = sess_id_usage;
                    do {
                      puVar9 = (undefined1 *)((int)puVar9 + 4);
                      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar1,"%s");
                    } while (*(int *)puVar9 != 0);
                    return 1;
                  }
                  param_1 = param_1 + -1;
                  if (param_1 == 0) goto LAB_004612b0;
                  local_34 = ppcVar12[1];
                  ppcVar7 = ppcVar12 + 1;
                }
              }
            }
          }
        }
      }
      param_1 = param_1 + -1;
      ppcVar12 = ppcVar7 + 1;
    } while (param_1 != 0);
    (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
    uVar3 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar2 = (*(code *)PTR_BIO_new_006a7fa4)(uVar3);
    if (iVar2 == 0) {
LAB_004616c4:
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar1);
      return 1;
    }
    if (local_50 == (char *)0x0) goto LAB_0046154c;
    iVar4 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar2,0x6c,3,local_50);
    if (iVar4 < 1) {
      (*(code *)PTR_perror_006aab88)(local_50);
      goto LAB_00461588;
    }
  }
  if (iVar10 == 1) {
    iVar10 = (*(code *)PTR_ASN1_d2i_bio_006a82c4)
                       (PTR_SSL_SESSION_new_006a8d74,PTR_d2i_SSL_SESSION_006a8d70,iVar2,0);
  }
  else {
    if (iVar10 != 3) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar1,"bad input format specified for input crl\n");
      goto LAB_00461588;
    }
    iVar10 = (*(code *)PTR_PEM_read_bio_SSL_SESSION_006a8a98)(iVar2,0,0,0);
  }
  if (iVar10 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar1,"unable to load SSL_SESSION\n");
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar1);
LAB_00461588:
    (*(code *)PTR_BIO_free_006a7f70)(iVar2);
    return 1;
  }
  (*(code *)PTR_BIO_free_006a7f70)(iVar2);
  iVar2 = (*(code *)PTR_SSL_SESSION_get0_peer_006a8d68)(iVar10);
  if (local_34 != (char *)0x0) {
    uVar5 = (*(code *)PTR_strlen_006aab30)(local_34);
    if (uVar5 < 0x21) {
      (*(code *)PTR_SSL_SESSION_set1_id_context_006a8d6c)(iVar10,local_34,uVar5);
      goto LAB_00461400;
    }
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar1,"Context too long\n");
LAB_00461180:
    uVar3 = 1;
    goto LAB_00461184;
  }
LAB_00461400:
  if ((local_2c != 0) && (local_40 == 0)) {
    uVar3 = 0;
    goto LAB_00461184;
  }
  uVar3 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  iVar4 = (*(code *)PTR_BIO_new_006a7fa4)(uVar3);
  if (iVar4 == 0) {
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar1);
    goto LAB_00461180;
  }
  if (local_48 == (char *)0x0) {
    (*(code *)PTR_BIO_ctrl_006a7f18)(iVar4,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
LAB_0046146c:
    if (local_40 == 0) {
      if (local_2c != 0) goto LAB_004615d8;
      if (local_38 == 0) goto LAB_004615f4;
      if (iVar2 != 0) goto LAB_004614b4;
      uVar3 = 0;
    }
    else {
      (*(code *)PTR_SSL_SESSION_print_006a8958)(iVar4,iVar10);
      if (local_38 == 0) {
        if (local_2c == 0) {
LAB_004615f4:
          if (iVar11 == 1) {
            iVar2 = (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_SSL_SESSION_006a8d78,iVar4,iVar10);
          }
          else {
            if (iVar11 != 3) {
LAB_004614cc:
              uVar3 = 1;
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar1,"bad output format specified for outfile\n");
              goto LAB_004614e4;
            }
            iVar2 = (*(code *)PTR_PEM_write_bio_SSL_SESSION_006a889c)(iVar4,iVar10);
          }
          if (iVar2 != 0) goto LAB_004615d8;
          uVar3 = 1;
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar1,"unable to write SSL_SESSION\n");
        }
        else {
          uVar3 = 0;
        }
      }
      else {
        if (iVar2 == 0) {
          (*(code *)PTR_BIO_puts_006a8058)(iVar4,"No certificate present\n");
        }
        else {
          (*(code *)PTR_X509_print_006a81c0)(iVar4,iVar2);
          if (local_2c == 0) {
LAB_004614b4:
            if (iVar11 == 1) {
              iVar2 = (*(code *)PTR_i2d_X509_bio_006a801c)(iVar4,iVar2);
            }
            else {
              if (iVar11 != 3) goto LAB_004614cc;
              iVar2 = (*(code *)PTR_PEM_write_bio_X509_006a8020)(iVar4,iVar2);
            }
            if (iVar2 == 0) {
              uVar3 = 1;
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar1,"unable to write X509\n");
              goto LAB_004614e4;
            }
          }
        }
LAB_004615d8:
        uVar3 = 0;
      }
    }
  }
  else {
    iVar6 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar4,0x6c,5,local_48);
    if (0 < iVar6) goto LAB_0046146c;
    uVar3 = 1;
    (*(code *)PTR_perror_006aab88)(local_48);
  }
LAB_004614e4:
  (*(code *)PTR_BIO_free_all_006a7f74)(iVar4);
LAB_00461184:
  (*(code *)PTR_SSL_SESSION_free_006a8aa0)(iVar10);
  return uVar3;
}

