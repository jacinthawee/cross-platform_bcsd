
ASN1_STRING * d2i_ASN1_type_bytes(ASN1_STRING **a,uchar **pp,long length,int type)

{
  uint uVar1;
  int reason;
  ASN1_STRING *a_00;
  ulong uVar2;
  uchar *__dest;
  int in_GS_OFFSET;
  uchar *local_30;
  size_t local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_30 = *pp;
  uVar1 = ASN1_get_object(&local_30,(long *)&local_2c,&local_28,&local_24,length);
  if ((uVar1 & 0x80) == 0) {
    reason = 0x99;
    if (local_28 < 0x20) {
      uVar2 = ASN1_tag2bit(local_28);
      if ((type & uVar2) != 0) {
        if (local_28 == 3) {
          a_00 = d2i_ASN1_BIT_STRING(a,pp,length);
        }
        else {
          if ((a == (ASN1_STRING **)0x0) || (a_00 = *a, a_00 == (ASN1_STRING *)0x0)) {
            a_00 = ASN1_STRING_new();
            if (a_00 == (ASN1_STRING *)0x0) {
              a_00 = (ASN1_STRING *)0x0;
              goto LAB_081d0143;
            }
          }
          __dest = (uchar *)0x0;
          if (local_2c != 0) {
            __dest = (uchar *)CRYPTO_malloc(local_2c + 1,"a_bytes.c",0x6b);
            if (__dest == (uchar *)0x0) {
              ERR_put_error(0xd,0x95,0x41,"a_bytes.c",0x80);
              if ((a == (ASN1_STRING **)0x0) || (a_00 != *a)) {
                ASN1_STRING_free(a_00);
              }
              a_00 = (ASN1_STRING *)0x0;
              goto LAB_081d0143;
            }
            memcpy(__dest,local_30,local_2c);
            __dest[local_2c] = '\0';
            local_30 = local_30 + local_2c;
          }
          if (a_00->data != (uchar *)0x0) {
            CRYPTO_free(a_00->data);
          }
          a_00->length = local_2c;
          a_00->data = __dest;
          a_00->type = local_28;
          if (a != (ASN1_STRING **)0x0) {
            *a = a_00;
          }
          *pp = local_30;
        }
        goto LAB_081d0143;
      }
      reason = 0xa9;
    }
  }
  else {
    reason = 0;
  }
  ERR_put_error(0xd,0x95,reason,"a_bytes.c",0x80);
  a_00 = (ASN1_STRING *)0x0;
LAB_081d0143:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return a_00;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

