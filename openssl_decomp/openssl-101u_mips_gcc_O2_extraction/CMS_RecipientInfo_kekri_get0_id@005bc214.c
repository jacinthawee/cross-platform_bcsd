
int CMS_RecipientInfo_kekri_get0_id
              (CMS_RecipientInfo *ri,X509_ALGOR **palg,ASN1_OCTET_STRING **pid,
              ASN1_GENERALIZEDTIME **pdate,ASN1_OBJECT **potherid,ASN1_TYPE **pothertype)

{
  ASN1_OCTET_STRING **ppAVar1;
  
  if (*(int *)ri != 2) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x89,0x7b,"cms_env.c",0x231);
    return 0;
  }
  ppAVar1 = *(ASN1_OCTET_STRING ***)(*(int *)(ri + 4) + 4);
  if (palg != (X509_ALGOR **)0x0) {
    *palg = *(X509_ALGOR **)(*(int *)(ri + 4) + 8);
  }
  if (pid != (ASN1_OCTET_STRING **)0x0) {
    *pid = *ppAVar1;
  }
  if (pdate != (ASN1_GENERALIZEDTIME **)0x0) {
    *pdate = ppAVar1[1];
  }
  if (potherid != (ASN1_OBJECT **)0x0) {
    if (ppAVar1[2] == (ASN1_OCTET_STRING *)0x0) {
      *potherid = (ASN1_OBJECT *)0x0;
    }
    else {
      *potherid = (ASN1_OBJECT *)ppAVar1[2]->length;
    }
  }
  if (pothertype != (ASN1_TYPE **)0x0) {
    if (ppAVar1[2] == (ASN1_OCTET_STRING *)0x0) {
      *pothertype = (ASN1_TYPE *)0x0;
      return 1;
    }
    *pothertype = (ASN1_TYPE *)ppAVar1[2]->type;
  }
  return 1;
}

