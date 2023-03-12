
OCSP_CERTID *
OCSP_cert_id_new(EVP_MD *dgst,X509_NAME *issuerName,ASN1_BIT_STRING *issuerKey,
                ASN1_INTEGER *serialNumber)

{
  X509_ALGOR *pXVar1;
  OCSP_CERTID *a;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  ASN1_TYPE *pAVar4;
  ASN1_STRING *pAVar5;
  int in_GS_OFFSET;
  uint local_64;
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  a = OCSP_CERTID_new();
  if (a == (OCSP_CERTID *)0x0) {
    a = (OCSP_CERTID *)0x0;
    goto LAB_08186fd0;
  }
  pXVar1 = a->hashAlgorithm;
  if (pXVar1->algorithm != (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free(pXVar1->algorithm);
  }
  iVar2 = EVP_MD_type(dgst);
  if (iVar2 == 0) {
    ERR_put_error(0x27,0x65,0x78,"ocsp_lib.c",0x74);
  }
  else {
    pAVar3 = OBJ_nid2obj(iVar2);
    pXVar1->algorithm = pAVar3;
    if (pAVar3 != (ASN1_OBJECT *)0x0) {
      pAVar4 = ASN1_TYPE_new();
      pXVar1->parameter = pAVar4;
      if (pAVar4 != (ASN1_TYPE *)0x0) {
        pAVar4->type = 5;
        iVar2 = X509_NAME_digest(issuerName,dgst,local_60,&local_64);
        if (iVar2 == 0) {
          ERR_put_error(0x27,0x65,0x66,"ocsp_lib.c",0x8b);
        }
        else {
          iVar2 = ASN1_OCTET_STRING_set(a->issuerNameHash,local_60,local_64);
          if (((iVar2 != 0) &&
              (iVar2 = EVP_Digest(issuerKey->data,issuerKey->length,local_60,&local_64,dgst,
                                  (ENGINE *)0x0), iVar2 != 0)) &&
             (iVar2 = ASN1_OCTET_STRING_set(a->issuerKeyHash,local_60,local_64), iVar2 != 0)) {
            if (serialNumber == (ASN1_INTEGER *)0x0) goto LAB_08186fd0;
            ASN1_INTEGER_free(a->serialNumber);
            pAVar5 = ASN1_INTEGER_dup(serialNumber);
            a->serialNumber = pAVar5;
            if (pAVar5 != (ASN1_STRING *)0x0) goto LAB_08186fd0;
          }
        }
      }
    }
  }
  OCSP_CERTID_free(a);
  a = (OCSP_CERTID *)0x0;
LAB_08186fd0:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return a;
}

