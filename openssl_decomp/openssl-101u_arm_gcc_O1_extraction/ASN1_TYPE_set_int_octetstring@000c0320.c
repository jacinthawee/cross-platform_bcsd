
int ASN1_TYPE_set_int_octetstring(ASN1_TYPE *a,long num,uchar *data,int len)

{
  int iVar1;
  int iVar2;
  int len_00;
  ASN1_STRING *str;
  ASN1_STRING *pAVar3;
  uchar *local_68;
  ASN1_STRING local_64;
  ASN1_INTEGER local_54;
  uchar auStack_44 [32];
  int local_24;
  
  local_54.data = auStack_44;
  local_54.length = 0x20;
  local_24 = __stack_chk_guard;
  local_64.type = 4;
  local_64.length = len;
  local_64.data = data;
  ASN1_INTEGER_set(&local_54,num);
  iVar1 = i2d_ASN1_INTEGER(&local_54,(uchar **)0x0);
  iVar2 = i2d_ASN1_bytes(&local_64,(uchar **)0x0,4,0);
  len_00 = ASN1_object_size(1,iVar1 + iVar2,0x10);
  str = ASN1_STRING_new();
  pAVar3 = str;
  if (str != (ASN1_STRING *)0x0) {
    pAVar3 = (ASN1_STRING *)ASN1_STRING_set(str,(void *)0x0,len_00);
    if (pAVar3 == (ASN1_STRING *)0x0) {
      ASN1_STRING_free(str);
    }
    else {
      local_68 = str->data;
      str->length = len_00;
      ASN1_put_object(&local_68,1,iVar1 + iVar2,0x10,0);
      i2d_ASN1_INTEGER(&local_54,&local_68);
      pAVar3 = (ASN1_STRING *)0x1;
      i2d_ASN1_bytes(&local_64,&local_68,4,0);
      ASN1_TYPE_set(a,0x10,str);
    }
  }
  if (local_24 == __stack_chk_guard) {
    return (int)pAVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

