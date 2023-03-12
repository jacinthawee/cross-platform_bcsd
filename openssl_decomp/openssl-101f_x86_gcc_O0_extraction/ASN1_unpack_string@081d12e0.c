
void * ASN1_unpack_string(ASN1_STRING *oct,undefined1 *d2i)

{
  void *pvVar1;
  int in_GS_OFFSET;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = oct->data;
  pvVar1 = (void *)(*(code *)d2i)(0,&local_14,oct->length);
  if (pvVar1 == (void *)0x0) {
    ERR_put_error(0xd,0x88,0x6e,"asn_pack.c",0x74);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pvVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

