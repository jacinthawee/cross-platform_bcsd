
undefined4 cert_status_cb(undefined4 param_1,int *param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int unaff_s3;
  int iVar6;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined auStack_bc [4];
  undefined4 local_b8;
  undefined auStack_b4 [136];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_c4 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar6 = param_2[5];
  if (param_2[6] != 0) {
    (*(code *)PTR_BIO_puts_006a8058)(iVar6,"cert_status: callback called\n");
  }
  iVar2 = (*(code *)PTR_SSL_get_certificate_006a8850)(param_1);
  iVar3 = (*(code *)PTR_X509_get1_ocsp_006a8800)(iVar2);
  if (iVar3 != 0) {
    uVar4 = (*(code *)PTR_sk_value_006a7f24)(iVar3,0);
    iVar5 = (*(code *)PTR_OCSP_parse_url_006a8854)(uVar4,&local_d4,&local_d0,&local_cc,&local_c8);
    if (iVar5 != 0) {
      if (param_2[6] != 0) {
        uVar4 = (*(code *)PTR_sk_value_006a7f24)(iVar3,0);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar6,"cert_status: AIA URL: %s\n",uVar4);
      }
      goto LAB_00442480;
    }
    unaff_s3 = 0;
    (*(code *)PTR_BIO_puts_006a8058)(iVar6,"cert_status: can\'t parse AIA URL\n");
    iVar2 = 0;
    iVar5 = 0;
    uVar4 = 2;
    (*(code *)PTR_ERR_print_errors_006a7f40)(iVar6);
    goto LAB_004424e8;
  }
  if (*param_2 == 0) {
    uVar4 = 3;
    (*(code *)PTR_BIO_puts_006a8058)
              (param_2[5],"cert_status: no AIA and no default responder URL\n");
    (*(code *)PTR_ERR_print_errors_006a7f40)(iVar6);
    goto LAB_00442568;
  }
  local_cc = param_2[1];
  local_d0 = param_2[2];
  local_c8 = param_2[3];
  local_d4 = *param_2;
LAB_00442480:
  uVar4 = (*(code *)PTR_SSL_get_SSL_CTX_006a8858)(param_1);
  uVar4 = (*(code *)PTR_SSL_CTX_get_cert_store_006a885c)(uVar4);
  iVar5 = (*(code *)PTR_X509_STORE_CTX_init_006a8304)(auStack_b4,uVar4,0,0);
  if (iVar5 == 0) {
LAB_004424c4:
    uVar4 = 2;
    iVar2 = 0;
    unaff_s3 = 0;
LAB_004424d0:
    (*(code *)PTR_ERR_print_errors_006a7f40)(iVar6);
    if (iVar3 == 0) goto LAB_0044253c;
    iVar5 = 0;
LAB_004424e8:
    (*(code *)PTR_CRYPTO_free_006a7f88)(local_d4);
    (*(code *)PTR_CRYPTO_free_006a7f88)(local_cc);
    (*(code *)PTR_CRYPTO_free_006a7f88)(local_d0);
    (*(code *)PTR_X509_email_free_006a8804)(iVar3);
    if (iVar5 == 0) goto LAB_0044253c;
  }
  else {
    uVar4 = (*(code *)PTR_X509_get_issuer_name_006a87d0)(iVar2);
    iVar5 = (*(code *)PTR_X509_STORE_get_by_subject_006a86d0)(auStack_b4,1,uVar4,auStack_bc);
    if (iVar5 < 1) {
      uVar4 = 3;
      (*(code *)PTR_BIO_puts_006a8058)(iVar6,"cert_status: Can\'t retrieve issuer certificate.\n");
      iVar2 = 0;
      unaff_s3 = 0;
      (*(code *)PTR_X509_STORE_CTX_cleanup_006a8310)(auStack_b4);
      goto LAB_004424d0;
    }
    unaff_s3 = (*(code *)PTR_OCSP_REQUEST_new_006a886c)();
    if (unaff_s3 == 0) goto LAB_004424c4;
    iVar5 = (*(code *)PTR_OCSP_cert_to_id_006a8870)(0,iVar2,local_b8);
    (*(code *)PTR_X509_free_006a7f90)(local_b8);
    (*(code *)PTR_X509_STORE_CTX_cleanup_006a8310)(auStack_b4);
    if (iVar5 == 0) {
LAB_0044282c:
      uVar4 = 2;
      iVar2 = 0;
      goto LAB_004424d0;
    }
    iVar2 = (*(code *)PTR_OCSP_request_add0_id_006a8874)(unaff_s3,iVar5);
    if (iVar2 != 0) {
      (*(code *)PTR_SSL_ctrl_006a8878)(param_1,0x42,0,&local_c0);
      for (iVar2 = 0; iVar5 = (*(code *)PTR_sk_num_006a7f2c)(local_c0), iVar2 < iVar5;
          iVar2 = iVar2 + 1) {
        uVar4 = (*(code *)PTR_sk_value_006a7f24)(local_c0,iVar2);
        iVar5 = (*(code *)PTR_OCSP_REQUEST_add_ext_006a887c)(unaff_s3,uVar4,0xffffffff);
        if (iVar5 == 0) goto LAB_0044282c;
      }
      iVar2 = (*(code *)PTR_process_responder_006a8880)
                        (iVar6,unaff_s3,local_d4,local_cc,local_d0,local_c8,0,param_2[4]);
      if (iVar2 == 0) {
        uVar4 = 3;
        (*(code *)PTR_BIO_puts_006a8058)(iVar6,"cert_status: error querying responder\n");
      }
      else {
        iVar5 = (*(code *)PTR_i2d_OCSP_RESPONSE_006a8884)(iVar2,&local_c4);
        if (0 < iVar5) {
          (*(code *)PTR_SSL_ctrl_006a8878)(param_1,0x47,iVar5,local_c4);
          if (param_2[6] != 0) {
            (*(code *)PTR_BIO_puts_006a8058)(iVar6,"cert_status: ocsp response sent:\n");
            (*(code *)PTR_OCSP_RESPONSE_print_006a8888)(iVar6,iVar2,2);
          }
          if (iVar3 == 0) goto LAB_004428f4;
          iVar5 = 0;
          uVar4 = 0;
          goto LAB_004424e8;
        }
        uVar4 = 2;
      }
      goto LAB_004424d0;
    }
    iVar2 = 0;
    uVar4 = 2;
    (*(code *)PTR_ERR_print_errors_006a7f40)(iVar6);
    if (iVar3 != 0) goto LAB_004424e8;
  }
  (*(code *)PTR_OCSP_CERTID_free_006a8860)(iVar5);
LAB_0044253c:
  if (unaff_s3 == 0) goto LAB_00442554;
  while( true ) {
    (*(code *)PTR_OCSP_REQUEST_free_006a8864)(unaff_s3);
LAB_00442554:
    if (iVar2 != 0) {
      (*(code *)PTR_OCSP_RESPONSE_free_006a8868)(iVar2);
    }
LAB_00442568:
    if (local_2c == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_004428f4:
    uVar4 = 0;
  }
  return uVar4;
}

