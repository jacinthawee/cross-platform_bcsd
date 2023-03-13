
int i2d_ASN1_OBJECT(ASN1_OBJECT *a,uchar **pp)

{
  int iVar1;
  int in_GS_OFFSET;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = 0;
  if (a == (ASN1_OBJECT *)0x0) {
    iVar1 = 0;
  }
  else if (((a->data != (uchar *)0x0) &&
           (iVar1 = ASN1_object_size(0,a->length,6), pp != (uchar **)0x0)) && (iVar1 != -1)) {
    local_14 = *pp;
    ASN1_put_object(&local_14,0,a->length,6,0);
    memcpy(local_14,a->data,a->length);
    *pp = local_14 + a->length;
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

