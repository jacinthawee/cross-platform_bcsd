
int X509_ATTRIBUTE_set1_data(X509_ATTRIBUTE *attr,int attrtype,void *data,int len)

{
  ASN1_STRING *str;
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  ASN1_TYPE *pAVar4;
  int iVar5;
  undefined4 uVar6;
  
  if (attr == (X509_ATTRIBUTE *)0x0) {
    return 0;
  }
  if ((attrtype & 0x1000U) == 0) {
    if (len == -1) {
      str = (ASN1_STRING *)0x0;
      iVar5 = 0;
      goto LAB_00581f1c;
    }
    str = ASN1_STRING_type_new(attrtype);
    if ((str != (ASN1_STRING *)0x0) &&
       (iVar1 = ASN1_STRING_set(str,data,len), iVar5 = attrtype, iVar1 != 0)) goto LAB_00581f1c;
  }
  else {
    iVar5 = (*(code *)PTR_OBJ_obj2nid_006a822c)(attr->object);
    str = ASN1_STRING_set_by_NID((ASN1_STRING **)0x0,(uchar *)data,len,attrtype,iVar5);
    if (str == (ASN1_STRING *)0x0) {
      uVar6 = 0xd;
      uVar2 = 0x127;
      goto LAB_00581ed4;
    }
    iVar5 = str->type;
LAB_00581f1c:
    pcVar3 = (char *)(*(code *)PTR_sk_new_null_006a80a4)();
    (attr->value).ptr = pcVar3;
    if (pcVar3 != (char *)0x0) {
      attr->single = 0;
      if (attrtype == 0) {
        return 1;
      }
      pAVar4 = ASN1_TYPE_new();
      if (pAVar4 != (ASN1_TYPE *)0x0) {
        if ((len == -1) && ((attrtype & 0x1000U) == 0)) {
          iVar5 = (*(code *)PTR_ASN1_TYPE_set1_006aa088)(pAVar4,attrtype,data);
          if (iVar5 == 0) goto LAB_00581ec0;
        }
        else {
          (*(code *)PTR_ASN1_TYPE_set_006a9dfc)(pAVar4,iVar5,str);
        }
        iVar5 = (*(code *)PTR_sk_push_006a80a8)((attr->value).ptr,pAVar4);
        if (iVar5 != 0) {
          return 1;
        }
      }
    }
  }
LAB_00581ec0:
  uVar6 = 0x41;
  uVar2 = 0x143;
LAB_00581ed4:
  (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x8a,uVar6,"x509_att.c",uVar2);
  return 0;
}

