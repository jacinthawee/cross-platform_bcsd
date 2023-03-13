
X509_ATTRIBUTE *
X509_ATTRIBUTE_create_by_NID(X509_ATTRIBUTE **attr,int nid,int atrtype,void *data,int len)

{
  ASN1_OBJECT *o;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  X509_ATTRIBUTE *attr_00;
  
  o = OBJ_nid2obj(nid);
  if (o == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xb,0x88,0x6d,"x509_att.c",0xe4);
    return (X509_ATTRIBUTE *)0x0;
  }
  if ((attr == (X509_ATTRIBUTE **)0x0) || (attr_00 = *attr, attr_00 == (X509_ATTRIBUTE *)0x0)) {
    attr_00 = X509_ATTRIBUTE_new();
    if (attr_00 == (X509_ATTRIBUTE *)0x0) {
      ERR_put_error(0xb,0x89,0x41,"x509_att.c",0xf7);
      goto LAB_08162a87;
    }
    ASN1_OBJECT_free(attr_00->object);
    pAVar1 = OBJ_dup(o);
    attr_00->object = pAVar1;
    iVar2 = X509_ATTRIBUTE_set1_data(attr_00,atrtype,data,len);
    if (iVar2 != 0) {
      if (attr == (X509_ATTRIBUTE **)0x0) {
        return attr_00;
      }
      goto LAB_08162ae8;
    }
    if (attr != (X509_ATTRIBUTE **)0x0) goto LAB_08162a77;
  }
  else {
    ASN1_OBJECT_free(attr_00->object);
    pAVar1 = OBJ_dup(o);
    attr_00->object = pAVar1;
    iVar2 = X509_ATTRIBUTE_set1_data(attr_00,atrtype,data,len);
    if (iVar2 != 0) {
LAB_08162ae8:
      if (*attr == (X509_ATTRIBUTE *)0x0) {
        *attr = attr_00;
      }
      return attr_00;
    }
LAB_08162a77:
    if (attr_00 == *attr) goto LAB_08162a87;
  }
  X509_ATTRIBUTE_free(attr_00);
LAB_08162a87:
  ASN1_OBJECT_free(o);
  return (X509_ATTRIBUTE *)0x0;
}

