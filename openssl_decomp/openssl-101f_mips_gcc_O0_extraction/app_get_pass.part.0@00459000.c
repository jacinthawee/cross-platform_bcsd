
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 app_get_pass_part_0(undefined4 param_1,undefined *param_2,int param_3,code *param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined *puVar7;
  uint uVar8;
  undefined1 *unaff_s1;
  uint uVar9;
  int unaff_s5;
  char acStack_86c [1024];
  char *pcStack_46c;
  undefined *puStack_468;
  undefined1 *puStack_464;
  undefined *puStack_460;
  int iStack_45c;
  undefined4 uStack_458;
  int iStack_454;
  undefined4 uStack_42c;
  undefined4 uStack_428;
  undefined auStack_424 [1024];
  int local_24;
  
  puStack_460 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((param_3 == 0) || (unaff_s1 = &_ITM_registerTMCloneTable, pwdbio_16681 == 0)) {
    iVar5 = (*(code *)PTR_strncmp_006aaa7c)(param_2,"file:",5);
    if (iVar5 == 0) {
      param_2 = param_2 + 5;
      unaff_s1 = &_ITM_registerTMCloneTable;
      pwdbio_16681 = (*(code *)PTR_BIO_new_file_006a7fac)(param_2,"r");
      if (pwdbio_16681 != 0) goto LAB_0045905c;
      pcVar6 = "Can\'t open file %s\n";
      puVar7 = param_2;
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Can\'t open file %s\n",param_2);
      uVar2 = 0;
    }
    else {
      puVar7 = (undefined *)0x3;
      iVar5 = (*(code *)PTR_strncmp_006aaa7c)(param_2,&DAT_0063fe40,3);
      if (iVar5 == 0) {
        param_2 = param_2 + 3;
        iVar5 = (*(code *)PTR_strtol_006aaa68)(param_2,0,10);
        if (-1 < iVar5) {
          unaff_s1 = &_ITM_registerTMCloneTable;
          pwdbio_16681 = (*(code *)PTR_BIO_new_fd_006a8c3c)(iVar5,0);
          if (pwdbio_16681 != 0) {
            uVar2 = (*(code *)PTR_BIO_f_buffer_006a8940)();
            uVar2 = (*(code *)PTR_BIO_new_006a7fa4)(uVar2);
            pwdbio_16681 = (*(code *)PTR_BIO_push_006a85c0)(uVar2,pwdbio_16681);
            goto LAB_0045905c;
          }
        }
        pcVar6 = "Can\'t access file descriptor %s\n";
        puVar7 = param_2;
        (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Can\'t access file descriptor %s\n",param_2);
        uVar2 = 0;
      }
      else {
        iVar5 = (*(code *)PTR_strcmp_006aac20)(param_2,"stdin");
        if (iVar5 == 0) {
          unaff_s1 = &_ITM_registerTMCloneTable;
          pwdbio_16681 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdin_006aab20,0);
          if (pwdbio_16681 != 0) goto LAB_0045905c;
          pcVar6 = "Can\'t open BIO for stdin\n";
          (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Can\'t open BIO for stdin\n");
          uVar2 = 0;
        }
        else {
          pcVar6 = "Invalid password argument \"%s\"\n";
          puVar7 = param_2;
          (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Invalid password argument \"%s\"\n",param_2);
          uVar2 = 0;
        }
      }
    }
  }
  else {
LAB_0045905c:
    unaff_s1 = &_ITM_registerTMCloneTable;
    param_2 = auStack_424;
    puVar7 = &DAT_00000400;
    unaff_s5 = (*(code *)PTR_BIO_gets_006a85d0)(pwdbio_16681,param_2,0x400);
    if (param_3 != 1) {
      (*(code *)PTR_BIO_free_all_006a7f74)(pwdbio_16681);
      pwdbio_16681 = 0;
    }
    if (unaff_s5 < 1) {
      pcVar6 = "Error reading password from BIO\n";
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Error reading password from BIO\n");
      uVar2 = 0;
    }
    else {
      pcVar6 = (char *)0xa;
      puVar1 = (undefined *)(*(code *)PTR_strchr_006aab34)(param_2,10);
      if (puVar1 != (undefined *)0x0) {
        *puVar1 = 0;
      }
      uVar2 = (*(code *)PTR_BUF_strdup_006a80dc)(param_2);
    }
  }
  if (local_24 == *(int *)puStack_460) {
    return uVar2;
  }
  iVar5 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pcStack_46c = *(char **)PTR___stack_chk_guard_006aabf0;
  puStack_468 = param_2;
  puStack_464 = unaff_s1;
  iStack_45c = param_3;
  uStack_458 = param_1;
  iStack_454 = unaff_s5;
  iVar3 = (*(code *)PTR_d2i_PKCS12_bio_006a838c)(pcVar6,0);
  if (iVar3 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"Error loading PKCS12 file for %s\n",puVar7);
    uVar2 = 0;
    goto LAB_004593b0;
  }
  iVar4 = (*(code *)PTR_PKCS12_verify_mac_006a8390)(iVar3,"",0);
  if ((iVar4 == 0) && (iVar4 = (*(code *)PTR_PKCS12_verify_mac_006a8390)(iVar3,0,0), iVar4 == 0)) {
    if (param_4 == (code *)0x0) {
      param_4 = password_callback;
    }
    pcVar6 = acStack_86c;
    iVar4 = (*param_4)(pcVar6,0x400,0,&_gp);
    if (iVar4 < 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"Passpharse callback error for %s\n",puVar7);
      uVar2 = 0;
    }
    else {
      if (iVar4 < 0x400) {
        acStack_86c[iVar4] = '\0';
      }
      iVar4 = (*(code *)PTR_PKCS12_verify_mac_006a8390)(iVar3,pcVar6,iVar4);
      if (iVar4 != 0) goto LAB_0045937c;
      (*(code *)PTR_BIO_printf_006a7f38)
                (iVar5,"Mac verify error (wrong password?) in PKCS12 file for %s\n",puVar7);
      uVar2 = 0;
    }
  }
  else {
    pcVar6 = "";
LAB_0045937c:
    uVar2 = (*(code *)PTR_PKCS12_parse_006a8c40)(iVar3,pcVar6,uStack_42c,uStack_428,0);
  }
  (*(code *)PTR_PKCS12_free_006a837c)(iVar3);
LAB_004593b0:
  if (pcStack_46c == *(char **)puVar1) {
    return uVar2;
  }
  pcVar6 = pcStack_46c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (pcVar6 != (char *)0x0) {
    uVar9 = (uint)*pcVar6;
    uVar8 = uVar9 & 0xffffffdf;
    if (uVar8 != 0x44) {
      if (uVar8 == 0x54) {
        uVar2 = 2;
      }
      else if (uVar8 == 0x4e) {
        uVar2 = 4;
      }
      else if (uVar8 == 0x53) {
        uVar2 = 6;
      }
      else if (uVar8 == 0x4d) {
        uVar2 = 0xb;
      }
      else if ((uVar9 == 0x31) || (iVar5 = (*(code *)PTR_strcmp_006aac20)(), iVar5 == 0)) {
        uVar2 = 5;
      }
      else {
        iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar6,"pkcs12");
        uVar2 = 5;
        if (((iVar5 != 0) &&
            (((((uVar9 & 0xff) != 0x50 && ((uVar9 & 0xff) != 0x70)) || (pcVar6[1] != '1')) ||
             ((pcVar6[2] != '2' || (uVar2 = 5, pcVar6[3] != '\0')))))) && (uVar2 = 7, uVar8 != 0x45)
           ) {
          if (uVar8 == 0x50) {
            uVar2 = 0xc;
            if ((pcVar6[1] & 0xdfU) != 0x56) {
              uVar2 = 3;
            }
          }
          else {
            uVar2 = 0;
          }
        }
      }
      return uVar2;
    }
    return 1;
  }
  return 0;
}

