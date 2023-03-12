
PKCS7 * TS_RESP_verify_signature
                  (PKCS7 *param_1,stack_st_X509 *param_2,undefined4 param_3,int *param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  PKCS7_SIGNER_INFO *si;
  ASN1_TYPE *pAVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  stack_st_X509 *psVar11;
  undefined4 uVar12;
  uchar *local_10b4 [34];
  undefined auStack_102c [4096];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_1 == (PKCS7 *)0x0) {
    uVar12 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x6a,0x66,"ts_rsp_verify.c",0x9b);
    uVar4 = 0;
    psVar11 = (stack_st_X509 *)0x0;
    goto LAB_005c5fe0;
  }
  iVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(param_1->type);
  if (iVar3 == 0x16) {
    iVar3 = (*(code *)PTR_PKCS7_get_signer_info_006aa29c)(param_1);
    if (iVar3 != 0) {
      iVar5 = (*(code *)PTR_sk_num_006a7f2c)(iVar3);
      if (iVar5 == 1) {
        si = (PKCS7_SIGNER_INFO *)(*(code *)PTR_sk_value_006a7f24)(iVar3,0);
        iVar3 = (*(code *)PTR_PKCS7_ctrl_006aa268)(param_1,2,0,0);
        if (iVar3 == 0) {
          psVar11 = PKCS7_get0_signers(param_1,param_2,0);
          if (psVar11 != (stack_st_X509 *)0x0) {
            iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psVar11);
            if (iVar3 == 1) {
              iVar3 = (*(code *)PTR_sk_value_006a7f24)(psVar11,0);
              (*(code *)PTR_X509_STORE_CTX_init_006a8304)(local_10b4,param_3,iVar3,param_2);
              (*(code *)PTR_X509_STORE_CTX_set_purpose_006aa284)(local_10b4,9);
              iVar5 = (*(code *)PTR_X509_verify_cert_006a8308)(local_10b4);
              if (iVar5 < 1) {
                uVar12 = 0;
                uVar4 = (*(code *)PTR_X509_STORE_CTX_get_error_006a8314)(local_10b4);
                (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x6d,100,"ts_rsp_verify.c",0xf6);
                param_1 = (PKCS7 *)0x0;
                uVar4 = (*(code *)PTR_X509_verify_cert_error_string_006a839c)(uVar4);
                (*(code *)PTR_ERR_add_error_data_006a9264)(2,"Verify error:",uVar4);
                uVar4 = 0;
                (*(code *)PTR_X509_STORE_CTX_cleanup_006a8310)(local_10b4);
              }
              else {
                uVar12 = (*(code *)PTR_X509_STORE_CTX_get1_chain_006a830c)(local_10b4);
                (*(code *)PTR_X509_STORE_CTX_cleanup_006a8310)(local_10b4);
                pAVar6 = PKCS7_get_signed_attribute(si,0xdf);
                if (pAVar6 == (ASN1_TYPE *)0x0) {
                  piVar7 = (int *)0x0;
                }
                else {
                  local_10b4[0] = ((pAVar6->value).asn1_string)->data;
                  piVar7 = (int *)d2i_ESS_SIGNING_CERT
                                            (0,local_10b4,((pAVar6->value).asn1_string)->length);
                  if (piVar7 != (int *)0x0) {
                    iVar5 = *piVar7;
                    iVar8 = (*(code *)PTR_sk_value_006a7f24)(uVar12,0);
                    if ((iVar5 != 0) && (iVar8 != 0)) {
                      (*(code *)PTR_X509_check_purpose_006a87e8)(iVar8,0xffffffff,0);
                      iVar8 = TS_find_cert_part_0(iVar5,iVar8);
                      if (iVar8 == 0) {
                        iVar8 = (*(code *)PTR_sk_num_006a7f2c)(iVar5);
                        if (1 < iVar8) {
                          iVar8 = 1;
                          while( true ) {
                            iVar9 = (*(code *)PTR_sk_num_006a7f2c)(uVar12);
                            if (iVar9 <= iVar8) break;
                            iVar9 = (*(code *)PTR_sk_value_006a7f24)(uVar12,iVar8);
                            if (iVar9 == 0) goto LAB_005c6288;
                            (*(code *)PTR_X509_check_purpose_006a87e8)(iVar9,0xffffffff,0);
                            iVar9 = TS_find_cert_part_0(iVar5,iVar9);
                            if (iVar9 < 0) goto LAB_005c6288;
                            iVar8 = iVar8 + 1;
                          }
                        }
                        ESS_SIGNING_CERT_free(piVar7);
                        uVar4 = (*(code *)PTR_PKCS7_dataInit_006aa21c)(param_1,0);
                        do {
                          iVar5 = (*(code *)PTR_BIO_read_006a85bc)(uVar4,auStack_102c,0x1000);
                        } while (0 < iVar5);
                        iVar5 = (*(code *)PTR_PKCS7_signatureVerify_006aa2b8)
                                          (uVar4,param_1,si,iVar3);
                        puVar1 = PTR_CRYPTO_add_lock_006a9080;
                        if (iVar5 < 1) {
                          param_1 = (PKCS7 *)0x0;
                          (*(code *)PTR_ERR_put_error_006a9030)
                                    (0x2f,0x6a,0x6d,"ts_rsp_verify.c",0xce);
                        }
                        else {
                          if (param_4 == (int *)0x0) goto LAB_005c6484;
                          *param_4 = iVar3;
                          param_1 = (PKCS7 *)0x1;
                          (*(code *)puVar1)(iVar3 + 0x10,1,3,"ts_rsp_verify.c",0xd6);
                        }
                        goto LAB_005c5fe0;
                      }
                    }
                  }
                }
LAB_005c6288:
                uVar4 = 0;
                (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x67,0x65,"ts_rsp_verify.c",0x123);
                param_1 = (PKCS7 *)0x0;
                ESS_SIGNING_CERT_free(piVar7);
              }
              goto LAB_005c5fe0;
            }
          }
          uVar12 = 0;
          uVar4 = 0;
          param_1 = (PKCS7 *)0x0;
          goto LAB_005c5fe0;
        }
        uVar10 = 0x6a;
        uVar4 = 0xb3;
        goto LAB_005c5fbc;
      }
    }
    uVar10 = 0x6e;
    uVar4 = 0xab;
  }
  else {
    uVar10 = 0x72;
    uVar4 = 0xa2;
  }
LAB_005c5fbc:
  uVar12 = 0;
  (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x6a,uVar10,"ts_rsp_verify.c",uVar4);
  uVar4 = 0;
  param_1 = (PKCS7 *)0x0;
  psVar11 = (stack_st_X509 *)0x0;
LAB_005c5fe0:
  while( true ) {
    (*(code *)PTR_BIO_free_all_006a7f74)(uVar4);
    (*(code *)PTR_sk_pop_free_006a8158)(uVar12,PTR_X509_free_006a7f90);
    (*(code *)PTR_sk_free_006a7f80)(psVar11);
    if (local_2c == *(int *)puVar2) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005c6484:
    param_1 = (PKCS7 *)0x1;
  }
  return param_1;
}

