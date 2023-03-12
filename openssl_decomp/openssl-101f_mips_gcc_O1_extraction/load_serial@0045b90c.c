
char * load_serial(char **param_1,char *param_2,char **param_3,char **param_4)

{
  code *pcVar1;
  undefined *puVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  char *unaff_s0;
  int unaff_s1;
  undefined *unaff_s6;
  undefined auStack_aac [256];
  undefined auStack_9ac [1024];
  int iStack_5ac;
  char *pcStack_5a8;
  undefined *puStack_5a4;
  char *pcStack_5a0;
  char **ppcStack_59c;
  char **ppcStack_598;
  char *pcStack_594;
  undefined *puStack_590;
  code *pcStack_58c;
  char *pcStack_578;
  undefined *puStack_570;
  undefined auStack_564 [256];
  char *pcStack_464;
  char *pcStack_460;
  int iStack_45c;
  char *pcStack_458;
  undefined *puStack_454;
  char **ppcStack_450;
  char *pcStack_44c;
  char *apcStack_424 [256];
  char *local_24;
  
  puStack_454 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(char **)PTR___stack_chk_guard_006aabf0;
  pcVar10 = param_2;
  ppcStack_598 = param_3;
  pcVar3 = (char *)(*(code *)PTR_ASN1_INTEGER_new_006a8260)();
  if (pcVar3 == (char *)0x0) {
    pcStack_458 = (char *)0x0;
  }
  else {
    uVar4 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    unaff_s1 = (*(code *)PTR_BIO_new_006a7fa4)(uVar4);
    unaff_s0 = pcVar3;
    if (unaff_s1 == 0) {
      pcStack_458 = (char *)0x0;
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
    }
    else {
      ppcStack_598 = (char **)0x3;
      pcVar10 = (char *)0x6c;
      param_4 = param_1;
      iVar5 = (*(code *)PTR_BIO_ctrl_006a7f18)(unaff_s1);
      if (iVar5 < 1) {
        if (param_2 == (char *)0x0) {
          pcStack_458 = (char *)0x0;
          (*(code *)PTR_perror_006aab88)(param_1);
        }
        else {
          pcStack_458 = (char *)(*(code *)PTR_BN_new_006a82b4)();
          if (pcStack_458 != (char *)0x0) {
            param_4 = (char **)0x0;
            ppcStack_598 = (char **)0x0;
            iVar5 = (*(code *)PTR_BN_pseudo_rand_006a8cd8)(pcStack_458,0x40);
            if ((iVar5 == 0) ||
               (pcVar10 = pcVar3, iVar5 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)(pcStack_458),
               pcVar1 = (code *)PTR_BIO_free_006a7f70, iVar5 == 0)) {
              pcVar10 = "Out of memory\n";
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
              pcVar1 = (code *)PTR_BIO_free_006a7f70;
            }
            goto joined_r0x0045ba8c;
          }
          pcVar10 = "Out of memory\n";
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
        }
      }
      else {
        param_4 = (char **)&DAT_00000400;
        ppcStack_598 = apcStack_424;
        iVar5 = (*(code *)PTR_a2i_ASN1_INTEGER_006a8cd4)(unaff_s1,pcVar3);
        if (iVar5 == 0) {
          pcVar10 = "unable to load number from %s\n";
          pcStack_458 = (char *)0x0;
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
          ppcStack_598 = param_1;
        }
        else {
          pcVar10 = (char *)0x0;
          pcStack_458 = (char *)(*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)(pcVar3);
          pcVar1 = (code *)PTR_BIO_free_006a7f70;
          if (pcStack_458 == (char *)0x0) {
            pcVar10 = "error converting number from bin to BIGNUM\n";
            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
          }
          else {
joined_r0x0045ba8c:
            PTR_BIO_free_006a7f70 = pcVar1;
            if (param_3 != (char **)0x0) {
              *param_3 = pcVar3;
              (*pcVar1)(unaff_s1);
              goto LAB_0045ba04;
            }
          }
        }
      }
      (*(code *)PTR_BIO_free_006a7f70)(unaff_s1);
    }
    (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(pcVar3);
  }
LAB_0045ba04:
  if (local_24 == *(char **)puStack_454) {
    return pcStack_458;
  }
  pcVar3 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_5a4 = PTR___stack_chk_guard_006aabf0;
  puStack_570 = &_gp;
  pcStack_464 = *(char **)PTR___stack_chk_guard_006aabf0;
  pcVar12 = (char *)ppcStack_598;
  pcStack_460 = unaff_s0;
  iStack_45c = unaff_s1;
  ppcStack_450 = param_3;
  pcStack_44c = param_2;
  if (pcVar10 == (char *)0x0) {
    iVar5 = (*(code *)PTR_strlen_006aab30)();
    if (iVar5 < 0x100) {
      pcVar12 = (char *)0x100;
      pcVar11 = pcVar3;
      (**(code **)(puStack_570 + -0x7e7c))(auStack_564);
      goto LAB_0045bc30;
    }
LAB_0045bd3c:
    pcStack_5a0 = (char *)0x0;
    pcVar11 = "file name too long\n";
    (**(code **)(puStack_570 + -0x7fa8))(**(undefined4 **)(puStack_570 + -0x7fa4));
  }
  else {
    unaff_s0 = (char *)(*(code *)PTR_strlen_006aab30)();
    iVar5 = (**(code **)(puStack_570 + -0x53b0))(pcVar10);
    param_2 = pcVar10;
    if (0xff < (int)(unaff_s0 + iVar5 + 1)) goto LAB_0045bd3c;
    pcVar12 = "%s.%s";
    pcVar11 = (char *)0x100;
    pcStack_578 = pcVar10;
    (**(code **)(puStack_570 + -0x7e80))(auStack_564,0x100,"%s.%s",pcVar3);
LAB_0045bc30:
    unaff_s6 = auStack_564;
    uVar4 = (**(code **)(puStack_570 + -0x7f40))();
    unaff_s0 = (char *)(**(code **)(puStack_570 + -0x7f3c))(uVar4);
    if (unaff_s0 == (char *)0x0) {
      pcStack_5a0 = (char *)0x0;
      (**(code **)(puStack_570 + -0x7fa0))(**(undefined4 **)(puStack_570 + -0x7fa4));
    }
    else {
      pcVar12 = &DAT_00000005;
      pcVar11 = (char *)0x6c;
      iVar5 = (**(code **)(puStack_570 + -0x7fc8))(unaff_s0,0x6c,5,unaff_s6);
      if (iVar5 < 1) {
        pcStack_5a0 = (char *)0x0;
        (**(code **)(puStack_570 + -0x5358))(pcVar3);
      }
      else {
        pcVar10 = (char *)(**(code **)(puStack_570 + -0x7cec))(ppcStack_598,0);
        if (pcVar10 == (char *)0x0) {
          pcVar11 = "error converting serial to ASN.1 format\n";
          (**(code **)(puStack_570 + -0x7fa8))(**(undefined4 **)(puStack_570 + -0x7fa4));
          pcStack_5a0 = pcVar10;
        }
        else {
          (**(code **)(puStack_570 + -0x77fc))(unaff_s0,pcVar10);
          pcVar11 = "\n";
          (**(code **)(puStack_570 + -0x7e88))(unaff_s0);
          if (param_4 == (char **)0x0) {
            (**(code **)(puStack_570 + -0x7f6c))(unaff_s0);
            pcStack_5a0 = (char *)0x1;
            (**(code **)(puStack_570 + -0x7f4c))(pcVar10);
            goto LAB_0045bcdc;
          }
          *param_4 = pcVar10;
          pcStack_5a0 = (char *)0x1;
        }
      }
      (**(code **)(puStack_570 + -0x7f6c))(unaff_s0);
    }
  }
LAB_0045bcdc:
  if (pcStack_464 == *(char **)puStack_5a4) {
    return pcStack_5a0;
  }
  pcStack_58c = rotate_serial;
  pcVar10 = pcStack_464;
  (**(code **)(puStack_570 + -0x5328))();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iStack_5ac = *(int *)PTR___stack_chk_guard_006aabf0;
  pcStack_5a8 = unaff_s0;
  ppcStack_59c = param_4;
  pcStack_594 = param_2;
  puStack_590 = unaff_s6;
  iVar6 = (*(code *)PTR_strlen_006aab30)();
  iVar7 = (*(code *)PTR_strlen_006aab30)(pcVar12);
  iVar8 = (*(code *)PTR_strlen_006aab30)(pcVar11);
  iVar5 = iVar6 + iVar8;
  if (iVar6 + iVar8 <= iVar6 + iVar7) {
    iVar5 = iVar6 + iVar7;
  }
  if (iVar5 < 0xff) {
    (*(code *)PTR_BIO_snprintf_006a8060)(auStack_aac,0x100,"%s.%s",pcVar10,pcVar11);
    (*(code *)PTR_BIO_snprintf_006a8060)(auStack_9ac,0x100,"%s.%s",pcVar10,pcVar12);
    iVar5 = (*(code *)PTR_rename_006aab3c)(pcVar10,auStack_9ac);
    if (iVar5 < 0) {
      piVar9 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
      if ((*piVar9 != 2) && (*piVar9 != 0x14)) {
        pcVar3 = "unable to rename %s to %s\n";
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)PTR_bio_err_006a7f3c,"unable to rename %s to %s\n",pcVar10,
                   auStack_9ac);
        (*(code *)PTR_perror_006aab88)("reason");
        pcVar12 = (char *)0x0;
        goto LAB_0045bf08;
      }
    }
    pcVar3 = pcVar10;
    iVar5 = (*(code *)PTR_rename_006aab3c)(auStack_aac);
    if (iVar5 < 0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"unable to rename %s to %s\n",auStack_aac,
                 pcVar10);
      (*(code *)PTR_perror_006aab88)("reason");
      (*(code *)PTR_rename_006aab3c)(auStack_9ac);
      pcVar12 = (char *)0x0;
      pcVar3 = pcVar10;
    }
    else {
      pcVar12 = (char *)0x1;
    }
  }
  else {
    pcVar3 = "file name too long\n";
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
    pcVar12 = (char *)0x0;
  }
LAB_0045bf08:
  if (iStack_5ac == *(int *)puVar2) {
    return pcVar12;
  }
  iVar5 = iStack_5ac;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (iVar5 == 0) {
    iVar6 = (*(code *)PTR_BN_new_006a82b4)();
    if (iVar6 == 0) {
      return (char *)0x0;
    }
    iVar7 = (*(code *)PTR_BN_pseudo_rand_006a8cd8)(iVar6,0x40,0,0);
    if (iVar7 == 0) {
      pcVar10 = (char *)0x0;
      goto LAB_0045c098;
    }
    if (pcVar3 == (char *)0x0) {
      pcVar10 = (char *)0x1;
      goto LAB_0045c098;
    }
  }
  else {
    iVar6 = (*(code *)PTR_BN_pseudo_rand_006a8cd8)();
    if (iVar6 == 0) {
      return (char *)0x0;
    }
    iVar6 = iVar5;
    if (pcVar3 == (char *)0x0) {
      return (char *)0x1;
    }
  }
  iVar7 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)(iVar6,pcVar3);
  pcVar10 = (char *)(uint)(iVar7 != 0);
  if (iVar5 != 0) {
    return pcVar10;
  }
LAB_0045c098:
  (*(code *)PTR_BN_free_006a811c)(iVar6);
  return pcVar10;
}

