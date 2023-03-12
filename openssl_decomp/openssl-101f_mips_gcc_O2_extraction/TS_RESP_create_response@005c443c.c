
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
  PKCS7 *p7;
  int *unaff_s3;
  int *piVar14;
  BIO *bio;
  PKCS7_SIGNER_INFO *unaff_s7;
  undefined4 uVar15;
  int local_50;
  undefined4 local_4c;
  int local_48;
  undefined auStack_44 [24];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  param_1[0x11] = (int *)0x0;
  param_1[0x12] = (int *)0x0;
  param_1[0x13] = (int *)0x0;
  local_2c = *(int *)puVar1;
  piVar3 = (int *)TS_RESP_new();
  param_1[0x12] = piVar3;
  if (piVar3 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x7a,0x41,"ts_rsp_sign.c",0x1ad);
    goto LAB_005c4540;
  }
  piVar3 = (int *)d2i_TS_REQ_bio(param_2,0);
  param_1[0x11] = piVar3;
  if (piVar3 == (int *)0x0) {
    pcVar11 = "Bad request format or system error.";
LAB_005c4850:
    TS_RESP_CTX_set_status_info(param_1,2,pcVar11);
    iVar5 = TS_RESP_get_status_info(param_1[0x12]);
    iVar6 = *(int *)(iVar5 + 8);
    if (iVar6 == 0) {
      iVar6 = (*(code *)PTR_ASN1_BIT_STRING_new_006a9784)();
      *(int *)(iVar5 + 8) = iVar6;
      if (iVar6 == 0) goto LAB_005c46b8;
    }
    iVar5 = (*(code *)PTR_ASN1_BIT_STRING_set_bit_006a9ee8)(iVar6,5,1);
joined_r0x005c4888:
    if (iVar5 != 0) goto LAB_005c4540;
  }
  else {
    puVar4 = (undefined4 *)TS_STATUS_INFO_new();
    if (((puVar4 == (undefined4 *)0x0) ||
        (iVar5 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(*puVar4,0), iVar5 == 0)) ||
       (iVar5 = TS_RESP_set_status_info(param_1[0x12],puVar4), iVar5 == 0)) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x84,0x41,"ts_rsp_sign.c",0x16e);
      TS_STATUS_INFO_free(puVar4);
      (*(code *)PTR_ASN1_UTF8STRING_free_006a9e3c)(0);
      goto LAB_005c4540;
    }
    TS_STATUS_INFO_free(puVar4);
    (*(code *)PTR_ASN1_UTF8STRING_free_006a9e3c)(0);
    piVar3 = param_1[0x11];
    iVar5 = TS_REQ_get_version(piVar3);
    if (iVar5 == 1) {
      unaff_s3 = (int *)0x1;
      uVar8 = TS_REQ_get_msg_imprint(piVar3);
      puVar4 = (undefined4 *)TS_MSG_IMPRINT_get_algo(uVar8);
      iVar5 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar4);
      while( true ) {
        iVar6 = (*(code *)PTR_sk_num_006a7f2c)(param_1[5]);
        if (iVar6 <= (int)unaff_s3 + -1) break;
        iVar6 = (*(code *)PTR_sk_value_006a7f24)(param_1[5],(int)unaff_s3 + -1);
        iVar7 = (*(code *)PTR_EVP_MD_type_006a84cc)(iVar6);
        if ((iVar5 == iVar7) && (iVar6 != 0)) {
          if ((puVar4[1] != 0) && (iVar5 = (*(code *)PTR_ASN1_TYPE_get_006a85b0)(), iVar5 != 5)) {
            pcVar11 = "Superfluous message digest parameter.";
            goto LAB_005c47fc;
          }
          piVar3 = (int *)TS_MSG_IMPRINT_get_msg(uVar8);
          iVar7 = *piVar3;
          iVar5 = (*(code *)PTR_EVP_MD_size_006a8f2c)(iVar6);
          if (iVar7 != iVar5) {
            pcVar11 = "Bad message digest.";
            goto LAB_005c4850;
          }
          iVar5 = TS_REQ_get_policy_id(param_1[0x11]);
          piVar3 = param_1[4];
          if (piVar3 == (int *)0x0) {
            (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x85,0x66,"ts_rsp_sign.c",0x240);
            goto LAB_005c4540;
          }
          if (iVar5 == 0) goto LAB_005c49a4;
          iVar6 = (*(code *)PTR_OBJ_cmp_006a9de4)(iVar5,piVar3);
          if (iVar6 != 0) {
            unaff_s3 = (int *)0x1;
            goto LAB_005c4938;
          }
          piVar3 = param_1[4];
          unaff_s3 = (int *)0x1;
          if (piVar3 != (int *)0x0) goto LAB_005c49a4;
          goto LAB_005c4938;
        }
        unaff_s3 = (int *)((int)unaff_s3 + 1);
      }
      pcVar11 = "Message digest algorithm is not supported.";
LAB_005c47fc:
      TS_RESP_CTX_set_status_info(param_1,2,pcVar11);
      iVar5 = TS_RESP_get_status_info(param_1[0x12]);
      iVar6 = *(int *)(iVar5 + 8);
      if (iVar6 == 0) {
        iVar6 = (*(code *)PTR_ASN1_BIT_STRING_new_006a9784)();
        *(int *)(iVar5 + 8) = iVar6;
        if (iVar6 == 0) goto LAB_005c46b8;
      }
      iVar5 = (*(code *)PTR_ASN1_BIT_STRING_set_bit_006a9ee8)(iVar6,0,1);
      goto joined_r0x005c4888;
    }
    TS_RESP_CTX_set_status_info(param_1,2,"Bad request version.");
    iVar5 = TS_RESP_get_status_info(param_1[0x12]);
    iVar6 = *(int *)(iVar5 + 8);
    if (iVar6 != 0) {
LAB_005c469c:
      iVar5 = (*(code *)PTR_ASN1_BIT_STRING_set_bit_006a9ee8)(iVar6,2,1);
      goto joined_r0x005c4888;
    }
    iVar6 = (*(code *)PTR_ASN1_BIT_STRING_new_006a9784)();
    *(int *)(iVar5 + 8) = iVar6;
    if (iVar6 != 0) goto LAB_005c469c;
  }
LAB_005c46b8:
  (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x7c,0x41,"ts_rsp_sign.c",0x18b);
  goto LAB_005c4540;
LAB_005c4938:
  iVar6 = (*(code *)PTR_sk_num_006a7f2c)(param_1[3]);
  if (iVar6 <= (int)unaff_s3 + -1) goto LAB_005c4a84;
  piVar3 = (int *)(*(code *)PTR_sk_value_006a7f24)(param_1[3],(int)unaff_s3 + -1);
  iVar6 = (*(code *)PTR_OBJ_cmp_006a9de4)(iVar5,piVar3);
  if ((iVar6 == 0) && (piVar3 != (int *)0x0)) {
LAB_005c49a4:
    unaff_s3 = (int *)TS_TST_INFO_new();
    if ((unaff_s3 != (int *)0x0) &&
       ((((iVar5 = TS_TST_INFO_set_version(unaff_s3,1), iVar5 != 0 &&
          (iVar5 = TS_TST_INFO_set_policy_id(unaff_s3,piVar3), iVar5 != 0)) &&
         (iVar5 = TS_TST_INFO_set_msg_imprint(unaff_s3,param_1[0x11][1]), iVar5 != 0)) &&
        (unaff_s7 = (PKCS7_SIGNER_INFO *)(*(code *)param_1[0xb])(param_1,param_1[0xc]),
        unaff_s7 != (PKCS7_SIGNER_INFO *)0x0)))) {
      iVar5 = TS_TST_INFO_set_serial(unaff_s3,unaff_s7);
      if (iVar5 != 0) goto LAB_005c4c3c;
      goto LAB_005c4ba8;
    }
    puVar4 = (undefined4 *)0x0;
    iVar6 = 0;
    iVar5 = 0;
    unaff_s7 = (PKCS7_SIGNER_INFO *)0x0;
    goto LAB_005c49e4;
  }
  unaff_s3 = (int *)((int)unaff_s3 + 1);
  goto LAB_005c4938;
LAB_005c4a84:
  (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x85,0x7d,"ts_rsp_sign.c",0x251);
  TS_RESP_CTX_set_status_info(param_1,2,"Requested policy is not supported.");
  iVar5 = TS_RESP_get_status_info(param_1[0x12]);
  iVar6 = *(int *)(iVar5 + 8);
  if (iVar6 == 0) {
    iVar6 = (*(code *)PTR_ASN1_BIT_STRING_new_006a9784)();
    *(int *)(iVar5 + 8) = iVar6;
    if (iVar6 != 0) goto LAB_005c4adc;
  }
  else {
LAB_005c4adc:
    iVar5 = (*(code *)PTR_ASN1_BIT_STRING_set_bit_006a9ee8)(iVar6,0xf,1);
    if (iVar5 != 0) goto LAB_005c4540;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x7c,0x41,"ts_rsp_sign.c",0x18b);
LAB_005c4540:
  (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x7a,0x79,"ts_rsp_sign.c",0x1d4);
  piVar3 = param_1[0x12];
  if (piVar3 != (int *)0x0) {
    puVar4 = (undefined4 *)TS_RESP_get_status_info(piVar3);
    iVar5 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)(*puVar4);
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
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005c4c3c:
    iVar5 = (*(code *)param_1[0xd])(param_1,param_1[0xe],&local_50,&local_4c);
    uVar8 = local_4c;
    if (iVar5 == 0) break;
    piVar3 = param_1[9];
    local_48 = local_50;
    if (&DAT_00000006 < piVar3) {
LAB_005c4d60:
      puVar4 = (undefined4 *)0x0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x86,0x73,"ts_rsp_sign.c",0x3fa);
      iVar6 = 0;
      iVar5 = 0;
      goto LAB_005c49e4;
    }
    puVar4 = (undefined4 *)(*(code *)PTR_gmtime_006aab04)(&local_48);
    if (puVar4 == (undefined4 *)0x0) goto LAB_005c4d60;
    iVar5 = (*(code *)PTR_BIO_snprintf_006a8060)
                      (auStack_44,0x17,"%04d%02d%02d%02d%02d%02d",puVar4[5] + 0x76c,puVar4[4] + 1,
                       puVar4[3],puVar4[2],puVar4[1],*puVar4);
    puVar13 = auStack_44 + iVar5;
    if (piVar3 != (int *)0x0) {
      (*(code *)PTR_BIO_snprintf_006a8060)
                (puVar13,(undefined *)((int)piVar3 + 2),&DAT_00673634,uVar8);
      iVar5 = (*(code *)PTR_strlen_006aab30)(puVar13);
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
    iVar5 = (*(code *)PTR_ASN1_STRING_type_new_006a97a4)(0x18);
    if (iVar5 == 0) goto LAB_005c4d60;
    iVar6 = (*(code *)PTR_ASN1_GENERALIZEDTIME_set_string_006a80fc)(iVar5,auStack_44);
    if (iVar6 == 0) {
      (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a8138)(iVar5);
      goto LAB_005c4d60;
    }
    iVar6 = TS_TST_INFO_set_time(unaff_s3,iVar5);
    if (iVar6 == 0) {
      puVar4 = (undefined4 *)0x0;
      iVar6 = 0;
      goto LAB_005c49e4;
    }
    if (((param_1[6] != (int *)0x0) || (param_1[7] != (int *)0x0)) || (param_1[8] != (int *)0x0)) {
      iVar6 = TS_ACCURACY_new();
      if (((iVar6 != 0) &&
          ((param_1[6] == (int *)0x0 || (iVar7 = TS_ACCURACY_set_seconds(iVar6), iVar7 != 0)))) &&
         ((param_1[7] == (int *)0x0 || (iVar7 = TS_ACCURACY_set_millis(iVar6), iVar7 != 0)))) {
        if (param_1[8] != (int *)0x0) {
          iVar7 = TS_ACCURACY_set_micros(iVar6);
          if (iVar7 == 0) goto LAB_005c4df0;
          if (iVar6 == 0) goto LAB_005c4e70;
        }
        iVar7 = TS_TST_INFO_set_accuracy(unaff_s3,iVar6);
        if (iVar7 != 0) {
          piVar3 = param_1[10];
          goto LAB_005c4e74;
        }
      }
LAB_005c4df0:
      puVar4 = (undefined4 *)0x0;
      goto LAB_005c49e4;
    }
    iVar6 = 0;
LAB_005c4e70:
    piVar3 = param_1[10];
LAB_005c4e74:
    if (((((uint)piVar3 & 2) != 0) && (iVar7 = TS_TST_INFO_set_ordering(unaff_s3,1), iVar7 == 0)) ||
       ((iVar7 = TS_REQ_get_nonce(param_1[0x11]), iVar7 != 0 &&
        (iVar7 = TS_TST_INFO_set_nonce(unaff_s3,iVar7), iVar7 == 0)))) goto LAB_005c4df0;
    if (((uint)param_1[10] & 1) == 0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = (undefined4 *)(*(code *)PTR_GENERAL_NAME_new_006aa150)();
      puVar13 = PTR_X509_NAME_dup_006a823c;
      if (puVar4 == (undefined4 *)0x0) goto LAB_005c49e4;
      piVar3 = *param_1;
      *puVar4 = 4;
      iVar7 = (*(code *)puVar13)(*(undefined4 *)(*piVar3 + 0x14));
      puVar4[1] = iVar7;
      if ((iVar7 == 0) || (iVar7 = TS_TST_INFO_set_tsa(unaff_s3,puVar4), iVar7 == 0))
      goto LAB_005c49e4;
    }
    (*(code *)PTR_GENERAL_NAME_free_006a84a4)(puVar4);
    TS_ACCURACY_free(iVar6);
    (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a8138)(iVar5);
    (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(unaff_s7);
    param_1[0x13] = unaff_s3;
    unaff_s3 = (int *)TS_REQ_get_exts(param_1[0x11]);
    iVar5 = 0;
    while (iVar6 = (*(code *)PTR_sk_num_006a7f2c)(unaff_s3), iVar5 < iVar6) {
      uVar8 = (*(code *)PTR_sk_value_006a7f24)(unaff_s3,iVar5);
      iVar6 = (*(code *)param_1[0xf])(param_1,uVar8,0);
      iVar5 = iVar5 + 1;
      if (iVar6 == 0) goto LAB_005c4540;
    }
    iVar5 = (*(code *)PTR_X509_check_private_key_006a817c)(*param_1,param_1[1]);
    if (iVar5 == 0) {
      bio = (BIO *)0x0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x88,0x78,"ts_rsp_sign.c",0x2d2);
      unaff_s3 = (int *)0x0;
      p7 = (PKCS7 *)0x0;
      goto LAB_005c4fd0;
    }
    p7 = (PKCS7 *)(*(code *)PTR_PKCS7_new_006a86ac)();
    if (p7 == (PKCS7 *)0x0) {
      uVar12 = 0x41;
      uVar15 = 0x2d8;
      uVar8 = 0x88;
      goto LAB_005c536c;
    }
    iVar5 = (*(code *)PTR_PKCS7_set_type_006aa2ac)(p7,0x16);
    if ((iVar5 == 0) ||
       (iVar5 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(((p7->d).data)->length,3), iVar5 == 0)) {
      bio = (BIO *)0x0;
      unaff_s3 = (int *)0x0;
      goto LAB_005c4fd0;
    }
    iVar5 = TS_REQ_get_cert_req(param_1[0x11]);
    if (iVar5 != 0) {
      (*(code *)PTR_PKCS7_add_certificate_006aa294)(p7,*param_1);
      piVar3 = param_1[2];
      if (piVar3 != (int *)0x0) {
        for (iVar5 = 0; iVar6 = (*(code *)PTR_sk_num_006a7f2c)(piVar3), iVar5 < iVar6;
            iVar5 = iVar5 + 1) {
          uVar8 = (*(code *)PTR_sk_value_006a7f24)(param_1[2],iVar5);
          (*(code *)PTR_PKCS7_add_certificate_006aa294)(p7,uVar8);
          piVar3 = param_1[2];
        }
      }
    }
    piVar3 = *param_1;
    piVar14 = param_1[1];
    uVar8 = (*(code *)PTR_EVP_sha1_006a86c4)();
    unaff_s7 = (PKCS7_SIGNER_INFO *)
               (*(code *)PTR_PKCS7_add_signature_006aa290)(p7,piVar3,piVar14,uVar8);
    if (unaff_s7 == (PKCS7_SIGNER_INFO *)0x0) {
      uVar12 = 0x76;
      uVar15 = 0x2f2;
      uVar8 = 0x88;
LAB_005c536c:
      bio = (BIO *)0x0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,uVar8,uVar12,"ts_rsp_sign.c",uVar15);
      unaff_s3 = (int *)0x0;
      goto LAB_005c4fd0;
    }
    pvVar9 = (void *)(*(code *)PTR_OBJ_nid2obj_006a8240)(0xcf);
    iVar5 = PKCS7_add_signed_attribute(unaff_s7,0x32,6,pvVar9);
    if (iVar5 == 0) {
      uVar12 = 0x77;
      uVar15 = 0x2fb;
      uVar8 = 0x88;
      goto LAB_005c536c;
    }
    piVar3 = (int *)0x0;
    if (((uint)param_1[10] & 4) != 0) {
      piVar3 = param_1[2];
    }
    piVar14 = *param_1;
    unaff_s3 = (int *)ESS_SIGNING_CERT_new();
    if (unaff_s3 == (int *)0x0) {
LAB_005c5344:
      ESS_SIGNING_CERT_free(unaff_s3);
      uVar12 = 0x41;
      uVar8 = 0x72;
      uVar15 = 0x350;
      goto LAB_005c536c;
    }
    if (*unaff_s3 == 0) {
      iVar5 = (*(code *)PTR_sk_new_null_006a80a4)();
      *unaff_s3 = iVar5;
      if (iVar5 == 0) goto LAB_005c5344;
    }
    (*(code *)PTR_X509_check_purpose_006a87e8)(piVar14,0xffffffff,0);
    puVar4 = (undefined4 *)ESS_CERT_ID_new();
    if ((puVar4 == (undefined4 *)0x0) ||
       (iVar5 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)(*puVar4,piVar14 + 0x14,0x14),
       iVar5 == 0)) {
      puVar10 = (undefined4 *)0x0;
LAB_005c5300:
      (*(code *)PTR_GENERAL_NAME_free_006a84a4)(puVar10);
      ESS_CERT_ID_free(puVar4);
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x71,0x41,"ts_rsp_sign.c",0x37b);
      goto LAB_005c5344;
    }
    iVar5 = (*(code *)PTR_sk_push_006a80a8)(*unaff_s3,puVar4);
    if (iVar5 == 0) goto LAB_005c5344;
    for (iVar5 = 0; iVar6 = (*(code *)PTR_sk_num_006a7f2c)(piVar3), iVar5 < iVar6; iVar5 = iVar5 + 1
        ) {
      piVar14 = (int *)(*(code *)PTR_sk_value_006a7f24)(piVar3,iVar5);
      (*(code *)PTR_X509_check_purpose_006a87e8)(piVar14,0xffffffff,0);
      puVar4 = (undefined4 *)ESS_CERT_ID_new();
      if ((puVar4 == (undefined4 *)0x0) ||
         (iVar6 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)(*puVar4,piVar14 + 0x14,0x14),
         iVar6 == 0)) {
LAB_005c53b8:
        puVar10 = (undefined4 *)0x0;
        goto LAB_005c5300;
      }
      if (puVar4[1] == 0) {
        iVar6 = ESS_ISSUER_SERIAL_new();
        puVar4[1] = iVar6;
        if (iVar6 == 0) goto LAB_005c53b8;
      }
      puVar10 = (undefined4 *)(*(code *)PTR_GENERAL_NAME_new_006aa150)();
      puVar13 = PTR_X509_NAME_dup_006a823c;
      if (puVar10 == (undefined4 *)0x0) goto LAB_005c53b8;
      iVar6 = *piVar14;
      *puVar10 = 4;
      iVar6 = (*(code *)puVar13)(*(undefined4 *)(iVar6 + 0xc));
      puVar10[1] = iVar6;
      if ((iVar6 == 0) ||
         (iVar6 = (*(code *)PTR_sk_push_006a80a8)(*(undefined4 *)puVar4[1],puVar10), iVar6 == 0))
      goto LAB_005c5300;
      (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(*(undefined4 *)(puVar4[1] + 4));
      iVar7 = puVar4[1];
      iVar6 = (*(code *)PTR_ASN1_INTEGER_dup_006aa37c)(*(undefined4 *)(*piVar14 + 4));
      *(int *)(iVar7 + 4) = iVar6;
      if (iVar6 == 0) goto LAB_005c53b8;
      iVar6 = (*(code *)PTR_sk_push_006a80a8)(*unaff_s3,puVar4);
      if (iVar6 == 0) goto LAB_005c5344;
    }
    uVar8 = i2d_ESS_SIGNING_CERT(unaff_s3,0);
    iVar5 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar8,"ts_rsp_sign.c",0x39d);
    if (iVar5 == 0) {
      pvVar9 = (void *)0x0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x70,0x41,"ts_rsp_sign.c",0x39f);
LAB_005c546c:
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(pvVar9);
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar5);
LAB_005c548c:
      bio = (BIO *)0x0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x88,0x74,"ts_rsp_sign.c",0x308);
      goto LAB_005c4fd0;
    }
    local_48 = iVar5;
    i2d_ESS_SIGNING_CERT(unaff_s3,&local_48);
    pvVar9 = (void *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if ((pvVar9 == (void *)0x0) ||
       (iVar6 = (*(code *)PTR_ASN1_STRING_set_006a8e0c)(pvVar9,iVar5,uVar8), iVar6 == 0)) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x70,0x41,"ts_rsp_sign.c",0x3a6);
      goto LAB_005c546c;
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar5);
    iVar5 = PKCS7_add_signed_attribute(unaff_s7,0xdf,0x10,pvVar9);
    if (iVar5 == 0) goto LAB_005c548c;
    iVar5 = (*(code *)PTR_PKCS7_new_006a86ac)();
    if (iVar5 == 0) {
LAB_005c56d0:
      (*(code *)PTR_ASN1_OCTET_STRING_free_006a9e1c)(0);
      bio = (BIO *)0x0;
      (*(code *)PTR_PKCS7_free_006a8350)(iVar5);
      goto LAB_005c4fd0;
    }
    iVar6 = (*(code *)PTR_ASN1_TYPE_new_006a8fbc)();
    *(int *)(iVar5 + 0x14) = iVar6;
    if (iVar6 == 0) goto LAB_005c56d0;
    uVar8 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0xcf);
    puVar13 = PTR_ASN1_OCTET_STRING_new_006a978c;
    *(undefined4 *)(iVar5 + 0x10) = uVar8;
    iVar6 = (*(code *)puVar13)();
    if (iVar6 == 0) goto LAB_005c56d0;
    (*(code *)PTR_ASN1_TYPE_set_006a9dfc)(*(undefined4 *)(iVar5 + 0x14),4,iVar6);
    iVar6 = (*(code *)PTR_PKCS7_set_content_006aa5e0)(p7,iVar5);
    if (iVar6 == 0) goto LAB_005c56d0;
    bio = (BIO *)(*(code *)PTR_PKCS7_dataInit_006aa21c)(p7,0);
    if (bio == (BIO *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x88,0x41,"ts_rsp_sign.c",0x311);
      goto LAB_005c4fd0;
    }
    iVar5 = i2d_TS_TST_INFO_bio(bio,param_1[0x13]);
    if (iVar5 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x88,0x7c,"ts_rsp_sign.c",0x318);
      goto LAB_005c4fd0;
    }
    iVar5 = PKCS7_dataFinal(p7,bio);
    if (iVar5 == 0) goto code_r0x005c57b0;
    TS_RESP_set_tst_info(param_1[0x12],p7,param_1[0x13]);
    puVar13 = PTR_BIO_free_all_006a7f74;
    param_1[0x13] = (int *)0x0;
    (*(code *)puVar13)(bio);
    ESS_SIGNING_CERT_free(unaff_s3);
    (*(code *)PTR_PKCS7_free_006a8350)(0);
    piVar3 = param_1[0x12];
  } while( true );
LAB_005c4ba8:
  puVar4 = (undefined4 *)0x0;
  iVar6 = 0;
  iVar5 = 0;
LAB_005c49e4:
  TS_TST_INFO_free(unaff_s3);
  (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x7b,0x7b,"ts_rsp_sign.c",0x29f);
  TS_RESP_CTX_set_status_info_cond(param_1,2,"Error during TSTInfo generation.");
  (*(code *)PTR_GENERAL_NAME_free_006a84a4)(puVar4);
  TS_ACCURACY_free(iVar6);
  (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a8138)(iVar5);
  (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(unaff_s7);
  param_1[0x13] = (int *)0x0;
  goto LAB_005c4540;
code_r0x005c57b0:
  (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x88,0x7c,"ts_rsp_sign.c",799);
LAB_005c4fd0:
  puVar4 = (undefined4 *)TS_RESP_get_status_info(param_1[0x12]);
  iVar5 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)(*puVar4);
  if (iVar5 == 0) {
    TS_RESP_CTX_set_status_info(param_1,2,"Error during signature generation.");
  }
  (*(code *)PTR_BIO_free_all_006a7f74)(bio);
  ESS_SIGNING_CERT_free(unaff_s3);
  (*(code *)PTR_PKCS7_free_006a8350)(p7);
  goto LAB_005c4540;
}

