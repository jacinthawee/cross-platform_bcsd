
int ASN1_TYPE_get_int_octetstring(ASN1_TYPE *a,long *num,uchar *data,int max_len)

{
  uchar *puVar1;
  ASN1_INTEGER *a_00;
  ASN1_OCTET_STRING *a_01;
  long lVar2;
  uint uVar3;
  ASN1_STRING *pAVar4;
  size_t sVar5;
  uchar *local_54;
  int local_50;
  ASN1_const_CTX local_4c;
  
  if ((a->type == 0x10) && (pAVar4 = (a->value).asn1_string, pAVar4 != (ASN1_STRING *)0x0)) {
    local_54 = pAVar4->data;
    local_50 = pAVar4->length;
    local_4c.max = local_54 + local_50;
    local_4c.pp = &local_54;
    local_4c.error = 0x6d;
    local_4c.p = local_54;
    a_00 = (ASN1_INTEGER *)asn1_GetSequence(&local_4c,&local_50);
    if (a_00 == (ASN1_INTEGER *)0x0) {
      local_4c.line = 0xa3;
    }
    else {
      local_4c.q = local_4c.p;
      a_00 = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&local_4c.p,local_4c.slen);
      puVar1 = local_4c.q;
      if (a_00 == (ASN1_INTEGER *)0x0) goto LAB_000c04b2;
      local_4c.q = local_4c.p;
      local_4c.slen = (long)(puVar1 + (local_4c.slen - (int)local_4c.p));
      a_01 = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_4c.p,local_4c.slen);
      if (a_01 != (ASN1_OCTET_STRING *)0x0) {
        local_4c.slen = (long)(local_4c.q + (local_4c.slen - (int)local_4c.p));
        if (local_4c.inf << 0x1f < 0) {
          local_4c.eos = ASN1_const_check_infinite_end(&local_4c.p,local_4c.slen);
          uVar3 = count_leading_zeroes(local_4c.eos);
          uVar3 = uVar3 >> 5;
        }
        else if (local_4c.slen < 1) {
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
        }
        if (uVar3 == 0) {
          if (num != (long *)0x0) {
            lVar2 = ASN1_INTEGER_get(a_00);
            *num = lVar2;
          }
          sVar5 = a_01->length;
          if (data != (uchar *)0x0) {
            if ((int)sVar5 <= max_len) {
              max_len = sVar5;
            }
            memcpy(data,a_01->data,max_len);
          }
        }
        else {
          sVar5 = 0xffffffff;
          ERR_put_error(0xd,0x86,0x6d,"evp_asn1.c",0xbc);
        }
        ASN1_STRING_free(a_01);
        goto LAB_000c0494;
      }
    }
  }
  else {
LAB_000c04b2:
    a_00 = (ASN1_INTEGER *)0x0;
  }
  sVar5 = 0xffffffff;
  ERR_put_error(0xd,0x86,0x6d,"evp_asn1.c",0xbc);
  if (a_00 == (ASN1_INTEGER *)0x0) {
    return -1;
  }
LAB_000c0494:
  ASN1_STRING_free(a_00);
  return sVar5;
}

