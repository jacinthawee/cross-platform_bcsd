
int PKCS8_pkey_get0(ASN1_OBJECT **ppkalg,uchar **pk,int *ppklen,X509_ALGOR **pa,
                   PKCS8_PRIV_KEY_INFO *p8)

{
  ASN1_TYPE *pAVar1;
  
  if (ppkalg != (ASN1_OBJECT **)0x0) {
    *ppkalg = p8->pkeyalg->algorithm;
  }
  pAVar1 = p8->pkey;
  if (pAVar1->type == 4) {
    p8->broken = 0;
    if (pk != (uchar **)0x0) {
      *pk = ((pAVar1->value).asn1_string)->data;
      *ppklen = ((p8->pkey->value).asn1_string)->length;
    }
  }
  else {
    if (pAVar1->type != 0x10) {
      return 0;
    }
    p8->broken = 1;
    if (pk != (uchar **)0x0) {
      *pk = ((pAVar1->value).asn1_string)->data;
      *ppklen = ((p8->pkey->value).asn1_string)->length;
    }
  }
  if (pa == (X509_ALGOR **)0x0) {
    return 1;
  }
  *pa = p8->pkeyalg;
  return 1;
}

