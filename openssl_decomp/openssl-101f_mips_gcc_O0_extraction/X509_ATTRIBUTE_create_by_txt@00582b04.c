
X509_ATTRIBUTE *
X509_ATTRIBUTE_create_by_txt(X509_ATTRIBUTE **attr,char *atrname,int type,uchar *bytes,int len)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  int iVar3;
  X509_ATTRIBUTE *attr_00;
  
  iVar1 = (*(code *)PTR_OBJ_txt2obj_006a8100)(atrname,0);
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x8c,0x77,"x509_att.c",0x10b);
    (*(code *)PTR_ERR_add_error_data_006a9264)(2,"name=",atrname);
    return (X509_ATTRIBUTE *)0x0;
  }
  if ((attr == (X509_ATTRIBUTE **)0x0) || (attr_00 = *attr, attr_00 == (X509_ATTRIBUTE *)0x0)) {
    attr_00 = (X509_ATTRIBUTE *)(*(code *)PTR_X509_ATTRIBUTE_new_006a9fe0)();
    if (attr_00 == (X509_ATTRIBUTE *)0x0) {
      attr_00 = (X509_ATTRIBUTE *)0x0;
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x89,0x41,"x509_att.c",0xed);
      goto LAB_00582bbc;
    }
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(attr_00->object);
    pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a95b4)(iVar1);
    attr_00->object = pAVar2;
    iVar3 = X509_ATTRIBUTE_set1_data(attr_00,type,bytes,len);
    if (iVar3 != 0) {
      if (attr == (X509_ATTRIBUTE **)0x0) goto LAB_00582bbc;
      goto LAB_00582c64;
    }
    if ((attr == (X509_ATTRIBUTE **)0x0) || (attr_00 != *attr)) goto LAB_00582bb0;
  }
  else {
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(attr_00->object);
    pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a95b4)(iVar1);
    attr_00->object = pAVar2;
    iVar3 = X509_ATTRIBUTE_set1_data(attr_00,type,bytes,len);
    if (iVar3 != 0) {
LAB_00582c64:
      if (*attr == (X509_ATTRIBUTE *)0x0) {
        *attr = attr_00;
      }
      goto LAB_00582bbc;
    }
    if (attr_00 != *attr) {
LAB_00582bb0:
      (*(code *)PTR_X509_ATTRIBUTE_free_006a9c00)(attr_00);
      attr_00 = (X509_ATTRIBUTE *)0x0;
      goto LAB_00582bbc;
    }
  }
  attr_00 = (X509_ATTRIBUTE *)0x0;
LAB_00582bbc:
  (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iVar1);
  return attr_00;
}

