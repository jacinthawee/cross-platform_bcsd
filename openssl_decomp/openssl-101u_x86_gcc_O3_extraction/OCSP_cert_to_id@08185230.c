
OCSP_CERTID * OCSP_cert_to_id(EVP_MD *dgst,X509 *subject,X509 *issuer)

{
  X509_ALGOR *pXVar1;
  X509_NAME *data;
  ASN1_BIT_STRING *pAVar2;
  OCSP_CERTID *a;
  int iVar3;
  ASN1_OBJECT *pAVar4;
  ASN1_TYPE *pAVar5;
  ASN1_STRING *pAVar6;
  int in_GS_OFFSET;
  ASN1_INTEGER *local_70;
  uint local_64;
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (dgst == (EVP_MD *)0x0) {
    dgst = EVP_sha1();
  }
  if (subject == (X509 *)0x0) {
    data = X509_get_subject_name(issuer);
    local_70 = (ASN1_STRING *)0x0;
  }
  else {
    data = X509_get_issuer_name(subject);
    local_70 = X509_get_serialNumber(subject);
  }
  pAVar2 = X509_get0_pubkey_bitstr(issuer);
  a = OCSP_CERTID_new();
  if (a == (OCSP_CERTID *)0x0) {
    a = (OCSP_CERTID *)0x0;
    goto LAB_081852eb;
  }
  pXVar1 = a->hashAlgorithm;
  if (pXVar1->algorithm != (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free(pXVar1->algorithm);
  }
  iVar3 = EVP_MD_type(dgst);
  if (iVar3 == 0) {
    ERR_put_error(0x27,0x65,0x78,"ocsp_lib.c",0x75);
  }
  else {
    pAVar4 = OBJ_nid2obj(iVar3);
    pXVar1->algorithm = pAVar4;
    if (pAVar4 != (ASN1_OBJECT *)0x0) {
      pAVar5 = ASN1_TYPE_new();
      pXVar1->parameter = pAVar5;
      if (pAVar5 != (ASN1_TYPE *)0x0) {
        pAVar5->type = 5;
        iVar3 = X509_NAME_digest(data,dgst,local_60,&local_64);
        if (iVar3 == 0) {
          ERR_put_error(0x27,0x65,0x66,"ocsp_lib.c",0x91);
        }
        else {
          iVar3 = ASN1_OCTET_STRING_set(a->issuerNameHash,local_60,local_64);
          if (((iVar3 != 0) &&
              (iVar3 = EVP_Digest(pAVar2->data,pAVar2->length,local_60,&local_64,dgst,(ENGINE *)0x0)
              , iVar3 != 0)) &&
             (iVar3 = ASN1_OCTET_STRING_set(a->issuerKeyHash,local_60,local_64), iVar3 != 0)) {
            if (local_70 == (ASN1_STRING *)0x0) goto LAB_081852eb;
            ASN1_INTEGER_free(a->serialNumber);
            pAVar6 = ASN1_INTEGER_dup(local_70);
            a->serialNumber = pAVar6;
            if (pAVar6 != (ASN1_STRING *)0x0) goto LAB_081852eb;
          }
        }
      }
    }
  }
  OCSP_CERTID_free(a);
  a = (OCSP_CERTID *)0x0;
LAB_081852eb:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return a;
}

