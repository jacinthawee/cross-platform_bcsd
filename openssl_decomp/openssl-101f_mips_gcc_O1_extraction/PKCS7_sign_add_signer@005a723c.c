
PKCS7_SIGNER_INFO *
PKCS7_sign_add_signer(PKCS7 *p7,X509 *signcert,EVP_PKEY *pkey,EVP_MD *md,int flags)

{
  int iVar1;
  PKCS7_SIGNER_INFO *si;
  stack_st_PKCS7_SIGNER_INFO *psVar2;
  int iVar3;
  PKCS7_SIGNER_INFO *pPVar4;
  ASN1_OCTET_STRING *pAVar5;
  stack_st_X509_ALGOR *sk;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  
  iVar1 = (*(code *)PTR_X509_check_private_key_006a817c)(signcert,pkey);
  if (iVar1 == 0) {
    uVar7 = 0x7f;
    uVar6 = 0xaa;
  }
  else {
    si = PKCS7_add_signature(p7,signcert,pkey,md);
    if (si != (PKCS7_SIGNER_INFO *)0x0) {
      if (((flags & 2U) == 0) && (iVar1 = PKCS7_add_certificate(p7,signcert), iVar1 == 0)) {
        return (PKCS7_SIGNER_INFO *)0x0;
      }
      if ((flags & 0x100U) == 0) {
        iVar1 = PKCS7_add_attrib_content_type(si,(ASN1_OBJECT *)0x0);
        if (iVar1 == 0) {
          return (PKCS7_SIGNER_INFO *)0x0;
        }
        if ((flags & 0x200U) == 0) {
          sk = (stack_st_X509_ALGOR *)(*(code *)PTR_sk_new_null_006a80a4)();
          if (sk == (stack_st_X509_ALGOR *)0x0) {
            (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x89,0x41,"pk7_smime.c",0xc5);
            return (PKCS7_SIGNER_INFO *)0x0;
          }
          uVar6 = (*(code *)PTR_OBJ_nid2sn_006a819c)(0x1ab);
          iVar1 = (*(code *)PTR_EVP_get_cipherbyname_006a8494)(uVar6);
          if ((iVar1 != 0) && (iVar1 = PKCS7_simple_smimecap(sk,0x1ab,-1), iVar1 == 0)) {
LAB_005a74d0:
            (*(code *)PTR_sk_pop_free_006a8158)(sk,PTR_X509_ALGOR_free_006a8f94);
            return (PKCS7_SIGNER_INFO *)0x0;
          }
          uVar6 = (*(code *)PTR_OBJ_nid2sn_006a819c)(0x329);
          iVar1 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar6);
          if ((iVar1 != 0) && (iVar1 = PKCS7_simple_smimecap(sk,0x329,-1), iVar1 == 0))
          goto LAB_005a74d0;
          uVar6 = (*(code *)PTR_OBJ_nid2sn_006a819c)(0x32d);
          iVar1 = (*(code *)PTR_EVP_get_cipherbyname_006a8494)(uVar6);
          if ((((((iVar1 != 0) && (iVar1 = PKCS7_simple_smimecap(sk,0x32d,-1), iVar1 == 0)) ||
                (iVar1 = add_cipher_smcap(sk,0x1a7,0xffffffff), iVar1 == 0)) ||
               ((iVar1 = add_cipher_smcap(sk,0x1a3,0xffffffff), iVar1 == 0 ||
                (iVar1 = add_cipher_smcap(sk,0x2c,0xffffffff), iVar1 == 0)))) ||
              (iVar1 = add_cipher_smcap(sk,0x25,0x80), iVar1 == 0)) ||
             (((iVar1 = add_cipher_smcap(sk,0x25,0x40), iVar1 == 0 ||
               (iVar1 = add_cipher_smcap(sk,0x1f,0xffffffff), iVar1 == 0)) ||
              ((iVar1 = add_cipher_smcap(sk,0x25,0x28), iVar1 == 0 ||
               (iVar1 = PKCS7_add_attrib_smimecap(si,sk), iVar1 == 0)))))) goto LAB_005a74d0;
          (*(code *)PTR_sk_pop_free_006a8158)(sk,PTR_X509_ALGOR_free_006a8f94);
        }
        if ((flags & 0x8000U) != 0) {
          psVar2 = PKCS7_get_signer_info(p7);
          iVar1 = 0;
          do {
            iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psVar2);
            iVar8 = iVar1 + 1;
            if ((iVar3 <= iVar1) ||
               (pPVar4 = (PKCS7_SIGNER_INFO *)(*(code *)PTR_sk_value_006a7f24)(psVar2,iVar1),
               si == pPVar4)) goto LAB_005a7504;
            iVar3 = (*(code *)PTR_sk_num_006a7f2c)(pPVar4->auth_attr);
            iVar1 = iVar8;
          } while ((iVar3 < 1) ||
                  (iVar3 = (*(code *)PTR_OBJ_cmp_006a9de4)
                                     (si->digest_alg->algorithm,pPVar4->digest_alg->algorithm),
                  iVar3 != 0));
          pAVar5 = PKCS7_digest_from_attributes(pPVar4->auth_attr);
          if (pAVar5 == (ASN1_OCTET_STRING *)0x0) {
LAB_005a7504:
            (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x8a,0x9a,"pk7_smime.c",0x106);
            si = (PKCS7_SIGNER_INFO *)0x0;
          }
          else {
            iVar1 = PKCS7_add1_attrib_digest(si,pAVar5->data,pAVar5->length);
            if (iVar1 == 0) {
              return (PKCS7_SIGNER_INFO *)0x0;
            }
            if (((flags & 0x4000U) == 0) && (iVar1 = PKCS7_SIGNER_INFO_sign(si), iVar1 == 0)) {
              return (PKCS7_SIGNER_INFO *)0x0;
            }
          }
        }
      }
      return si;
    }
    uVar7 = 0x7c;
    uVar6 = 0xb1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x89,uVar7,"pk7_smime.c",uVar6);
  return (PKCS7_SIGNER_INFO *)0x0;
}

