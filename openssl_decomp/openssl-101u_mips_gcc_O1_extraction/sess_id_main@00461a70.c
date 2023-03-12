
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
  
  puVar1 = PTR_bio_err_006a6e3c;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  if (*(int *)puVar1 == 0) {
    uVar3 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar2 = (*(code *)PTR_BIO_new_006a6ea4)(uVar3);
    *(int *)puVar1 = iVar2;
    if (iVar2 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar2,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
    }
  }
  param_1 = param_1 + -1;
  ppcVar12 = (char **)(param_2 + 4);
  if (param_1 < 1) {
    (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
    uVar3 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar2 = (*(code *)PTR_BIO_new_006a6ea4)(uVar3);
    if (iVar2 == 0) goto LAB_004621f4;
    iVar11 = 3;
    local_34 = (char *)0x0;
    iVar10 = 3;
    local_38 = 0;
    local_40 = 0;
    local_2c = 0;
    local_48 = (char *)0x0;
LAB_0046207c:
    (*(code *)PTR_BIO_ctrl_006a6e18)(iVar2,0x6a,0,*(undefined4 *)PTR_stdin_006a9a14);
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
LAB_00461b60:
    do {
      pcVar8 = *ppcVar12;
      iVar2 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-inform");
      if (iVar2 == 0) {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_00461de0;
        ppcVar7 = ppcVar12 + 1;
        iVar10 = str2fmt(ppcVar12[1]);
      }
      else {
        iVar2 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-outform");
        if (iVar2 == 0) {
          if (param_1 == 1) goto LAB_00461de0;
          ppcVar7 = ppcVar12 + 1;
          param_1 = param_1 + -2;
          ppcVar12 = ppcVar12 + 2;
          iVar11 = str2fmt(*ppcVar7);
          if (param_1 == 0) break;
          goto LAB_00461b60;
        }
        if ((((*pcVar8 == '-') && (pcVar8[1] == 'i')) && (pcVar8[2] == 'n')) && (pcVar8[3] == '\0'))
        {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_00461de0;
          local_50 = ppcVar12[1];
          ppcVar7 = ppcVar12 + 1;
        }
        else {
          iVar2 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,&DAT_00632514);
          if (iVar2 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00461de0;
            local_48 = ppcVar12[1];
            ppcVar7 = ppcVar12 + 1;
          }
          else {
            iVar2 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-text");
            ppcVar7 = ppcVar12;
            if (iVar2 == 0) {
              local_4c = local_4c + 1;
              local_40 = local_4c;
            }
            else {
              iVar2 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-cert");
              if (iVar2 == 0) {
                local_4c = local_4c + 1;
                local_38 = local_4c;
              }
              else {
                iVar2 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-noout");
                if (iVar2 == 0) {
                  local_4c = local_4c + 1;
                  local_2c = local_4c;
                }
                else {
                  iVar2 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-context");
                  if (iVar2 != 0) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar1,"unknown option %s\n",pcVar8);
LAB_00461de0:
                    if (sess_id_usage._0_4_ == 0) {
                      return 1;
                    }
                    puVar9 = sess_id_usage;
                    do {
                      puVar9 = (undefined1 *)((int)puVar9 + 4);
                      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"%s");
                    } while (*(int *)puVar9 != 0);
                    return 1;
                  }
                  param_1 = param_1 + -1;
                  if (param_1 == 0) goto LAB_00461de0;
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
    (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
    uVar3 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar2 = (*(code *)PTR_BIO_new_006a6ea4)(uVar3);
    if (iVar2 == 0) {
LAB_004621f4:
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar1);
      return 1;
    }
    if (local_50 == (char *)0x0) goto LAB_0046207c;
    iVar4 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar2,0x6c,3,local_50);
    if (iVar4 < 1) {
      (*(code *)PTR_perror_006a9a80)(local_50);
      goto LAB_004620b8;
    }
  }
  if (iVar10 == 1) {
    iVar10 = (*(code *)PTR_ASN1_d2i_bio_006a71c4)
                       (PTR_SSL_SESSION_new_006a7c84,PTR_d2i_SSL_SESSION_006a7c80,iVar2,0);
  }
  else {
    if (iVar10 != 3) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"bad input format specified for input crl\n");
      goto LAB_004620b8;
    }
    iVar10 = (*(code *)PTR_PEM_read_bio_SSL_SESSION_006a79ac)(iVar2,0,0,0);
  }
  if (iVar10 == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"unable to load SSL_SESSION\n");
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar1);
LAB_004620b8:
    (*(code *)PTR_BIO_free_006a6e70)(iVar2);
    return 1;
  }
  (*(code *)PTR_BIO_free_006a6e70)(iVar2);
  iVar2 = (*(code *)PTR_SSL_SESSION_get0_peer_006a7c78)(iVar10);
  if (local_34 != (char *)0x0) {
    uVar5 = (*(code *)PTR_strlen_006a9a24)(local_34);
    if (uVar5 < 0x21) {
      (*(code *)PTR_SSL_SESSION_set1_id_context_006a7c7c)(iVar10,local_34,uVar5);
      goto LAB_00461f30;
    }
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"Context too long\n");
LAB_00461cb0:
    uVar3 = 1;
    goto LAB_00461cb4;
  }
LAB_00461f30:
  if ((local_2c != 0) && (local_40 == 0)) {
    uVar3 = 0;
    goto LAB_00461cb4;
  }
  uVar3 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar4 = (*(code *)PTR_BIO_new_006a6ea4)(uVar3);
  if (iVar4 == 0) {
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar1);
    goto LAB_00461cb0;
  }
  if (local_48 == (char *)0x0) {
    (*(code *)PTR_BIO_ctrl_006a6e18)(iVar4,0x6a,0,*(undefined4 *)PTR_stdout_006a99c8);
LAB_00461f9c:
    if (local_40 == 0) {
      if (local_2c != 0) goto LAB_00462108;
      if (local_38 == 0) goto LAB_00462124;
      if (iVar2 != 0) goto LAB_00461fe4;
      uVar3 = 0;
    }
    else {
      (*(code *)PTR_SSL_SESSION_print_006a7870)(iVar4,iVar10);
      if (local_38 == 0) {
        if (local_2c == 0) {
LAB_00462124:
          if (iVar11 == 1) {
            iVar2 = (*(code *)PTR_ASN1_i2d_bio_006a7198)(PTR_i2d_SSL_SESSION_006a7c88,iVar4,iVar10);
          }
          else {
            if (iVar11 != 3) {
LAB_00461ffc:
              uVar3 = 1;
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar1,"bad output format specified for outfile\n");
              goto LAB_00462014;
            }
            iVar2 = (*(code *)PTR_PEM_write_bio_SSL_SESSION_006a77b0)(iVar4,iVar10);
          }
          if (iVar2 != 0) goto LAB_00462108;
          uVar3 = 1;
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"unable to write SSL_SESSION\n");
        }
        else {
          uVar3 = 0;
        }
      }
      else {
        if (iVar2 == 0) {
          (*(code *)PTR_BIO_puts_006a6f58)(iVar4,"No certificate present\n");
        }
        else {
          (*(code *)PTR_X509_print_006a70c0)(iVar4,iVar2);
          if (local_2c == 0) {
LAB_00461fe4:
            if (iVar11 == 1) {
              iVar2 = (*(code *)PTR_i2d_X509_bio_006a6f1c)(iVar4,iVar2);
            }
            else {
              if (iVar11 != 3) goto LAB_00461ffc;
              iVar2 = (*(code *)PTR_PEM_write_bio_X509_006a6f20)(iVar4,iVar2);
            }
            if (iVar2 == 0) {
              uVar3 = 1;
              (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"unable to write X509\n");
              goto LAB_00462014;
            }
          }
        }
LAB_00462108:
        uVar3 = 0;
      }
    }
  }
  else {
    iVar6 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar4,0x6c,5,local_48);
    if (0 < iVar6) goto LAB_00461f9c;
    uVar3 = 1;
    (*(code *)PTR_perror_006a9a80)(local_48);
  }
LAB_00462014:
  (*(code *)PTR_BIO_free_all_006a6e74)(iVar4);
LAB_00461cb4:
  (*(code *)PTR_SSL_SESSION_free_006a79b4)(iVar10);
  return uVar3;
}

