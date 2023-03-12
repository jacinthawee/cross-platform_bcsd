
int verify_main(int param_1,char **param_2)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  char **ppcVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  char *pcVar14;
  int iVar15;
  undefined4 uVar16;
  int local_res0 [4];
  char *local_5c;
  char *local_54;
  char *local_4c;
  char *local_48;
  char *local_44;
  char **local_3c [2];
  int local_34;
  int local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_34 = 0;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_res0[0] = param_1;
  local_3c[0] = param_2;
  iVar4 = (*(code *)PTR_X509_STORE_new_006a8364)();
  puVar2 = PTR_bio_err_006a7f3c;
  if (iVar4 != 0) {
    (*(code *)PTR_X509_STORE_set_verify_cb_006a83f8)(iVar4,cb);
    (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
    (*(code *)PTR_signal_006aabe0)(0xd,1);
    iVar10 = *(int *)puVar2;
    if (iVar10 == 0) {
      uVar5 = (*(code *)PTR_BIO_s_file_006a7fa0)();
      iVar10 = (*(code *)PTR_BIO_new_006a7fa4)(uVar5);
      *(int *)puVar2 = iVar10;
      if (iVar10 != 0) {
        (*(code *)PTR_BIO_ctrl_006a7f18)(iVar10,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
        iVar10 = *(int *)puVar2;
      }
    }
    iVar10 = (*(code *)PTR_load_config_006a7f64)(iVar10,0);
    if (iVar10 != 0) {
      pcVar13 = (char *)0x0;
      local_48 = (char *)0x0;
      local_3c[0] = local_3c[0] + 1;
      local_44 = (char *)0x0;
      local_res0[0] = local_res0[0] + -1;
      local_4c = (char *)0x0;
      local_54 = (char *)0x0;
      local_5c = (char *)0x0;
LAB_0042298c:
      while (ppcVar8 = local_3c[0], iVar10 = local_res0[0], 0 < local_res0[0]) {
        pcVar14 = *local_3c[0];
        iVar12 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-CApath");
        if (iVar12 == 0) {
          pcVar13 = ppcVar8[1];
          ppcVar8 = ppcVar8 + 1;
          iVar10 = iVar10 + -1;
        }
        else {
          iVar12 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-CAfile");
          if (iVar12 == 0) {
            local_5c = ppcVar8[1];
            ppcVar8 = ppcVar8 + 1;
            iVar10 = iVar10 + -1;
            goto LAB_004229bc;
          }
          iVar10 = (*(code *)PTR_args_verify_006a8490)
                             (local_3c,local_res0,&local_34,*(undefined4 *)puVar2,&local_30);
          ppcVar8 = local_3c[0];
          if (iVar10 != 0) goto code_r0x00422a24;
          pcVar14 = *local_3c[0];
          iVar10 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-untrusted");
          if (iVar10 == 0) {
            iVar10 = local_res0[0] + -1;
            bVar1 = local_res0[0] < 1;
            local_res0[0] = iVar10;
            if (bVar1) goto LAB_0042276c;
            local_54 = ppcVar8[1];
            ppcVar8 = ppcVar8 + 1;
          }
          else {
            iVar10 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-trusted");
            if (iVar10 == 0) {
              iVar10 = local_res0[0] + -1;
              bVar1 = local_res0[0] < 1;
              local_res0[0] = iVar10;
              if (bVar1) goto LAB_0042276c;
              local_4c = ppcVar8[1];
              ppcVar8 = ppcVar8 + 1;
            }
            else {
              iVar10 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-CRLfile");
              if (iVar10 == 0) {
                iVar10 = local_res0[0] + -1;
                bVar1 = local_res0[0] < 1;
                local_res0[0] = iVar10;
                if (bVar1) goto LAB_0042276c;
                local_44 = ppcVar8[1];
                ppcVar8 = ppcVar8 + 1;
              }
              else {
                iVar10 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-engine");
                if (iVar10 == 0) {
                  local_res0[0] = local_res0[0] + -1;
                  if (0 < local_res0[0]) {
                    local_48 = ppcVar8[1];
                    ppcVar8 = ppcVar8 + 1;
                    iVar10 = local_res0[0];
                    goto LAB_004229bc;
                  }
                  goto LAB_0042276c;
                }
                iVar10 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-help");
                if (iVar10 == 0) goto LAB_0042276c;
                iVar10 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-verbose");
                if (iVar10 != 0) {
                  if (*pcVar14 != '-') break;
                  goto LAB_0042276c;
                }
                v_verbose = 1;
                iVar10 = local_res0[0];
              }
            }
          }
        }
LAB_004229bc:
        local_3c[0] = ppcVar8 + 1;
        local_res0[0] = iVar10 + -1;
      }
      uVar5 = (*(code *)PTR_setup_engine_006a7fc4)(*(undefined4 *)puVar2,local_48,0);
      if (local_30 != 0) {
        (*(code *)PTR_X509_STORE_set1_param_006a83fc)(iVar4);
      }
      uVar6 = (*(code *)PTR_X509_LOOKUP_file_006a8580)();
      iVar10 = (*(code *)PTR_X509_STORE_add_lookup_006a8584)(iVar4,uVar6);
      if (iVar10 == 0) goto LAB_00422f2c;
      if (local_5c != (char *)0x0) {
        iVar10 = (*(code *)PTR_X509_LOOKUP_ctrl_006a8588)(iVar10,1,local_5c,1,0);
        if (iVar10 != 0) goto LAB_00422b68;
        uVar5 = *(undefined4 *)puVar2;
        pcVar14 = "Error loading file %s\n";
LAB_00422db8:
        iVar12 = 0;
        (*(code *)PTR_BIO_printf_006a7f38)(uVar5,pcVar14,local_5c);
        iVar10 = 0;
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
        goto LAB_00422774;
      }
      (*(code *)PTR_X509_LOOKUP_ctrl_006a8588)(iVar10,1,0,3,0);
LAB_00422b68:
      uVar6 = (*(code *)PTR_X509_LOOKUP_hash_dir_006a858c)();
      iVar10 = (*(code *)PTR_X509_STORE_add_lookup_006a8584)(iVar4,uVar6);
      if (iVar10 == 0) goto LAB_00422f2c;
      if (pcVar13 == (char *)0x0) {
        (*(code *)PTR_X509_LOOKUP_ctrl_006a8588)(iVar10,2,0,3,0);
      }
      else {
        iVar10 = (*(code *)PTR_X509_LOOKUP_ctrl_006a8588)(iVar10,2,pcVar13,1,0);
        if (iVar10 == 0) {
          uVar5 = *(undefined4 *)puVar2;
          pcVar14 = "Error loading directory %s\n";
          local_5c = pcVar13;
          goto LAB_00422db8;
        }
      }
      (*(code *)PTR_ERR_clear_error_006a7fe0)();
      if (local_54 == (char *)0x0) {
        iVar10 = 0;
      }
      else {
        iVar10 = (*(code *)PTR_load_certs_006a8358)
                           (*(undefined4 *)puVar2,local_54,3,0,uVar5,"untrusted certificates");
        if (iVar10 == 0) goto LAB_0042276c;
      }
      if (local_4c == (char *)0x0) {
        iVar12 = 0;
      }
      else {
        iVar12 = (*(code *)PTR_load_certs_006a8358)
                           (*(undefined4 *)puVar2,local_4c,3,0,uVar5,"trusted certificates");
        if (iVar12 == 0) goto LAB_00422774;
      }
      if (local_44 == (char *)0x0) {
        iVar11 = 0;
      }
      else {
        iVar11 = (*(code *)PTR_load_crls_006a8590)
                           (*(undefined4 *)puVar2,local_44,3,0,uVar5,"other CRLs");
        if (iVar11 == 0) goto LAB_00422774;
      }
      if (local_res0[0] < 1) {
        iVar7 = check(iVar4,0,iVar10,iVar12,iVar11,uVar5);
        iVar7 = -(uint)(iVar7 != 1);
      }
      else {
        iVar7 = 0;
        iVar15 = 0;
        do {
          ppcVar8 = local_3c[0] + iVar15;
          iVar15 = iVar15 + 1;
          iVar9 = check(iVar4,*ppcVar8,iVar10,iVar12,iVar11,uVar5);
          if (iVar9 != 1) {
            iVar7 = -1;
          }
        } while (iVar15 < local_res0[0]);
      }
      if (local_30 != 0) goto LAB_00422880;
      goto LAB_00422898;
    }
  }
LAB_0042276c:
  iVar12 = 0;
  iVar10 = 0;
LAB_00422774:
  (*(code *)PTR_BIO_printf_006a7f38)
            (*(undefined4 *)puVar2,
             "usage: verify [-verbose] [-CApath path] [-CAfile file] [-purpose purpose] [-crl_check]"
            );
  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2," [-attime timestamp]");
  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2," [-engine e]");
  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2," cert1 cert2 ...\n");
  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"recognized usages:\n");
  for (iVar11 = 0; iVar7 = (*(code *)PTR_X509_PURPOSE_get_count_006a857c)(), iVar11 < iVar7;
      iVar11 = iVar11 + 1) {
    uVar5 = (*(code *)PTR_X509_PURPOSE_get0_006a8570)(iVar11);
    uVar16 = *(undefined4 *)puVar2;
    uVar6 = (*(code *)PTR_X509_PURPOSE_get0_sname_006a8574)(uVar5);
    uVar5 = (*(code *)PTR_X509_PURPOSE_get0_name_006a8578)(uVar5);
    (*(code *)PTR_BIO_printf_006a7f38)(uVar16,"\t%-10s\t%s\n",uVar6,uVar5);
  }
  iVar7 = 1;
  if (local_30 == 0) {
    if (iVar4 == 0) {
      iVar7 = 1;
      (*(code *)PTR_sk_pop_free_006a8158)(iVar10,PTR_X509_free_006a7f90);
      (*(code *)PTR_sk_pop_free_006a8158)(iVar12,PTR_X509_free_006a7f90);
      (*(code *)PTR_sk_pop_free_006a8158)(0,PTR_X509_CRL_free_006a8160);
      goto LAB_004228ec;
    }
    iVar7 = 1;
    iVar11 = 0;
LAB_00422898:
    (*(code *)PTR_X509_STORE_free_006a8384)(iVar4);
  }
  else {
    iVar11 = 0;
LAB_00422880:
    (*(code *)PTR_X509_VERIFY_PARAM_free_006a83cc)();
    if (iVar4 != 0) goto LAB_00422898;
  }
  (*(code *)PTR_sk_pop_free_006a8158)(iVar10,PTR_X509_free_006a7f90);
  (*(code *)PTR_sk_pop_free_006a8158)(iVar12,PTR_X509_free_006a7f90);
  (*(code *)PTR_sk_pop_free_006a8158)(iVar11,PTR_X509_CRL_free_006a8160);
  if (iVar7 == -1) {
    iVar7 = 2;
  }
LAB_004228ec:
  if (local_2c == *(int *)puVar3) {
    return iVar7;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00422f2c:
  iVar4 = (*(code *)PTR_abort_006aaa74)();
  return iVar4;
code_r0x00422a24:
  if (local_34 != 0) goto LAB_0042276c;
  goto LAB_0042298c;
}

