
ASN1_GENERALIZEDTIME * ASN1_TIME_to_generalizedtime(ASN1_TIME *t,ASN1_GENERALIZEDTIME **out)

{
  int iVar1;
  ASN1_GENERALIZEDTIME *str;
  uchar *puVar2;
  
  if (t->type == 0x18) {
    iVar1 = ASN1_GENERALIZEDTIME_check(t);
  }
  else {
    if (t->type != 0x17) {
      return (ASN1_GENERALIZEDTIME *)0x0;
    }
    iVar1 = ASN1_UTCTIME_check(t);
  }
  if (iVar1 != 0) {
    if (out == (ASN1_GENERALIZEDTIME **)0x0) {
      str = ASN1_GENERALIZEDTIME_new();
      if (str == (ASN1_GENERALIZEDTIME *)0x0) {
        return (ASN1_GENERALIZEDTIME *)0x0;
      }
      iVar1 = t->type;
    }
    else {
      str = *out;
      if (str == (ASN1_GENERALIZEDTIME *)0x0) {
        str = ASN1_GENERALIZEDTIME_new();
        if (str == (ASN1_GENERALIZEDTIME *)0x0) {
          return (ASN1_GENERALIZEDTIME *)0x0;
        }
        *out = str;
      }
      iVar1 = t->type;
    }
    if (iVar1 == 0x18) {
      iVar1 = ASN1_STRING_set(str,t->data,t->length);
      if (iVar1 != 0) {
        return str;
      }
    }
    else {
      iVar1 = ASN1_STRING_set(str,(void *)0x0,t->length + 2);
      if (iVar1 != 0) {
        puVar2 = str->data;
        iVar1 = t->length + 3;
        if (*t->data < 0x35) {
          (*(code *)PTR_BUF_strlcpy_006a8064)(puVar2,&DAT_0066a000,iVar1);
        }
        else {
          (*(code *)PTR_BUF_strlcpy_006a8064)(puVar2,&DAT_00669ffc);
        }
        (*(code *)PTR_BUF_strlcat_006a8068)(puVar2,t->data,iVar1);
        return str;
      }
    }
  }
  return (ASN1_GENERALIZEDTIME *)0x0;
}

