
X509_EXTENSION * X509V3_EXT_i2d(int ext_nid,int crit,void *ext_struc)

{
  X509V3_EXT_METHOD *pXVar1;
  int num;
  ASN1_STRING *data;
  X509_EXTENSION *pXVar2;
  uchar *local_20;
  uchar *local_1c;
  
  pXVar1 = X509V3_EXT_get_nid(ext_nid);
  if (pXVar1 == (X509V3_EXT_METHOD *)0x0) {
    ERR_put_error(0x22,0x88,0x81,"v3_conf.c",0xdb);
    return (X509_EXTENSION *)0x0;
  }
  if (pXVar1->it == (ASN1_ITEM *)0x0) {
    num = (*pXVar1->i2d)(ext_struc,(uchar **)0x0);
    local_20 = (uchar *)CRYPTO_malloc(num,"v3_conf.c",0xc1);
    if (local_20 == (uchar *)0x0) goto LAB_000d0458;
    local_1c = local_20;
    (*pXVar1->i2d)(ext_struc,&local_1c);
  }
  else {
    local_20 = (uchar *)0x0;
    num = ASN1_item_i2d((ASN1_VALUE *)ext_struc,&local_20,pXVar1->it);
    if (num < 0) goto LAB_000d0458;
  }
  data = ASN1_STRING_type_new(4);
  if (data != (ASN1_STRING *)0x0) {
    data->length = num;
    data->data = local_20;
    pXVar2 = X509_EXTENSION_create_by_NID((X509_EXTENSION **)0x0,ext_nid,crit,data);
    if (pXVar2 != (X509_EXTENSION *)0x0) {
      ASN1_STRING_free(data);
      return pXVar2;
    }
  }
LAB_000d0458:
  ERR_put_error(0x22,0x87,0x41,"v3_conf.c",0xd0);
  return (X509_EXTENSION *)0x0;
}

