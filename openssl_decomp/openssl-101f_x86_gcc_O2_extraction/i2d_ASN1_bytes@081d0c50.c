
int i2d_ASN1_bytes(ASN1_STRING *a,uchar **pp,int tag,int xclass)

{
  int length;
  int iVar1;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (a == (ASN1_STRING *)0x0) {
    iVar1 = 0;
  }
  else if (tag == 3) {
    iVar1 = i2d_ASN1_BIT_STRING(a,pp);
  }
  else {
    length = a->length;
    iVar1 = ASN1_object_size(0,length,tag);
    if (pp != (uchar **)0x0) {
      local_24 = *pp;
      ASN1_put_object(&local_24,(uint)(tag - 0x10U < 2),length,tag,xclass);
      memcpy(local_24,a->data,a->length);
      *pp = local_24 + a->length;
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

