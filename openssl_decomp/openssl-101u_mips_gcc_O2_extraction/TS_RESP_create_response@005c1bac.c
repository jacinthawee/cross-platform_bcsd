
int * TS_RESP_create_response(int **param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  void *pvVar9;
  undefined4 *puVar10;
  char *pcVar11;
  undefined4 uVar12;
  undefined *puVar13;
  int *unaff_s3;
  int *piVar14;
  int iVar15;
  PKCS7_SIGNER_INFO *unaff_s7;
  undefined4 uVar16;
  int local_50;
  undefined4 local_4c;
  int local_48;
  undefined auStack_44 [24];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  param_1[0x11] = (int *)0x0;
  param_1[0x12] = (int *)0x0;
  param_1[0x13] = (int *)0x0;
  local_2c = *(int *)puVar1;
  piVar3 = (int *)TS_RESP_new();
  param_1[0x12] = piVar3;
  if (piVar3 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x7a,0x41,"ts_rsp_sign.c",0x1b5);
    goto LAB_005c1cb0;
  }
  piVar3 = (int *)d2i_TS_REQ_bio(param_2,0);
  param_1[0x11] = piVar3;
  if (piVar3 == (int *)0x0) {
    pcVar11 = "Bad request format or system error.";
LAB_005c1fc0:
    TS_RESP_CTX_set_status_info(param_1,2,pcVar11);
    iVar5 = TS_RESP_get_status_info(param_1[0x12]);
    iVar6 = *(int *)(iVar5 + 8);
    if (iVar6 == 0) {
      iVar6 = (*(code *)PTR_ASN1_BIT_STRING_new_006a8660)();
      *(int *)(iVar5 + 8) = iVar6;
      if (iVar6 == 0) goto LAB_005c1e28;
    }
    iVar5 = (*(code *)PTR_ASN1_BIT_STRING_set_bit_006a8de0)(iVar6,5,1);
joined_r0x005c1ff8:
    if (iVar5 != 0) goto LAB_005c1cb0;
  }
  else {
    puVar4 = (undefined4 *)TS_STATUS_INFO_new();
    if (((puVar4 == (undefined4 *)0x0) ||
        (iVar5 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(*puVar4,0), iVar5 == 0)) ||
       (iVar5 = TS_RESP_set_status_info(param_1[0x12],puVar4), iVar5 == 0)) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x84,0x41,"ts_rsp_sign.c",0x177);
      TS_STATUS_INFO_free(puVar4);
      (*(code *)PTR_ASN1_UTF8STRING_free_006a8d1c)(0);
      goto LAB_005c1cb0;
    }
    TS_STATUS_INFO_free(puVar4);
    (*(code *)PTR_ASN1_UTF8STRING_free_006a8d1c)(0);
    piVar3 = param_1[0x11];
    iVar5 = TS_REQ_get_version(piVar3);
    if (iVar5 == 1) {
      unaff_s3 = (int *)0x1;
      uVar8 = TS_REQ_get_msg_imprint(piVar3);
      puVar4 = (undefined4 *)TS_MSG_IMPRINT_get_algo(uVar8);
      iVar5 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar4);
      while( true ) {
        iVar6 = (*(code *)PTR_sk_num_006a6e2c)(param_1[5]);
        if (iVar6 <= (int)unaff_s3 + -1) break;
        iVar6 = (*(code *)PTR_sk_value_006a6e24)(param_1[5],(int)unaff_s3 + -1);
        iVar7 = (*(code *)PTR_EVP_MD_type_006a73cc)(iVar6);
        if ((iVar5 == iVar7) && (iVar6 != 0)) {
          if ((puVar4[1] != 0) && (iVar5 = (*(code *)PTR_ASN1_TYPE_get_006a74b0)(), iVar5 != 5)) {
            pcVar11 = "Superfluous message digest parameter.";
            goto LAB_005c1f6c;
          }
          piVar3 = (int *)TS_MSG_IMPRINT_get_msg(uVar8);
          iVar7 = *piVar3;
          iVar5 = (*(code *)PTR_EVP_MD_size_006a7e3c)(iVar6);
          if (iVar7 != iVar5) {
            pcVar11 = "Bad message digest.";
            goto LAB_005c1fc0;
          }
          iVar5 = TS_REQ_get_policy_id(param_1[0x11]);
          piVar3 = param_1[4];
          if (piVar3 == (int *)0x0) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x85,0x66,"ts_rsp_sign.c",0x241);
            goto LAB_005c1cb0;
          }
          if (iVar5 == 0) goto LAB_005c2114;
          iVar6 = (*(code *)PTR_OBJ_cmp_006a8cc4)(iVar5,piVar3);
          if (iVar6 != 0) {
            unaff_s3 = (int *)0x1;
            goto LAB_005c20a8;
          }
          piVar3 = param_1[4];
          unaff_s3 = (int *)0x1;
          if (piVar3 != (int *)0x0) goto LAB_005c2114;
          goto LAB_005c20a8;
        }
        unaff_s3 = (int *)((int)unaff_s3 + 1);
      }
      pcVar11 = "Message digest algorithm is not supported.";
LAB_005c1f6c:
      TS_RESP_CTX_set_status_info(param_1,2,pcVar11);
      iVar5 = TS_RESP_get_status_info(param_1[0x12]);
      iVar6 = *(int *)(iVar5 + 8);
      if (iVar6 == 0) {
        iVar6 = (*(code *)PTR_ASN1_BIT_STRING_new_006a8660)();
        *(int *)(iVar5 + 8) = iVar6;
        if (iVar6 == 0) goto LAB_005c1e28;
      }
      iVar5 = (*(code *)PTR_ASN1_BIT_STRING_set_bit_006a8de0)(iVar6,0,1);
      goto joined_r0x005c1ff8;
    }
    TS_RESP_CTX_set_status_info(param_1,2,"Bad request version.");
    iVar5 = TS_RESP_get_status_info(param_1[0x12]);
    iVar6 = *(int *)(iVar5 + 8);
    if (iVar6 != 0) {
LAB_005c1e0c:
      iVar5 = (*(code *)PTR_ASN1_BIT_STRING_set_bit_006a8de0)(iVar6,2,1);
      goto joined_r0x005c1ff8;
    }
    iVar6 = (*(code *)PTR_ASN1_BIT_STRING_new_006a8660)();
    *(int *)(iVar5 + 8) = iVar6;
    if (iVar6 != 0) goto LAB_005c1e0c;
  }
LAB_005c1e28:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x7c,0x41,"ts_rsp_sign.c",0x193);
  goto LAB_005c1cb0;
LAB_005c20a8:
  iVar6 = (*(code *)PTR_sk_num_006a6e2c)(param_1[3]);
  if (iVar6 <= (int)unaff_s3 + -1) goto LAB_005c21f4;
  piVar3 = (int *)(*(code *)PTR_sk_value_006a6e24)(param_1[3],(int)unaff_s3 + -1);
  iVar6 = (*(code *)PTR_OBJ_cmp_006a8cc4)(iVar5,piVar3);
  if ((iVar6 == 0) && (piVar3 != (int *)0x0)) {
LAB_005c2114:
    unaff_s3 = (int *)TS_TST_INFO_new();
    if ((unaff_s3 != (int *)0x0) &&
       ((((iVar5 = TS_TST_INFO_set_version(unaff_s3,1), iVar5 != 0 &&
          (iVar5 = TS_TST_INFO_set_policy_id(unaff_s3,piVar3), iVar5 != 0)) &&
         (iVar5 = TS_TST_INFO_set_msg_imprint(unaff_s3,param_1[0x11][1]), iVar5 != 0)) &&
        (unaff_s7 = (PKCS7_SIGNER_INFO *)(*(code *)param_1[0xb])(param_1,param_1[0xc]),
        unaff_s7 != (PKCS7_SIGNER_INFO *)0x0)))) {
      iVar5 = TS_TST_INFO_set_serial(unaff_s3,unaff_s7);
      if (iVar5 != 0) goto LAB_005c23ac;
      goto LAB_005c2318;
    }
    puVar4 = (undefined4 *)0x0;
    iVar6 = 0;
    iVar5 = 0;
    unaff_s7 = (PKCS7_SIGNER_INFO *)0x0;
    goto LAB_005c2154;
  }
  unaff_s3 = (int *)((int)unaff_s3 + 1);
  goto LAB_005c20a8;
LAB_005c21f4:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x85,0x7d,"ts_rsp_sign.c",0x252);
  TS_RESP_CTX_set_status_info(param_1,2,"Requested policy is not supported.");
  iVar5 = TS_RESP_get_status_info(param_1[0x12]);
  iVar6 = *(int *)(iVar5 + 8);
  if (iVar6 == 0) {
    iVar6 = (*(code *)PTR_ASN1_BIT_STRING_new_006a8660)();
    *(int *)(iVar5 + 8) = iVar6;
    if (iVar6 != 0) goto LAB_005c224c;
  }
  else {
LAB_005c224c:
    iVar5 = (*(code *)PTR_ASN1_BIT_STRING_set_bit_006a8de0)(iVar6,0xf,1);
    if (iVar5 != 0) goto LAB_005c1cb0;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x7c,0x41,"ts_rsp_sign.c",0x193);
LAB_005c1cb0:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x7a,0x79,"ts_rsp_sign.c",0x1dd);
  piVar3 = param_1[0x12];
  if (piVar3 != (int *)0x0) {
    puVar4 = (undefined4 *)TS_RESP_get_status_info(piVar3);
    iVar5 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)(*puVar4);
    if ((iVar5 == 0) &&
       (iVar5 = TS_RESP_CTX_set_status_info(param_1,2,"Error during response generation."),
       iVar5 == 0)) {
      piVar3 = (int *)0x0;
      TS_RESP_free(param_1[0x12]);
    }
    else {
      piVar3 = param_1[0x12];
    }
  }
  do {
    param_1[0x12] = (int *)0x0;
    TS_REQ_free(param_1[0x11]);
    param_1[0x11] = (int *)0x0;
    TS_RESP_free(param_1[0x12]);
    param_1[0x12] = (int *)0x0;
    TS_TST_INFO_free(param_1[0x13]);
    iVar5 = *(int *)puVar1;
    param_1[0x13] = (int *)0x0;
    if (local_2c == iVar5) {
      return piVar3;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005c23ac:
    iVar5 = (*(code *)param_1[0xd])(param_1,param_1[0xe],&local_50,&local_4c);
    uVar8 = local_4c;
    if (iVar5 == 0) break;
    piVar3 = param_1[9];
    local_48 = local_50;
    if (&DAT_00000006 < piVar3) {
LAB_005c24d0:
      puVar4 = (undefined4 *)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x86,0x73,"ts_rsp_sign.c",0x3ff);
      iVar6 = 0;
      iVar5 = 0;
      goto LAB_005c2154;
    }
    puVar4 = (undefined4 *)(*(code *)PTR_gmtime_006a99f8)(&local_48);
    if (puVar4 == (undefined4 *)0x0) goto LAB_005c24d0;
    iVar5 = (*(code *)PTR_BIO_snprintf_006a6f60)
                      (auStack_44,0x17,"%04d%02d%02d%02d%02d%02d",puVar4[5] + 0x76c,puVar4[4] + 1,
                       puVar4[3],puVar4[2],puVar4[1],*puVar4);
    puVar13 = auStack_44 + iVar5;
    if (piVar3 != (int *)0x0) {
      (*(code *)PTR_BIO_snprintf_006a6f60)(puVar13,(undefined *)((int)piVar3 + 2),".%06ld",uVar8);
      iVar5 = (*(code *)PTR_strlen_006a9a24)(puVar13);
      puVar2 = puVar13 + iVar5;
      do {
        puVar13 = puVar2;
        puVar2 = puVar13 + -1;
      } while (puVar13[-1] == '0');
      if (puVar13[-1] == '.') {
        puVar13 = puVar13 + -1;
      }
    }
    puVar13[1] = 0;
    *puVar13 = 0x5a;
    iVar5 = (*(code *)PTR_ASN1_STRING_type_new_006a8680)(0x18);
    if (iVar5 == 0) goto LAB_005c24d0;
    iVar6 = (*(code *)PTR_ASN1_GENERALIZEDTIME_set_string_006a6ffc)(iVar5,auStack_44);
    if (iVar6 == 0) {
      (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a7038)(iVar5);
      goto LAB_005c24d0;
    }
    iVar6 = TS_TST_INFO_set_time(unaff_s3,iVar5);
    if (iVar6 == 0) {
      puVar4 = (undefined4 *)0x0;
      iVar6 = 0;
      goto LAB_005c2154;
    }
    if (((param_1[6] != (int *)0x0) || (param_1[7] != (int *)0x0)) || (param_1[8] != (int *)0x0)) {
      iVar6 = TS_ACCURACY_new();
      if (((iVar6 != 0) &&
          ((param_1[6] == (int *)0x0 || (iVar7 = TS_ACCURACY_set_seconds(iVar6), iVar7 != 0)))) &&
         ((param_1[7] == (int *)0x0 || (iVar7 = TS_ACCURACY_set_millis(iVar6), iVar7 != 0)))) {
        if (param_1[8] != (int *)0x0) {
          iVar7 = TS_ACCURACY_set_micros(iVar6);
          if (iVar7 == 0) goto LAB_005c2560;
          if (iVar6 == 0) goto LAB_005c25e0;
        }
        iVar7 = TS_TST_INFO_set_accuracy(unaff_s3,iVar6);
        if (iVar7 != 0) {
          piVar3 = param_1[10];
          goto LAB_005c25e4;
        }
      }
LAB_005c2560:
      puVar4 = (undefined4 *)0x0;
      goto LAB_005c2154;
    }
    iVar6 = 0;
LAB_005c25e0:
    piVar3 = param_1[10];
LAB_005c25e4:
    if (((((uint)piVar3 & 2) != 0) && (iVar7 = TS_TST_INFO_set_ordering(unaff_s3,1), iVar7 == 0)) ||
       ((iVar7 = TS_REQ_get_nonce(param_1[0x11]), iVar7 != 0 &&
        (iVar7 = TS_TST_INFO_set_nonce(unaff_s3,iVar7), iVar7 == 0)))) goto LAB_005c2560;
    if (((uint)param_1[10] & 1) == 0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = (undefined4 *)(*(code *)PTR_GENERAL_NAME_new_006a9034)();
      puVar13 = PTR_X509_NAME_dup_006a713c;
      if (puVar4 == (undefined4 *)0x0) goto LAB_005c2154;
      piVar3 = *param_1;
      *puVar4 = 4;
      iVar7 = (*(code *)puVar13)(*(undefined4 *)(*piVar3 + 0x14));
      puVar4[1] = iVar7;
      if ((iVar7 == 0) || (iVar7 = TS_TST_INFO_set_tsa(unaff_s3,puVar4), iVar7 == 0))
      goto LAB_005c2154;
    }
    (*(code *)PTR_GENERAL_NAME_free_006a73a4)(puVar4);
    TS_ACCURACY_free(iVar6);
    (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a7038)(iVar5);
    (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(unaff_s7);
    param_1[0x13] = unaff_s3;
    unaff_s3 = (int *)TS_REQ_get_exts(param_1[0x11]);
    iVar5 = 0;
    while (iVar6 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s3), iVar5 < iVar6) {
      uVar8 = (*(code *)PTR_sk_value_006a6e24)(unaff_s3,iVar5);
      iVar6 = (*(code *)param_1[0xf])(param_1,uVar8,0);
      iVar5 = iVar5 + 1;
      if (iVar6 == 0) goto LAB_005c1cb0;
    }
    iVar5 = (*(code *)PTR_X509_check_private_key_006a707c)(*param_1,param_1[1]);
    if (iVar5 == 0) {
      iVar6 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x88,0x78,"ts_rsp_sign.c",0x2d3);
      unaff_s3 = (int *)0x0;
      iVar5 = 0;
      goto LAB_005c2740;
    }
    iVar5 = (*(code *)PTR_PKCS7_new_006a75bc)();
    if (iVar5 == 0) {
      uVar12 = 0x41;
      uVar16 = 0x2d9;
      uVar8 = 0x88;
      goto LAB_005c2adc;
    }
    iVar6 = (*(code *)PTR_PKCS7_set_type_006a9190)(iVar5,0x16);
    if ((iVar6 == 0) ||
       (iVar6 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(**(undefined4 **)(iVar5 + 0x14),3),
       iVar6 == 0)) {
      iVar6 = 0;
      unaff_s3 = (int *)0x0;
      goto LAB_005c2740;
    }
    iVar6 = TS_REQ_get_cert_req(param_1[0x11]);
    if (iVar6 != 0) {
      (*(code *)PTR_PKCS7_add_certificate_006a9178)(iVar5,*param_1);
      piVar3 = param_1[2];
      if (piVar3 != (int *)0x0) {
        for (iVar6 = 0; iVar7 = (*(code *)PTR_sk_num_006a6e2c)(piVar3), iVar6 < iVar7;
            iVar6 = iVar6 + 1) {
          uVar8 = (*(code *)PTR_sk_value_006a6e24)(param_1[2],iVar6);
          (*(code *)PTR_PKCS7_add_certificate_006a9178)(iVar5,uVar8);
          piVar3 = param_1[2];
        }
      }
    }
    piVar3 = *param_1;
    piVar14 = param_1[1];
    uVar8 = (*(code *)PTR_EVP_sha1_006a75d0)();
    unaff_s7 = (PKCS7_SIGNER_INFO *)
               (*(code *)PTR_PKCS7_add_signature_006a9174)(iVar5,piVar3,piVar14,uVar8);
    if (unaff_s7 == (PKCS7_SIGNER_INFO *)0x0) {
      uVar12 = 0x76;
      uVar16 = 0x2f1;
      uVar8 = 0x88;
LAB_005c2adc:
      iVar6 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,uVar8,uVar12,"ts_rsp_sign.c",uVar16);
      unaff_s3 = (int *)0x0;
      goto LAB_005c2740;
    }
    pvVar9 = (void *)(*(code *)PTR_OBJ_nid2obj_006a7140)(0xcf);
    iVar6 = PKCS7_add_signed_attribute(unaff_s7,0x32,6,pvVar9);
    if (iVar6 == 0) {
      uVar12 = 0x77;
      uVar16 = 0x2f9;
      uVar8 = 0x88;
      goto LAB_005c2adc;
    }
    piVar3 = (int *)0x0;
    if (((uint)param_1[10] & 4) != 0) {
      piVar3 = param_1[2];
    }
    piVar14 = *param_1;
    unaff_s3 = (int *)ESS_SIGNING_CERT_new();
    if (unaff_s3 == (int *)0x0) {
LAB_005c2ab4:
      ESS_SIGNING_CERT_free(unaff_s3);
      uVar12 = 0x41;
      uVar8 = 0x72;
      uVar16 = 0x34e;
      goto LAB_005c2adc;
    }
    if (*unaff_s3 == 0) {
      iVar6 = (*(code *)PTR_sk_new_null_006a6fa4)();
      *unaff_s3 = iVar6;
      if (iVar6 == 0) goto LAB_005c2ab4;
    }
    (*(code *)PTR_X509_check_purpose_006a771c)(piVar14,0xffffffff,0);
    puVar4 = (undefined4 *)ESS_CERT_ID_new();
    if ((puVar4 == (undefined4 *)0x0) ||
       (iVar6 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a866c)(*puVar4,piVar14 + 0x14,0x14),
       iVar6 == 0)) {
      puVar10 = (undefined4 *)0x0;
LAB_005c2a70:
      (*(code *)PTR_GENERAL_NAME_free_006a73a4)(puVar10);
      ESS_CERT_ID_free(puVar4);
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x71,0x41,"ts_rsp_sign.c",0x37a);
      goto LAB_005c2ab4;
    }
    iVar6 = (*(code *)PTR_sk_push_006a6fa8)(*unaff_s3,puVar4);
    if (iVar6 == 0) goto LAB_005c2ab4;
    for (iVar6 = 0; iVar7 = (*(code *)PTR_sk_num_006a6e2c)(piVar3), iVar6 < iVar7; iVar6 = iVar6 + 1
        ) {
      piVar14 = (int *)(*(code *)PTR_sk_value_006a6e24)(piVar3,iVar6);
      (*(code *)PTR_X509_check_purpose_006a771c)(piVar14,0xffffffff,0);
      puVar4 = (undefined4 *)ESS_CERT_ID_new();
      if ((puVar4 == (undefined4 *)0x0) ||
         (iVar7 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a866c)(*puVar4,piVar14 + 0x14,0x14),
         iVar7 == 0)) {
LAB_005c2b28:
        puVar10 = (undefined4 *)0x0;
        goto LAB_005c2a70;
      }
      if (puVar4[1] == 0) {
        iVar7 = ESS_ISSUER_SERIAL_new();
        puVar4[1] = iVar7;
        if (iVar7 == 0) goto LAB_005c2b28;
      }
      puVar10 = (undefined4 *)(*(code *)PTR_GENERAL_NAME_new_006a9034)();
      puVar13 = PTR_X509_NAME_dup_006a713c;
      if (puVar10 == (undefined4 *)0x0) goto LAB_005c2b28;
      iVar7 = *piVar14;
      *puVar10 = 4;
      iVar7 = (*(code *)puVar13)(*(undefined4 *)(iVar7 + 0xc));
      puVar10[1] = iVar7;
      if ((iVar7 == 0) ||
         (iVar7 = (*(code *)PTR_sk_push_006a6fa8)(*(undefined4 *)puVar4[1],puVar10), iVar7 == 0))
      goto LAB_005c2a70;
      (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(*(undefined4 *)(puVar4[1] + 4));
      iVar15 = puVar4[1];
      iVar7 = (*(code *)PTR_ASN1_INTEGER_dup_006a9270)(*(undefined4 *)(*piVar14 + 4));
      *(int *)(iVar15 + 4) = iVar7;
      if (iVar7 == 0) goto LAB_005c2b28;
      iVar7 = (*(code *)PTR_sk_push_006a6fa8)(*unaff_s3,puVar4);
      if (iVar7 == 0) goto LAB_005c2ab4;
    }
    uVar8 = i2d_ESS_SIGNING_CERT(unaff_s3,0);
    iVar6 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar8,"ts_rsp_sign.c",0x3a0);
    if (iVar6 == 0) {
      pvVar9 = (void *)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x70,0x41,"ts_rsp_sign.c",0x3a1);
LAB_005c2bdc:
      (*(code *)PTR_ASN1_STRING_free_006a879c)(pvVar9);
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar6);
LAB_005c2bfc:
      iVar6 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x88,0x74,"ts_rsp_sign.c",0x307);
      goto LAB_005c2740;
    }
    local_48 = iVar6;
    i2d_ESS_SIGNING_CERT(unaff_s3,&local_48);
    pvVar9 = (void *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if ((pvVar9 == (void *)0x0) ||
       (iVar7 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)(pvVar9,iVar6,uVar8), iVar7 == 0)) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x70,0x41,"ts_rsp_sign.c",0x3a7);
      goto LAB_005c2bdc;
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar6);
    iVar6 = PKCS7_add_signed_attribute(unaff_s7,0xdf,0x10,pvVar9);
    if (iVar6 == 0) goto LAB_005c2bfc;
    iVar7 = (*(code *)PTR_PKCS7_new_006a75bc)();
    if (iVar7 == 0) {
LAB_005c2e40:
      (*(code *)PTR_ASN1_OCTET_STRING_free_006a8cfc)(0);
      iVar6 = 0;
      (*(code *)PTR_PKCS7_free_006a723c)(iVar7);
      goto LAB_005c2740;
    }
    iVar6 = (*(code *)PTR_ASN1_TYPE_new_006a7ecc)();
    *(int *)(iVar7 + 0x14) = iVar6;
    if (iVar6 == 0) goto LAB_005c2e40;
    uVar8 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0xcf);
    puVar13 = PTR_ASN1_OCTET_STRING_new_006a8668;
    *(undefined4 *)(iVar7 + 0x10) = uVar8;
    iVar6 = (*(code *)puVar13)();
    if (iVar6 == 0) goto LAB_005c2e40;
    (*(code *)PTR_ASN1_TYPE_set_006a8cd8)(*(undefined4 *)(iVar7 + 0x14),4,iVar6);
    iVar6 = (*(code *)PTR_PKCS7_set_content_006a94d4)(iVar5,iVar7);
    if (iVar6 == 0) goto LAB_005c2e40;
    iVar6 = (*(code *)PTR_PKCS7_dataInit_006a9100)(iVar5,0);
    if (iVar6 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x88,0x41,"ts_rsp_sign.c",0x311);
      goto LAB_005c2740;
    }
    iVar7 = i2d_TS_TST_INFO_bio(iVar6,param_1[0x13]);
    if (iVar7 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x88,0x7c,"ts_rsp_sign.c",0x317);
      goto LAB_005c2740;
    }
    iVar7 = (*(code *)PTR_PKCS7_dataFinal_006a9104)(iVar5,iVar6);
    if (iVar7 == 0) goto code_r0x005c2f20;
    TS_RESP_set_tst_info(param_1[0x12],iVar5,param_1[0x13]);
    puVar13 = PTR_BIO_free_all_006a6e74;
    param_1[0x13] = (int *)0x0;
    (*(code *)puVar13)(iVar6);
    ESS_SIGNING_CERT_free(unaff_s3);
    (*(code *)PTR_PKCS7_free_006a723c)(0);
    piVar3 = param_1[0x12];
  } while( true );
LAB_005c2318:
  puVar4 = (undefined4 *)0x0;
  iVar6 = 0;
  iVar5 = 0;
LAB_005c2154:
  TS_TST_INFO_free(unaff_s3);
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x7b,0x7b,"ts_rsp_sign.c",0x2a3);
  TS_RESP_CTX_set_status_info_cond(param_1,2,"Error during TSTInfo generation.");
  (*(code *)PTR_GENERAL_NAME_free_006a73a4)(puVar4);
  TS_ACCURACY_free(iVar6);
  (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a7038)(iVar5);
  (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(unaff_s7);
  param_1[0x13] = (int *)0x0;
  goto LAB_005c1cb0;
code_r0x005c2f20:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x88,0x7c,"ts_rsp_sign.c",0x31d);
LAB_005c2740:
  puVar4 = (undefined4 *)TS_RESP_get_status_info(param_1[0x12]);
  iVar7 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)(*puVar4);
  if (iVar7 == 0) {
    TS_RESP_CTX_set_status_info(param_1,2,"Error during signature generation.");
  }
  (*(code *)PTR_BIO_free_all_006a6e74)(iVar6);
  ESS_SIGNING_CERT_free(unaff_s3);
  (*(code *)PTR_PKCS7_free_006a723c)(iVar5);
  goto LAB_005c1cb0;
}

