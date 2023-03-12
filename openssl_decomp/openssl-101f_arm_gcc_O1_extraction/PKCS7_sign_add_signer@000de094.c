
PKCS7_SIGNER_INFO *
PKCS7_sign_add_signer(PKCS7 *p7,X509 *signcert,EVP_PKEY *pkey,EVP_MD *md,int flags)

{
  int iVar1;
  PKCS7_SIGNER_INFO *si;
  _STACK *p_Var2;
  int iVar3;
  PKCS7_SIGNER_INFO *pPVar4;
  ASN1_OCTET_STRING *pAVar5;
  char *pcVar6;
  EVP_CIPHER *pEVar7;
  EVP_MD *pEVar8;
  int iVar9;
  
  iVar1 = X509_check_private_key(signcert,pkey);
  if (iVar1 == 0) {
    ERR_put_error(0x21,0x89,0x7f,"pk7_smime.c",0xaa);
    return (PKCS7_SIGNER_INFO *)0x0;
  }
  si = PKCS7_add_signature(p7,signcert,pkey,md);
  if (si == (PKCS7_SIGNER_INFO *)0x0) {
    ERR_put_error(0x21,0x89,0x7c,"pk7_smime.c",0xb1);
    return (PKCS7_SIGNER_INFO *)0x0;
  }
  if ((-1 < flags << 0x1e) && (iVar1 = PKCS7_add_certificate(p7,signcert), iVar1 == 0)) {
    return (PKCS7_SIGNER_INFO *)0x0;
  }
  if ((flags & 0x100U) != 0) {
    return si;
  }
  iVar1 = PKCS7_add_attrib_content_type(si,(ASN1_OBJECT *)0x0);
  if (iVar1 == 0) {
    return (PKCS7_SIGNER_INFO *)0x0;
  }
  if (flags << 0x16 < 0) {
LAB_000de0e0:
    if (flags << 0x10 < 0) {
      p_Var2 = (_STACK *)PKCS7_get_signer_info(p7);
      iVar1 = 0;
      do {
        iVar3 = sk_num(p_Var2);
        iVar9 = iVar1 + 1;
        if ((iVar3 <= iVar1) || (pPVar4 = (PKCS7_SIGNER_INFO *)sk_value(p_Var2,iVar1), si == pPVar4)
           ) goto LAB_000de2a8;
        iVar3 = sk_num((_STACK *)pPVar4->auth_attr);
        iVar1 = iVar9;
      } while ((iVar3 < 1) ||
              (iVar3 = OBJ_cmp(si->digest_alg->algorithm,pPVar4->digest_alg->algorithm), iVar3 != 0)
              );
      pAVar5 = PKCS7_digest_from_attributes(pPVar4->auth_attr);
      if (pAVar5 == (ASN1_OCTET_STRING *)0x0) {
LAB_000de2a8:
        ERR_put_error(0x21,0x8a,0x9a,"pk7_smime.c",0x106);
      }
      else {
        iVar1 = PKCS7_add1_attrib_digest(si,pAVar5->data,pAVar5->length);
        if (iVar1 != 0) {
          if (flags << 0x11 < 0) {
            return si;
          }
          iVar1 = PKCS7_SIGNER_INFO_sign(si);
          if (iVar1 != 0) {
            return si;
          }
        }
      }
      return (PKCS7_SIGNER_INFO *)0x0;
    }
  }
  else {
    p_Var2 = sk_new_null();
    if (p_Var2 == (_STACK *)0x0) {
      ERR_put_error(0x21,0x89,0x41,"pk7_smime.c",0xc5);
      return (PKCS7_SIGNER_INFO *)0x0;
    }
    pcVar6 = OBJ_nid2sn(0x1ab);
    pEVar7 = EVP_get_cipherbyname(pcVar6);
    if ((pEVar7 == (EVP_CIPHER *)0x0) ||
       (iVar1 = PKCS7_simple_smimecap((stack_st_X509_ALGOR *)p_Var2,0x1ab,-1), iVar1 != 0)) {
      pcVar6 = OBJ_nid2sn(0x329);
      pEVar8 = EVP_get_digestbyname(pcVar6);
      if ((pEVar8 == (EVP_MD *)0x0) ||
         (iVar1 = PKCS7_simple_smimecap((stack_st_X509_ALGOR *)p_Var2,0x329,-1), iVar1 != 0)) {
        pcVar6 = OBJ_nid2sn(0x32d);
        pEVar7 = EVP_get_cipherbyname(pcVar6);
        if ((((((pEVar7 == (EVP_CIPHER *)0x0) ||
               (iVar1 = PKCS7_simple_smimecap((stack_st_X509_ALGOR *)p_Var2,0x32d,-1), iVar1 != 0))
              && (iVar1 = add_cipher_smcap(p_Var2,0x1a7,0xffffffff), iVar1 != 0)) &&
             ((iVar1 = add_cipher_smcap(p_Var2,0x1a3,0xffffffff), iVar1 != 0 &&
              (iVar1 = add_cipher_smcap(p_Var2,0x2c,0xffffffff), iVar1 != 0)))) &&
            (iVar1 = add_cipher_smcap(p_Var2,0x25,0x80), iVar1 != 0)) &&
           (((iVar1 = add_cipher_smcap(p_Var2,0x25,0x40), iVar1 != 0 &&
             (iVar1 = add_cipher_smcap(p_Var2,0x1f,0xffffffff), iVar1 != 0)) &&
            ((iVar1 = add_cipher_smcap(p_Var2,0x25,0x28), iVar1 != 0 &&
             (iVar1 = PKCS7_add_attrib_smimecap(si,(stack_st_X509_ALGOR *)p_Var2), iVar1 != 0))))))
        {
          sk_pop_free(p_Var2,X509_ALGOR_free + 1);
          goto LAB_000de0e0;
        }
      }
    }
    sk_pop_free(p_Var2,X509_ALGOR_free + 1);
    si = (PKCS7_SIGNER_INFO *)0x0;
  }
  return si;
}

