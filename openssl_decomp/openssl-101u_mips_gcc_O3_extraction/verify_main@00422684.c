
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
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_34 = 0;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_res0[0] = param_1;
  local_3c[0] = param_2;
  iVar4 = (*(code *)PTR_X509_STORE_new_006a7250)();
  puVar2 = PTR_bio_err_006a6e3c;
  if (iVar4 != 0) {
    (*(code *)PTR_X509_STORE_set_verify_cb_006a72f8)(iVar4,cb);
    (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
    (*(code *)PTR_signal_006a9ad8)(0xd,1);
    iVar10 = *(int *)puVar2;
    if (iVar10 == 0) {
      uVar5 = (*(code *)PTR_BIO_s_file_006a6ea0)();
      iVar10 = (*(code *)PTR_BIO_new_006a6ea4)(uVar5);
      *(int *)puVar2 = iVar10;
      if (iVar10 != 0) {
        (*(code *)PTR_BIO_ctrl_006a6e18)(iVar10,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
        iVar10 = *(int *)puVar2;
      }
    }
    iVar10 = (*(code *)PTR_load_config_006a6e64)(iVar10,0);
    if (iVar10 != 0) {
      pcVar13 = (char *)0x0;
      local_48 = (char *)0x0;
      local_3c[0] = local_3c[0] + 1;
      local_44 = (char *)0x0;
      local_res0[0] = local_res0[0] + -1;
      local_4c = (char *)0x0;
      local_54 = (char *)0x0;
      local_5c = (char *)0x0;
LAB_0042296c:
      while (ppcVar8 = local_3c[0], iVar10 = local_res0[0], 0 < local_res0[0]) {
        pcVar14 = *local_3c[0];
        iVar12 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-CApath");
        if (iVar12 == 0) {
          pcVar13 = ppcVar8[1];
          ppcVar8 = ppcVar8 + 1;
          iVar10 = iVar10 + -1;
        }
        else {
          iVar12 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-CAfile");
          if (iVar12 == 0) {
            local_5c = ppcVar8[1];
            ppcVar8 = ppcVar8 + 1;
            iVar10 = iVar10 + -1;
            goto LAB_0042299c;
          }
          iVar10 = (*(code *)PTR_args_verify_006a7390)
                             (local_3c,local_res0,&local_34,*(undefined4 *)puVar2,&local_30);
          ppcVar8 = local_3c[0];
          if (iVar10 != 0) goto code_r0x00422a04;
          pcVar14 = *local_3c[0];
          iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-untrusted");
          if (iVar10 == 0) {
            iVar10 = local_res0[0] + -1;
            bVar1 = local_res0[0] < 1;
            local_res0[0] = iVar10;
            if (bVar1) goto LAB_0042274c;
            local_54 = ppcVar8[1];
            ppcVar8 = ppcVar8 + 1;
          }
          else {
            iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-trusted");
            if (iVar10 == 0) {
              iVar10 = local_res0[0] + -1;
              bVar1 = local_res0[0] < 1;
              local_res0[0] = iVar10;
              if (bVar1) goto LAB_0042274c;
              local_4c = ppcVar8[1];
              ppcVar8 = ppcVar8 + 1;
            }
            else {
              iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-CRLfile");
              if (iVar10 == 0) {
                iVar10 = local_res0[0] + -1;
                bVar1 = local_res0[0] < 1;
                local_res0[0] = iVar10;
                if (bVar1) goto LAB_0042274c;
                local_44 = ppcVar8[1];
                ppcVar8 = ppcVar8 + 1;
              }
              else {
                iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-engine");
                if (iVar10 == 0) {
                  local_res0[0] = local_res0[0] + -1;
                  if (0 < local_res0[0]) {
                    local_48 = ppcVar8[1];
                    ppcVar8 = ppcVar8 + 1;
                    iVar10 = local_res0[0];
                    goto LAB_0042299c;
                  }
                  goto LAB_0042274c;
                }
                iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-help");
                if (iVar10 == 0) goto LAB_0042274c;
                iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-verbose");
                if (iVar10 != 0) {
                  if (*pcVar14 != '-') break;
                  goto LAB_0042274c;
                }
                v_verbose = 1;
                iVar10 = local_res0[0];
              }
            }
          }
        }
LAB_0042299c:
        local_3c[0] = ppcVar8 + 1;
        local_res0[0] = iVar10 + -1;
      }
      uVar5 = (*(code *)PTR_setup_engine_006a6ec4)(*(undefined4 *)puVar2,local_48,0);
      if (local_30 != 0) {
        (*(code *)PTR_X509_STORE_set1_param_006a72fc)(iVar4);
      }
      uVar6 = (*(code *)PTR_X509_LOOKUP_file_006a7480)();
      iVar10 = (*(code *)PTR_X509_STORE_add_lookup_006a7484)(iVar4,uVar6);
      if (iVar10 == 0) goto LAB_00422f0c;
      if (local_5c != (char *)0x0) {
        iVar10 = (*(code *)PTR_X509_LOOKUP_ctrl_006a7488)(iVar10,1,local_5c,1,0);
        if (iVar10 != 0) goto LAB_00422b48;
        uVar5 = *(undefined4 *)puVar2;
        pcVar14 = "Error loading file %s\n";
LAB_00422d98:
        iVar12 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)(uVar5,pcVar14,local_5c);
        iVar10 = 0;
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
        goto LAB_00422754;
      }
      (*(code *)PTR_X509_LOOKUP_ctrl_006a7488)(iVar10,1,0,3,0);
LAB_00422b48:
      uVar6 = (*(code *)PTR_X509_LOOKUP_hash_dir_006a748c)();
      iVar10 = (*(code *)PTR_X509_STORE_add_lookup_006a7484)(iVar4,uVar6);
      if (iVar10 == 0) goto LAB_00422f0c;
      if (pcVar13 == (char *)0x0) {
        (*(code *)PTR_X509_LOOKUP_ctrl_006a7488)(iVar10,2,0,3,0);
      }
      else {
        iVar10 = (*(code *)PTR_X509_LOOKUP_ctrl_006a7488)(iVar10,2,pcVar13,1,0);
        if (iVar10 == 0) {
          uVar5 = *(undefined4 *)puVar2;
          pcVar14 = "Error loading directory %s\n";
          local_5c = pcVar13;
          goto LAB_00422d98;
        }
      }
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
      if (local_54 == (char *)0x0) {
        iVar10 = 0;
      }
      else {
        iVar10 = (*(code *)PTR_load_certs_006a7244)
                           (*(undefined4 *)puVar2,local_54,3,0,uVar5,"untrusted certificates");
        if (iVar10 == 0) goto LAB_0042274c;
      }
      if (local_4c == (char *)0x0) {
        iVar12 = 0;
      }
      else {
        iVar12 = (*(code *)PTR_load_certs_006a7244)
                           (*(undefined4 *)puVar2,local_4c,3,0,uVar5,"trusted certificates");
        if (iVar12 == 0) goto LAB_00422754;
      }
      if (local_44 == (char *)0x0) {
        iVar11 = 0;
      }
      else {
        iVar11 = (*(code *)PTR_load_crls_006a7490)
                           (*(undefined4 *)puVar2,local_44,3,0,uVar5,"other CRLs");
        if (iVar11 == 0) goto LAB_00422754;
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
      if (local_30 != 0) goto LAB_00422860;
      goto LAB_00422878;
    }
  }
LAB_0042274c:
  iVar12 = 0;
  iVar10 = 0;
LAB_00422754:
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar2,
             "usage: verify [-verbose] [-CApath path] [-CAfile file] [-purpose purpose] [-crl_check]"
            );
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2," [-no_alt_chains] [-attime timestamp]");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2," [-engine e]");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2," cert1 cert2 ...\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"recognized usages:\n");
  for (iVar11 = 0; iVar7 = (*(code *)PTR_X509_PURPOSE_get_count_006a747c)(), iVar11 < iVar7;
      iVar11 = iVar11 + 1) {
    uVar5 = (*(code *)PTR_X509_PURPOSE_get0_006a7470)(iVar11);
    uVar16 = *(undefined4 *)puVar2;
    uVar6 = (*(code *)PTR_X509_PURPOSE_get0_sname_006a7474)(uVar5);
    uVar5 = (*(code *)PTR_X509_PURPOSE_get0_name_006a7478)(uVar5);
    (*(code *)PTR_BIO_printf_006a6e38)(uVar16,"\t%-10s\t%s\n",uVar6,uVar5);
  }
  iVar7 = 1;
  if (local_30 == 0) {
    if (iVar4 == 0) {
      iVar7 = 1;
      (*(code *)PTR_sk_pop_free_006a7058)(iVar10,PTR_X509_free_006a6e90);
      (*(code *)PTR_sk_pop_free_006a7058)(iVar12,PTR_X509_free_006a6e90);
      (*(code *)PTR_sk_pop_free_006a7058)(0,PTR_X509_CRL_free_006a7060);
      goto LAB_004228cc;
    }
    iVar7 = 1;
    iVar11 = 0;
LAB_00422878:
    (*(code *)PTR_X509_STORE_free_006a7274)(iVar4);
  }
  else {
    iVar11 = 0;
LAB_00422860:
    (*(code *)PTR_X509_VERIFY_PARAM_free_006a72cc)();
    if (iVar4 != 0) goto LAB_00422878;
  }
  (*(code *)PTR_sk_pop_free_006a7058)(iVar10,PTR_X509_free_006a6e90);
  (*(code *)PTR_sk_pop_free_006a7058)(iVar12,PTR_X509_free_006a6e90);
  (*(code *)PTR_sk_pop_free_006a7058)(iVar11,PTR_X509_CRL_free_006a7060);
  if (iVar7 == -1) {
    iVar7 = 2;
  }
LAB_004228cc:
  if (local_2c == *(int *)puVar3) {
    return iVar7;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00422f0c:
  iVar4 = (*(code *)PTR_abort_006a9964)();
  return iVar4;
code_r0x00422a04:
  if (local_34 != 0) goto LAB_0042274c;
  goto LAB_0042296c;
}

