
int PKCS8_pkey_set0(PKCS8_PRIV_KEY_INFO *priv,ASN1_OBJECT *aobj,int version,int ptype,void *pval,
                   uchar *penc,int penclen)

{
  int iVar1;
  ASN1_OCTET_STRING *value;
  int type;
  
  if ((-1 < version) && (iVar1 = ASN1_INTEGER_set(priv->version,version), iVar1 == 0)) {
    return 0;
  }
  if (penc == (uchar *)0x0) {
    iVar1 = X509_ALGOR_set0(priv->pkeyalg,aobj,ptype,pval);
    return (uint)(iVar1 != 0);
  }
  value = ASN1_OCTET_STRING_new();
  if (value == (ASN1_OCTET_STRING *)0x0) {
    return 0;
  }
  iVar1 = priv->broken;
  value->data = penc;
  value->length = penclen;
  type = 0x10;
  if (iVar1 != 1) {
    type = 4;
  }
  ASN1_TYPE_set(priv->pkey,type,value);
  iVar1 = X509_ALGOR_set0(priv->pkeyalg,aobj,ptype,pval);
  if (iVar1 != 0) {
    return 1;
  }
  value->data = (uchar *)0x0;
  return 0;
}

