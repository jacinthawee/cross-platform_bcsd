
stack_st_X509_NAME * SSL_load_client_CA_file(char *file)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  SSL *ssl;
  int *piVar6;
  uchar *id;
  char *pcVar7;
  stack_st_X509_NAME *psVar8;
  int *unaff_s5;
  code *pcVar9;
  int iStack_4c0;
  char acStack_4bc [1024];
  SSL *pSStack_bc;
  stack_st_X509_NAME *psStack_b8;
  stack_st_X509_NAME *psStack_b4;
  int iStack_b0;
  undefined *puStack_ac;
  undefined4 uStack_a8;
  int *piStack_a4;
  int iStack_70;
  stack_st_X509_NAME *psStack_6c;
  char *pcStack_64;
  stack_st_X509_NAME *psStack_60;
  int iStack_5c;
  int iStack_58;
  undefined *puStack_54;
  int *piStack_50;
  code *pcStack_4c;
  undefined4 local_38;
  undefined *local_30;
  int local_28;
  int local_24;
  
  puStack_54 = PTR___stack_chk_guard_006aabf0;
  local_30 = &_gp;
  local_28 = 0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_58 = (*(code *)PTR_sk_new_006a91b4)(xname_cmp);
  uVar2 = (**(code **)(local_30 + -0x7f40))();
  iStack_5c = (**(code **)(local_30 + -0x7f3c))(uVar2);
  if (iStack_58 == 0) {
    local_38 = 0x2ad;
    piVar6 = (int *)0xb9;
    psStack_b4 = (stack_st_X509_NAME *)0x0;
    (**(code **)(local_30 + -0x6eb0))(0x14,0xb9,0x41,"ssl_cert.c");
    goto LAB_004b087c;
  }
  if (iStack_5c == 0) {
    pcVar9 = *(code **)(local_30 + -0x6eb0);
    local_38 = 0x2ad;
LAB_004b0854:
    piVar6 = (int *)0xb9;
    (*pcVar9)(0x14,0xb9,0x41,"ssl_cert.c");
LAB_004b0868:
    psStack_b4 = (stack_st_X509_NAME *)0x0;
  }
  else {
    piVar6 = (int *)&DAT_0000006c;
    iVar3 = (**(code **)(local_30 + -0x7fc8))(iStack_5c,0x6c,3,file);
    if (iVar3 == 0) goto LAB_004b0868;
    psVar8 = (stack_st_X509_NAME *)0x0;
    unaff_s5 = &local_28;
LAB_004b076c:
    piVar6 = unaff_s5;
    iVar3 = (**(code **)(local_30 + -0x7e14))(iStack_5c,unaff_s5,0,0);
    psStack_b4 = psVar8;
    if (iVar3 != 0) {
      pcVar9 = *(code **)(local_30 + -0x7e3c);
      if (psVar8 == (stack_st_X509_NAME *)0x0) goto LAB_004b0814;
      do {
        pcVar9 = *(code **)(local_30 + -0x7ee0);
        do {
          iVar3 = (*pcVar9)(local_28);
          if ((iVar3 == 0) ||
             (file = (char *)(**(code **)(local_30 + -0x7ca4))(iVar3), file == (char *)0x0)) {
            piVar6 = *(int **)(local_30 + -0x7de8);
            psStack_b4 = (stack_st_X509_NAME *)0x0;
            (**(code **)(local_30 + -0x7d88))(psVar8,piVar6);
            goto LAB_004b086c;
          }
          iVar3 = (**(code **)(local_30 + -0x6e74))(iStack_58,file);
          if (iVar3 < 0) {
            (**(code **)(local_30 + -0x7e38))(iStack_58,file);
            (**(code **)(local_30 + -0x7e38))(psVar8,file);
            goto LAB_004b076c;
          }
          (**(code **)(local_30 + -0x7de8))(file);
          piVar6 = unaff_s5;
          iVar3 = (**(code **)(local_30 + -0x7e14))(iStack_5c,unaff_s5,0,0);
          psStack_b4 = psVar8;
          if (iVar3 == 0) goto LAB_004b086c;
          pcVar9 = *(code **)(local_30 + -0x7ee0);
        } while (psVar8 != (stack_st_X509_NAME *)0x0);
        pcVar9 = *(code **)(local_30 + -0x7e3c);
LAB_004b0814:
        psVar8 = (stack_st_X509_NAME *)(*pcVar9)();
      } while (psVar8 != (stack_st_X509_NAME *)0x0);
      pcVar9 = *(code **)(local_30 + -0x6eb0);
      local_38 = 0x2bd;
      goto LAB_004b0854;
    }
  }
LAB_004b086c:
  (**(code **)(local_30 + -0x7f60))(iStack_58);
LAB_004b087c:
  if (iStack_5c != 0) {
    (**(code **)(local_30 + -0x7f70))(iStack_5c);
  }
  if (local_28 != 0) {
    (**(code **)(local_30 + -0x7f50))();
  }
  if (psStack_b4 != (stack_st_X509_NAME *)0x0) {
    (**(code **)(local_30 + -0x7f00))();
  }
  if (local_24 == *(int *)puStack_54) {
    return psStack_b4;
  }
  pcStack_4c = SSL_add_file_cert_subjects_to_stack;
  iStack_b0 = local_24;
  (**(code **)(local_30 + -0x5328))();
  puStack_ac = PTR___stack_chk_guard_006aabf0;
  iStack_70 = 0;
  psStack_6c = *(stack_st_X509_NAME **)PTR___stack_chk_guard_006aabf0;
  pcStack_64 = file;
  psStack_60 = psStack_b4;
  piStack_50 = unaff_s5;
  uStack_a8 = (*(code *)PTR_sk_set_cmp_func_006a9090)();
  uVar2 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  psVar8 = (stack_st_X509_NAME *)(*(code *)PTR_BIO_new_006a7fa4)(uVar2);
  if (psVar8 == (stack_st_X509_NAME *)0x0) {
    psStack_b8 = (stack_st_X509_NAME *)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xd8,0x41,"ssl_cert.c");
  }
  else {
    iVar3 = (*(code *)PTR_BIO_ctrl_006a7f18)(psVar8,0x6c,3,piVar6);
    if (iVar3 != 0) {
      unaff_s5 = &iStack_70;
      do {
        iVar3 = (*(code *)PTR_PEM_read_bio_X509_006a80cc)(psVar8,unaff_s5,0,0);
        while( true ) {
          if (iVar3 == 0) {
            psStack_b8 = (stack_st_X509_NAME *)0x1;
            (*(code *)PTR_ERR_clear_error_006a7fe0)();
            goto LAB_004b0ac8;
          }
          iVar3 = (*(code *)PTR_X509_get_subject_name_006a8000)(iStack_70);
          if ((iVar3 == 0) || (iVar3 = (*(code *)PTR_X509_NAME_dup_006a823c)(iVar3), iVar3 == 0))
          goto LAB_004b0ac4;
          iVar4 = (*(code *)PTR_sk_find_006a906c)(iStack_b0,iVar3);
          if (iVar4 < 0) break;
          (*(code *)PTR_X509_NAME_free_006a80f8)(iVar3);
          iVar3 = (*(code *)PTR_PEM_read_bio_X509_006a80cc)(psVar8,unaff_s5,0,0);
        }
        (*(code *)PTR_sk_push_006a80a8)(iStack_b0,iVar3);
      } while( true );
    }
LAB_004b0ac4:
    psStack_b8 = (stack_st_X509_NAME *)0x0;
LAB_004b0ac8:
    (*(code *)PTR_BIO_free_006a7f70)(psVar8);
    psStack_b4 = psVar8;
  }
  if (iStack_70 != 0) {
    (*(code *)PTR_X509_free_006a7f90)();
  }
  uVar2 = uStack_a8;
  (*(code *)PTR_sk_set_cmp_func_006a9090)(iStack_b0);
  if (psStack_6c == *(stack_st_X509_NAME **)puStack_ac) {
    return psStack_b8;
  }
  psVar8 = psStack_6c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_4c0 = 0;
  pSStack_bc = *(SSL **)PTR___stack_chk_guard_006aabf0;
  piStack_a4 = unaff_s5;
  CRYPTO_lock(9,0x18,"ssl_cert.c",0x32c);
  do {
    iVar3 = OPENSSL_DIR_read(&iStack_4c0,uVar2);
    if (iVar3 == 0) {
      piVar6 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
      if (*piVar6 == 0) {
        psVar8 = (stack_st_X509_NAME *)0x1;
        goto LAB_004b0d30;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(2,10,*piVar6,"ssl_cert.c",0x348);
      (*(code *)PTR_ERR_add_error_data_006a9264)(3,"OPENSSL_DIR_read(&ctx, \'",uVar2,&DAT_00648304);
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xd7,2,"ssl_cert.c",0x34a);
LAB_004b0d2c:
      psVar8 = (stack_st_X509_NAME *)0x0;
LAB_004b0d30:
      if (iStack_4c0 != 0) {
        OPENSSL_DIR_end(&iStack_4c0);
      }
      pcVar7 = "ssl_cert.c";
      id = &DAT_00000018;
      CRYPTO_lock(10,0x18,"ssl_cert.c",0x352);
      if (pSStack_bc != *(SSL **)puVar1) {
        ssl = pSStack_bc;
        (*(code *)PTR___stack_chk_fail_006aabb8)();
        iVar3 = 10;
        while( true ) {
          iVar3 = iVar3 + -1;
          iVar4 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(id,*(uint *)pcVar7);
          if (iVar4 < 1) {
            return (stack_st_X509_NAME *)0x0;
          }
          iVar4 = SSL_has_matching_session_id(ssl,id,*(uint *)pcVar7);
          if (iVar4 == 0) break;
          if (iVar3 == 0) {
            return (stack_st_X509_NAME *)0x0;
          }
        }
        return (stack_st_X509_NAME *)0x1;
      }
      return psVar8;
    }
    iVar4 = (*(code *)PTR_strlen_006aab30)(uVar2);
    iVar5 = (*(code *)PTR_strlen_006aab30)(iVar3);
    if (0x400 < iVar4 + iVar5 + 2U) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xd7,0x10e,"ssl_cert.c",0x337);
      goto LAB_004b0d2c;
    }
    iVar3 = (*(code *)PTR_BIO_snprintf_006a8060)(acStack_4bc,0x400,"%s/%s",uVar2,iVar3);
    if ((0x3fe < iVar3 - 1U) ||
       (iVar3 = SSL_add_file_cert_subjects_to_stack(psVar8,acStack_4bc), iVar3 == 0))
    goto LAB_004b0d2c;
  } while( true );
}

