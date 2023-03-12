
undefined4 ******
create_digest(int param_1,undefined4 ******param_2,undefined *param_3,char **param_4)

{
  undefined *puVar1;
  char *pcVar2;
  int iVar3;
  undefined4 ******ppppppuVar4;
  int iVar5;
  int iVar6;
  undefined4 ******ppppppuVar7;
  char *pcVar8;
  undefined4 ******ppppppuVar9;
  undefined4 ******unaff_s3;
  undefined auStack_14ac [1024];
  int iStack_10ac;
  undefined4 ******ppppppuStack_10a4;
  int iStack_10a0;
  undefined *puStack_109c;
  undefined4 ******ppppppuStack_1098;
  code *pcStack_1094;
  undefined *puStack_1080;
  int iStack_1078;
  int iStack_1074;
  undefined *puStack_106c;
  int iStack_1068;
  undefined4 ******ppppppuStack_1064;
  undefined4 ******ppppppuStack_1060;
  code *pcStack_105c;
  undefined *local_1048;
  undefined4 ******local_103c [6];
  undefined auStack_1024 [4096];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1048 = &_gp;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar8 = (char *)param_2;
  ppppppuStack_1098 = (undefined4 ******)(*(code *)PTR_EVP_MD_size_006a8f2c)(param_3);
  if ((int)ppppppuStack_1098 < 0) {
LAB_00474824:
    ppppppuStack_1098 = unaff_s3;
    ppppppuVar4 = (undefined4 ******)0x0;
  }
  else {
    ppppppuVar4 = ppppppuStack_1098;
    if (param_1 == 0) {
      pcVar8 = (char *)local_103c;
      pcVar2 = (char *)(**(code **)(local_1048 + -0x7a54))(param_2,pcVar8);
      *param_4 = pcVar2;
      if ((pcVar2 == (char *)0x0) || (ppppppuStack_1098 != local_103c[0])) {
        (**(code **)(local_1048 + -0x7f58))(pcVar2);
        *param_4 = (char *)0x0;
        pcVar8 = "bad digest, %d bytes must be specified\n";
        (**(code **)(local_1048 + -0x7fa8))
                  (**(undefined4 **)(local_1048 + -0x7fa4),
                   "bad digest, %d bytes must be specified\n",ppppppuStack_1098);
        ppppppuVar4 = (undefined4 ******)0x0;
      }
    }
    else {
      pcVar8 = &DAT_006459ec;
      pcVar2 = (char *)(**(code **)(local_1048 + -0x7dd8))(ppppppuStack_1098,&DAT_006459ec,0x265);
      *param_4 = pcVar2;
      unaff_s3 = ppppppuStack_1098;
      if (pcVar2 == (char *)0x0) goto LAB_00474824;
      param_2 = local_103c;
      (**(code **)(local_1048 + -0x6fb0))(param_2,param_3);
      param_3 = auStack_1024;
      while (iVar3 = (**(code **)(local_1048 + -0x7924))(param_1,param_3,0x1000), 0 < iVar3) {
        (**(code **)(local_1048 + -0x786c))(param_2,param_3,iVar3);
      }
      pcVar8 = *param_4;
      (**(code **)(local_1048 + -0x6fac))(param_2,pcVar8,0);
    }
  }
  if (local_24 == *(int *)puVar1) {
    return ppppppuVar4;
  }
  pcStack_105c = load_config_file;
  iStack_10a0 = local_24;
  (**(code **)(local_1048 + -0x5328))();
  puStack_109c = PTR___stack_chk_guard_006aabf0;
  iStack_1078 = -1;
  puStack_1080 = &_gp;
  iStack_1074 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_106c = param_3;
  iStack_1068 = param_1;
  ppppppuStack_1064 = param_2;
  ppppppuStack_1060 = ppppppuStack_1098;
  if (((iStack_10a0 == 0) &&
      (iStack_10a0 = (*(code *)PTR_getenv_006aab6c)("OPENSSL_CONF"), iStack_10a0 == 0)) &&
     (iStack_10a0 = (**(code **)(puStack_1080 + -0x5374))("SSLEAY_CONF"), iStack_10a0 == 0)) {
    ppppppuStack_10a4 = (undefined4 ******)0x0;
    goto LAB_004749c8;
  }
  ppppppuStack_10a4 = (undefined4 ******)(**(code **)(puStack_1080 + -0x7f88))(0);
  if ((ppppppuStack_10a4 == (undefined4 ******)0x0) ||
     (iVar3 = (**(code **)(puStack_1080 + -0x7f84))(ppppppuStack_10a4,iStack_10a0,&iStack_1078),
     iVar3 < 1)) {
    ppppppuStack_1098 = *(undefined4 *******)(puStack_1080 + -0x7fa4);
    if (iStack_1078 < 1) {
      pcVar8 = "error loading the config file \'%s\'\n";
      (**(code **)(puStack_1080 + -0x7fa8))
                (*ppppppuStack_1098,"error loading the config file \'%s\'\n",iStack_10a0);
      if (ppppppuStack_10a4 != (undefined4 ******)0x0) goto LAB_00474920;
      ppppppuStack_10a4 = (undefined4 ******)0x0;
    }
    else {
      pcVar8 = "error on line %ld of config file \'%s\'\n";
      (**(code **)(puStack_1080 + -0x7fa8))
                (*ppppppuStack_1098,"error on line %ld of config file \'%s\'\n",iStack_1078,
                 iStack_10a0);
      if (ppppppuStack_10a4 != (undefined4 ******)0x0) goto LAB_00474920;
      ppppppuStack_10a4 = (undefined4 ******)0x0;
    }
  }
  else {
    ppppppuStack_1098 = *(undefined4 *******)(puStack_1080 + -0x7fa4);
LAB_00474920:
    (**(code **)(puStack_1080 + -0x7fa8))
              (*ppppppuStack_1098,"Using configuration from %s\n",iStack_10a0);
    iVar3 = (**(code **)(puStack_1080 + -0x7f38))(ppppppuStack_10a4,0,"oid_file");
    if (iVar3 == 0) {
      (**(code **)(puStack_1080 + -0x7f00))();
    }
    else {
      iStack_10a0 = (**(code **)(puStack_1080 + -0x7f34))(iVar3,"r");
      if (iStack_10a0 == 0) {
        (**(code **)(puStack_1080 + -0x7fa0))(**(undefined4 **)(puStack_1080 + -0x7fa4));
      }
      else {
        (**(code **)(puStack_1080 + -0x7f30))(iStack_10a0);
        (**(code **)(puStack_1080 + -0x7f6c))(iStack_10a0);
      }
    }
    pcVar8 = (char *)ppppppuStack_10a4;
    iVar3 = add_oid_section(*ppppppuStack_1098,ppppppuStack_10a4);
    if (iVar3 == 0) {
      (**(code **)(puStack_1080 + -0x7fa0))(**(undefined4 **)(puStack_1080 + -0x7fa4));
    }
  }
LAB_004749c8:
  if (iStack_1074 == *(int *)puStack_109c) {
    return ppppppuStack_10a4;
  }
  pcStack_1094 = next_serial;
  iVar3 = iStack_1074;
  (**(code **)(puStack_1080 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_10ac = *(int *)PTR___stack_chk_guard_006aabf0;
  ppppppuVar4 = (undefined4 ******)(*(code *)PTR_ASN1_INTEGER_new_006a8260)();
  if (ppppppuVar4 == (undefined4 ******)0x0) {
    iVar6 = 0;
    iVar5 = 0;
  }
  else {
    iVar5 = (*(code *)PTR_BIO_new_file_006a7fac)(iVar3,"r");
    if (iVar5 == 0) {
      (*(code *)PTR_ERR_clear_error_006a7fe0)();
      iVar6 = 0;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,
                 "Warning: could not open file %s for reading, using serial number: 1\n",iVar3);
      pcVar8 = (char *)0x1;
      ppppppuVar7 = (undefined4 ******)(*(code *)PTR_ASN1_INTEGER_set_006a8264)(ppppppuVar4,1);
joined_r0x00474c94:
      ppppppuVar9 = ppppppuVar4;
      if (ppppppuVar7 != (undefined4 ******)0x0) goto LAB_00474b8c;
    }
    else {
      iVar6 = (*(code *)PTR_a2i_ASN1_INTEGER_006a8cd4)(iVar5,ppppppuVar4,auStack_14ac,0x400);
      if (iVar6 == 0) {
        pcVar8 = "unable to load number from %s\n";
        iVar6 = 0;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)PTR_bio_err_006a7f3c,"unable to load number from %s\n",iVar3);
      }
      else {
        pcVar8 = (char *)0x0;
        iVar6 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)(ppppppuVar4,0);
        if (iVar6 != 0) {
          (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(ppppppuVar4);
          pcVar8 = (char *)0x1;
          iVar3 = (*(code *)PTR_BN_add_word_006a81bc)(iVar6,1);
          if (iVar3 != 0) {
            pcVar8 = (char *)0x0;
            ppppppuVar4 = (undefined4 ******)(*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)(iVar6,0);
            ppppppuVar7 = ppppppuVar4;
            goto joined_r0x00474c94;
          }
          ppppppuVar4 = (undefined4 ******)0x0;
        }
      }
    }
  }
  ppppppuVar9 = (undefined4 ******)0x0;
  (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(ppppppuVar4);
LAB_00474b8c:
  (*(code *)PTR_BIO_free_all_006a7f74)(iVar5);
  (*(code *)PTR_BN_free_006a811c)(iVar6);
  if (iStack_10ac == *(int *)puVar1) {
    return ppppppuVar9;
  }
  iVar3 = iStack_10ac;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  ppppppuVar4 = (undefined4 ******)next_serial(pcVar8);
  if (ppppppuVar4 == (undefined4 ******)0x0) {
    (*(code *)PTR_TS_RESP_CTX_set_status_info_006a8f38)
              (iVar3,2,"Error during serial number generation.");
    (*(code *)PTR_TS_RESP_CTX_add_failure_info_006a8f3c)(iVar3,0x11);
    return (undefined4 ******)0x0;
  }
  iVar3 = (*(code *)PTR_BIO_new_file_006a7fac)(pcVar8,"w");
  if (((iVar3 == 0) ||
      (iVar6 = (*(code *)PTR_i2a_ASN1_INTEGER_006a86e4)(iVar3,ppppppuVar4), iVar6 < 1)) ||
     (iVar6 = (*(code *)PTR_BIO_puts_006a8058)(iVar3,"\n"), iVar6 < 1)) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,"could not save serial number to %s\n",pcVar8);
  }
  (*(code *)PTR_BIO_free_all_006a7f74)(iVar3);
  return ppppppuVar4;
}

