
OCSP_CERTID * OCSP_cert_to_id(EVP_MD *dgst,X509 *subject,X509 *issuer)

{
  X509_NAME *data;
  ASN1_BIT_STRING *pAVar1;
  OCSP_CERTID *a;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  ASN1_TYPE *pAVar4;
  ASN1_STRING *pAVar5;
  X509_ALGOR *pXVar6;
  uint local_68;
  uchar auStack_64 [64];
  int local_24;
  
  local_24 = __TMC_END__;
  if (dgst == (EVP_MD *)0x0) {
    dgst = EVP_sha1();
  }
  if (subject == (X509 *)0x0) {
    data = X509_get_subject_name(issuer);
    pAVar1 = X509_get0_pubkey_bitstr(issuer);
    a = OCSP_CERTID_new();
  }
  else {
    data = X509_get_issuer_name(subject);
    subject = (X509 *)X509_get_serialNumber(subject);
    pAVar1 = X509_get0_pubkey_bitstr(issuer);
    a = OCSP_CERTID_new();
  }
  if (a == (OCSP_CERTID *)0x0) goto LAB_000e1f2c;
  pXVar6 = a->hashAlgorithm;
  if (pXVar6->algorithm != (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free(pXVar6->algorithm);
  }
  iVar2 = EVP_MD_type(dgst);
  if (iVar2 == 0) {
    ERR_put_error(0x27,0x65,0x78,"ocsp_lib.c",0x74);
  }
  else {
    pAVar3 = OBJ_nid2obj(iVar2);
    pXVar6->algorithm = pAVar3;
    if (pAVar3 != (ASN1_OBJECT *)0x0) {
      pAVar4 = ASN1_TYPE_new();
      pXVar6->parameter = pAVar4;
      if (pAVar4 != (ASN1_TYPE *)0x0) {
        pAVar4->type = 5;
        iVar2 = X509_NAME_digest(data,dgst,auStack_64,&local_68);
        if (iVar2 == 0) {
          ERR_put_error(0x27,0x65,0x66,"ocsp_lib.c",0x8b);
        }
        else {
          iVar2 = ASN1_OCTET_STRING_set(a->issuerNameHash,auStack_64,local_68);
          if (((iVar2 != 0) &&
              (iVar2 = EVP_Digest(pAVar1->data,pAVar1->length,auStack_64,&local_68,dgst,
                                  (ENGINE *)0x0), iVar2 != 0)) &&
             (iVar2 = ASN1_OCTET_STRING_set(a->issuerKeyHash,auStack_64,local_68), iVar2 != 0)) {
            if (subject == (X509 *)0x0) goto LAB_000e1f2c;
            ASN1_INTEGER_free(a->serialNumber);
            pAVar5 = ASN1_INTEGER_dup((ASN1_STRING *)subject);
            a->serialNumber = pAVar5;
            if (pAVar5 != (ASN1_STRING *)0x0) goto LAB_000e1f2c;
          }
        }
      }
    }
  }
  OCSP_CERTID_free(a);
  a = (OCSP_CERTID *)0x0;
LAB_000e1f2c:
  if (local_24 == __TMC_END__) {
    return a;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

