
int SSL_add_file_cert_subjects_to_stack(stack_st_X509_NAME *stackCAs,char *file)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  stack_st_X509_NAME *stackCAs_00;
  SSL *ssl;
  uchar *id;
  char *pcVar7;
  int unaff_s1;
  int *unaff_s5;
  int iStack_478;
  char acStack_474 [1024];
  SSL *pSStack_74;
  int iStack_70;
  int iStack_6c;
  stack_st_X509_NAME *psStack_68;
  undefined *puStack_64;
  undefined4 uStack_60;
  int *piStack_5c;
  int local_28;
  stack_st_X509_NAME *local_24;
  
  puStack_64 = PTR___stack_chk_guard_006aabf0;
  local_28 = 0;
  local_24 = *(stack_st_X509_NAME **)PTR___stack_chk_guard_006aabf0;
  uStack_60 = (*(code *)PTR_sk_set_cmp_func_006a9090)(stackCAs,xname_cmp);
  uVar2 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  iVar3 = (*(code *)PTR_BIO_new_006a7fa4)(uVar2);
  if (iVar3 == 0) {
    iStack_70 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xd8,0x41,"ssl_cert.c");
  }
  else {
    iVar4 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar3,0x6c,3,file);
    if (iVar4 != 0) {
      unaff_s5 = &local_28;
      do {
        iVar4 = (*(code *)PTR_PEM_read_bio_X509_006a80cc)(iVar3,unaff_s5,0,0);
        while( true ) {
          if (iVar4 == 0) {
            iStack_70 = 1;
            (*(code *)PTR_ERR_clear_error_006a7fe0)();
            goto LAB_004b0ac8;
          }
          iVar4 = (*(code *)PTR_X509_get_subject_name_006a8000)(local_28);
          if ((iVar4 == 0) || (iVar4 = (*(code *)PTR_X509_NAME_dup_006a823c)(iVar4), iVar4 == 0))
          goto LAB_004b0ac4;
          iVar5 = (*(code *)PTR_sk_find_006a906c)(stackCAs,iVar4);
          if (iVar5 < 0) break;
          (*(code *)PTR_X509_NAME_free_006a80f8)(iVar4);
          iVar4 = (*(code *)PTR_PEM_read_bio_X509_006a80cc)(iVar3,unaff_s5,0,0);
        }
        (*(code *)PTR_sk_push_006a80a8)(stackCAs,iVar4);
      } while( true );
    }
LAB_004b0ac4:
    iStack_70 = 0;
LAB_004b0ac8:
    (*(code *)PTR_BIO_free_006a7f70)(iVar3);
    unaff_s1 = iVar3;
  }
  if (local_28 != 0) {
    (*(code *)PTR_X509_free_006a7f90)();
  }
  uVar2 = uStack_60;
  (*(code *)PTR_sk_set_cmp_func_006a9090)(stackCAs);
  if (local_24 == *(stack_st_X509_NAME **)puStack_64) {
    return iStack_70;
  }
  stackCAs_00 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_478 = 0;
  pSStack_74 = *(SSL **)PTR___stack_chk_guard_006aabf0;
  iStack_6c = unaff_s1;
  psStack_68 = stackCAs;
  piStack_5c = unaff_s5;
  CRYPTO_lock(9,0x18,"ssl_cert.c",0x32c);
  do {
    iVar3 = OPENSSL_DIR_read(&iStack_478,uVar2);
    if (iVar3 == 0) {
      piVar6 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
      if (*piVar6 == 0) {
        iVar3 = 1;
        goto LAB_004b0d30;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(2,10,*piVar6,"ssl_cert.c",0x348);
      (*(code *)PTR_ERR_add_error_data_006a9264)(3,"OPENSSL_DIR_read(&ctx, \'",uVar2,&DAT_00648304);
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xd7,2,"ssl_cert.c",0x34a);
LAB_004b0d2c:
      iVar3 = 0;
LAB_004b0d30:
      if (iStack_478 != 0) {
        OPENSSL_DIR_end(&iStack_478);
      }
      pcVar7 = "ssl_cert.c";
      id = &DAT_00000018;
      CRYPTO_lock(10,0x18,"ssl_cert.c",0x352);
      if (pSStack_74 != *(SSL **)puVar1) {
        ssl = pSStack_74;
        (*(code *)PTR___stack_chk_fail_006aabb8)();
        iVar3 = 10;
        while( true ) {
          iVar3 = iVar3 + -1;
          iVar4 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(id,*(uint *)pcVar7);
          if (iVar4 < 1) {
            return 0;
          }
          iVar4 = SSL_has_matching_session_id(ssl,id,*(uint *)pcVar7);
          if (iVar4 == 0) break;
          if (iVar3 == 0) {
            return 0;
          }
        }
        return 1;
      }
      return iVar3;
    }
    iVar4 = (*(code *)PTR_strlen_006aab30)(uVar2);
    iVar5 = (*(code *)PTR_strlen_006aab30)(iVar3);
    if (0x400 < iVar4 + iVar5 + 2U) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xd7,0x10e,"ssl_cert.c",0x337);
      goto LAB_004b0d2c;
    }
    iVar3 = (*(code *)PTR_BIO_snprintf_006a8060)(acStack_474,0x400,"%s/%s",uVar2,iVar3);
    if ((0x3fe < iVar3 - 1U) ||
       (iVar3 = SSL_add_file_cert_subjects_to_stack(stackCAs_00,acStack_474), iVar3 == 0))
    goto LAB_004b0d2c;
  } while( true );
}

