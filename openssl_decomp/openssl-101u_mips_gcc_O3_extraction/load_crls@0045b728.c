
int load_crls(undefined4 param_1,char *param_2,int param_3,undefined4 param_4,undefined4 param_5,
             undefined4 param_6)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  char *pcVar10;
  int iVar11;
  int *piVar12;
  int iStack_74;
  undefined4 local_2c;
  char *local_28;
  uint *local_24;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(uint **)PTR___stack_chk_guard_006a9ae8;
  local_2c = param_4;
  local_28 = param_2;
  if (param_3 == 3) {
    if (param_2 == (char *)0x0) {
      iVar5 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdin_006a9a14);
      if (iVar5 != 0) goto LAB_0045b7a0;
      param_2 = "stdin";
LAB_0045b930:
      pcVar10 = "Error opening %s %s\n";
      (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Error opening %s %s\n",param_6,param_2);
    }
    else {
      iVar5 = (*(code *)PTR_BIO_new_file_006a6eac)(param_2,"r");
      if (iVar5 == 0) goto LAB_0045b930;
LAB_0045b7a0:
      pcVar10 = (char *)0x0;
      iVar6 = (*(code *)PTR_PEM_X509_INFO_read_bio_006a75c4)(iVar5,0,password_callback,&local_2c);
      (*(code *)PTR_BIO_free_006a6e70)(iVar5);
      iVar5 = (*(code *)PTR_sk_new_null_006a6fa4)();
      if (iVar5 != 0) {
        iVar11 = 0;
        iVar7 = (*(code *)PTR_sk_num_006a6e2c)(iVar6);
        if (0 < iVar7) {
          do {
            iVar7 = (*(code *)PTR_sk_value_006a6e24)(iVar6,iVar11);
            pcVar10 = *(char **)(iVar7 + 4);
            if (pcVar10 != (char *)0x0) {
              iVar8 = (*(code *)PTR_sk_push_006a6fa8)(iVar5);
              if (iVar8 == 0) goto LAB_0045b8cc;
              *(undefined4 *)(iVar7 + 4) = 0;
            }
            iVar11 = iVar11 + 1;
            iVar7 = (*(code *)PTR_sk_num_006a6e2c)(iVar6);
          } while (iVar11 < iVar7);
        }
        iVar7 = (*(code *)PTR_sk_num_006a6e2c)(iVar5);
        if (0 < iVar7) {
          if (iVar6 != 0) {
            pcVar10 = PTR_X509_INFO_free_006a75c8;
            (*(code *)PTR_sk_pop_free_006a7058)(iVar6);
          }
          goto LAB_0045b89c;
        }
      }
LAB_0045b8cc:
      if (iVar6 != 0) {
        (*(code *)PTR_sk_pop_free_006a7058)(iVar6,PTR_X509_INFO_free_006a75c8);
      }
      (*(code *)PTR_sk_pop_free_006a7058)(iVar5,PTR_X509_CRL_free_006a7060);
      pcVar10 = "unable to load %s\n";
      (*(code *)PTR_BIO_printf_006a6e38)(param_1,"unable to load %s\n",&DAT_0063fb84);
    }
    (*(code *)PTR_ERR_print_errors_006a6e40)(param_1);
  }
  else {
    pcVar10 = "bad input format specified for %s\n";
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"bad input format specified for %s\n",param_6);
  }
  iVar5 = 0;
LAB_0045b89c:
  if (local_24 == *(uint **)puVar2) {
    return iVar5;
  }
  puVar9 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (pcVar10 == (char *)0x0) {
    return 0;
  }
  iVar6 = 0;
  uVar3 = (*(code *)PTR_X509V3_parse_list_006a7b48)(pcVar10);
  iStack_74 = 1;
  iVar5 = (*(code *)PTR_sk_num_006a6e2c)(uVar3);
  if (0 < iVar5) {
    do {
      iVar5 = (*(code *)PTR_sk_value_006a6e24)(uVar3,iVar6);
      pcVar10 = *(char **)(iVar5 + 4);
      piVar12 = (int *)cert_tbl_16879;
      iVar5 = cert_tbl_16879._0_4_;
      if (*pcVar10 == '-') {
        pcVar10 = pcVar10 + 1;
        bVar1 = false;
      }
      else if (*pcVar10 == '+') {
        pcVar10 = pcVar10 + 1;
        bVar1 = true;
      }
      else {
        bVar1 = true;
      }
      while (iVar5 != 0) {
        iVar5 = (*(code *)PTR_strcasecmp_006a9a18)(pcVar10);
        if (iVar5 == 0) {
          uVar4 = ~piVar12[2] & *puVar9;
          *puVar9 = uVar4;
          if (bVar1) {
            *puVar9 = uVar4 | piVar12[1];
          }
          else {
            *puVar9 = ~piVar12[1] & uVar4;
          }
          goto LAB_00459948;
        }
        piVar12 = piVar12 + 3;
        iVar5 = *piVar12;
      }
      iStack_74 = 0;
LAB_00459948:
      iVar6 = iVar6 + 1;
      iVar5 = (*(code *)PTR_sk_num_006a6e2c)(uVar3);
    } while (iVar6 < iVar5);
  }
  (*(code *)PTR_sk_pop_free_006a7058)(uVar3,PTR_X509V3_conf_free_006a7b4c);
  return iStack_74;
}

