
ASN1_OBJECT * d2i_ASN1_OBJECT(ASN1_OBJECT **a,uchar **pp,long length)

{
  uint uVar1;
  ASN1_OBJECT *pAVar2;
  int reason;
  int in_GS_OFFSET;
  uchar *local_20;
  long local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_20 = *pp;
  uVar1 = ASN1_get_object(&local_20,&local_1c,&local_18,&local_14,length);
  if ((uVar1 & 0x80) == 0) {
    if (local_18 == 6) {
      pAVar2 = c2i_ASN1_OBJECT(a,&local_20,local_1c);
      if (pAVar2 == (ASN1_OBJECT *)0x0) {
        pAVar2 = (ASN1_OBJECT *)0x0;
      }
      else {
        *pp = local_20;
      }
      goto LAB_08136406;
    }
    reason = 0x74;
  }
  else {
    reason = 0x66;
  }
  ERR_put_error(0xd,0x93,reason,"a_object.c",0x10c);
  pAVar2 = (ASN1_OBJECT *)0x0;
LAB_08136406:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

