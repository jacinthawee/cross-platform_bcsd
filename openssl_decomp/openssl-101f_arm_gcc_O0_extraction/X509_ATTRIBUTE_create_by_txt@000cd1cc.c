
X509_ATTRIBUTE *
X509_ATTRIBUTE_create_by_txt(X509_ATTRIBUTE **attr,char *atrname,int type,uchar *bytes,int len)

{
  ASN1_OBJECT *o;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  X509_ATTRIBUTE *attr_00;
  X509_ATTRIBUTE *a;
  
  o = OBJ_txt2obj(atrname,0);
  if (o == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xb,0x8c,0x77,"x509_att.c",0x10b);
    ERR_add_error_data(2,"name=",atrname);
    return (X509_ATTRIBUTE *)0x0;
  }
  if ((attr == (X509_ATTRIBUTE **)0x0) || (attr_00 = *attr, attr_00 == (X509_ATTRIBUTE *)0x0)) {
    attr_00 = X509_ATTRIBUTE_new();
    if (attr_00 == (X509_ATTRIBUTE *)0x0) {
      attr_00 = (X509_ATTRIBUTE *)X509_ATTRIBUTE_create_by_OBJ_part_0();
      goto LAB_000cd21c;
    }
    ASN1_OBJECT_free(attr_00->object);
    pAVar1 = OBJ_dup(o);
    attr_00->object = pAVar1;
    iVar2 = X509_ATTRIBUTE_set1_data(attr_00,type,bytes,len);
    if (iVar2 != 0) {
      if (attr == (X509_ATTRIBUTE **)0x0) goto LAB_000cd21c;
      goto LAB_000cd252;
    }
    a = attr_00;
    if (attr != (X509_ATTRIBUTE **)0x0) goto LAB_000cd20a;
  }
  else {
    ASN1_OBJECT_free(attr_00->object);
    pAVar1 = OBJ_dup(o);
    attr_00->object = pAVar1;
    iVar2 = X509_ATTRIBUTE_set1_data(attr_00,type,bytes,len);
    if (iVar2 != 0) {
LAB_000cd252:
      if (*attr == (X509_ATTRIBUTE *)0x0) {
        *attr = attr_00;
      }
      goto LAB_000cd21c;
    }
LAB_000cd20a:
    a = attr_00;
    if (attr_00 == *attr) {
      attr_00 = (X509_ATTRIBUTE *)0x0;
      goto LAB_000cd21c;
    }
  }
  attr_00 = (X509_ATTRIBUTE *)0x0;
  X509_ATTRIBUTE_free(a);
LAB_000cd21c:
  ASN1_OBJECT_free(o);
  return attr_00;
}

