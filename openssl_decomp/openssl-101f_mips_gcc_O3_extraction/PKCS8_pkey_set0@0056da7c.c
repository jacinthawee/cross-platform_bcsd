
int PKCS8_pkey_set0(PKCS8_PRIV_KEY_INFO *priv,ASN1_OBJECT *aobj,int version,int ptype,void *pval,
                   uchar *penc,int penclen)

{
  int iVar1;
  ASN1_OCTET_STRING *value;
  ASN1_TYPE *a;
  int type;
  
  if ((version < 0) || (iVar1 = ASN1_INTEGER_set(priv->version,version), iVar1 != 0)) {
    if (penc == (uchar *)0x0) {
      iVar1 = X509_ALGOR_set0(priv->pkeyalg,aobj,ptype,pval);
      return (uint)(iVar1 != 0);
    }
    value = ASN1_OCTET_STRING_new();
    if (value != (ASN1_OCTET_STRING *)0x0) {
      iVar1 = priv->broken;
      type = 0x10;
      a = priv->pkey;
      value->data = penc;
      if (iVar1 != 1) {
        type = 4;
      }
      value->length = penclen;
      ASN1_TYPE_set(a,type,value);
      iVar1 = X509_ALGOR_set0(priv->pkeyalg,aobj,ptype,pval);
      if (iVar1 == 0) {
        value->data = (uchar *)0x0;
        return 0;
      }
      return 1;
    }
  }
  return 0;
}

