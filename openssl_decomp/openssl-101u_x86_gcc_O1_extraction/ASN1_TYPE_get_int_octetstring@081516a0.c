
int ASN1_TYPE_get_int_octetstring(ASN1_TYPE *a,long *num,uchar *data,int max_len)

{
  ASN1_STRING *pAVar1;
  int iVar2;
  ASN1_INTEGER *a_00;
  ASN1_OCTET_STRING *a_01;
  long lVar3;
  size_t __n;
  size_t sVar4;
  int in_GS_OFFSET;
  bool bVar5;
  uchar *local_54;
  int local_50;
  undefined local_4c [24];
  int local_34;
  uchar *local_30;
  uchar *local_2c;
  uchar **local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((a->type == 0x10) && (pAVar1 = (a->value).asn1_string, pAVar1 != (ASN1_STRING *)0x0)) {
    local_54 = pAVar1->data;
    local_50 = pAVar1->length;
    local_28 = &local_54;
    local_4c._8_4_ = 0x6d;
    local_30 = local_54 + local_50;
    local_4c._0_4_ = local_54;
    iVar2 = asn1_GetSequence((ASN1_const_CTX *)local_4c,&local_50);
    if (iVar2 == 0) {
      local_24 = 0xa3;
      a_00 = (ASN1_INTEGER *)0x0;
      goto LAB_0815180a;
    }
    local_2c = local_4c._0_4_;
    a_00 = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,(uchar **)(ASN1_const_CTX *)local_4c,local_34);
    if (a_00 == (ASN1_INTEGER *)0x0) goto LAB_08151808;
    iVar2 = (int)local_4c._0_4_ - (int)local_2c;
    local_2c = local_4c._0_4_;
    local_34 = local_34 - iVar2;
    a_01 = d2i_ASN1_OCTET_STRING
                     ((ASN1_OCTET_STRING **)0x0,(uchar **)(ASN1_const_CTX *)local_4c,local_34);
    if (a_01 == (ASN1_OCTET_STRING *)0x0) goto LAB_0815180a;
    local_34 = local_34 - ((int)local_4c._0_4_ - (int)local_2c);
    if ((local_4c[12] & 1) == 0) {
      bVar5 = 0 < local_34;
    }
    else {
      local_4c._4_4_ = ASN1_const_check_infinite_end((uchar **)(ASN1_const_CTX *)local_4c,local_34);
      bVar5 = local_4c._4_4_ == 0;
    }
    if (bVar5) {
      sVar4 = 0xffffffff;
      ERR_put_error(0xd,0x86,0x6d,"evp_asn1.c",0xbc);
    }
    else {
      if (num != (long *)0x0) {
        lVar3 = ASN1_INTEGER_get(a_00);
        *num = lVar3;
      }
      sVar4 = a_01->length;
      if (data != (uchar *)0x0) {
        __n = sVar4;
        if (max_len < (int)sVar4) {
          __n = max_len;
        }
        memcpy(data,a_01->data,__n);
      }
    }
    ASN1_STRING_free(a_01);
  }
  else {
LAB_08151808:
    a_00 = (ASN1_INTEGER *)0x0;
LAB_0815180a:
    sVar4 = 0xffffffff;
    ERR_put_error(0xd,0x86,0x6d,"evp_asn1.c",0xbc);
    if (a_00 == (ASN1_INTEGER *)0x0) goto LAB_081517ea;
  }
  ASN1_STRING_free(a_00);
LAB_081517ea:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return sVar4;
}

