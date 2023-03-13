
X509_ATTRIBUTE *
X509_ATTRIBUTE_create_by_txt(X509_ATTRIBUTE **attr,char *atrname,int type,uchar *bytes,int len)

{
  ASN1_OBJECT *o;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  X509_ATTRIBUTE *attr_00;
  
  o = OBJ_txt2obj(atrname,0);
  if (o == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xb,0x8c,0x77,"x509_att.c",0x116);
    ERR_add_error_data(2,"name=",atrname);
    return (X509_ATTRIBUTE *)0x0;
  }
  if ((attr == (X509_ATTRIBUTE **)0x0) || (attr_00 = *attr, attr_00 == (X509_ATTRIBUTE *)0x0)) {
    attr_00 = X509_ATTRIBUTE_new();
    if (attr_00 == (X509_ATTRIBUTE *)0x0) {
      attr_00 = (X509_ATTRIBUTE *)0x0;
      ERR_put_error(0xb,0x89,0x41,"x509_att.c",0xf7);
      goto LAB_08162941;
    }
    ASN1_OBJECT_free(attr_00->object);
    pAVar1 = OBJ_dup(o);
    attr_00->object = pAVar1;
    iVar2 = X509_ATTRIBUTE_set1_data(attr_00,type,bytes,len);
    if (iVar2 != 0) {
      if (attr == (X509_ATTRIBUTE **)0x0) goto LAB_08162941;
      goto LAB_081629b0;
    }
    if ((attr != (X509_ATTRIBUTE **)0x0) && (*attr == attr_00)) goto LAB_081629a4;
  }
  else {
    ASN1_OBJECT_free(attr_00->object);
    pAVar1 = OBJ_dup(o);
    attr_00->object = pAVar1;
    iVar2 = X509_ATTRIBUTE_set1_data(attr_00,type,bytes,len);
    if (iVar2 != 0) {
LAB_081629b0:
      if (*attr == (X509_ATTRIBUTE *)0x0) {
        *attr = attr_00;
      }
      goto LAB_08162941;
    }
    if (*attr == attr_00) {
LAB_081629a4:
      attr_00 = (X509_ATTRIBUTE *)0x0;
      goto LAB_08162941;
    }
  }
  X509_ATTRIBUTE_free(attr_00);
  attr_00 = (X509_ATTRIBUTE *)0x0;
LAB_08162941:
  ASN1_OBJECT_free(o);
  return attr_00;
}

