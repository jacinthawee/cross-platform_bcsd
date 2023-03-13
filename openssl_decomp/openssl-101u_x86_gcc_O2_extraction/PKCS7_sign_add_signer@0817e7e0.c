
PKCS7_SIGNER_INFO *
PKCS7_sign_add_signer(PKCS7 *p7,X509 *signcert,EVP_PKEY *pkey,EVP_MD *md,int flags)

{
  int iVar1;
  PKCS7_SIGNER_INFO *si;
  _STACK *p_Var2;
  PKCS7_SIGNER_INFO *pPVar3;
  int iVar4;
  char *pcVar5;
  EVP_CIPHER *pEVar6;
  EVP_MD *pEVar7;
  ASN1_OCTET_STRING *pAVar8;
  
  iVar1 = X509_check_private_key(signcert,pkey);
  if (iVar1 == 0) {
    iVar4 = 0xa3;
    iVar1 = 0x7f;
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
          p_Var2 = sk_new_null();
          if (p_Var2 == (_STACK *)0x0) {
            ERR_put_error(0x21,0x89,0x41,"pk7_smime.c",0xb8);
            return (PKCS7_SIGNER_INFO *)0x0;
          }
          pcVar5 = OBJ_nid2sn(0x1ab);
          pEVar6 = EVP_get_cipherbyname(pcVar5);
          if ((pEVar6 != (EVP_CIPHER *)0x0) &&
             (iVar1 = PKCS7_simple_smimecap((stack_st_X509_ALGOR *)p_Var2,0x1ab,-1), iVar1 == 0)) {
LAB_0817e9ca:
            sk_pop_free(p_Var2,X509_ALGOR_free);
            return (PKCS7_SIGNER_INFO *)0x0;
          }
          pcVar5 = OBJ_nid2sn(0x329);
          pEVar7 = EVP_get_digestbyname(pcVar5);
          if ((pEVar7 != (EVP_MD *)0x0) &&
             (iVar1 = PKCS7_simple_smimecap((stack_st_X509_ALGOR *)p_Var2,0x329,-1), iVar1 == 0))
          goto LAB_0817e9ca;
          pcVar5 = OBJ_nid2sn(0x32d);
          pEVar6 = EVP_get_cipherbyname(pcVar5);
          if ((((((pEVar6 != (EVP_CIPHER *)0x0) &&
                 (iVar1 = PKCS7_simple_smimecap((stack_st_X509_ALGOR *)p_Var2,0x32d,-1), iVar1 == 0)
                 ) || (iVar1 = add_cipher_smcap(), iVar1 == 0)) ||
               ((iVar1 = add_cipher_smcap(), iVar1 == 0 || (iVar1 = add_cipher_smcap(), iVar1 == 0))
               )) || (iVar1 = add_cipher_smcap(), iVar1 == 0)) ||
             (((iVar1 = add_cipher_smcap(), iVar1 == 0 || (iVar1 = add_cipher_smcap(), iVar1 == 0))
              || ((iVar1 = add_cipher_smcap(), iVar1 == 0 ||
                  (iVar1 = PKCS7_add_attrib_smimecap(si,(stack_st_X509_ALGOR *)p_Var2), iVar1 == 0))
                 )))) goto LAB_0817e9ca;
          sk_pop_free(p_Var2,X509_ALGOR_free);
        }
        if ((flags & 0x8000U) != 0) {
          iVar1 = 0;
          p_Var2 = (_STACK *)PKCS7_get_signer_info(p7);
          while( true ) {
            iVar4 = sk_num(p_Var2);
            if ((iVar4 <= iVar1) ||
               (pPVar3 = (PKCS7_SIGNER_INFO *)sk_value(p_Var2,iVar1), si == pPVar3))
            goto LAB_0817e8dd;
            iVar4 = sk_num((_STACK *)pPVar3->auth_attr);
            if ((0 < iVar4) &&
               (iVar4 = OBJ_cmp(si->digest_alg->algorithm,pPVar3->digest_alg->algorithm), iVar4 == 0
               )) break;
            iVar1 = iVar1 + 1;
          }
          pAVar8 = PKCS7_digest_from_attributes(pPVar3->auth_attr);
          if (pAVar8 != (ASN1_OCTET_STRING *)0x0) {
            iVar1 = PKCS7_add1_attrib_digest(si,pAVar8->data,pAVar8->length);
            if (iVar1 == 0) {
              return (PKCS7_SIGNER_INFO *)0x0;
            }
            if ((flags & 0x4000U) != 0) {
              return si;
            }
            iVar1 = PKCS7_SIGNER_INFO_sign(si);
            if (iVar1 != 0) {
              return si;
            }
            return (PKCS7_SIGNER_INFO *)0x0;
          }
LAB_0817e8dd:
          si = (PKCS7_SIGNER_INFO *)0x0;
          ERR_put_error(0x21,0x8a,0x9a,"pk7_smime.c",0xf5);
        }
      }
      return si;
    }
    iVar4 = 0xa9;
    iVar1 = 0x7c;
  }
  ERR_put_error(0x21,0x89,iVar1,"pk7_smime.c",iVar4);
  return (PKCS7_SIGNER_INFO *)0x0;
}

