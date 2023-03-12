
ASN1_INTEGER * d2i_ASN1_UINTEGER(ASN1_INTEGER **a,uchar **pp,long length)

{
  uint uVar1;
  int reason;
  ASN1_STRING *a_00;
  uchar *__dest;
  int in_GS_OFFSET;
  uchar *local_30;
  size_t local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((a == (ASN1_INTEGER **)0x0) || (a_00 = *a, a_00 == (ASN1_STRING *)0x0)) {
    a_00 = ASN1_STRING_type_new(2);
    if (a_00 != (ASN1_STRING *)0x0) {
      a_00->type = 2;
      goto LAB_0813ab6d;
    }
  }
  else {
LAB_0813ab6d:
    local_30 = *pp;
    uVar1 = ASN1_get_object(&local_30,(long *)&local_2c,&local_28,&local_24,length);
    if ((uVar1 & 0x80) == 0) {
      reason = 0x73;
      if (local_28 == 2) {
        __dest = (uchar *)CRYPTO_malloc(local_2c + 1,"a_int.c",0x131);
        if (__dest != (uchar *)0x0) {
          a_00->type = 2;
          if (local_2c != 0) {
            if ((*local_30 == '\0') && (local_2c != 1)) {
              local_30 = local_30 + 1;
              local_2c = local_2c - 1;
            }
            memcpy(__dest,local_30,local_2c);
            local_30 = local_30 + local_2c;
          }
          if (a_00->data != (uchar *)0x0) {
            CRYPTO_free(a_00->data);
          }
          a_00->data = __dest;
          a_00->length = local_2c;
          if (a != (ASN1_INTEGER **)0x0) {
            *a = a_00;
          }
          *pp = local_30;
          goto LAB_0813abdd;
        }
        reason = 0x41;
      }
      ERR_put_error(0xd,0x96,reason,"a_int.c",0x149);
    }
    else {
      ERR_put_error(0xd,0x96,0x66,"a_int.c",0x149);
    }
    if ((a == (ASN1_INTEGER **)0x0) || (*a != a_00)) {
      ASN1_STRING_free(a_00);
    }
  }
  a_00 = (ASN1_INTEGER *)0x0;
LAB_0813abdd:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return a_00;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

